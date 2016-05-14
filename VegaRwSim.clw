; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CVegaRwSimView
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "vegarwsim.h"
LastPage=0

ClassCount=6
Class1=CMainFrame
Class2=CVegaRwSimApp
Class3=CAboutDlg
Class4=CVegaRwSimDoc
Class5=CVegaRwSimView

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class6=CVegaParView
Resource3=IDD_VegaPar

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=ID_SPIN

[CLS:CVegaRwSimApp]
Type=0
BaseClass=CWinApp
HeaderFile=VegaRwSim.h
ImplementationFile=VegaRwSim.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=VegaRwSim.cpp
ImplementationFile=VegaRwSim.cpp
LastObject=CAboutDlg

[CLS:CVegaRwSimDoc]
Type=0
BaseClass=CDocument
HeaderFile=VegaRwSimDoc.h
ImplementationFile=VegaRwSimDoc.cpp

[CLS:CVegaRwSimView]
Type=0
BaseClass=CView
HeaderFile=VegaRwSimView.h
ImplementationFile=VegaRwSimView.cpp
Filter=C
VirtualFilter=VWC
LastObject=ID_PauseOrRun

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_VegaPar]
Type=1
Class=CVegaParView
ControlCount=28
Control1=IDC_STATIC,static,1342308352
Control2=IDC_ObsX,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ObsY,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_ObsZ,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ObsH,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_ObsP,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_ObsR,edit,1350631552
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_RadarScanMin,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_RadarScanMax,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_RadarScanMinGap,edit,1350631552
Control22=IDC_STATIC,static,1342308352
Control23=IDC_RadarScanMaxGap,edit,1350631552
Control24=IDC_STATIC,button,1342177287
Control25=IDC_STATIC,static,1342308352
Control26=IDC_RadarRangeMin,edit,1350631552
Control27=IDC_STATIC,static,1342308352
Control28=IDC_RadarRangeMax,edit,1350631552

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_FULLSCREEN_VIEW
Command14=ID_PauseOrRun
Command15=ID_SPIN
Command16=ID_DRIVE
Command17=ID_UFO
Command18=ID_APP_ABOUT
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[CLS:CVegaParView]
Type=0
HeaderFile=VegaParView.h
ImplementationFile=VegaParView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_ObsH
VirtualFilter=VWC

