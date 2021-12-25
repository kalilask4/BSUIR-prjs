//TestClientCpp.cpp

#include <iostream>
#include <windows.h>
#include <stdio.h>


int main()
{
	// std::cout << "Hello World!\n";
	DWORD clsctx;
	clsctx = CLSCTX_INPROC_SERVER;

	printf("Kotsuba D Test CPlus Client\n");
	HRESULT hr = OleInitialize(NULL);
	if (FAILED(hr))
	{
		printf("Failed to initialize.hr=%X \n", hr);
		return 1;
	}

	// Get the CLSID for the application.

	wchar_t progid[] = L"Atl-autoSrv.CoMyMath.1";

	CLSID clsid;
	hr = ::CLSIDFromProgID(progid, &clsid);
	if (FAILED(hr))
	{
		printf("Failed to get CLSID.hr=%X \n", hr);
		return 1;
	}

	// Create the component.
	IDispatch* pIDispatch = NULL;
	hr = ::CoCreateInstance(clsid,
		NULL,
		clsctx,
		IID_IDispatch,
		(void**)&pIDispatch);
	if (FAILED(hr))
	{
		printf("Create instance failed.hr=%X \n", hr);
		OleUninitialize();
		return 1;
	}
	printf("CoCreateInstance succeeded.\n");

	// First we need to get the IDs for the function names.
	printf("Get DispID for function \"Add\".\n");

	DISPID dispid;
	OLECHAR* name = (OLECHAR*)L"Add";
	hr = pIDispatch->GetIDsOfNames(IID_NULL,
		&name,
		1,
		GetUserDefaultLCID(),
		&dispid);
	if (FAILED(hr))
	{
		printf("Query GetIDsOfNames failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}

	// Prepare the arguments for Fx.
	VARIANT vargs[2];
	VariantInit(&vargs[1]);
	vargs[1].vt = VT_I4;
	vargs[1].lVal = 4;
	VariantInit(&vargs[0]);
	vargs[0].vt = VT_I4;
	vargs[0].lVal = 5;

	DISPPARAMS dispparams = { vargs, NULL, 2, 0 };

	VARIANT result;
	VariantInit(&result);
	result.vt = VT_I4;

	printf("Invoke the function \"Add\".\n");
	hr = pIDispatch->Invoke(dispid,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_METHOD,
		&dispparams,
		&result,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}

	// Display the returned result.
	if (result.vt == VT_I4)
	{
		printf("String returned from component: %d + %d = %d", vargs[1].lVal, vargs[0].llVal, result.lVal);
	}

	// Release the dispatch interface.
	pIDispatch->Release();

	// Uninitialize the OLE library.
	OleUninitialize();
	return 0;

}

