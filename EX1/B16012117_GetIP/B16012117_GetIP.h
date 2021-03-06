// B16012117_GetIP.h : main header file for the B16012117_GETIP application
//

#if !defined(AFX_B16012117_GETIP_H__5197D598_8308_4FA6_A454_63668452E192__INCLUDED_)
#define AFX_B16012117_GETIP_H__5197D598_8308_4FA6_A454_63668452E192__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CB16012117_GetIPApp:
// See B16012117_GetIP.cpp for the implementation of this class
//

class CB16012117_GetIPApp : public CWinApp
{
public:
	CB16012117_GetIPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_GetIPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CB16012117_GetIPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_GETIP_H__5197D598_8308_4FA6_A454_63668452E192__INCLUDED_)
