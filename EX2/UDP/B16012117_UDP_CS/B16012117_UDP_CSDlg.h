// B16012117_UDP_CSDlg.h : header file
//

#if !defined(AFX_B16012117_UDP_CSDLG_H__0D595864_5F8F_42B9_980F_84C4C034B6D4__INCLUDED_)
#define AFX_B16012117_UDP_CSDLG_H__0D595864_5F8F_42B9_980F_84C4C034B6D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CB16012117_UDP_CSDlg dialog

class CB16012117_UDP_CSDlg : public CDialog
{
// Construction
public:
	CB16012117_UDP_CSDlg(CWnd* pParent = NULL);	// standard constructor
	UINT	m_sport;
	UINT	m_dport;

// Dialog Data
	//{{AFX_DATA(CB16012117_UDP_CSDlg)
	enum { IDD = IDD_B16012117_UDP_CS_DIALOG };
	CButton	m_Exit;
	CListBox	list;
	CButton	m_Send;
	CEdit	m_EditWords;
	CEdit	PortDest;
	CIPAddressCtrl	IPDest;
	CButton	m_Stop;
	CButton	m_Start;
	CEdit	PortLocal;
	CIPAddressCtrl	IPLocal;
	CString	LocalPort;
	CString	DestPort;
	CString	str;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_UDP_CSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	LRESULT OnReadClose(WPARAM wParam,LPARAM lParam);
    public:
	SOCKET Client;                          //客户的连接请求
	SOCKET ServerSocket;                    //SOCKET 
	SOCKADDR_IN m_sockServerAddr;           //SOCKET 结构
	SOCKADDR_IN m_sockAddrto;               //SOCKET 结构

	int socklen;

	BOOL IsTrue;

	Msg msg;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CB16012117_UDP_CSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnStop();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_UDP_CSDLG_H__0D595864_5F8F_42B9_980F_84C4C034B6D4__INCLUDED_)
