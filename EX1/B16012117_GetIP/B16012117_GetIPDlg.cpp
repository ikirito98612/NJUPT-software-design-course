// B16012117_GetIPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "B16012117_GetIP.h"
#include "B16012117_GetIPDlg.h"
#include "iphlpapi.h"
#include <winsock.h>
#include <wsipx.h>
#include <wsnwlink.h>





#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
PIP_ADAPTER_INFO pinfo = NULL;
FIXED_INFO * FixedInfo;
unsigned long len = 0;

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
// CB16012117_GetIPDlg dialog

CB16012117_GetIPDlg::CB16012117_GetIPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CB16012117_GetIPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CB16012117_GetIPDlg)
	m_DNS = _T("");
	m_Gateway = _T("");
	m_HostName = _T("");
	m_IPaddress = _T("");
	m_MAC = _T("");
	m_SubnetMask = _T("");
	m_DNS2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CB16012117_GetIPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CB16012117_GetIPDlg)
	DDX_Text(pDX, IDC_DNS, m_DNS);
	DDX_Text(pDX, IDC_GateWay, m_Gateway);
	DDX_Text(pDX, IDC_HostName, m_HostName);
	DDX_Text(pDX, IDC_IPAddress, m_IPaddress);
	DDX_Text(pDX, IDC_MAC, m_MAC);
	DDX_Text(pDX, IDC_SubnetMask, m_SubnetMask);
	DDX_Text(pDX, IDC_DNS2, m_DNS2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CB16012117_GetIPDlg, CDialog)
	//{{AFX_MSG_MAP(CB16012117_GetIPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1_GetIP, OnBUTTON1GetIP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB16012117_GetIPDlg message handlers

BOOL CB16012117_GetIPDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CB16012117_GetIPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CB16012117_GetIPDlg::OnPaint() 
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
HCURSOR CB16012117_GetIPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


int CB16012117_GetIPDlg::StartUp()  
// ��ʹ��WinSock API֮ǰ����Ҫ����startup()������ֻ�иú����ɹ�����(��ʾӦ�ó�����winsock��ɹ��Ľ���������)��Ӧ�ó���ſ��Ե�������windows sockets DLL�еĺ���
{
	// Initialize windows sockets API. Ask for version 1.1

	int	err; 
	
	WORD wVersionRequested = MAKEWORD(1, 1);   //����汾��Ϣ����
	WSADATA wsaData;      //����������Ϣ����
	
	err = WSAStartup( wVersionRequested, &wsaData ); //��������Ϣ��ֵ
	if ( err != 0 ) {
		// Couldn't find a usable WinSock DLL
		return err;  
	} 
	
	return 0;
}

int CB16012117_GetIPDlg::CleanUp()  //�������ʱ������cleanup���������ͷ�ռ����Դ
{
	// Terminate windows sockets API

	int nRetCode;

	nRetCode = WSACleanup();
	if (nRetCode != 0) {
		// An error occured. 
		return WSAGetLastError();
	}

	return 0; 
}


int CB16012117_GetIPDlg::GetHostName(CString& sHostName)  //��GetHostName������ȡ������������
{
	char szHostName[256];
	int  nRetCode;

	nRetCode = gethostname(szHostName, sizeof(szHostName));

	if (nRetCode != 0) {
		// An error has occurred
		sHostName = _T("Not available");;
		return WSAGetLastError();
	}

	sHostName = szHostName;
	return 0;
}

int CB16012117_GetIPDlg::GetIPAddress(const CString& sHostName, CString& sIPAddress)
//
{
	struct hostent FAR *lpHostEnt = gethostbyname (sHostName);   //gethostbyname()���ض�Ӧ�ڸ����������İ����������ֺ͵�ַ��Ϣ��hostent�ṹָ�롣�ṹ��������gethostaddr()��һ�¡�

	if (lpHostEnt == NULL) {
		// An error occurred. 
		sIPAddress = _T("");
		return WSAGetLastError();
	}

	LPSTR lpAddr = lpHostEnt->h_addr_list[0];
	if (lpAddr) {
		struct in_addr  inAddr;
		memmove (&inAddr, lpAddr, 4);     // ��src��ָ�ڴ�������4���ֽڵ�dest��ָ�ڴ�����
		sIPAddress = inet_ntoa (inAddr);  //inet_ntoa��һ��IPת����һ����������׼��ָ�ʽ���ַ���
		if (sIPAddress.IsEmpty())
			sIPAddress = _T("Not available");
	}		
	
	return 0;
}

