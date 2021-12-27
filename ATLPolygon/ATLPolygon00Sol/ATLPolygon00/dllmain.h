// dllmain.h: объявление класса модуля.

class CATLPolygon00Module : public ATL::CAtlDllModuleT< CATLPolygon00Module >
{
public :
	DECLARE_LIBID(LIBID_ATLPolygon00Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLPOLYGON00, "{5d3b508f-3ce0-4522-a4c3-3bad4b7ce3c6}")
};

extern class CATLPolygon00Module _AtlModule;
