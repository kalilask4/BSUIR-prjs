// GrafCtl.h: объявление CGrafCtl
#pragma once
#include "resource.h"       // основные символы
#include <atlctl.h>
#include "Graf_i.h"
#include "_IGrafCtlEvents_CP.h"
#include <math.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Однопотоковые COM-объекты не поддерживаются должным образом платформой Windows CE, например платформами Windows Mobile, в которых не предусмотрена полная поддержка DCOM. Определите _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, чтобы принудить ATL поддерживать создание однопотоковых COM-объектов и разрешить использование его реализаций однопотоковых COM-объектов. Для потоковой модели в вашем rgs-файле задано значение 'Free', поскольку это единственная потоковая модель, поддерживаемая не-DCOM платформами Windows CE."
#endif

using namespace ATL;



// CGrafCtl
class ATL_NO_VTABLE CGrafCtl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CGrafCtl, IGrafCtl>,
	public IPersistStreamInitImpl<CGrafCtl>,
	public IOleControlImpl<CGrafCtl>,
	public IOleObjectImpl<CGrafCtl>,
	public IOleInPlaceActiveObjectImpl<CGrafCtl>,
	public IViewObjectExImpl<CGrafCtl>,
	public IOleInPlaceObjectWindowlessImpl<CGrafCtl>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CGrafCtl>,
	public CProxy_IGrafCtlEvents<CGrafCtl>,
	public IObjectWithSiteImpl<CGrafCtl>,
	public IServiceProviderImpl<CGrafCtl>,
	public IPersistStorageImpl<CGrafCtl>,
	public ISpecifyPropertyPagesImpl<CGrafCtl>,
	public IQuickActivateImpl<CGrafCtl>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CGrafCtl>,
