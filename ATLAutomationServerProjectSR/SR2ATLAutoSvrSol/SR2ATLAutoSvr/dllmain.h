// dllmain.h: объявление класса модуля.

class CSR2ATLAutoSvrModule : public ATL::CAtlDllModuleT< CSR2ATLAutoSvrModule >
{
public :
	DECLARE_LIBID(LIBID_SR2ATLAutoSvrLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SR2ATLAUTOSVR, "{95263321-2bc9-4785-aa57-472da3ebc9d5}")
};

extern class CSR2ATLAutoSvrModule _AtlModule;
