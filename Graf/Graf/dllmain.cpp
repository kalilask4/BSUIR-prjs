// dllmain.cpp: реализация DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "Graf_i.h"
#include "dllmain.h"

CGrafModule _AtlModule;

// Точка входа DLL
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved);
}
