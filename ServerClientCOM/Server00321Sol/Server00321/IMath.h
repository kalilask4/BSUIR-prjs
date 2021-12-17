#pragma once
#include <Windows.h> //для наших макро DEFINE_GUID, STDMETHOD...
//
// imath.h
//

//Идентификатор класса компонента
// {0BAED82A-2EB8-4FF8-912F-128A4E904BB5}
DEFINE_GUID(CLSID_MATH ,
	0xbaed82a, 0x2eb8, 0x4ff8, 0x91, 0x2f, 0x12, 0x8a, 0x4e, 0x90, 0x4b, 0xb5);

//Идентификатор интерфейса
// {56D7AF4F-C48A-4190-8880-19962537A9AE}
DEFINE_GUID(IID_IMATH ,
	0x56d7af4f, 0xc48a, 0x4190, 0x88, 0x80, 0x19, 0x96, 0x25, 0x37, 0xa9, 0xae);

// {2F85142B-F184-4106-B73A-767845260D1F}
DEFINE_GUID(IID_IVer ,
	0x2f85142b, 0xf184, 0x4106, 0xb7, 0x3a, 0x76, 0x78, 0x45, 0x26, 0xd, 0x1f);




class IMath : public IUnknown
{
public:
 STDMETHOD( Add( long, long, long* )) PURE;
 STDMETHOD( Subtract( long, long, long* )) PURE;
 STDMETHOD( Multiply( long, long, long* )) PURE;
 STDMETHOD( Divide( long, long, long* )) PURE;
 STDMETHOD(FunTest(int, int, float*)) PURE;
};


class IVer : public IUnknown {
public:
	STDMETHOD(GetAuthor(wchar_t**autor)) PURE;
};



