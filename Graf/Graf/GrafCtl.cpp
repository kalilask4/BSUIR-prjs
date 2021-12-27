// GrafCtl.cpp: реализация CGrafCtl
#include "pch.h"
#include "GrafCtl.h"


// CGrafCtl


STDMETHODIMP CGrafCtl::get_StartX(LONG* pVal)
{
	// TODO: Добавьте сюда код реализации
	*pVal = m_nStartX;
	return S_OK;
}


STDMETHODIMP CGrafCtl::put_StartX(LONG newVal)
{
	// TODO: Добавьте сюда код реализации
	m_nStartX = newVal;
	FireViewChange();
	return S_OK;
}

void CGrafCtl::CalcPoints(const RECT& rc)
{

    double x;
    x = m_nStartX;
    double scaleX = (rc.right - rc.left) / 20.;// (1 * (_xEnd - _xStart));
    double scaleY = (rc.bottom - rc.top) / 20.;// / (_yEnd - _yStart);
    double offsetX = 5 * scaleX;
    double offsetY = (rc.bottom - rc.top) / 2.;

    for (int i = 0; i < nPoints; i++)
    {
       m_arrPoint[i].x = (long)(((x + 2) * scaleX) + offsetX);
       m_arrPoint[i].y = -(long)((x - pow(sin(x), 2)) * scaleY - offsetY);

        x += ((double)(m_nEndX - m_nStartX)) / (nPoints - 1);
    }


}


STDMETHODIMP CGrafCtl::get_EndX(LONG* pVal)
{
    // TODO: Добавьте сюда код реализации
    *pVal = m_nEndX;
    return S_OK;
}


STDMETHODIMP CGrafCtl::put_EndX(LONG newVal)
{
    // TODO: Добавьте сюда код реализации
    m_nEndX = newVal;
    FireViewChange();
    return S_OK;
}


STDMETHODIMP CGrafCtl::get_StartY(LONG* pVal)
{
    // TODO: Добавьте сюда код реализации
    *pVal = m_nStartY;
    return S_OK;
}


STDMETHODIMP CGrafCtl::put_StartY(LONG newVal)
{
    // TODO: Добавьте сюда код реализации
    m_nStartY = newVal;
    FireViewChange();
    return S_OK;
}


STDMETHODIMP CGrafCtl::get_EndY(LONG* pVal)
{
    // TODO: Добавьте сюда код реализации
    *pVal = m_nEndY;
    return S_OK;
}


STDMETHODIMP CGrafCtl::put_EndY(LONG newVal)
{
    // TODO: Добавьте сюда код реализации
    m_nEndY = newVal;
    FireViewChange();
    return S_OK;
}

LRESULT CGrafCtl::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    
    if (Error == true)
    {
        ClicOnOff = true;
        FireViewChange();
        Error = False;
        return 0;
    }
    else
    {
        Error = true;
        FireViewChange();
        return 0;
    }
    
}

LRESULT CGrafCtl::OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    if (Error == False)
    {
        ClicOnOff = False;
        FireViewChange();
        Error = true;
        return 0;
    }
    else
    {
        Error = False;
        FireViewChange();
        return 0;
    }
    return 0;
}