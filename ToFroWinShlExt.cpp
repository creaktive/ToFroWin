// ToFroWinShlExt.cpp : Implementation of CToFroWinShlExt
#include "stdafx.h"
#include "ToFroWin.h"
#include "ToFroWinShlExt.h"

#include <atlcom.h>
#include <atlconv.h>

#include "wintofrodos.h"


/////////////////////////////////////////////////////////////////////////////
// CToFroWinShlExt

HRESULT CToFroWinShlExt::Initialize ( LPCITEMIDLIST pidlFolder,
                                   LPDATAOBJECT pDataObj,
                                   HKEY hProgID )
{
	FORMATETC	fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM	stg = { TYMED_HGLOBAL };
	HDROP		hDrop;
	TCHAR		szFile[MAX_PATH];

	// Look for CF_HDROP data in the data object.
	if (FAILED(pDataObj->GetData(&fmt, &stg)))
		// Nope! Return an "invalid argument" error back to Explorer.
		return E_INVALIDARG;

	// Get a pointer to the actual data.
	hDrop = (HDROP) GlobalLock(stg.hGlobal);

	// Make sure it worked.
	if (hDrop == NULL)
		return E_INVALIDARG;

	// Sanity check - make sure there is at least one filename.
	UINT uNumFiles = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);

	HRESULT hr = E_INVALIDARG;
	head = NULL;
	tail = NULL;

	if (uNumFiles != 0)
	{
		for (UINT uFile = 0; uFile < uNumFiles; uFile++)
		{
			// Get the next filename.
			if (DragQueryFile(hDrop, uFile, szFile, MAX_PATH) == 0)
				continue;

			SelectFile *file = (SelectFile *) malloc(sizeof(SelectFile));
			lstrcpyn(file->file, szFile, MAX_PATH - 1);
			file->next = NULL;

			if (head == NULL)
			{
				head = file;
				tail = file;
			}
			else
			{
				tail->next = file;
				tail = file;
			}
		}

		hr = S_OK;
	}

	GlobalUnlock(stg.hGlobal);
	ReleaseStgMedium(&stg);

	return hr;
}

HRESULT CToFroWinShlExt::QueryContextMenu ( HMENU hmenu, UINT  uMenuIndex, 
                                         UINT  uidFirstCmd, UINT  uidLastCmd,
                                         UINT  uFlags )
{
	UINT uCmdID = uidFirstCmd;
	int num = 0;
	HINSTANCE hMod = _Module.GetModuleInstance();

    // If the flags include CMF_DEFAULTONLY then we shouldn't do anything.
    if ( uFlags & CMF_DEFAULTONLY )
        {
        return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 0 );
        }

	HMENU hSubMenu = CreatePopupMenu();

    HBITMAP Icon = LoadBitmap ( hMod, MAKEINTRESOURCE(IDB_ICON) );
    HBITMAP d2u = LoadBitmap ( hMod, MAKEINTRESOURCE(IDB_D2U) );
    HBITMAP u2d = LoadBitmap ( hMod, MAKEINTRESOURCE(IDB_U2D) );

	InsertMenu ( hSubMenu, num, MF_STRING | MF_BYPOSITION, uCmdID++, _T("From DOS to &UNIX") );
	SetMenuItemBitmaps ( hSubMenu, num, MF_BYPOSITION, d2u, NULL );
	num++;

	InsertMenu ( hSubMenu, num, MF_STRING | MF_BYPOSITION, uCmdID++, _T("From UNIX to &DOS") );
	SetMenuItemBitmaps ( hSubMenu, num, MF_BYPOSITION, u2d, NULL );
	num++;

	InsertMenu ( hmenu, uMenuIndex, MF_POPUP  | MF_BYPOSITION, (UINT) hSubMenu, _T("&Convert text mode") );
	SetMenuItemBitmaps ( hmenu, uMenuIndex, MF_BYPOSITION, Icon, NULL );

    return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, num );
}

HRESULT CToFroWinShlExt::GetCommandString ( UINT  idCmd,      UINT uFlags,
                                         UINT* pwReserved, LPSTR pszName,
                                         UINT  cchMax )
{
    USES_CONVERSION;

    // If Explorer is asking for a help string, copy our string into the
    // supplied buffer.
    if ( uFlags & GCS_HELPTEXT )
        {
        LPCTSTR szText = _T("Performs conversion between DOS and UNIX text formats");

        if ( uFlags & GCS_UNICODE )
            {
            // We need to cast pszName to a Unicode string, and then use the
            // Unicode string copy API.
            lstrcpynW ( (LPWSTR) pszName, T2CW(szText), cchMax );
            }
        else
            {
            // Use the ANSI string copy API to return the help string.
            lstrcpynA ( pszName, T2CA(szText), cchMax );
            }

        return S_OK;
        }

    return E_INVALIDARG;
}

HRESULT CToFroWinShlExt::InvokeCommand ( LPCMINVOKECOMMANDINFO pCmdInfo )
{
	// If lpVerb really points to a string, ignore this function call and bail out.
	if (HIWORD(pCmdInfo->lpVerb) != 0)
		return E_INVALIDARG;

	// Get the command index
	BOOL d2u = FALSE;
	switch (LOWORD(pCmdInfo->lpVerb))
	{
		case 0:
			d2u = TRUE;
		case 1:
		{
			UINT num = 0;

			for (SelectFile *p = head; p != NULL; num++)
			{
				if (d2u)
					dos2unix(pCmdInfo->hwnd, p->file);
				else
					unix2dos(pCmdInfo->hwnd, p->file);

				SelectFile *q = p;
				p = p->next;
				free(q);
			}

			TCHAR msg[256];
			wsprintf(msg, "Converted %d files from %s to %s.",
				num,
				 d2u ? "DOS" : "UNIX",
				!d2u ? "DOS" : "UNIX"
			);

			MessageBox(pCmdInfo->hwnd, msg, "Conversion completed", MB_OK | MB_ICONINFORMATION);

			return S_OK;
		}

		default:
			return E_INVALIDARG;
	}
}
