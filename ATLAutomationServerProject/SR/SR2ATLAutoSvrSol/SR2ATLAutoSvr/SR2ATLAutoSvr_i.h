

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for SR2ATLAutoSvr.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SR2ATLAutoSvr_i_h__
#define __SR2ATLAutoSvr_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISR2MyMath_FWD_DEFINED__
#define __ISR2MyMath_FWD_DEFINED__
typedef interface ISR2MyMath ISR2MyMath;

#endif 	/* __ISR2MyMath_FWD_DEFINED__ */


#ifndef __SR2MyMath_FWD_DEFINED__
#define __SR2MyMath_FWD_DEFINED__

#ifdef __cplusplus
typedef class SR2MyMath SR2MyMath;
#else
typedef struct SR2MyMath SR2MyMath;
#endif /* __cplusplus */

#endif 	/* __SR2MyMath_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISR2MyMath_INTERFACE_DEFINED__
#define __ISR2MyMath_INTERFACE_DEFINED__

/* interface ISR2MyMath */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISR2MyMath;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ef79723f-48f7-4fb1-afc9-c0ddbbc32eac")
    ISR2MyMath : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fun141( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [retval][out] */ DOUBLE *z) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fun142( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG z,
            /* [retval][out] */ LONG *output) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fun143( 
            /* [in] */ DOUBLE x,
            /* [retval][out] */ DOUBLE *output) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISR2MyMathVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISR2MyMath * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISR2MyMath * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISR2MyMath * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISR2MyMath * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISR2MyMath * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISR2MyMath * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISR2MyMath * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *fun141 )( 
            ISR2MyMath * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [retval][out] */ DOUBLE *z);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *fun142 )( 
            ISR2MyMath * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG z,
            /* [retval][out] */ LONG *output);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *fun143 )( 
            ISR2MyMath * This,
            /* [in] */ DOUBLE x,
            /* [retval][out] */ DOUBLE *output);
        
        END_INTERFACE
    } ISR2MyMathVtbl;

    interface ISR2MyMath
    {
        CONST_VTBL struct ISR2MyMathVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISR2MyMath_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISR2MyMath_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISR2MyMath_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISR2MyMath_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISR2MyMath_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISR2MyMath_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISR2MyMath_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISR2MyMath_fun141(This,x,y,z)	\
    ( (This)->lpVtbl -> fun141(This,x,y,z) ) 

#define ISR2MyMath_fun142(This,x,y,z,output)	\
    ( (This)->lpVtbl -> fun142(This,x,y,z,output) ) 

#define ISR2MyMath_fun143(This,x,output)	\
    ( (This)->lpVtbl -> fun143(This,x,output) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISR2MyMath_INTERFACE_DEFINED__ */



#ifndef __SR2ATLAutoSvrLib_LIBRARY_DEFINED__
#define __SR2ATLAutoSvrLib_LIBRARY_DEFINED__

/* library SR2ATLAutoSvrLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_SR2ATLAutoSvrLib;

EXTERN_C const CLSID CLSID_SR2MyMath;

#ifdef __cplusplus

class DECLSPEC_UUID("a76ea009-d52b-4d40-9444-3301a1357ed9")
SR2MyMath;
#endif
#endif /* __SR2ATLAutoSvrLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