void CB16012117_GetIPDlg::GetGateWay_SubNet()
// GetAdaptersInfo���Ի�ñ��ؼ������������Ϣ���ú�����ͷ�ļ�iphlpapi.h�����������ļ�iphlpapi.lib
{
    u_char pMac[6];
    PIP_ADAPTER_INFO adp = NULL;
    ULONG uLong=0;
    //Ϊ�����������ڴ�
    ::GetAdaptersInfo(adp,&uLong);
    adp = (PIP_ADAPTER_INFO)::GlobalAlloc(GPTR,uLong);

    //ȡ�ñ����������ṹ��Ϣ
    if(::GetAdaptersInfo(adp,&uLong) == ERROR_SUCCESS)
	{
        if (adp != NULL)
		{
//strMacAdd.Format("%s",adp->Address);
            memcpy(pMac,adp->Address,6);
            m_MAC.Format("%02X-%02X-%02X-%02X-%02X-%02X",pMac[0],pMac[1],pMac[2],pMac[3],pMac[4],pMac[5]);
            m_Gateway.Format("%s",adp->GatewayList.IpAddress.String);// ����
            m_SubnetMask.Format("%s",adp->IpAddressList.IpMask.String);//��������
		}
	}
/***	if (pinfo!=NULL)
		delete (pinfo);
	unsigned  long nError;
	pinfo= (PIP_ADAPTER_INFO)malloc(len);
	nError = GetAdaptersInfo(pinfo,&len);
	if (nError==0)
	{
		if (pinfo!=NULL)
		{
			PIP_ADDR_STRING pAddressList = &(pinfo->IpAddressList);
			do 
			{
				pAddressList = pAddressList->Next;
			} while (pAddressList != NULL);

			memcpy(pMac,pinfo->Address,6);
            m_MAC.Format("%02X-%02X-%02X-%02X-%02X-%02X",pMac[0],pMac[1],pMac[2],pMac[3],pMac[4],pMac[5]);

			m_SubnetMask.Format("%s",pinfo->IpAddressList.IpMask.String);
			m_Gateway.Format("%s",pinfo->GatewayList.IpAddress.String);
		}
	}***/
}




void CB16012117_GetIPDlg::Get_DNS()
//  GetNetworkParams���Ի�ñ���DNS���á�
//  FIXED_INFO�ṹ��������һ̨�������������ӿ�����ͬ����Ϣ
{

	FixedInfo = (FIXED_INFO *) GlobalAlloc( GPTR, sizeof( FIXED_INFO ) );
	len = sizeof( FIXED_INFO );
   
	if( ERROR_BUFFER_OVERFLOW == GetNetworkParams( FixedInfo, &len ) ) 
	{
		GlobalFree( FixedInfo );
		FixedInfo = (FIXED_INFO *) GlobalAlloc( GPTR, len );
	}
	GetNetworkParams( FixedInfo, &len );

	
	m_DNS.Format("%s\n",FixedInfo -> DnsServerList.IpAddress.String);

	IP_ADDR_STRING *pIPAddr = FixedInfo->DnsServerList.Next;
		if(pIPAddr != NULL)
			m_DNS2.Format("%s\n",pIPAddr->IpAddress.String);

}

//-------------------------






void CB16012117_GetIPDlg::OnBUTTON1GetIP() 
{
	// TODO: Add your control notification handler code here
	int nRetCode;

	nRetCode = StartUp();
	TRACE1("StartUp RetCode: %d\n", nRetCode);

	nRetCode = GetHostName(m_HostName);
	TRACE1("GetHostName RetCode: %d\n", nRetCode);

	nRetCode = GetIPAddress(m_HostName, m_IPaddress);
	TRACE1("GetIPAddress RetCode: %d\n", nRetCode);

	nRetCode = CleanUp();
	TRACE1("CleanUp RetCode: %d\n", nRetCode);

	GetGateWay_SubNet();
	if(m_Gateway == _T("")&&m_SubnetMask == _T("")&&m_MAC == _T(""))
		GetGateWay_SubNet();
	
	Get_DNS();

	UpdateData(FALSE);


}
