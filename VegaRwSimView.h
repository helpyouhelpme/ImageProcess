// VegaRwSimView.h : interface of the CVegaRwSimView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VEGARWSIMVIEW_H__51ED4CDB_938C_4CAD_84DE_C5A9FBE6F406__INCLUDED_)
#define AFX_VEGARWSIMVIEW_H__51ED4CDB_938C_4CAD_84DE_C5A9FBE6F406__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "MainFrm.h"
#include "VegaParView.h"

#define Running TRUE
#define Pausing FALSE


class CVegaRwSimView : public CView
{
protected: // create from serialization only
	CVegaRwSimView();
	DECLARE_DYNCREATE(CVegaRwSimView)

// Attributes
public:
	CVegaRwSimDoc* GetDocument();

	const char *getAdfName(void);
    static void getInput(void);

	void postFrame(void); // vega��ѭ����֡��Ⱦ��ɺ�Ĳ���
	void postSync(void); // vega��ѭ����֡ͬ����ɺ�Ĳ���

	void postConfiged(void); // vegaϵͳ������ɺ�Ĳ���
	void postDefined(void);
	void postInitted(void);

	void setVegaConfiged(BOOL i)  { m_vegaConfiged=i;    }
	BOOL getVegaConfiged(void)    {return m_vegaConfiged;} // ��ȡvegaϵͳ���õ�״̬

	void setVegaDefined(BOOL i)   { m_vegaDefined=i;       }
	BOOL getVegaDefined(void)     { return m_vegaDefined;  } // ��ȡvegaϵͳ�����״̬

	void setVegaInitted(BOOL i)  { m_vegaInitted=i;}
	BOOL getVegaInitted(void)     { return m_vegaInitted;} // ��ȡvegaϵͳ��ʼ����״̬

	BOOL getVegaRunning(void) const {return m_isRunning;}  // ��ȡvegaϵͳ������״̬

	void pauseVega( void );
	void unPauseVega( void );
	void stopVega();
	void runVega();

// Operations
public:
	CMainFrame *m_pMainFrame;
	CWinThread *m_pVegaThread; //ָ��vega�̵߳�ָ��

	CString m_pathName;
	int m_cx;
	int m_cy;

	//Vega ״̬����
	BOOL m_vegaDefined;
	BOOL m_isRunning;
	BOOL m_vegaConfiged;
	BOOL m_vegaInitted;

protected:
	BOOL m_VegaState;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVegaRwSimView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVegaRwSimView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVegaRwSimView)
	afx_msg void OnFileOpen();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSpin();
	afx_msg void OnUpdateSpin(CCmdUI* pCmdUI);
	afx_msg void OnUfo();
	afx_msg void OnUpdateUfo(CCmdUI* pCmdUI);
	afx_msg void OnDrive();
	afx_msg void OnUpdateDrive(CCmdUI* pCmdUI);
	afx_msg void OnPauseOrRun();
	afx_msg void OnUpdatePauseOrRun(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VegaRwSimView.cpp
inline CVegaRwSimDoc* CVegaRwSimView::GetDocument()
   { return (CVegaRwSimDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VEGARWSIMVIEW_H__51ED4CDB_938C_4CAD_84DE_C5A9FBE6F406__INCLUDED_)
