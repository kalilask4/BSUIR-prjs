// SR2MyMath.cpp: реализация CSR2MyMath

#include "pch.h"
#include "SR2MyMath.h"


// CSR2MyMath



STDMETHODIMP CSR2MyMath::fun141(LONG x, LONG y, DOUBLE* output)
{
	*output = ((double)x + (double)y) / 2.0;
	
    return S_OK;
}



STDMETHODIMP CSR2MyMath::fun142(LONG x, LONG y, LONG z, LONG* output)
{

	int r;
	if (x > y)
		r = x;
	else
		r = y;
	if (y > r)
		r = z;
	*output = r;

	return S_OK;
}


STDMETHODIMP CSR2MyMath::fun143(DOUBLE x, DOUBLE* output)
{
	//kg to pound
	*output = x * 2.2046226;

	return S_OK;
}