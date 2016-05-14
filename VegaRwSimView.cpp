// VegaRwSimView.cpp : implementation of the CVegaRwSimView class
//

#include "stdafx.h"
#include "VegaRwSim.h"

#include "VegaRwSimDoc.h"
#include "VegaRwSimView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimView

IMPLEMENT_DYNCREATE(CVegaRwSimView, CView)

BEGIN_MESSAGE_MAP(CVegaRwSimView, CView)
	//{{AFX_MSG_MAP(CVegaRwSimView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_COMMAND(ID_SPIN, OnSpin)
	ON_UPDATE_COMMAND_UI(ID_SPIN, OnUpdateSpin)
	ON_COMMAND(ID_UFO, OnUfo)
	ON_UPDATE_COMMAND_UI(ID_UFO, OnUpdateUfo)
	ON_COMMAND(ID_DRIVE, OnDrive)
	ON_UPDATE_COMMAND_UI(ID_DRIVE, OnUpdateDrive)
	ON_COMMAND(ID_PauseOrRun, OnPauseOrRun)
	ON_UPDATE_COMMAND_UI(ID_PauseOrRun, OnUpdatePauseOrRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimView construction/destruction

CVegaRwSimView::CVegaRwSimView()
{
	EnableAutomation();

	m_pathName = "";
	m_vegaInitted=FALSE;
	m_vegaDefined=FALSE;
	m_vegaConfiged=FALSE;
	m_isRunning=FALSE;
	m_pVegaThread=NULL;

	m_VegaState = Running;
}

CVegaRwSimView::~CVegaRwSimView()
{
	stopVega();
}

BOOL CVegaRwSimView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimView drawing

void CVegaRwSimView::OnDraw(CDC* pDC)
{
	CVegaRwSimDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CRect rcClient;
	GetClientRect(&rcClient);
	pDC->FillSolidRect(&rcClient,RGB(0,0,0)); // ������Ϊ��ɫ
}

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimView diagnostics

#ifdef _DEBUG
void CVegaRwSimView::AssertValid() const
{
	CView::AssertValid();
}

void CVegaRwSimView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVegaRwSimDoc* CVegaRwSimView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVegaRwSimDoc)));
	return (CVegaRwSimDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVegaRwSimView message handlers

void CVegaRwSimView::OnFileOpen() 
{
	CFileDialog fileDlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,"Application Define Files(*.adf)|*.adf|",this);
	if(fileDlg.DoModal()==IDOK)
	{
	  m_pathName=fileDlg.GetPathName();
	  CString fileName=fileDlg.GetFileTitle();
	  SetWindowText(fileName);
	  GetDocument()->SetPathName(m_pathName,FALSE);
	}

	//����vega�߳�
	runVega();
}

