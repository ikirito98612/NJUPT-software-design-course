// B16012117_UDP_CSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "B16012117_UDP_CS.h"
#include "B16012117_UDP_CSDlg.h"

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
// CB16012117_UDP_CSDlg dialog

CB16012117_UDP_CSDlg::CB16012117_UDP_CSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CB16012117_UDP_CSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CB16012117_UDP_CSDlg)
	LocalPort = _T("");
	DestPort = _T("");
	str = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32		
	str = _T("");
	m_sport = 0;
	m_dport = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	IsTrue = FALSE;
	Client = INVALID_SOCKET;
}

void CB16012117_UDP_CSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CB16012117_UDP_CSDlg)
	DDX_Control(pDX, IDCANCEL, m_Exit);
	DDX_Control(pDX, IDC_LIST1, list);
	DDX_Control(pDX, IDC_Send, m_Send);
	DDX_Control(pDX, IDC_EDITWORDS, m_EditWords);
	DDX_Control(pDX, IDC_EDIT2, PortDest);
	DDX_Control(pDX, IDC_IPADDRESS2, IPDest);
	DDX_Control(pDX, IDC_STOP, m_Stop);
	DDX_Control(pDX, IDOK, m_Start);
	DDX_Control(pDX, IDC_EDIT1, PortLocal);
	DDX_Control(pDX, IDC_IPADDRESS1, IPLocal);
	DDX_Text(pDX, IDC_EDIT1, LocalPort);
	DDX_Text(pDX, IDC_EDIT2, DestPort);
	DDX_Text(pDX, IDC_EDITWORDS, str);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CB16012117_UDP_CSDlg, CDialog)
	//{{AFX_MSG_MAP(CB16012117_UDP_CSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_MESSAGE(WM_CLIENT_READCLOSE,OnReadClose)
	ON_BN_CLICKED(IDC_Send, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB16012117_UDP_CSDlg message handlers

BOOL CB16012117_UDP_CSDlg::OnInitDialog()
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
	IPLocal.SetFocus();
	list.EnableWindow(false);
	m_Stop.EnableWindow(false);
	IPDest.EnableWindow(false);
	PortDest.EnableWindow(false);
	m_EditWords.EnableWindow(false);
	m_Send.EnableWindow(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CB16012117_UDP_CSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CB16012117_UDP_CSDlg::OnPaint() 
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
HCURSOR CB16012117_UDP_CSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CB16012117_UDP_CSDlg::OnOK() 
{
	// TODO: Add extra validation here
		UpdateData();
	if(IPLocal.IsBlank())
	{
		AfxMessageBox("������IP��ַ!");
		return;	
	}
	if(LocalPort.IsEmpty())
	{
		AfxMessageBox("�����ö˿ں�!");
		return;
	}
	//��ʼ�����
    WSADATA wsaData;
    int iErrorCode;
    if (WSAStartup(MAKEWORD(2,1),&wsaData)) //����Windows Sockets DLL
	{ 
         list.AddString("Winsock�޷���ʼ��!");
         WSACleanup();
         return;
	}

	list.AddString("��ʼ����Socket��");

	ServerSocket = socket(PF_INET,SOCK_DGRAM,0);    //�����������̵�Socket������ΪSOCK_DGRAM�������ӵ�ͨ��

    if(ServerSocket == INVALID_SOCKET)
	{
         list.AddString("����socketʧ��!");
         return;
	}

	//��ȡ�������̵�IP�Ͷ˿�
	BYTE nFild[4];
	CString sIP;
	IPLocal.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);
	sIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);

    m_sockServerAddr.sin_family = AF_INET;
    m_sockServerAddr.sin_addr.s_addr = inet_addr(sIP); 
    m_sockServerAddr.sin_port = htons(atoi(LocalPort));

	socklen = sizeof(m_sockServerAddr);

    if (bind(ServerSocket,(LPSOCKADDR)&m_sockServerAddr,sizeof(m_sockServerAddr)) == SOCKET_ERROR) //�����õĶ˿ڰ�
    {
	    list.AddString("��ʧ��!");
        return;
	}
	iErrorCode = WSAAsyncSelect(ServerSocket,m_hWnd,WM_CLIENT_READCLOSE,FD_READ);

    // ������Ӧ���ݸ����ڵ���ϢΪWM_SERVER_ACCEPT �������Զ�����Ϣ

    if (iErrorCode == SOCKET_ERROR) 
	{
         list.AddString("WSAAsyncSelect�趨ʧ��!�������������������Ϣ");
         return;
	}


 	list.AddString("�������������ɹ�!");
	list.AddString("��ַ " + sIP + "  �˿� " + LocalPort);
	this->SetWindowTextA("����Ӧ�ý��̣�" + sIP + ":" + LocalPort + "��-UDProcsComm");

	//����
    IPLocal.EnableWindow(false);
	PortLocal.EnableWindow(false);
	m_Start.EnableWindow(false);
	m_Stop.EnableWindow(true);
	IPDest.EnableWindow(true);
	IPDest.SetFocus();
	PortDest.EnableWindow(true);
	m_EditWords.EnableWindow(true);
	m_Send.EnableWindow(true);
	list.EnableWindow(true);
	m_Exit.EnableWindow(false);
	//����
    return; 
	CDialog::OnOK();
}

