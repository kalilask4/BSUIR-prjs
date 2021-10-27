// dllmain.h: объявление класса модуля.

class CATLautoSrvModule : public ATL::CAtlDllModuleT< CATLautoSrvModule >
{
public :
	DECLARE_LIBID(LIBID_ATLautoSrvLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLAUTOSRV, "{6d2ec9b2-2f7a-4358-8fb4-d333b8edd6fa}")
};

extern class CATLautoSrvModule _AtlModule;
