// SR2MyMath.h: объявление CSR2MyMath

#pragma once
#include "resource.h"       // основные символы



#include "SR2ATLAutoSvr_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Однопотоковые COM-объекты не поддерживаются должным образом платформой Windows CE, например платформами Windows Mobile, в которых не предусмотрена полная поддержка DCOM. Определите _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, чтобы принудить ATL поддерживать создание однопотоковых COM-объектов и разрешить использование его реализаций однопотоковых COM-объектов. Для потоковой модели в вашем rgs-файле задано значение 'Free', поскольку это единственная потоковая модель, поддерживаемая не-DCOM платформами Windows CE."
#endif

using namespace ATL;


// CSR2MyMath

class ATL_NO_VTABLE CSR2MyMath :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSR2MyMath, &CLSID_SR2MyMath>,
	public IDispatchImpl<ISR2MyMath, &IID_ISR2MyMath, &LIBID_SR2ATLAutoSvrLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSR2MyMath()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CSR2MyMath)
	COM_INTERFACE_ENTRY(ISR2MyMath)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(fun141)(LONG x, LONG y, DOUBLE* z);
	STDMETHOD(fun142)(LONG x, LONG y, LONG z, LONG* output);
	STDMETHOD(fun143)(DOUBLE x, DOUBLE* output);

};

OBJECT_ENTRY_AUTO(__uuidof(SR2MyMath), CSR2MyMath)
