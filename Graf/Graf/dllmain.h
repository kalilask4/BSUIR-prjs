// dllmain.h: объявление класса модуля.

class CGrafModule : public ATL::CAtlDllModuleT< CGrafModule >
{
public :
	DECLARE_LIBID(LIBID_GrafLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_GRAF, "{58fe36b6-a0c7-447e-b1bb-f780c5775a7f}")
};

extern class CGrafModule _AtlModule;
