// B16012117_BrowserView.h : interface of the CB16012117_BrowserView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_B16012117_BROWSERVIEW_H__B608FE30_788C_4DCC_AF82_4B7574DC3386__INCLUDED_)
#define AFX_B16012117_BROWSERVIEW_H__B608FE30_788C_4DCC_AF82_4B7574DC3386__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "B16012117_BrowserDoc.h"


class CB16012117_BrowserView : public CHtmlView
{
protected: // create from serialization only
	CB16012117_BrowserView();
	DECLARE_DYNCREATE(CB16012117_BrowserView)

// Attributes
public:
	CB16012117_BrowserDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_BrowserView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnDocumentComplete(LPCTSTR lpszURL);
	virtual void OnNewWindow2(LPDISPATCH* ppDisp, BOOL* Cancel);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL EmptyDirectory(LPCTSTR szPath,BOOL bDeleteDesktopIni,BOOL bWipeIndexDat);
	
	enum DEL_CACHE_TYPE
	{
		File,    //表示Internet临时文件
		Cookie   //表示Cookie
	};
	BOOL DeleteUrlCache(DEL_CACHE_TYPE type);
	virtual ~CB16012117_BrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CB16012117_BrowserView)
	afx_msg void OnBack();
	afx_msg void OnForward();
	afx_msg void OnHome();
	afx_msg void OnRefresh();
	afx_msg void OnStop();
	afx_msg void OnDelTemp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in B16012117_BrowserView.cpp
inline CB16012117_BrowserDoc* CB16012117_BrowserView::GetDocument()
   { return (CB16012117_BrowserDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_BROWSERVIEW_H__B608FE30_788C_4DCC_AF82_4B7574DC3386__INCLUDED_)
