// VegaRwSimDoc.h : interface of the CVegaRwSimDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VEGARWSIMDOC_H__B7E21BC1_F1F7_417F_B2B3_83F0954768F9__INCLUDED_)
#define AFX_VEGARWSIMDOC_H__B7E21BC1_F1F7_417F_B2B3_83F0954768F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVegaRwSimDoc : public CDocument
{
protected: // create from serialization only
	CVegaRwSimDoc();
	DECLARE_DYNCREATE(CVegaRwSimDoc)

// Attributes
public:
	BOOL m_IsVegaRuning;

	int m_ObsX;
	int m_ObsY;
	int m_ObsZ;
	int m_ObsH;
	int m_ObsP;
	int m_ObsR;

	int  m_RadarScanMax;
	int  m_RadarScanMin;
	int  m_RadarScanMinGap;
	int  m_RadarScanMaxGap;
	int  m_RadarRangeMin;
	int  m_RadarRangeMax;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVegaRwSimDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVegaRwSimDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVegaRwSimDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VEGARWSIMDOC_H__B7E21BC1_F1F7_417F_B2B3_83F0954768F9__INCLUDED_)
