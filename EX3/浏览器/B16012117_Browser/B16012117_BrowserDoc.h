// B16012117_BrowserDoc.h : interface of the CB16012117_BrowserDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_B16012117_BROWSERDOC_H__5E9BD067_86DC_4AF1_BB7A_8EA251DA7533__INCLUDED_)
#define AFX_B16012117_BROWSERDOC_H__5E9BD067_86DC_4AF1_BB7A_8EA251DA7533__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CB16012117_BrowserDoc : public CDocument
{
protected: // create from serialization only
	CB16012117_BrowserDoc();
	DECLARE_DYNCREATE(CB16012117_BrowserDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_BrowserDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CB16012117_BrowserDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CB16012117_BrowserDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_BROWSERDOC_H__5E9BD067_86DC_4AF1_BB7A_8EA251DA7533__INCLUDED_)
