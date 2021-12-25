//CalClientCPlus.cpp
#include <windows.h>
#include <stdio.h>

int main()
{
	printf("SR2 00321 KotsubaD \n");
	DWORD clsctx;
	clsctx = CLSCTX_INPROC_SERVER;

	HRESULT hr = OleInitialize(NULL);
	if (FAILED(hr))
	{
		printf("Failed to initialize.hr=%X \n", hr);
		return 1;
	}

	//Get the CLSID for the application
	wchar_t progid[] = L"MSCAL.Календарь.7";
	CLSID clsid;
	hr = ::CLSIDFromProgID(progid, &clsid);
	if (FAILED(hr))
	{
		printf("Failed to get CLSID.hr=%X \n", hr);
		return 1;
	}

	// Create the component
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
	printf("CoCreateInstance succeeded. \n\n");



	//Getting the ID for the property Month
	printf("Get DispID for property \"Month\".\n\n");
	DISPID dispidMonth;
	OLECHAR* name1 = (OLECHAR*)L"Month";
	hr = pIDispatch->GetIDsOfNames(IID_NULL,
		&name1,
		1,
		GetUserDefaultLCID(),
		&dispidMonth);
	if (FAILED(hr))
	{
		printf("Query GetIDsOfNames failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}

	// get month

	VARIANT result1;
	VariantInit(&result1);
	result1.vt = VT_I2;

	DISPPARAMS dispparams1 = { NULL, NULL, 0, 0 };

	printf("Invoke the propertyGet \"Month\". \n");
	hr = pIDispatch->Invoke(dispidMonth,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_PROPERTYGET,
		&dispparams1,
		&result1,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}
	// Display the returned result.
	if (result1.vt == VT_I2)
	{
		printf("Result returned from component. Current month: %d\n\n", result1.iVal);
	}



	// put month

	VARIANTARG varg2[1];
	::VariantInit(&varg2[0]);
	varg2[0].vt = VT_I2;
	varg2[0].intVal = 6;

	DISPID dispidNamed2 = DISPID_PROPERTYPUT;
	DISPPARAMS dispparams2;
	dispparams2.rgvarg = varg2;
	dispparams2.cArgs = 1;
	dispparams2.cNamedArgs = 1;
	dispparams2.rgdispidNamedArgs = &dispidNamed2;

	printf("Invoke the propertyPut \"Month\". \n");
	hr = pIDispatch->Invoke(dispidMonth,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_PROPERTYPUT,
		&dispparams2,
		NULL,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}
	else // Display log if Invoke() succeeded.
	{
		printf("Month was changed to: %d\n\n", varg2[0].intVal);
	}


	printf("Check result. Invoke the propertyGet \"Month\". \n");
	hr = pIDispatch->Invoke(dispidMonth,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_PROPERTYGET,
		&dispparams1,
		&result1,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}
	// Display the returned result.
	if (result1.vt == VT_I2)
	{
		printf("Result returned from component. Current month after changes: %d\n\n", result1.iVal);
	}


	//Getting the ID for the property Year
	printf("Get DispID for property \"Year\".\n\n");


	DISPID dispidYear;
	OLECHAR* name3 = (OLECHAR*)L"Year";
	hr = pIDispatch->GetIDsOfNames(IID_NULL,
		&name3,
		1,
		GetUserDefaultLCID(),
		&dispidYear);
	if (FAILED(hr))
	{
		printf("Query GetIDsOfNames failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}



	// get Year

	VARIANT result3;
	VariantInit(&result3);
	result3.vt = VT_I2;

	DISPPARAMS dispparams3 = { NULL, NULL, 0, 0 };

	printf("Invoke the propertyGet \"Year\". \n");
	hr = pIDispatch->Invoke(dispidYear,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_PROPERTYGET,
		&dispparams3,
		&result3,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}
	// Display the returned result.
	if (result3.vt == VT_I2)
	{
		printf("Result returned from component. Current Year: %d\n\n", result3.iVal);
	}


	// put Year

	VARIANTARG varg4[1];
	::VariantInit(&varg4[0]);
	varg4[0].vt = VT_I2;
	varg4[0].intVal = 1997;

	DISPID dispidNamed4 = DISPID_PROPERTYPUT;
	DISPPARAMS dispparams4;
	dispparams4.rgvarg = varg4;
	dispparams4.cArgs = 1;
	dispparams4.cNamedArgs = 1;
	dispparams4.rgdispidNamedArgs = &dispidNamed4;

	printf("Invoke the propertyPut \"Year\". \n");
	hr = pIDispatch->Invoke(dispidYear,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_PROPERTYPUT,
		&dispparams4,
		NULL,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}
	else // Display log if Invoke() succeeded.
	{
		printf("Year was changed to: %d\n\n", varg4[0].intVal);
	}

	printf("Check result. Invoke the propertyGet \"Year\" \n");
	hr = pIDispatch->Invoke(dispidYear,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_PROPERTYGET,
		&dispparams3,
		&result3,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}
	// Display the returned result.
	if (result3.vt == VT_I2)
	{
		printf("Result returned from component. Current Year after changes: %d\n\n", result3.iVal);
	}
}

