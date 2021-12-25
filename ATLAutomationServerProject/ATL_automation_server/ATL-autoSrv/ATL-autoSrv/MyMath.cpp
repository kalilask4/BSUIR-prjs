﻿// MyMath.cpp: реализация CMyMath

#include "pch.h"
#include "MyMath.h"


// CMyMath

STDMETHODIMP CMyMath::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IMyMath
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CMyMath::Add(LONG x, LONG y, LONG* z)
{
	*z = x + y;

	return S_OK;
}

STDMETHODIMP CMyMath::Sub(LONG x, LONG y, LONG* z)
{
	*z = x - y;

	return S_OK;
} 

STDMETHODIMP CMyMath::Mul(LONG x, LONG y, LONG* z)
{
	*z = x * y;

	return S_OK;
}

STDMETHODIMP CMyMath::Div(LONG x, LONG y, LONG* z)
{
	*z = x / y;

	return S_OK;
}