#endif
	public IProvideClassInfo2Impl<&CLSID_GrafCtl, &__uuidof(_IGrafCtlEvents), &LIBID_GrafLib>,
	public IPropertyNotifySinkCP<CGrafCtl>,
	public IObjectSafetyImpl<CGrafCtl, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public CComCoClass<CGrafCtl, &CLSID_GrafCtl>,
	public CComControl<CGrafCtl>
{
public:


	CGrafCtl()
	{
		 m_nStartX = -1;
		 m_nEndX = 4;
		 m_nStartY = -1;
		 m_nEndY = 4;
		 m_clrFillColor = RGB(229,204,255);
		 m_clrBackColor = RGB(51, 0, 102);
		
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_GRAFCTL)


BEGIN_COM_MAP(CGrafCtl)
	COM_INTERFACE_ENTRY(IGrafCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IServiceProvider)
	COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
END_COM_MAP()

BEGIN_PROP_MAP(CGrafCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
#ifndef _WIN32_WCE
	PROP_ENTRY_TYPE("BackColor", DISPID_BACKCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
	PROP_ENTRY_TYPE("BorderStyle", DISPID_BORDERSTYLE, CLSID_NULL, VT_I4)
#ifndef _WIN32_WCE
	PROP_ENTRY_TYPE("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
	// Записи примеров
	// PROP_ENTRY_TYPE("Имя свойства", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CGrafCtl)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(__uuidof(_IGrafCtlEvents))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CGrafCtl)
	CHAIN_MSG_MAP(CComControl<CGrafCtl>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown);
    MESSAGE_HANDLER(WM_RBUTTONDOWN, OnRButtonDown);
END_MSG_MAP()
// Прототипы обработчика:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* const arr[] =
		{
			&IID_IGrafCtl,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IGrafCtl
	static const int nPoints = 100;
	POINT m_arrPoint[nPoints];
	void CalcPoints(const RECT& rc);
	bool ClicOnOff;
	bool Error = True;
public:
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		COLORREF    colFore;
		HBRUSH      hOldBrush, hBrush;
		HPEN        hOldPen, hPen;

		// Translate m_colFore into a COLORREF type
		OleTranslateColor(m_clrFillColor, NULL, &colFore);

		hBrush = CreateSolidBrush(colFore);
		SelectObject(di.hdcDraw, hBrush);
		RECT& rc = *(RECT*)di.prcBounds;
		// Ограничивает область вырезания прямоугольником, указанным в di.prcBounds
		HRGN hRgnOld = nullptr;
		if (GetClipRgn(di.hdcDraw, hRgnOld) != 1)
			hRgnOld = nullptr;
		bool bSelectOldRgn = false;

		HRGN hRgnNew = CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);

		if (hRgnNew != nullptr)
		{
			bSelectOldRgn = (SelectClipRgn(di.hdcDraw, hRgnNew) != ERROR);
		}

		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right * 2, rc.bottom);
		// ///////////////////////////////////////////////////////////////
	    HDC hdc = di.hdcDraw;

		// Create and select the colors to draw the circle
		hPen = (HPEN)GetStockObject(BLACK_PEN);
		hOldPen = (HPEN)SelectObject(hdc, hPen);
		hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

		// Create and select the brush that will be used to fill the graf
		//hBrush = CreateSolidBrush(colFore);
		//SelectObject(hdc, hBrush);

		CalcPoints(rc);

		MoveToEx(hdc, (rc.right - rc.left) / 4, rc.top, NULL);
		LineTo(hdc, (rc.right - rc.left) / 4, rc.bottom);

		MoveToEx(hdc, rc.left, (rc.bottom - rc.top) / 2, NULL);
		LineTo(hdc, rc.right, (rc.bottom - rc.top) / 2);

		hBrush = CreateSolidBrush(m_clrFillColor);

		SelectObject(hdc, hBrush);

		hPen = CreatePen(PS_SOLID, 2, m_clrBackColor);

		SelectObject(hdc, hPen);

		if (ClicOnOff == true)
		{
			Polyline(hdc, &m_arrPoint[0], nPoints);
		}
		

		// Select back the old pen and brush and delete the brush we created
		SelectObject(hdc, hOldPen);
		//SelectObject(hdc, hOldBrush);
		//DeleteObject(hBrush);
		DeleteObject(hPen);

		// ///////////////////////////////////////////////////////////////

		//TextOut()
		/*-------------------------------------------*/
		SetTextAlign(di.hdcDraw, TA_CENTER | TA_BASELINE);
		LPCTSTR pszText = _T("mdkotsuba_00321_SR4");
//#ifndef _WIN32_WCE
		TextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 1.2,
			pszText,
			lstrlen(pszText));

/*--------------------------------------------------------------------*/

#ifndef _WIN32_WCE
		
#else
		ExtTextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			ETO_OPAQUE,
			nullptr,
			pszText,
			ATL::lstrlen(pszText),
			nullptr);
#endif

		if (bSelectOldRgn)
			SelectClipRgn(di.hdcDraw, hRgnOld);
		DeleteObject(hRgnNew);

		return S_OK;
	}

	OLE_COLOR m_clrBackColor;
	void OnBackColorChanged()
	{
		ATLTRACE(_T("OnBackColorChanged\n"));
	}
	LONG m_nBorderStyle;
	void OnBorderStyleChanged()
	{
		ATLTRACE(_T("OnBorderStyleChanged\n"));
	}
	OLE_COLOR m_clrFillColor;
	void OnFillColorChanged()
	{
		ATLTRACE(_T("OnFillColorChanged\n"));
	}
	STDMETHOD(_InternalQueryService)(REFGUID /*guidService*/, REFIID /*riid*/, void** /*ppvObject*/)
	{
		return E_NOTIMPL;
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
	INT16 m_nStartX;
	INT16 m_nEndX;
	INT16 m_nStartY;
	INT16 m_nEndY;
	STDMETHOD(get_StartX)(LONG* pVal);
	STDMETHOD(put_StartX)(LONG newVal);
	STDMETHOD(get_EndX)(LONG* pVal);
	STDMETHOD(put_EndX)(LONG newVal);
	STDMETHOD(get_StartY)(LONG* pVal);
	STDMETHOD(put_StartY)(LONG newVal);
	STDMETHOD(get_EndY)(LONG* pVal);
	STDMETHOD(put_EndY)(LONG newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(GrafCtl), CGrafCtl)
