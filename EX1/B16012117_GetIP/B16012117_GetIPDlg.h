// B16012117_GetIPDlg.h : header file
//

#if !defined(AFX_B16012117_GETIPDLG_H__AD70FFF4_62C4_4E8D_AEC8_5482CD23DC23__INCLUDED_)
#define AFX_B16012117_GETIPDLG_H__AD70FFF4_62C4_4E8D_AEC8_5482CD23DC23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CB16012117_GetIPDlg dialog

class CB16012117_GetIPDlg : public CDialog
{
// Construction
public:
	CB16012117_GetIPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CB16012117_GetIPDlg)
	enum { IDD = IDD_B16012117_GETIP_DIALOG };
	CString	m_DNS;
	CString	m_Gateway;
	CString	m_HostName;
	CString	m_IPaddress;
	CString	m_MAC;
	CString	m_SubnetMask;
	CString	m_DNS2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_GetIPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	int StartUp();
	int CleanUp();
	int GetHostName(CString& sHostName);
	int GetIPAddress(const CString& sHostName, CString& sIPAddress);
	void GetGateWay_SubNet();
	void Get_DNS();

	// Generated message map functions
	//{{AFX_MSG(CB16012117_GetIPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTON1GetIP();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_GETIPDLG_H__AD70FFF4_62C4_4E8D_AEC8_5482CD23DC23__INCLUDED_)
