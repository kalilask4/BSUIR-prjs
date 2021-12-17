//
// �Math.cpp
//
#include <windows.h>
#include "CMath.h"
//
// Math class implementation
//
// Constructors
CMath::CMath()
{
	m_lRef = 0;
	// ��������� �������� �������� �������� ��������
	InterlockedIncrement(&g_lObjs);
}
// The destructor
CMath::~CMath()
{
	// ��������� �������� �������� �������� ��������
	InterlockedDecrement(&g_lObjs);
}

STDMETHODIMP CMath::QueryInterface(REFIID riid, void** ppv)
{
	/**ppv = 0;
	if (riid == IID_IUnknown || riid == IID_IMATH)
		*ppv = this;*/
	*ppv = 0;

	if (riid == IID_IUnknown)
		*ppv = (IMath*)this;
	else if (riid == IID_IMATH)
		*ppv = (IMath*)this;
	else if (riid == IID_IVer)
			*ppv = (IVer*)this;

	

	if (*ppv)
	{
		AddRef();
		return(S_OK);
	}
	return (E_NOINTERFACE);
}
STDMETHODIMP_(ULONG) CMath::AddRef()
{
	return InterlockedIncrement(&m_lRef);
}
STDMETHODIMP_(ULONG) CMath::Release()
{
	if (InterlockedDecrement(&m_lRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_lRef;
}


STDMETHODIMP CMath::Add(long lOp1, long lOp2, long* pResult)
{
	*pResult = lOp1 + lOp2;
	return S_OK;
}
STDMETHODIMP CMath::Subtract(long lOp1, long lOp2, long*
	pResult)
{
	*pResult = lOp1 - lOp2;
	return S_OK;
}
STDMETHODIMP CMath::Multiply(long lOp1, long lOp2, long*
	pResult)
{
	*pResult = lOp1 * lOp2;
	return S_OK;
}

STDMETHODIMP CMath::Divide(long lOp1, long lOp2, long* pResult
)
{
	*pResult = lOp1 / lOp2;
	return S_OK;
}

STDMETHODIMP CMath::FunTest(int lOp1, int lOp2, float* pResult)
{

	*pResult = lOp1 * lOp2 * 10;
	return S_OK;
}


STDMETHODIMP CMath::GetAuthor(wchar_t** author)
{
	wchar_t* p = (wchar_t*)CoTaskMemAlloc(200);
	lstrcpyW(p, L"From COM object 00321 kalilask4\n");
	*author = p;
	return S_OK;
}


//������� ������
MathClassFactory::MathClassFactory()
{
	m_lRef = 0;
}
MathClassFactory::~MathClassFactory()
{
}
STDMETHODIMP MathClassFactory::QueryInterface(REFIID riid,
	void** ppv)
{
	*ppv = 0;
	if (riid == IID_IUnknown || riid == IID_IClassFactory)
		*ppv = this;
	if (*ppv)
	{
		AddRef();
		return S_OK;
	}
	return(E_NOINTERFACE);
}
STDMETHODIMP_(ULONG) MathClassFactory::AddRef()
{
	return InterlockedIncrement(&m_lRef);
}
STDMETHODIMP_(ULONG) MathClassFactory::Release()
{
	if (InterlockedDecrement(&m_lRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_lRef;
}
STDMETHODIMP MathClassFactory::CreateInstance
(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj)
{
	CMath* pMath;
	HRESULT hr;
	*ppvObj = 0;
	pMath = new CMath;
	if (pMath == 0)
		return(E_OUTOFMEMORY);
	hr = pMath->QueryInterface(riid, ppvObj);
	if (FAILED(hr))
		delete pMath;
	return hr;
}
STDMETHODIMP MathClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
		InterlockedIncrement(&g_lLocks);
	else
		InterlockedDecrement(&g_lLocks);
	return S_OK;
}
