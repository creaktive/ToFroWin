/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Mar 27 12:14:41 2004
 */
/* Compiler settings for D:\Stas\buf\ToFroWin\ToFroWin.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ToFroWin_h__
#define __ToFroWin_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IToFroWinShlExt_FWD_DEFINED__
#define __IToFroWinShlExt_FWD_DEFINED__
typedef interface IToFroWinShlExt IToFroWinShlExt;
#endif 	/* __IToFroWinShlExt_FWD_DEFINED__ */


#ifndef __ToFroWinShlExt_FWD_DEFINED__
#define __ToFroWinShlExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class ToFroWinShlExt ToFroWinShlExt;
#else
typedef struct ToFroWinShlExt ToFroWinShlExt;
#endif /* __cplusplus */

#endif 	/* __ToFroWinShlExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IToFroWinShlExt_INTERFACE_DEFINED__
#define __IToFroWinShlExt_INTERFACE_DEFINED__

/* interface IToFroWinShlExt */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IToFroWinShlExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81D748F0-3A27-45FF-88F9-178354D9BD69")
    IToFroWinShlExt : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IToFroWinShlExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IToFroWinShlExt __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IToFroWinShlExt __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IToFroWinShlExt __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IToFroWinShlExt __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IToFroWinShlExt __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IToFroWinShlExt __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IToFroWinShlExt __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IToFroWinShlExtVtbl;

    interface IToFroWinShlExt
    {
        CONST_VTBL struct IToFroWinShlExtVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IToFroWinShlExt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IToFroWinShlExt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IToFroWinShlExt_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IToFroWinShlExt_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IToFroWinShlExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IToFroWinShlExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IToFroWinShlExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IToFroWinShlExt_INTERFACE_DEFINED__ */



#ifndef __TOFROWINLib_LIBRARY_DEFINED__
#define __TOFROWINLib_LIBRARY_DEFINED__

/* library TOFROWINLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TOFROWINLib;

EXTERN_C const CLSID CLSID_ToFroWinShlExt;

#ifdef __cplusplus

class DECLSPEC_UUID("0FDEEA60-1DA5-4930-83A8-5A75CAD2BBE1")
ToFroWinShlExt;
#endif
#endif /* __TOFROWINLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
