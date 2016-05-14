// VegaParView.cpp : implementation file
//

#include "stdafx.h"
#include "vegarwsim.h"
#include "VegaParView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVegaParView

IMPLEMENT_DYNCREATE(CVegaParView, CFormView)

CVegaParView::CVegaParView()
	: CFormView(CVegaParView::IDD)
{
	//{{AFX_DATA_INIT(CVegaParView)
	m_ScanMin = 0;
	m_ScanMax = 0;
	m_ScanMaxGap = 0;
	m_ScanMinGap = 0;
	m_RangeMin = 0;
	m_RangeMax = 0;
	m_ObsX = 0;
	m_ObsY = 0;
	m_ObsZ = 0;
	m_ObsH = 0;
	m_ObsP = 0;
	m_ObsR = 0;
	//}}AFX_DATA_INIT
}

CVegaParView::~CVegaParView()
{
}

void CVegaParView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVegaParView)
	DDX_Text(pDX, IDC_RadarScanMin, m_ScanMin);
	DDX_Text(pDX, IDC_RadarScanMax, m_ScanMax);
	DDX_Text(pDX, IDC_RadarScanMaxGap, m_ScanMaxGap);
	DDV_MinMaxInt(pDX, m_ScanMaxGap, 0, 80);
	DDX_Text(pDX, IDC_RadarScanMinGap, m_ScanMinGap);
	DDV_MinMaxInt(pDX, m_ScanMinGap, -80, 0);
	DDX_Text(pDX, IDC_RadarRangeMin, m_RangeMin);
	DDX_Text(pDX, IDC_RadarRangeMax, m_RangeMax);
	DDX_Text(pDX, IDC_ObsX, m_ObsX);
	DDX_Text(pDX, IDC_ObsY, m_ObsY);
	DDX_Text(pDX, IDC_ObsZ, m_ObsZ);
	DDX_Text(pDX, IDC_ObsH, m_ObsH);
	DDX_Text(pDX, IDC_ObsP, m_ObsP);
	DDX_Text(pDX, IDC_ObsR, m_ObsR);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVegaParView, CFormView)
	//{{AFX_MSG_MAP(CVegaParView)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_THREAD_UPDATE, OnUpdateView)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVegaParView diagnostics

#ifdef _DEBUG
void CVegaParView::AssertValid() const
{
	CFormView::AssertValid();
}

void CVegaParView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
CVegaRwSimDoc* CVegaParView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVegaRwSimDoc)));
	return (CVegaRwSimDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVegaParView message handlers

void CVegaParView::OnDraw(CDC* pDC) 
{
	CVegaRwSimDoc *pDoc = GetDocument();
	if (pDoc->m_IsVegaRuning)
	{
		m_ScanMax = pDoc->m_RadarScanMax;
		m_ScanMin = pDoc->m_RadarScanMin;
		m_ScanMinGap = pDoc->m_RadarScanMinGap;
		m_ScanMaxGap = pDoc->m_RadarScanMaxGap;
		m_RangeMax = pDoc->m_RadarRangeMax;
		m_RangeMin = pDoc->m_RadarRangeMin;
		m_ObsX = pDoc->m_ObsX;
		m_ObsY = pDoc->m_ObsY;
		m_ObsZ = pDoc->m_ObsZ;
		m_ObsH = pDoc->m_ObsH;
		m_ObsP = pDoc->m_ObsP;
		m_ObsR = pDoc->m_ObsR;
		
		UpdateData(FALSE);
	}
}



void CVegaParView::OnUpdateView(WPARAM wParam, LPARAM lParam) 
{
 	UpdateData();
 	Invalidate();
	return;
}
