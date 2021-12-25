// COMDemo.h: объявление CCOMDemo

#pragma once
#include "resource.h"       // основные символы



#include "COMServer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Однопотоковые COM-объекты не поддерживаются должным образом платформой Windows CE, например платформами Windows Mobile, в которых не предусмотрена полная поддержка DCOM. Определите _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, чтобы принудить ATL поддерживать создание однопотоковых COM-объектов и разрешить использование его реализаций однопотоковых COM-объектов. Для потоковой модели в вашем rgs-файле задано значение 'Free', поскольку это единственная потоковая модель, поддерживаемая не-DCOM платформами Windows CE."
#endif

using namespace ATL;


// CCOMDemo

class ATL_NO_VTABLE CCOMDemo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCOMDemo, &CLSID_COMDemo>,
	public IDispatchImpl<IWelcome, &IID_IWelcome, &LIBID_COMServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	//public IDispatchImpl2<IMath, &IID_IMath, &LIBID_COMServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
	public IDispatchImpl<IMath, &IID_IMath, &LIBID_COMServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCOMDemo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CCOMDemo)
	COM_INTERFACE_ENTRY(IWelcome)
	COM_INTERFACE_ENTRY(IMath)
	COM_INTERFACE_ENTRY2(IDispatch, IWelcome)
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



	STDMETHOD(Greeting)(BSTR name, BSTR* message);
	STDMETHOD(Add)(LONG x, LONG y, LONG * result);
	STDMETHOD(Sub)(LONG x, LONG y, LONG* result);
	STDMETHOD(Mul)(LONG x, LONG y, LONG* z);
	STDMETHOD(Div)(LONG x, LONG y, LONG* z);


};

OBJECT_ENTRY_AUTO(__uuidof(COMDemo), CCOMDemo)