// ʵ�ֵ�����vega�߳�
UINT runVegaProc(LPVOID pParam)
{
// 	CVegaRwSimView* hParent = (CVegaRwSimView*)pParam;
// 
// 	vgInitWinSys(AfxGetInstanceHandle(), hParent->GetSafeHwnd());
// 	hParent->setVegaInitted(TRUE);  // m_vegaInitted����Ϊ��
// 	hParent->postInitted();
// 
//     vgInitRW();
// 
//     vgDefineSys(hParent->getAdfName());
// 	hParent->setVegaDefined(TRUE);
// 	hParent->postDefined(); 
// 
// 	vgProp(vgGetRWSensor(0), VGRWSENSOR_DBS_SCAN_MIN, -120);
// 	vgProp(vgGetRWSensor(0), VGRWSENSOR_DBS_SCAN_MAX, 120);
// 
//     vgConfigSys(); 
// 	hParent->setVegaConfiged(TRUE);
// 	hParent->postConfiged();   	
// 
// 	CVegaRwSimDoc *pDoc = hParent->GetDocument();
// 	pDoc->m_IsVegaRuning = TRUE;
// 	pDoc->m_RadarScanMin = vgGetProp(vgGetRWSensor(0), VGRWSENSOR_DBS_SCAN_MIN);
// 	pDoc->m_RadarScanMax = vgGetProp(vgGetRWSensor(0), VGRWSENSOR_DBS_SCAN_MAX);
// 	pDoc->m_RadarScanMinGap = vgGetProp(vgGetRWSensor(0), VGRWSENSOR_DBS_GAP_MIN);
// 	pDoc->m_RadarScanMaxGap = vgGetProp(vgGetRWSensor(0), VGRWSENSOR_DBS_GAP_MAX);
// 	pDoc->m_RadarRangeMax = vgGetProp(vgGetRWSensor(0), VGRWSENSOR_DBS_RANGE_MAX);
// 	pDoc->m_RadarRangeMin = vgGetProp(vgGetRWSensor(0), VGRWSENSOR_DBS_RANGE_MIN);
// 	
// 	//��ȡǰ�ӹ۲��ߵ�λ�ú���̬ʸ��
// 	float x,y,z,h,p,r;
//     vgPosition  *vgpos;
// 	vgpos = vgNewPos();
// 	vgGetPos(obs, vgpos);
// 	vgGetPosVec(vgpos, &x, &y, &z, &h, &p, &r);
// 	pDoc->m_ObsX = x;
// 	pDoc->m_ObsY = y;
// 	pDoc->m_ObsZ = z;
// 	pDoc->m_ObsH = h;
// 	pDoc->m_ObsP = p;
// 	pDoc->m_ObsR = r;
// 
// 	CView*   pv;     
// 	POSITION  pos = pDoc->GetFirstViewPosition();  
// 	while((pv = pDoc->GetNextView(pos)) != NULL)
// 	{   
// 		if(pv->IsKindOf(RUNTIME_CLASS(CVegaParView)))
// 		{
// 			::PostMessage(pv->GetSafeHwnd(),  WM_THREAD_UPDATE,  NULL, NULL); 
// 		}  
// 	};   

//	while(hParent->m_isRunning)
	{
// 		vgSyncFrame();  
// 		hParent->postSync();
// 		vgFrame();		
// 		hParent->postFrame();
// 		
// 		hParent->getInput();	
	}

 //  hParent->setVegaInitted(FALSE); 
//   vgExit(0);
   
   return 0;
}

void CVegaRwSimView::runVega()
{
	m_isRunning = TRUE;
	
	if (m_pVegaThread == NULL) 
	{
		//�������߳�
		m_pVegaThread = AfxBeginThread(
			runVegaProc,  //�������߳̿��ƺ�����ָ��
			this,         //���ݸ��߳̿��ƺ����Ĳ���
			THREAD_PRIORITY_NORMAL,  //�̵߳����ȼ���0��ʾ�븸�̵߳����ȼ���ͬ
			0,            //��ջ��С�븸�߳���ͬ
			0,            //�趨�̴߳���������ִ��
			NULL          //�̵߳İ�ȫ����
			);
	}

    while (!getVegaDefined())
	{
		Sleep(10);
	}

// 	win=vgGetWin(0);  // ����	
// 	if (win == NULL)
// 	{
// 	  vgNotify(VG_FATAL,VG_APP,"ERROR: No Vega Window Define---check %s",getAdfName());
// 	  exit(-1);
// 	}
// 
// 	gfx=vgGetGfx(0);// Graphic States
// 
//     if (gfx==NULL)
// 	{
// 	  vgNotify(VG_FATAL,VG_APP,"ERROR: No Graphic States Define---check %s",getAdfName());
// 	  exit(-1);
// 	}
// 
// 	chan=vgGetChan(0); // channel
//     if (chan==NULL)
// 	{
// 	  vgNotify(VG_FATAL,VG_APP,"ERROR: No Vega Channel Define---check %s",getAdfName());
// 	  exit(-1);
// 	}
// 
// 	obs=vgGetObserv(0); // observer
//     if (obs==NULL)
// 	{
// 	  vgNotify(VG_FATAL,VG_APP,"ERROR: Couldn't find obs---check %s",getAdfName());
// 	  exit(-1);
// 	}
// 
//     scene=vgGetScene(0);
//     if (scene == NULL)
// 	{
// 	  vgNotify(VG_FATAL,VG_APP,"ERROR: Couldn't find scene---check %s",getAdfName());
// 	  exit(-1);
// 	}
// 
// 	env = vgGetEnv(0);
//     if (env == NULL)
// 	{
// 	  vgNotify(VG_FATAL,VG_APP,"ERROR: Couldn't find env---check %s",getAdfName());
// 	  exit(-1);
// 	}
}

