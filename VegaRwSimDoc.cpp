// VegaRwSimDoc.cpp : implementation of the CVegaRwSimDoc class
//

#include "stdafx.h"
#include "VegaRwSim.h"

#include "VegaRwSimDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimDoc

IMPLEMENT_DYNCREATE(CVegaRwSimDoc, CDocument)

BEGIN_MESSAGE_MAP(CVegaRwSimDoc, CDocument)
	//{{AFX_MSG_MAP(CVegaRwSimDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimDoc construction/destruction

CVegaRwSimDoc::CVegaRwSimDoc()
{	
	m_IsVegaRuning = FALSE;

	m_ObsX = 0;
	m_ObsY = 0;
	m_ObsZ = 0;
	m_ObsH = 0;
	m_ObsP = 0;
	m_ObsR = 0;
	m_RadarScanMin = 0;
	m_RadarScanMax = 0;
	m_RadarScanMinGap = 0;
	m_RadarScanMaxGap = 0;
	m_RadarRangeMin = 0;
	m_RadarRangeMax = 0;
}

CVegaRwSimDoc::~CVegaRwSimDoc()
{
}

BOOL CVegaRwSimDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimDoc serialization

void CVegaRwSimDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimDoc diagnostics

#ifdef _DEBUG
void CVegaRwSimDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVegaRwSimDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimDoc commands
