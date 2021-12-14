#pragma once
#include <Windows.h> //для наших макро DEFINE_GUID, STDMETHOD...
//
// imath.h
//

////Идентификатор класса компонента
//// {0BAED82A-2EB8-4FF8-912F-128A4E904BB5}
//DEFINE_GUID(CLSID_MATH ,
//	0xbaed82a, 0x2eb8, 0x4ff8, 0x91, 0x2f, 0x12, 0x8a, 0x4e, 0x90, 0x4b, 0xb5);

////Идентификатор интерфейса
//// {56D7AF4F-C48A-4190-8880-19962537A9AE}
//DEFINE_GUID(IID_IMATH ,
//	0x56d7af4f, 0xc48a, 0x4190, 0x88, 0x80, 0x19, 0x96, 0x25, 0x37, 0xa9, 0xae);


// {39A4982E-76E5-4F8A-A759-953E69C86E18}
DEFINE_GUID(CLSID_MATH,
	0x39a4982e, 0x76e5, 0x4f8a, 0xa7, 0x59, 0x95, 0x3e, 0x69, 0xc8, 0x6e, 0x18);

// {8650651B-DEA8-4A8C-B5CA-9B1D85A64372}
DEFINE_GUID(IID_IMATH,
	0x8650651b, 0xdea8, 0x4a8c, 0xb5, 0xca, 0x9b, 0x1d, 0x85, 0xa6, 0x43, 0x72);




class IMath : public IUnknown
{
public:
 STDMETHOD( Add( long, long, long* )) PURE;
 STDMETHOD( Subtract( long, long, long* )) PURE;
 STDMETHOD( Multiply( long, long, long* )) PURE;
 STDMETHOD( Divide( long, long, long* )) PURE;
};