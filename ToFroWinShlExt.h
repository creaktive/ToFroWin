// ToFroWinShlExt.h : Declaration of the CToFroWinShlExt

#ifndef __TOFROWINSHLEXT_H_
#define __TOFROWINSHLEXT_H_

#include "resource.h"       // main symbols
#include <shlobj.h>
#include <comdef.h>

/////////////////////////////////////////////////////////////////////////////
// CToFroWinShlExt
class ATL_NO_VTABLE CToFroWinShlExt : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CToFroWinShlExt, &CLSID_ToFroWinShlExt>,
	public IDispatchImpl<IToFroWinShlExt, &IID_IToFroWinShlExt, &LIBID_TOFROWINLib>,

	public IShellExtInit,
	public IContextMenu
{
public:
	CToFroWinShlExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TOFROWINSHLEXT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CToFroWinShlExt)
	COM_INTERFACE_ENTRY(IToFroWinShlExt)
	COM_INTERFACE_ENTRY(IDispatch)

	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()

// IToFroWinShlExt
public:

protected:

	typedef struct _SelectFile
	{
		TCHAR file[MAX_PATH];
		struct _SelectFile *next;
	} SelectFile;

	SelectFile *head, *tail;

public:
    // IToFroWinExt
    STDMETHOD(Initialize)(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

    // IContextMenu
    STDMETHOD(GetCommandString)(UINT, UINT, UINT*, LPSTR, UINT);
    STDMETHOD(InvokeCommand)(LPCMINVOKECOMMANDINFO);
    STDMETHOD(QueryContextMenu)(HMENU, UINT, UINT, UINT, UINT);

};

#endif //__TOFROWINSHLEXT_H_
