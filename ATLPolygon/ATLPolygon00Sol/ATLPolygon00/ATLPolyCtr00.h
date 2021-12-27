// ATLPolyCtr00.h: объявление CATLPolyCtr00
#pragma once
#include "resource.h"       // основные символы
#include <atlctl.h>
#include "ATLPolygon00_i.h"
#include "_IATLPolyCtr00Events_CP.h"
#include <math.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Однопотоковые COM-объекты не поддерживаются должным образом платформой Windows CE, например платформами Windows Mobile, в которых не предусмотрена полная поддержка DCOM. Определите _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, чтобы принудить ATL поддерживать создание однопотоковых COM-объектов и разрешить использование его реализаций однопотоковых COM-объектов. Для потоковой модели в вашем rgs-файле задано значение 'Free', поскольку это единственная потоковая модель, поддерживаемая не-DCOM платформами Windows CE."
#endif

using namespace ATL;



// CATLPolyCtr00
class ATL_NO_VTABLE CATLPolyCtr00 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CATLPolyCtr00, IATLPolyCtr00>,
	public IPersistStreamInitImpl<CATLPolyCtr00>,
	public IOleControlImpl<CATLPolyCtr00>,
	public IOleObjectImpl<CATLPolyCtr00>,
	public IOleInPlaceActiveObjectImpl<CATLPolyCtr00>,
	public IViewObjectExImpl<CATLPolyCtr00>,
	public IOleInPlaceObjectWindowlessImpl<CATLPolyCtr00>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CATLPolyCtr00>,
	public CProxy_IATLPolyCtr00Events<CATLPolyCtr00>,
	public IObjectWithSiteImpl<CATLPolyCtr00>,
	public IServiceProviderImpl<CATLPolyCtr00>,
	public IPersistStorageImpl<CATLPolyCtr00>,
	public ISpecifyPropertyPagesImpl<CATLPolyCtr00>,
	public IQuickActivateImpl<CATLPolyCtr00>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CATLPolyCtr00>,
#endif
	public IProvideClassInfo2Impl<&CLSID_ATLPolyCtr00, &__uuidof(_IATLPolyCtr00Events), &LIBID_ATLPolygon00Lib>,
	public IPropertyNotifySinkCP<CATLPolyCtr00>,
	public IObjectSafetyImpl<CATLPolyCtr00, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public CComCoClass<CATLPolyCtr00, &CLSID_ATLPolyCtr00>,
	public CComControl<CATLPolyCtr00>
{
public:


	CATLPolyCtr00()
	{
		m_nSides = 8;
		m_clrFillColor = RGB(153, 153, 255);
		m_clrBorderColor = RGB(0, 0, 102);
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_ATLPOLYCTR00)


BEGIN_COM_MAP(CATLPolyCtr00)
	COM_INTERFACE_ENTRY(IATLPolyCtr00)
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

BEGIN_PROP_MAP(CATLPolyCtr00)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
#ifndef _WIN32_WCE
	PROP_ENTRY_TYPE("BorderColor", DISPID_BORDERCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
	PROP_ENTRY_TYPE("BorderWidth", DISPID_BORDERWIDTH, CLSID_NULL, VT_I4)
#ifndef _WIN32_WCE
	PROP_ENTRY_TYPE("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
	// Записи примеров
	// PROP_ENTRY_TYPE("Имя свойства", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CATLPolyCtr00)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(__uuidof(_IATLPolyCtr00Events))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CATLPolyCtr00)
	CHAIN_MSG_MAP(CComControl<CATLPolyCtr00>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)

END_MSG_MAP()
// Прототипы обработчика:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* const arr[] =
		{
			&IID_IATLPolyCtr00,
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

// IATLPolyCtr00
	POINT m_arrPoint[10];
	void CalcPoints(const RECT& rc);


public:
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
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

		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);



		/*--------------------------------------------------------------------*/
		HDC hdc = di.hdcDraw;
		COLORREF colFore;
		HBRUSH hOldBrush, hBrush;
		HPEN hOldPen, hPen;
		// Translate m_colFore into a COLORREF type
		OleTranslateColor(m_clrFillColor, NULL, &colFore);
		// Create and select the colors to draw the circle
		hPen = (HPEN)GetStockObject(BLACK_PEN);

		hOldPen = (HPEN)SelectObject(hdc, hPen);
		hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
		// Create and select the brush that will be used to fill the polygon
		hBrush = CreateSolidBrush(colFore);
		SelectObject(hdc, hBrush);
		CalcPoints(rc);
		Polygon(hdc, &m_arrPoint[0], m_nSides);
		// Select back the old pen and brush and delete the brush we created
		SelectObject(hdc, hOldPen);
		SelectObject(hdc, hOldBrush);
		DeleteObject(hBrush);
		/*--------------------------------------------------------------------*/

		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		//LPCTSTR pszText = _T("ATLPolyCtr00");
		LPCTSTR pszText = _T("DKotsuba - 00321 - 27.12.22");
#ifndef _WIN32_WCE
		TextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			pszText,
			lstrlen(pszText));
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

	OLE_COLOR m_clrBorderColor;
	void OnBorderColorChanged()
	{
		ATLTRACE(_T("OnBorderColorChanged\n"));
	}
	LONG m_nBorderWidth;
	void OnBorderWidthChanged()
	{
		ATLTRACE(_T("OnBorderWidthChanged\n"));
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
	SHORT m_nSides;
	STDMETHOD(get_Sides)(SHORT* pVal);
	STDMETHOD(put_Sides)(SHORT newVal);
	
};

OBJECT_ENTRY_AUTO(__uuidof(ATLPolyCtr00), CATLPolyCtr00)
