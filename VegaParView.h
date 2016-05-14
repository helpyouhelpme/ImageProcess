#if !defined(AFX_VEGAPARVIEW_H__470956C5_3A1F_4062_94FF_E90C19AE25B8__INCLUDED_)
#define AFX_VEGAPARVIEW_H__470956C5_3A1F_4062_94FF_E90C19AE25B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VegaParView.h : header file
//
#include "VegaRwSimDoc.h"

#define WM_THREAD_UPDATE WM_USER+100

/////////////////////////////////////////////////////////////////////////////
// CVegaParView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CVegaParView : public CFormView
{
protected:
	CVegaParView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CVegaParView)

	CVegaRwSimDoc *GetDocument();

// Form Data
public:
	//{{AFX_DATA(CVegaParView)
	enum { IDD = IDD_VegaPar };
	int		m_ScanMin;
	int		m_ScanMax;
	int		m_ScanMaxGap;
	int		m_ScanMinGap;
	int		m_RangeMin;
	int		m_RangeMax;
	int		m_ObsX;
	int		m_ObsY;
	int		m_ObsZ;
	int		m_ObsH;
	int		m_ObsP;
	int		m_ObsR;
	//}}AFX_DATA

// Attributes
public:
	BOOL  m_isRunning;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVegaParView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CVegaParView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CVegaParView)
	//}}AFX_MSG
	afx_msg void OnUpdateView(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyVegaRwView.cpp
inline CVegaRwSimDoc* CVegaParView::GetDocument()
   { return (CVegaRwSimDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VEGAPARVIEW_H__470956C5_3A1F_4062_94FF_E90C19AE25B8__INCLUDED_)
