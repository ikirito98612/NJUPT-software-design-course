// B16012117_FTPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "B16012117_FTP.h"
#include "B16012117_FTPDlg.h"

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
// CB16012117_FTPDlg dialog

CB16012117_FTPDlg::CB16012117_FTPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CB16012117_FTPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CB16012117_FTPDlg)
	strport = _T("");
	strpwd = _T("");
	strusr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CB16012117_FTPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CB16012117_FTPDlg)
	DDX_Control(pDX, IDCANCEL, m_exit);
	DDX_Control(pDX, IDC_USERNAME, m_usr);
	DDX_Control(pDX, IDC_UPLOAD, m_upload);
	DDX_Control(pDX, IDC_PWD, m_pwd);
	DDX_Control(pDX, IDC_PORT, m_port);
	DDX_Control(pDX, IDC_NONAME, m_noname);
	DDX_Control(pDX, IDC_IPADDRESS, ServerIP);
	DDX_Control(pDX, IDC_GOBACK, m_goback);
	DDX_Control(pDX, IDC_FTPLIST, m_lst);
	DDX_Control(pDX, IDC_ENTERDIR, m_enterdir);
	DDX_Control(pDX, IDC_DOWNLOAD, m_download);
	DDX_Control(pDX, IDC_DISCONNECT, m_disconnect);
	DDX_Control(pDX, IDC_DELETE, m_delete);
	DDX_Control(pDX, IDC_CONNECT, m_connect);
	DDX_Text(pDX, IDC_PORT, strport);
	DDX_Text(pDX, IDC_PWD, strpwd);
	DDX_Text(pDX, IDC_USERNAME, strusr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CB16012117_FTPDlg, CDialog)
	//{{AFX_MSG_MAP(CB16012117_FTPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NONAME, OnNoname)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_ENTERDIR, OnEnterdir)
	ON_BN_CLICKED(IDC_GOBACK, OnGoback)
	ON_BN_CLICKED(IDC_UPLOAD, OnUpload)
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB16012117_FTPDlg message handlers

BOOL CB16012117_FTPDlg::OnInitDialog()
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
	bconnect=false;
	m_lst.ResetContent ();
	m_lst.AddString("尚未连接服务器，无法浏览FTP资源");
	m_connect.EnableWindow(false);
	m_disconnect.EnableWindow (false);
	m_enterdir.EnableWindow (false);
	m_goback.EnableWindow (false);
	m_upload.EnableWindow (false);
	m_download.EnableWindow (false);
	m_delete.EnableWindow (false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CB16012117_FTPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CB16012117_FTPDlg::OnPaint() 
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
HCURSOR CB16012117_FTPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CB16012117_FTPDlg::OnNoname() 
{
	// TODO: Add your control notification handler code here
	int ickeck=m_noname.GetCheck();//获得匿名选择状态
	if(ickeck==1)
	{
		m_usr.EnableWindow(false);
		m_pwd.EnableWindow(false);
		m_usr.SetWindowTextA("anonymous");//用户名自动设置为默认anonymous
		m_pwd.SetWindowTextA("");
		UpdateData();
		if(!ServerIP.IsBlank() &&!strport.IsEmpty())
		{
			m_connect.EnableWindow(true);//连接按钮可用
		}
	}
	else//未按要求输入，不能连接
	{
		m_usr.EnableWindow(true);
		m_pwd.EnableWindow(true);
		m_usr.SetWindowTextA("");
		m_pwd.SetWindowTextA("");
		m_connect.EnableWindow(false);//连接按钮不可用
	}
}


void CB16012117_FTPDlg::ConnectFtp()
{
BYTE nFild[4];
     UpdateData();
	 ServerIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);
	 CString sip;
	 sip.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);
	 if(sip.IsEmpty())
	 {
		 AfxMessageBox("请指定IP地址");
		 return;
	 }
	 if(strport.IsEmpty())
	 {
		 AfxMessageBox("请指定连接端口");
		 return;
	 }
	 if(strusr.IsEmpty())
	     return;//建立一个Internet会话
	 pInternetSession= new CInternetSession("MR",INTERNET_OPEN_TYPE_PRECONFIG);
	 try
	 {
		 //利用Internet会话对象pInternetSession打开一个FTP连接
		 pFtpConnection=pInternetSession->GetFtpConnection(sip,strusr,strpwd,atoi(strport));
		 bconnect=true;
	 }catch(CInternetException* pEx)
	 {
		 TCHAR szErr[1024];
		 pEx->GetErrorMessage(szErr,1024);
		 AfxMessageBox(szErr);
		 pEx->Delete();
	 }
}

