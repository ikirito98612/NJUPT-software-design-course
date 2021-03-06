// B16012117_TCP_S.h : main header file for the B16012117_TCP_S application
//

#if !defined(AFX_B16012117_TCP_S_H__B835551B_7169_42C5_B3D8_878C9D13670D__INCLUDED_)
#define AFX_B16012117_TCP_S_H__B835551B_7169_42C5_B3D8_878C9D13670D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CB16012117_TCP_SApp:
// See B16012117_TCP_S.cpp for the implementation of this class
//

class CB16012117_TCP_SApp : public CWinApp
{
public:
	CB16012117_TCP_SApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB16012117_TCP_SApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CB16012117_TCP_SApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B16012117_TCP_S_H__B835551B_7169_42C5_B3D8_878C9D13670D__INCLUDED_)
