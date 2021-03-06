// B16012117_BrowserView.cpp : implementation of the CB16012117_BrowserView class
//

#include "stdafx.h"
#include "B16012117_Browser.h"
#include "MainFrm.h"
#include "B16012117_BrowserDoc.h"
#include "B16012117_BrowserView.h"

#include <wininet.h>
#include <UrlHist.h>
#include <Mshtml.h>
#include <COMDEF.H>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserView

IMPLEMENT_DYNCREATE(CB16012117_BrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CB16012117_BrowserView, CHtmlView)
	//{{AFX_MSG_MAP(CB16012117_BrowserView)
	ON_COMMAND(ID_BACK, OnBack)
	ON_COMMAND(ID_FORWARD, OnForward)
	ON_COMMAND(ID_HOME, OnHome)
	ON_COMMAND(ID_REFRESH, OnRefresh)
	ON_COMMAND(ID_STOP, OnStop)
	ON_COMMAND(ID_DelTemp, OnDelTemp)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserView construction/destruction

CB16012117_BrowserView::CB16012117_BrowserView()
{
	// TODO: add construction code here

}

CB16012117_BrowserView::~CB16012117_BrowserView()
{
}

BOOL CB16012117_BrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserView drawing

void CB16012117_BrowserView::OnDraw(CDC* pDC)
{
	CB16012117_BrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CB16012117_BrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
 
	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("http://www.baidu.com"),NULL,NULL);
	CHtmlView::SetSilent(TRUE);
}


/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserView printing


/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserView diagnostics

