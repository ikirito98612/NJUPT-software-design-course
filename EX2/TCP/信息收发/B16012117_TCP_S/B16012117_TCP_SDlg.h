// B16012117_TCP_SDlg.h : header file
//

#if !defined(AFX_B16012117_TCP_SDLG_H__7C9D0EEA_9B19_4B66_BEE3_D656184E5FDE__INCLUDED_)
#define AFX_B16012117_TCP_SDLG_H__7C9D0EEA_9B19_4B66_BEE3_D656184E5FDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CB16012117_TCP_SDlg dialog

class CB16012117_TCP_SDlg : public CDialog
{
	SOCKET m_server,m_client;
// Construction
public:
	void CloseSock();
	void ReceiveData();
	void HandleData();
	CB16012117_TCP_SDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CB16012117_TCP_SDlg)
	enum { IDD = IDD_B16012117_TCP_S_DIALOG };
	CEdit	ServerPort;
	CIPAddressCtrl	ServerIP;
	CButton	m_ButtonSend;
	CButton	m_ButtonExit;
	CEdit	m_EditWords;
	CButton	m_ButtonStopListen;
	CButton	m_ButtonListen;
	CButton	m_ButtonClear;
	CButton	m_ButtonDisconnect;
	CListBox	m_ListWords;
	CString	m_sWords;
	CString	sPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_TCP_SDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CB16012117_TCP_SDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnListen();
	afx_msg void OnStopListen();
	afx_msg void OnSend();
	afx_msg void OnDisconnect();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_TCP_SDLG_H__7C9D0EEA_9B19_4B66_BEE3_D656184E5FDE__INCLUDED_)
