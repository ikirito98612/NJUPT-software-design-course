; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CB16012117_TCP_SDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "B16012117_TCP_S.h"

ClassCount=3
Class1=CB16012117_TCP_SApp
Class2=CB16012117_TCP_SDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_B16012117_TCP_S_DIALOG

[CLS:CB16012117_TCP_SApp]
Type=0
HeaderFile=B16012117_TCP_S.h
ImplementationFile=B16012117_TCP_S.cpp
Filter=N

[CLS:CB16012117_TCP_SDlg]
Type=0
HeaderFile=B16012117_TCP_SDlg.h
ImplementationFile=B16012117_TCP_SDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LISTWords

[CLS:CAboutDlg]
Type=0
HeaderFile=B16012117_TCP_SDlg.h
ImplementationFile=B16012117_TCP_SDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_B16012117_TCP_S_DIALOG]
Type=1
Class=CB16012117_TCP_SDlg
ControlCount=15
Control1=ID_EXIT,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_ServerIP,SysIPAddress32,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_sPort,edit,1350631552
Control7=IDC_Listen,button,1342242816
Control8=IDC_StopListen,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_EditWords,edit,1350631552
Control12=IDC_Send,button,1342242816
Control13=IDC_Clear,button,1342242816
Control14=IDC_Disconnect,button,1342242816
Control15=IDC_LISTWords,listbox,1352728835

