//
// server.cpp : Defines the initialization routines for the DLL.
//
#include <windows.h>
#include <initguid.h>
#include "CMath.h"
#include "../REGISTRY.H"

///////////////////////////////////////////////////////////
//
// Global variables
//
static HMODULE g_hModule = NULL;   // DLL module handle

// Friendly name of component
const char g_szFriendlyName[] = "TCP_Lab1 Math Component 00321";

// Version-independent ProgID
const char g_szVerIndProgID[] = "Math.Component";

// ProgID
const char g_szProgID[] = "Math.Component.1";

long g_lObjs = 0;   //счетчик объектов
long g_lLocks = 0;  //счетчик блокировок

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void**
	ppv)
{
	HRESULT hr;
	MathClassFactory* pCF;
	pCF = 0;
	// Make sure the CLSID is for our Expression component
	if (rclsid != CLSID_MATH)
		return(E_FAIL);
	pCF = new MathClassFactory;
	if (pCF == 0)
		return(E_OUTOFMEMORY);
	hr = pCF->QueryInterface(riid, ppv);
	// Check for failure of QueryInterface
	if (FAILED(hr))
	{
		delete pCF;
		pCF = 0;
	}
	return hr;
}
STDAPI DllCanUnloadNow(void)
{
	if (g_lObjs || g_lLocks)
		return(S_FALSE);
	else
		return(S_OK);
}

//
// Server registration
//
STDAPI DllRegisterServer()
{
	return RegisterServer(g_hModule,
		CLSID_MATH,
		g_szFriendlyName,
		g_szVerIndProgID,
		g_szProgID);
}


//
// Server unregistration
//
STDAPI DllUnregisterServer()
{
	return UnregisterServer(CLSID_MATH,
		g_szVerIndProgID,
		g_szProgID);
}