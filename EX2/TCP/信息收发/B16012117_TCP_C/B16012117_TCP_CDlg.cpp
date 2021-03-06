// B16012117_TCP_CDlg.cpp : implementation file
//

#include "stdafx.h"
#include "B16012117_TCP_C.h"
#include "B16012117_TCP_CDlg.h"

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
// CB16012117_TCP_CDlg dialog

CB16012117_TCP_CDlg::CB16012117_TCP_CDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CB16012117_TCP_CDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CB16012117_TCP_CDlg)
	m_sWords = _T("");
	sPort = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CB16012117_TCP_CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CB16012117_TCP_CDlg)
	DDX_Control(pDX, IDC_Exit, m_ButtonExit);
	DDX_Control(pDX, IDC_sPort, ServerPort);
	DDX_Control(pDX, IDC_ServerIP, ServerIP);
	DDX_Control(pDX, IDC_Send, m_ButtonSend);
	DDX_Control(pDX, IDC_Words, m_EditWords);
	DDX_Control(pDX, IDC_Clear, m_ButtonClear);
	DDX_Control(pDX, IDC_LISTWORDS, m_ListWords);
	DDX_Control(pDX, IDC_Disconnect, m_ButtonDisconnect);
	DDX_Control(pDX, IDC_Connect, m_ButtonConnect);
	DDX_Text(pDX, IDC_Words, m_sWords);
	DDX_Text(pDX, IDC_sPort, sPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CB16012117_TCP_CDlg, CDialog)
	//{{AFX_MSG_MAP(CB16012117_TCP_CDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Connect, OnConnect)
	ON_BN_CLICKED(IDC_Disconnect, OnDisconnect)
	ON_BN_CLICKED(IDC_Send, OnSend)
	ON_BN_CLICKED(IDC_Clear, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB16012117_TCP_CDlg message handlers

BOOL CB16012117_TCP_CDlg::OnInitDialog()
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
	m_ButtonClear.EnableWindow(false);
	m_EditWords.EnableWindow(false);
	m_ButtonSend.EnableWindow(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CB16012117_TCP_CDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CB16012117_TCP_CDlg::OnPaint() 
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
HCURSOR CB16012117_TCP_CDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CB16012117_TCP_CDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CB16012117_TCP_CDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	m_client=socket(AF_INET,SOCK_STREAM,0);

	sockaddr_in serveraddr;
	UpdateData();
	if(ServerIP.IsBlank())
	{
		AfxMessageBox("请指定服务器IP");
		return;
	}
	if(sPort.IsEmpty())
	{
		AfxMessageBox("请指定端口");
		return;
	}
	BYTE nFild[4];
	CString sIP;
	ServerIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);
	sIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.S_un .S_addr = inet_addr(sIP);
	serveraddr.sin_port =htons(atoi(sPort));

	if(connect(m_client,(sockaddr*)&serveraddr,sizeof(serveraddr))!=0)
	{
		MessageBox("连接失败");
		return;
	}
	else
	{
		m_ListWords.AddString("连接服务器成功");
		m_ListWords.SetTopIndex(m_ListWords.GetCount() - 1);
	}
	WSAAsyncSelect(m_client,m_hWnd,10000,FD_READ|FD_CLOSE);

	ServerIP.EnableWindow(false);
	ServerPort.EnableWindow(false);
	m_ButtonConnect.EnableWindow(false);
	m_ButtonDisconnect.EnableWindow();
	m_EditWords.EnableWindow();
	m_ButtonSend.EnableWindow();
	m_ButtonExit.EnableWindow(false);
	m_ButtonClear.EnableWindow();

}

void CB16012117_TCP_CDlg::OnDisconnect() 
{
	// TODO: Add your control notification handler code here
	closesocket(m_client);
	m_ListWords.AddString("从服务器断开");
	m_ListWords.SetTopIndex(m_ListWords.GetCount() - 1);
	ServerIP.EnableWindow();
	ServerPort.EnableWindow();
	m_ButtonConnect.EnableWindow();
	m_ButtonDisconnect.EnableWindow(false);
	m_EditWords.EnableWindow(false);
	m_ButtonSend.EnableWindow(false);
	m_ButtonExit.EnableWindow();
}

void CB16012117_TCP_CDlg::OnSend() 
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

BOOL CB16012117_TCP_CDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == 10000)
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

void CB16012117_TCP_CDlg::ReceiveData()
{
    char buffer[1024];
	int num = recv(m_client,buffer,1024,0);
	buffer[num]='\0';
	CString sTemp;
	sTemp.Format ("收到：%s",buffer);
	WSAAsyncSelect(m_client,m_hWnd,10000,FD_READ|FD_CLOSE);
	m_ListWords.AddString(sTemp);
	m_ListWords.SetTopIndex(m_ListWords.GetCount() -1);
//	WSAAsyncSelect(m_client,m_hWnd,10000,FD_READ|FD_CLOSE);
}

void CB16012117_TCP_CDlg::CloseSock()
{
    m_ListWords.AddString("服务器断开了");
	m_ListWords.SetTopIndex(m_ListWords.GetCount() -1);
	closesocket(m_client);
	ServerIP.EnableWindow();
	ServerPort.EnableWindow();
	m_ButtonConnect.EnableWindow();
    m_ButtonDisconnect.EnableWindow(false);
    m_EditWords.EnableWindow(false);
    m_ButtonSend.EnableWindow(false);
    m_ButtonExit.EnableWindow();
}

void CB16012117_TCP_CDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	m_ListWords.ResetContent();
}
