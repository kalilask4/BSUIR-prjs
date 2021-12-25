// COMDemo.cpp: реализация CCOMDemo

#include "pch.h"
#include "COMDemo.h"
#include <string>
#include <iostream>


// CCOMDemo



STDMETHODIMP CCOMDemo::Greeting(BSTR name, BSTR* message)
{
    CComBSTR tmp("Welcome, ");
    tmp.Append(name);
    *message = tmp;
    return S_OK;
}


STDMETHODIMP CCOMDemo::Add(LONG x, LONG y, LONG* z)
{
    *z = x + y;
    return S_OK;
}

STDMETHODIMP CCOMDemo::Sub(LONG x, LONG y, LONG* z)
{
    *z = x - y;
    return S_OK;
}

STDMETHODIMP CCOMDemo::Mul(LONG x, LONG y, LONG* z)
{
    *z = x * y;

    return S_OK;
}

STDMETHODIMP CCOMDemo::Div(LONG x, LONG y, LONG* z)
{

    if (y == 0) {
       
       throw EXCEPTION_FLT_DIVIDE_BY_ZERO; 
    }

    *z = 1;// x / y;
     
    
return S_OK;
    
}


//STDMETHODIMP CCOMDemo::CreateError()
//{
//    CComBSTR someText(L"CreateError Test");
//    ICreateErrorInfo* pCreateError;
//    IErrorInfo* pError;
//    HRESULT result = CreateErrorInfo(&pCreateError);
//    /*if (FAILED(result))
//        return E_NOTIMPL;
//    result = pCreateError->QueryInterface(&pError);*/
//    if (FAILED(result))
//        return E_NOTIMPL;
//    result = pCreateError->SetDescription(someText);
//    pError->Release();
//    pCreateError->Release();
//    return E_FAIL;
//}