#ifdef _DEBUG
void CB16012117_BrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CB16012117_BrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CB16012117_BrowserDoc* CB16012117_BrowserView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CB16012117_BrowserDoc)));
	return (CB16012117_BrowserDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CB16012117_BrowserView message handlers

void CB16012117_BrowserView::OnBack() 
{
	// TODO: Add your command handler code here
	CB16012117_BrowserView::GoBack();
}

void CB16012117_BrowserView::OnForward() 
{
	// TODO: Add your command handler code here
	CB16012117_BrowserView::GoForward();
}

void CB16012117_BrowserView::OnHome() 
{
	// TODO: Add your command handler code here
	CB16012117_BrowserView::GoHome();

}

void CB16012117_BrowserView::OnRefresh() 
{
	// TODO: Add your command handler code here
	CB16012117_BrowserView::Refresh();
}

void CB16012117_BrowserView::OnStop() 
{
	// TODO: Add your command handler code here
	CB16012117_BrowserView::Stop();
}

void CB16012117_BrowserView::OnDocumentComplete(LPCTSTR lpszURL) 
{
	// TODO: Add your specialized code here and/or call the base class
	((CMainFrame*)GetParentFrame())->SetURL(lpszURL);
	GetDocument()->SetTitle(lpszURL);
	CHtmlView::OnDocumentComplete(lpszURL);
}








BOOL CB16012117_BrowserView::DeleteUrlCache(DEL_CACHE_TYPE type)
{
    BOOL bRet=FALSE;
	HANDLE hEntry;
	LPINTERNET_CACHE_ENTRY_INFO lpCacheEntry=NULL;   //Cache���ָ��
	DWORD dwEntrySize;
	dwEntrySize=0;
	hEntry=FindFirstUrlCacheEntry(NULL,NULL,&dwEntrySize); //�ҵ���һ��URL Cache���
	lpCacheEntry=(LPINTERNET_CACHE_ENTRY_INFO) new char[dwEntrySize];//����ռ�
	hEntry=FindFirstUrlCacheEntry(NULL,lpCacheEntry,&dwEntrySize);
	if (!hEntry)
	{
		goto cleanup;
	}
	do 
	{
		if (type==File&&!(lpCacheEntry->CacheEntryType&COOKIE_CACHE_ENTRY))
		{
			DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
		} 
		else if(type==Cookie&&(lpCacheEntry->CacheEntryType&COOKIE_CACHE_ENTRY))
		{
			DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
		}
		dwEntrySize=0;
		FindNextUrlCacheEntry(hEntry,NULL,&dwEntrySize);
		delete [] lpCacheEntry;
		lpCacheEntry=(LPINTERNET_CACHE_ENTRY_INFO) new char[dwEntrySize];
	} 
	while (FindNextUrlCacheEntry(hEntry,lpCacheEntry,&dwEntrySize));
	bRet=TRUE;
	cleanup:
	if (lpCacheEntry)
	{
		delete [] lpCacheEntry;
	}
	return bRet;
}

BOOL CB16012117_BrowserView::EmptyDirectory(LPCTSTR szPath, BOOL bDeleteDesktopIni, BOOL bWipeIndexDat)
{
	WIN32_FIND_DATA wfd;
	HANDLE hFind;        //�ļ����
	CString sFullPath;
	CString sFindFilter;
	DWORD dwAttributes = 0;
	sFindFilter = szPath;         //·����
	sFindFilter +=_T("\\*.*");    //��ʾ�����ļ���Ҫɾ��
    //�ҵ���һ���ļ�
	if((hFind=FindFirstFile(sFindFilter,&wfd))==INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	do
	{
		if(_tcscmp(wfd.cFileName,_T("."))==0||
			_tcscmp(wfd.cFileName,_T(".."))==0||
			(bDeleteDesktopIni==FALSE&&_tcscmp(wfd.cFileName,_T("desktop.ini"))==0))
		{
			continue;
		}
		sFullPath=szPath;
		sFullPath+=_T('\\');
		sFullPath+=wfd.cFileName;     //�ļ�������·��������
		//����ļ�����ֻ�����ԣ���ôӦ��ȥ����������ɾ��
		dwAttributes=GetFileAttributes(sFullPath);       //�õ��ļ�����
		if (dwAttributes&FILE_ATTRIBUTE_READONLY)        //�ж��Ƿ�ֻ��
		{
			dwAttributes&=~FILE_ATTRIBUTE_READONLY;      //ɾ��ֻ������
			SetFileAttributes(sFullPath,dwAttributes);   //����ɾ��
		}
		//�жϸ��ļ��Ƿ���һ��Ŀ¼�������Ŀ¼��ݹ���������Ŀ¼
		if (wfd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
		{
			EmptyDirectory(sFullPath,bDeleteDesktopIni,bWipeIndexDat);
			RemoveDirectory(sFullPath);
		} 
		else          //����һ���ļ�
		{
			DeleteFile(sFullPath);           //ɾ�����ļ�
		}
	}
	while(FindNextFile(hFind,&wfd));        //������һ���ļ�
	FindClose(hFind);                       //�ر��ļ����
	return TRUE;
}

void CB16012117_BrowserView::OnDelTemp()
{
	TCHAR szPath[MAX_PATH];
	DeleteUrlCache(File);   //ɾ��URL��Cache
	if (SHGetSpecialFolderPath(NULL,szPath,CSIDL_INTERNET_CACHE,FALSE))
	{   
		//�õ���ʱĿ¼�������
		EmptyDirectory(szPath,NULL,NULL);
	}
}

void CB16012117_BrowserView::OnNewWindow2(LPDISPATCH* ppDisp, BOOL* Cancel) 
{
	// TODO: Add your specialized code here and/or call the base class
	CComPtr<IHTMLDocument2> pHTMLDocument2;

    m_pBrowserApp->get_Document((IDispatch **)&pHTMLDocument2);
    if (pHTMLDocument2!=NULL)
	{
        CComPtr<IHTMLElement> pIHTMLElement;
        pHTMLDocument2->get_activeElement(&pIHTMLElement);

        if (pIHTMLElement!=NULL)
		{
             variant_t url;
             HRESULT hr=pIHTMLElement->getAttribute(L"href", 0, &url);
             if (SUCCEEDED(hr))
			 {
                hr=m_pBrowserApp->Navigate2(&url, NULL, NULL, NULL, NULL);

                url.Clear();

                if (SUCCEEDED(hr))
				{
                     *Cancel=TRUE;
				}
			 }
		} 
	}	
	CHtmlView::OnNewWindow2(ppDisp, Cancel);
}