void CB16012117_FTPDlg::UpdateDir()
{
m_lst.ResetContent();
	CFtpFileFind ftpfind(pFtpConnection);//找到第一个文件夹
	BOOL bfind=ftpfind.FindFile(NULL);
	while (bfind)
	{
		bfind=ftpfind.FindNextFile();
		CString strpath;
		if(!ftpfind.IsDirectory())
		{
			strpath=ftpfind.GetFileName();
			m_lst.AddString(strpath);
		}
		else
		{
			strpath=ftpfind.GetFilePath();
			m_lst.AddString(strpath);
		}
	}
}


void CB16012117_FTPDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
this->ConnectFtp();//连接FTP服务器
    this->UpdateDir();//显示服务器上的目录和文件夹列表
	ServerIP.EnableWindow(false);
	m_port.EnableWindow(false);
    m_connect.EnableWindow(false);
	m_disconnect.EnableWindow(true);
	m_enterdir.EnableWindow(true);
	m_upload.EnableWindow(true);
	m_download.EnableWindow(true);
	m_delete.EnableWindow(true);
	m_noname.EnableWindow(false);
	m_exit.EnableWindow(false);
}

void CB16012117_FTPDlg::OnEnterdir() 
{
	// TODO: Add your control notification handler code here
	CString selfile;
	m_lst.GetText (m_lst.GetCurSel(),selfile);
	if(!selfile.IsEmpty())
	{
		pInternetSession->Close();
		this->ConnectFtp();
		CString strdir;
		pFtpConnection->GetCurrentDirectory (strdir);
		strdir+=selfile;
		pFtpConnection->SetCurrentDirectory (strdir);
		this->UpdateDir ();
		m_goback.EnableWindow (true);
	}
}

void CB16012117_FTPDlg::OnGoback() 
{
	// TODO: Add your control notification handler code here
	CString strdir;
	pFtpConnection->GetCurrentDirectory (strdir);
	int pos;
	pos = strdir.ReverseFind('/');
	strdir = strdir.Left(pos);
	pInternetSession->Close();
	this->ConnectFtp();
	pFtpConnection->SetCurrentDirectory (strdir);
	this->UpdateDir();
}

void CB16012117_FTPDlg::OnUpload() 
{
	// TODO: Add your control notification handler code here
	CString str;
	CString strname;
	CFileDialog file(true, NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"所有文件(*.*)|*.*|",this);
	if (file.DoModal()==IDOK)
	{
		str =file.GetPathName();
		strname=file.GetFileName();
	}
	if(bconnect)
	{
		CString strdir;
		pFtpConnection->GetCurrentDirectory (strdir);
		BOOL bput=pFtpConnection->PutFile ((LPCTSTR)str,(LPCTSTR)strname);
		if(bput)
		{
			pInternetSession->Close ();
			this->ConnectFtp ();
			pFtpConnection->SetCurrentDirectory (strdir);
			this->UpdateDir();
			AfxMessageBox("上传成功");
		}
	}

}

void CB16012117_FTPDlg::OnDownload() 
{
	// TODO: Add your control notification handler code here
	CString selfile;
	m_lst.GetText (m_lst.GetCurSel(),selfile);
	if(!selfile.IsEmpty ())
	{
		CFileDialog file(false,NULL,selfile,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"所有文件(*.*)|*.*|",this);
		if(file.DoModal()==IDOK)
		{
			CString strname;
			strname=file.GetFileName ();
			CString strdir;
			pFtpConnection->GetCurrentDirectory (strdir);
			pFtpConnection->GetFile (selfile,strname);
			pInternetSession->Close();
			this->ConnectFtp();
			pFtpConnection->SetCurrentDirectory (strdir);
			this->UpdateDir ();
			AfxMessageBox("下载成功");
		}
	}
}

void CB16012117_FTPDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CString selfile;
	m_lst.GetText(m_lst.GetCurSel(),selfile);
	if(!selfile.IsEmpty())
	{
		//弹出对话框确认删除
		if(AfxMessageBox("您真的要删除这个文件吗？",4+48)==6)
		{
			pFtpConnection->Remove(selfile);
		}
		CString strdir;
		pFtpConnection->GetCurrentDirectory (strdir);
		pInternetSession->Close();
		this->ConnectFtp();
		pFtpConnection->SetCurrentDirectory (strdir);
		this->UpdateDir();
	}
}

void CB16012117_FTPDlg::OnDisconnect() 
{
	// TODO: Add your control notification handler code here
	pInternetSession->Close();
	m_lst.ResetContent();
	m_lst.AddString ("连接已断开");
	//界面控制
	ServerIP.EnableWindow (true);
	m_port.EnableWindow (true);
	m_connect.EnableWindow (true);
	m_disconnect.EnableWindow (false);
	m_enterdir.EnableWindow (false);
	m_goback.EnableWindow (false);
	m_upload.EnableWindow (false);
	m_download.EnableWindow (false);
	m_delete.EnableWindow (false);
	m_noname.EnableWindow (true);
	m_exit.EnableWindow (true);
}