LRESULT CB16012117_UDP_CSDlg::OnReadClose(WPARAM wParam,LPARAM lParam)
{
	//�Զ���Ĺر��뻺��������Ϣ
	CString str;
	switch (WSAGETSELECTEVENT(lParam))
	{
	    case FD_READ:
		if(recvfrom(ServerSocket,(char *)&msg,sizeof(msg),0,(LPSOCKADDR)&m_sockServerAddr,(int *)&socklen) == SOCKET_ERROR)		
		{
			list.AddString("����ʧ��!�Է�������Ӧ�ý���û������");
			return 0;
		}
		str.Format("%s",msg.msg);
		list.AddString(str);
		break;
	}
	return 0L;
}

void CB16012117_UDP_CSDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
		//������ֹͣ����ʱ����SOCKET���
	list.AddString("���ڹر�Socket��");
	closesocket(ServerSocket);
	WSACleanup();
	list.AddString("��������ֹͣ����!");

	//����
    IPLocal.EnableWindow(true);
	PortLocal.EnableWindow(true);
	m_Start.EnableWindow(true);
	m_Stop.EnableWindow(false);
	list.EnableWindow(false);
	IPLocal.SetFocus();

	IPDest.EnableWindow(false);
	PortDest.EnableWindow(false);
	m_EditWords.EnableWindow(false);
	m_Send.EnableWindow(false);
	m_Exit.EnableWindow(true);
	//����
}

void CB16012117_UDP_CSDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
		//��������
	UpdateData();
	if(IPDest.IsBlank())
	{
		AfxMessageBox("��ָ��Ŀ���������������IP��ַ!");
		return;	
	}
	if(DestPort.IsEmpty())
	{
		AfxMessageBox("��ָ��Ŀ����̵Ķ˿ں�!");
		return;
	}
	//��ȡĿ����̵�IP�Ͷ˿�
	BYTE nFild[4];
	CString sIP;
	IPDest.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);
	sIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);

	m_sockAddrto.sin_family = AF_INET;
    m_sockAddrto.sin_addr.s_addr = inet_addr(sIP); 
    m_sockAddrto.sin_port = htons(atoi(DestPort));
	if(str.IsEmpty())
	{
	    AfxMessageBox("���͵���Ϣ����Ϊ��!");
		return;
	}
	strcpy(msg.msg,(LPCTSTR)str);
	msg.i = 0;
	if(sendto(ServerSocket,(char *)&msg,sizeof(msg),0,(LPSOCKADDR)&m_sockAddrto,sizeof(m_sockAddrto)) == SOCKET_ERROR)
	{
		list.AddString("��������ʧ��!");
	};
	str.Empty();
	UpdateData(FALSE);
}
