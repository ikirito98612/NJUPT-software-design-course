// B16012117_TCP_SDlg.cpp : implementation file
//

#include "stdafx.h"
#include "B16012117_TCP_S.h"
#include "B16012117_TCP_SDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB16012117_TCP_SDlg dialog

CB16012117_TCP_SDlg::CB16012117_TCP_SDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CB16012117_TCP_SDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CB16012117_TCP_SDlg)
	m_sWords = _T("");
	sPort = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CB16012117_TCP_SDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CB16012117_TCP_SDlg)
	DDX_Control(pDX, IDC_sPort, ServerPort);
	DDX_Control(pDX, IDC_ServerIP, ServerIP);
	DDX_Control(pDX, IDC_Send, m_ButtonSend);
	DDX_Control(pDX, ID_EXIT, m_ButtonExit);
	DDX_Control(pDX, IDC_EditWords, m_EditWords);
	DDX_Control(pDX, IDC_StopListen, m_ButtonStopListen);
	DDX_Control(pDX, IDC_Listen, m_ButtonListen);
	DDX_Control(pDX, IDC_Clear, m_ButtonClear);
	DDX_Control(pDX, IDC_Disconnect, m_ButtonDisconnect);
	DDX_Control(pDX, IDC_LISTWords, m_ListWords);
	DDX_Text(pDX, IDC_EditWords, m_sWords);
	DDX_Text(pDX, IDC_sPort, sPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CB16012117_TCP_SDlg, CDialog)
	//{{AFX_MSG_MAP(CB16012117_TCP_SDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Listen, OnListen)
	ON_BN_CLICKED(IDC_StopListen, OnStopListen)
	ON_BN_CLICKED(IDC_Send, OnSend)
	ON_BN_CLICKED(IDC_Disconnect, OnDisconnect)
	ON_BN_CLICKED(IDC_Clear, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB16012117_TCP_SDlg message handlers

BOOL CB16012117_TCP_SDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ButtonDisconnect.EnableWindow(false);
	m_EditWords.EnableWindow(false);
	m_ButtonSend.EnableWindow(false);
	m_ButtonClear.EnableWindow(false);
    m_ButtonStopListen.EnableWindow(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CB16012117_TCP_SDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CB16012117_TCP_SDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CB16012117_TCP_SDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CB16012117_TCP_SDlg::OnListen() 
{
	// TODO: Add your control notification handler code here
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	m_server=socket(AF_INET,SOCK_STREAM,0);
	WSAAsyncSelect(m_server,m_hWnd,20000,FD_ACCEPT);

	m_client=0;
	BYTE nFild[4];
	CString sIP;
	UpdateData();
	if(ServerIP.IsBlank())
	{	
		AfxMessageBox("请设置IP");
		return;
	}
	if(sPort.IsEmpty())
	{
		AfxMessageBox("请设置监听端口");
		return;
	}
	ServerIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);
	sIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.S_un .S_addr = inet_addr(sIP);
	serveraddr.sin_port =htons(atoi(sPort));
	if (bind(m_server,(sockaddr*)&serveraddr,sizeof(serveraddr)))
	{
		MessageBox("绑定地址失败");
		return;
	}
	listen(m_server,5);
	m_ListWords.AddString("监听开始：");
    m_ListWords.AddString("地址"+sIP+"端口"+sPort);
	m_ListWords.AddString("等待客户端连接……");

	m_ListWords.SetTopIndex(m_ListWords.GetCount() - 1);
	ServerIP.EnableWindow(false);
	ServerPort.EnableWindow(false);
	m_ButtonListen.EnableWindow(false);
	m_ButtonStopListen.EnableWindow();
	m_ButtonExit.EnableWindow(false);
	m_ButtonClear.EnableWindow();
}

void CB16012117_TCP_SDlg::OnStopListen() 
{
	// TODO: Add your control notification handler code here
	closesocket(m_server);
	m_ListWords.AddString("停止监听");
	m_ListWords.SetTopIndex(m_ListWords.GetCount() - 1);
	ServerIP.EnableWindow();
    ServerPort.EnableWindow();
    m_ButtonListen.EnableWindow();
	m_ButtonStopListen.EnableWindow(false);
    m_ButtonExit.EnableWindow();
}

void CB16012117_TCP_SDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_sWords.IsEmpty())
	{
		AfxMessageBox("发送的消息不能为空");
		return;
	}
	int i = send(m_client,m_sWords.GetBuffer(0),m_sWords.GetLength(),0);
	m_ListWords.AddString("发送："+m_sWords);
	m_ListWords.SetTopIndex(m_ListWords.GetCount() - 1);
}

void CB16012117_TCP_SDlg::OnDisconnect() 
{
	// TODO: Add your control notification handler code here
	closesocket(m_client);
	m_ListWords.AddString("与客户端断开");
	m_ListWords.SetTopIndex(m_ListWords.GetCount() - 1);
	m_ButtonDisconnect.EnableWindow(false);
	m_EditWords.EnableWindow(false);
	m_ButtonSend.EnableWindow(false);
}

BOOL CB16012117_TCP_SDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == 20000)
	{
		this->HandleData();
	}
	else if(pMsg->message == 30000)
	{
		switch(pMsg->lParam)
		{
		    case FD_READ:
			    this->ReceiveData();
				break;
			case FD_CLOSE:
				this->CloseSock();
				break;
		}
	}
	else
	    return CDialog::PreTranslateMessage(pMsg);
}

void CB16012117_TCP_SDlg::HandleData()
{
    sockaddr_in serveraddr;
	int len=sizeof(serveraddr);
	m_client=accept(m_server,(struct sockaddr*)&serveraddr,&len);
	WSAAsyncSelect(m_client,m_hWnd,30000,FD_READ|FD_CLOSE);
	m_ListWords.AddString("接收一个客户端的连接请求");
    m_ListWords.SetTopIndex(m_ListWords.GetCount() - 1);
	m_ButtonDisconnect.EnableWindow();
	m_EditWords.EnableWindow();
	m_ButtonSend.EnableWindow();
}

void CB16012117_TCP_SDlg::ReceiveData()
{
    char buffer[1024];
	int num = recv(m_client,buffer,1024,0);
	buffer[num]= 0;
	CString sTemp;
	sTemp.Format ("收到：%s",buffer);
	m_ListWords.AddString(sTemp);
	m_ListWords.SetTopIndex(m_ListWords.GetCount() -1);
	WSAAsyncSelect(m_client,m_hWnd,30000,FD_READ|FD_CLOSE);
}

void CB16012117_TCP_SDlg::CloseSock()
{
    m_ListWords.AddString("客户端断开连接");
	m_ListWords.SetTopIndex(m_ListWords.GetCount() -1);
	closesocket(m_client);
	WSAAsyncSelect(m_server,m_hWnd,20000,FD_ACCEPT);
	m_ButtonDisconnect.EnableWindow(false);
	m_EditWords.EnableWindow(false);
	m_ButtonSend.EnableWindow(false);
}

void CB16012117_TCP_SDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	m_ListWords.ResetContent();
}
