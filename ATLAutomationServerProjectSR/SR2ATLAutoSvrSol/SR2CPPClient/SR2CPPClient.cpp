//SR2CPPClient

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

	wchar_t progid[] = L"SR2ATLAutoSvr.SR2MyMath.1";

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
	printf("CreateInstance succeeded.\n");


	////////////////////////////////////////////////////////////////

	// First we need to get the IDs for the function names.
	printf("Get DispID for function \"fun141\".\n");

	DISPID dispid141;
	OLECHAR* name141 = (OLECHAR*)L"fun141";
	hr = pIDispatch->GetIDsOfNames(IID_NULL,
		&name141,
		1,
		GetUserDefaultLCID(),
		&dispid141);
	if (FAILED(hr))
	{
		printf("Query GetIDsOfNames failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}


	// Prepare the arguments for Fx fun141.
	VARIANT vargs141[2];
	VariantInit(&vargs141[1]);
	vargs141[1].vt = VT_I4;
	vargs141[1].lVal = 6;
	VariantInit(&vargs141[0]);
	vargs141[0].vt = VT_I4;
	vargs141[0].lVal = 4;

	VARIANT result141;
	VariantInit(&result141);
	result141.vt = VT_I4;

	DISPPARAMS dispparams141 = { vargs141, NULL, 2, 0 };


	printf("Invoke the function \"fun141\".\n");
	hr = pIDispatch->Invoke(dispid141,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_METHOD,
		&dispparams141,
		&result141,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.hr=%X \n", hr);
		pIDispatch->Release();
		return 1;
	}

	// Display the returned result.
		printf("\nString returned from component: (%d + %d)/2 = %0.2f \n", vargs141[1].lVal, vargs141[0].lVal, result141.date);
	
	//////////////////////////////////////////////////////////////////////////////////

		// First we need to get the IDs for the function names.
		printf("Get DispID for function \"fun142\".\n");

		DISPID dispid142;
		OLECHAR* name142 = (OLECHAR*)L"fun142";
		hr = pIDispatch->GetIDsOfNames(IID_NULL,
			&name142,
			1,
			GetUserDefaultLCID(),
			&dispid142);
		if (FAILED(hr))
		{
			printf("Query GetIDsOfNames failed.hr=%X \n", hr);
			pIDispatch->Release();
			return 1;
		}


		// Prepare the arguments for Fx fun142.
		VARIANT vargs142[3];
		VariantInit(&vargs142[1]);
		vargs142[1].vt = VT_I4;
		vargs142[1].lVal = 6;
		VariantInit(&vargs142[0]);
		vargs142[0].vt = VT_I4;
		vargs142[0].lVal = 4;
		VariantInit(&vargs142[2]);
		vargs142[2].vt = VT_I4;
		vargs142[2].lVal = 11;

		VARIANT result142;
		VariantInit(&result142);
		result142.vt = VT_I4;

		DISPPARAMS dispparams142 = { vargs142, NULL, 3, 0 };


		printf("Invoke the function \"fun142\".\n");
		hr = pIDispatch->Invoke(dispid142,
			IID_NULL,
			GetUserDefaultLCID(),
			DISPATCH_METHOD,
			&dispparams142,
			&result142,
			NULL,
			NULL);
		if (FAILED(hr))
		{
			printf("Invoke call failed.hr=%X \n", hr);
			pIDispatch->Release();
			return 1;
		}

		// Display the returned result.
		printf("String returned from component: max (%d, %d, %d) = %d \n", vargs142[1].lVal, vargs142[0].lVal, vargs142[2].lVal, result142.llVal);


		//////////////////////////////////////////////////////////////////////////////////

	// First we need to get the IDs for the function names.
		printf("Get DispID for function \"fun143\".\n");

		DISPID dispid143;
		OLECHAR* name143 = (OLECHAR*)L"fun143";
		hr = pIDispatch->GetIDsOfNames(IID_NULL,
			&name143,
			1,
			GetUserDefaultLCID(),
			&dispid143);
		if (FAILED(hr))
		{
			printf("Query GetIDsOfNames failed.hr=%X \n", hr);
			pIDispatch->Release();
			return 1;
		}


		// Prepare the arguments for Fx fun142.
		VARIANT vargs143[3];
		/*VariantInit(&vargs143[1]);
		vargs143[1].vt = VT_I4;
		vargs143[1].lVal = 6;*/
		VariantInit(&vargs143[0]);
		vargs143[0].vt = VT_I4;
		vargs143[0].lVal = 6;
		/*VariantInit(&vargs143[2]);
		vargs143[2].vt = VT_I4;
		vargs143[2].lVal = 11;*/

		VARIANT result143;
		VariantInit(&result143);
		result143.vt = VT_I4;

		DISPPARAMS dispparams143 = { vargs143, NULL, 1, 0 };


		printf("Invoke the function \"fun143\".\n");
		hr = pIDispatch->Invoke(dispid143,
			IID_NULL,
			GetUserDefaultLCID(),
			DISPATCH_METHOD,
			&dispparams143,
			&result143,
			NULL,
			NULL);
		if (FAILED(hr))
		{
			printf("Invoke call failed.hr=%X \n", hr);
			pIDispatch->Release();
			return 1;
		}

		// Display the returned result. 
		printf("String returned from component: %d to pound = %0.2f \n", vargs143[0].lVal, result143.dblVal);



	// Release the dispatch interface.
	pIDispatch->Release();

	// Uninitialize the OLE library.
	OleUninitialize();
	return 0;

}