void CVegaRwSimView::stopVega()
{
    if (!m_vegaInitted) 
		return;
	
	//ֹͣ��Ⱦ
//	vgDrawEnabled(false);

	m_isRunning=FALSE;

	while (m_vegaInitted) Sleep(10);
}


void CVegaRwSimView::pauseVega( void )
{
//	vgDrawEnabled(0);
}

void CVegaRwSimView::unPauseVega( void )
{
//	vgDrawEnabled(1);
}



void CVegaRwSimView::postDefined()
{
 
}

void CVegaRwSimView::postConfiged()
{

}

void CVegaRwSimView::postInitted()
{
  
}


void CVegaRwSimView::postSync()
{

}

void CVegaRwSimView::postFrame()
{

}

const char* CVegaRwSimView::getAdfName()
{
  CVegaRwSimDoc *doc=(CVegaRwSimDoc *)GetDocument();
  const char* adfName=doc->GetPathName();
  if (strlen(adfName)==0)
	   return "vegawin.adf";
  else 
	  return adfName;
}


void CVegaRwSimView::getInput(void)
{
    int ival, key;
    float fval;
	
   
}

void CVegaRwSimView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	//��֤Vega�������Ӵ���Сһ��
	m_cx = cx;
	m_cy = cy;

	if (!getVegaInitted())
	{
		return;
	}

}

void CVegaRwSimView::OnTimer(UINT nIDEvent) 
{
	if (getVegaRunning() == TRUE)
	{
		CString strEyeXYZ;
		CString strEyeHPR;
		float x,y,z,h,p,r;
		
	}	
	
	CView::OnTimer(nIDEvent);
}

void CVegaRwSimView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (nChar == VK_ESCAPE) // ����Esc��
	{
	    if (m_pMainFrame->m_bFullScreen)
			m_pMainFrame->FullScreenOff();  //ȡ��ȫ��
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}



int CVegaRwSimView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pMainFrame=(CMainFrame *) GetParentFrame();
		
	const int TIMER_XYZ=1;
	SetTimer(TIMER_XYZ, 1000, NULL);  //���ö�ʱ����������״̬���ϸ��µ�ǰVega�۲��ߵ��������
	
	return 0;
}

void CVegaRwSimView::OnSpin() 
{

}

void CVegaRwSimView::OnUpdateSpin(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(getVegaRunning());
//	if (getVegaRunning()==TRUE)
//		pCmdUI->SetCheck(vgGetProp(vgGetMot(0),VGMOT_MODEL)==VGMOT_SPIN);
}

void CVegaRwSimView::OnUfo() 
{
	
}

void CVegaRwSimView::OnUpdateUfo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(getVegaRunning());
//	if (getVegaRunning()==TRUE)
//		pCmdUI->SetCheck(vgGetProp(vgGetMot(0),VGMOT_MODEL)==VGMOT_UFO); 
}

void CVegaRwSimView::OnDrive() 
{
	
}

void CVegaRwSimView::OnUpdateDrive(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(getVegaRunning());
//	if (getVegaRunning()==TRUE)
//		pCmdUI->SetCheck(vgGetProp(vgGetMot(0),VGMOT_MODEL)==VGMOT_DRIVE);
}



void CVegaRwSimView::OnPauseOrRun() 
{
	m_VegaState = !m_VegaState;
	//vgDrawEnabled(m_VegaState);
}

void CVegaRwSimView::OnUpdatePauseOrRun(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(getVegaRunning());
	if (m_VegaState)
	{       
		pCmdUI->SetText("��ͣ");
	}
	else 
	{
		pCmdUI->SetText("����");
	}
}
