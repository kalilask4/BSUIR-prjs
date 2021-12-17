//
// Client.cpp
//
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#include <initguid.h>
#include "..\Server00321\IMath.h"

int main(int argc, char* argv[])
{
    printf("Initializing COM \n");
    if (FAILED(CoInitialize(NULL)))
    {
        printf("Unable to initialize COM \n"); return -1;
    }
    const char* szProgID = "Math.Component.1"; // - Program ID
    WCHAR szWideProgID[128];
    CLSID clsid;
    long lLen = MultiByteToWideChar(CP_ACP, 0, szProgID,
        strlen(szProgID), szWideProgID, sizeof(szWideProgID));
    szWideProgID[lLen] = '\0';
    HRESULT hr = ::CLSIDFromProgID(szWideProgID, &clsid);
    if (FAILED(hr))
    {
        printf("Unable to get CLSID from ProgID. HR = %X \n", hr); return -1;
    }

    IClassFactory* pCF;
    // Получить фабрику класса для CMath
    hr = CoGetClassObject(clsid, CLSCTX_INPROC, NULL,
        IID_IClassFactory, (void**)&pCF);
    if (FAILED(hr))
    {
        printf("Failed to GetClassObject server instance. HR = %X \n", hr); return -1;
    }

    // с помощью фабрики класса создать экземпляр 
      // компонента и получить интерфейс IUnknown.

    IUnknown* pUnk; hr = pCF->CreateInstance(NULL, IID_IUnknown, (void**)&pUnk);

    // Release the class factory pCF->Release();
    if (FAILED(hr))
    {
        printf("Failed to create server instance. HR =%X \n", hr); return -1;
    }
    printf("Instance created \n");
    IMath* pMath = NULL;
    hr = pUnk->QueryInterface(IID_IMATH, (LPVOID*)&pMath);
    if (FAILED(hr))
    {
        printf("QueryInterface() for IMath failed \n"); return -1;
    }
    pUnk->Release();

    long result;
    pMath->Multiply(20, 7, &result);
    printf("20 * 7 is %d \n", result);

    pMath->Subtract(200, 123, &result);
    printf("200 - 123 is %d \n", result);
    printf("Releasing instance \n");

    float floatResult0 = 0;
    pMath->FunTest(5, 8, &floatResult0);
    printf("5 * 8 * 10 = %lf \n", floatResult0);

    IVer* pVer = NULL;
    hr = pMath->QueryInterface(IID_IVer, (LPVOID*)&pVer);

    pMath->Release();

    wchar_t str_author[200];
    wchar_t* pstr;
    hr = pVer->GetAuthor(&pstr);
    lstrcpyW(str_author, pstr);
    CoTaskMemFree(pstr);
    pVer->Release();
    wprintf(L"%s", str_author);

       
    
    printf("\nShuting down COM\n");
    CoUninitialize();
    return 0;
}