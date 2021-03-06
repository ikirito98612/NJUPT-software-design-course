// B16012117_TCP_CDlg.h : header file
//

#if !defined(AFX_B16012117_TCP_CDLG_H__7E7A64E7_0A2C_4E39_8612_99FA4FB5D2AE__INCLUDED_)
#define AFX_B16012117_TCP_CDLG_H__7E7A64E7_0A2C_4E39_8612_99FA4FB5D2AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CB16012117_TCP_CDlg dialog

class CB16012117_TCP_CDlg : public CDialog
{
	SOCKET m_client;

// Construction
public:
	void CloseSock();
	void ReceiveData();
	CB16012117_TCP_CDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CB16012117_TCP_CDlg)
	enum { IDD = IDD_B16012117_TCP_C_DIALOG };
	CButton	m_ButtonExit;
	CEdit	ServerPort;
	CIPAddressCtrl	ServerIP;
	CButton	m_ButtonSend;
	CEdit	m_EditWords;
	CButton	m_ButtonClear;
	CListBox	m_ListWords;
	CButton	m_ButtonDisconnect;
	CButton	m_ButtonConnect;
	CString	m_sWords;
	CString	sPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_TCP_CDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CB16012117_TCP_CDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnConnect();
	afx_msg void OnDisconnect();
	afx_msg void OnSend();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_TCP_CDLG_H__7E7A64E7_0A2C_4E39_8612_99FA4FB5D2AE__INCLUDED_)
