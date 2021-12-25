// dllmain.h: объявление класса модуля.

class CCOMServerModule : public ATL::CAtlDllModuleT< CCOMServerModule >
{
public :
	DECLARE_LIBID(LIBID_COMServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COMSERVER, "{84314509-1c0c-4123-a5c7-a8ad7b1b50ec}")
};

extern class CCOMServerModule _AtlModule;
