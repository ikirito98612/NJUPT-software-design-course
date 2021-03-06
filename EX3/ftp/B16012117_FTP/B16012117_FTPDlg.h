// B16012117_FTPDlg.h : header file
//
#include "afxinet.h"
#if !defined(AFX_B16012117_FTPDLG_H__D8C70FAD_87D0_46BE_A4A8_72142F479298__INCLUDED_)
#define AFX_B16012117_FTPDLG_H__D8C70FAD_87D0_46BE_A4A8_72142F479298__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CB16012117_FTPDlg dialog

class CB16012117_FTPDlg : public CDialog
{
// Construction
public:
	CB16012117_FTPDlg(CWnd* pParent = NULL);	// standard constructor
    BOOL bconnect;
	CInternetSession *pInternetSession;
	CFtpConnection *pFtpConnection;
	void ConnectFtp();
	void UpdateDir();
// Dialog Data
	//{{AFX_DATA(CB16012117_FTPDlg)
	enum { IDD = IDD_B16012117_FTP_DIALOG };
	CButton	m_exit;
	CEdit	m_usr;
	CButton	m_upload;
	CEdit	m_pwd;
	CEdit	m_port;
	CButton	m_noname;
	CIPAddressCtrl	ServerIP;
	CButton	m_goback;
	CListBox	m_lst;
	CButton	m_enterdir;
	CButton	m_download;
	CButton	m_disconnect;
	CButton	m_delete;
	CButton	m_connect;
	CString	strport;
	CString	strpwd;
	CString	strusr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_FTPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CB16012117_FTPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNoname();
	afx_msg void OnConnect();
	afx_msg void OnEnterdir();
	afx_msg void OnGoback();
	afx_msg void OnUpload();
	afx_msg void OnDownload();
	afx_msg void OnDelete();
	afx_msg void OnDisconnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_FTPDLG_H__D8C70FAD_87D0_46BE_A4A8_72142F479298__INCLUDED_)
