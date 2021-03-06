// B16012117_BrowserDoc.cpp : implementation of the CB16012117_BrowserDoc class
//

#include "stdafx.h"
#include "B16012117_Browser.h"

#include "B16012117_BrowserDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserDoc

IMPLEMENT_DYNCREATE(CB16012117_BrowserDoc, CDocument)

BEGIN_MESSAGE_MAP(CB16012117_BrowserDoc, CDocument)
	//{{AFX_MSG_MAP(CB16012117_BrowserDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserDoc construction/destruction

CB16012117_BrowserDoc::CB16012117_BrowserDoc()
{
	// TODO: add one-time construction code here

}

CB16012117_BrowserDoc::~CB16012117_BrowserDoc()
{
}

BOOL CB16012117_BrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserDoc serialization

void CB16012117_BrowserDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserDoc diagnostics

#ifdef _DEBUG
void CB16012117_BrowserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CB16012117_BrowserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserDoc commands
