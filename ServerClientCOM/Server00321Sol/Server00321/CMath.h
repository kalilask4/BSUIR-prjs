#pragma once
//
// сmath.h
//
#include "IMath.h"
extern long g_lObjs; //счетчик компонентов, созданных на базе сервера; память для него будет выделена в другом файле
extern long g_lLocks; //счетчик блокировок
class CMath : public IMath, IVer, IFN_14
{
protected:
	// Reference count
	long m_lRef;
public:
	CMath();
	~CMath();
public:
	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());
	
	// IMath
	STDMETHOD(Add(long, long, long*));
	STDMETHOD(Subtract(long, long, long*));
	STDMETHOD(Multiply(long, long, long*));
	STDMETHOD(Divide(long, long, long*));
	STDMETHOD(FunTest(int, int, float*));
	
	//IVer
	STDMETHOD(GetAuthor(wchar_t** autor));

	//IFN_14
	STDMETHOD(Fun0(int, int, float*));
	double Fun141(int, int);
	int Fun142(int, int, int);
	STDMETHOD(Fun143(double, double*));
	
};
class MathClassFactory : public IClassFactory
{
protected:
	long m_lRef;
public:
	MathClassFactory();
	~MathClassFactory();
	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());
	// IClassFactory
	STDMETHOD(CreateInstance(LPUNKNOWN, REFIID, void**));
	STDMETHOD(LockServer(BOOL));
};