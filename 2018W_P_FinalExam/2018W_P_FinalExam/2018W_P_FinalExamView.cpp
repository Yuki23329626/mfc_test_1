
// 2018W_P_FinalExamView.cpp : CMy2018W_P_FinalExamView 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "2018W_P_FinalExam.h"
#endif

#include "2018W_P_FinalExamDoc.h"
#include "2018W_P_FinalExamView.h"
#include "VedioDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2018W_P_FinalExamView

IMPLEMENT_DYNCREATE(CMy2018W_P_FinalExamView, CView)

BEGIN_MESSAGE_MAP(CMy2018W_P_FinalExamView, CView)
	ON_COMMAND(ID_DEMO, &CMy2018W_P_FinalExamView::OnDemo)
END_MESSAGE_MAP()

// CMy2018W_P_FinalExamView 建構/解構

CMy2018W_P_FinalExamView::CMy2018W_P_FinalExamView()
	: CheckTime(0)
{
	// TODO: 在此加入建構程式碼
	IntroduceDlg=new Introduce();

}

CMy2018W_P_FinalExamView::~CMy2018W_P_FinalExamView()
{
}

BOOL CMy2018W_P_FinalExamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CMy2018W_P_FinalExamView 描繪

void CMy2018W_P_FinalExamView::OnDraw(CDC* /*pDC*/)
{
	CMy2018W_P_FinalExamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼
}


// CMy2018W_P_FinalExamView 診斷

#ifdef _DEBUG
void CMy2018W_P_FinalExamView::AssertValid() const
{
	CView::AssertValid();
}

void CMy2018W_P_FinalExamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2018W_P_FinalExamDoc* CMy2018W_P_FinalExamView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2018W_P_FinalExamDoc)));
	return (CMy2018W_P_FinalExamDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy2018W_P_FinalExamView 訊息處理常式


void CMy2018W_P_FinalExamView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SYSTEMTIME st;
	int starttime; 
	  GetLocalTime(&st);
     CString Time_str;     
   //	 Time_str.Format("%04d/%02d/%02d %02d:%02d:%02d",st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
	    starttime=st.wHour;
		IntroduceDlg->Create(IDD_DIALOG1,this);
	 int check;	
	 int checknum=2017;
	  check=AfxGetApp()->GetProfileInt(_T("InitData"),_T("Start Check"),0);
	  CheckTime=AfxGetApp()->GetProfileInt(_T("InitData"),_T("CheckTime"),0);
	  if(check!=checknum)
	  {
	    AfxGetApp()->WriteProfileInt(_T("InitData"),_T("Start Check"),checknum);
	    AfxGetApp()->WriteProfileInt(_T("InitData"),_T("Start Time"),starttime);
		IntroduceDlg->ShowWindow(1);
	  }
	  if(st.wDay==5&&st.wHour>22&&CheckTime!=checknum)
	  {
	  AfxMessageBox(" 離繳交時間不到一小時，請加快腳步注意時間 ! ");
	 AfxGetApp()->WriteProfileInt(_T("InitData"),_T("CheckTime"),checknum);
  }
	// TODO: 在此加入特定的程式碼和 (或) 呼叫基底類別
}


void CMy2018W_P_FinalExamView::OnDemo()
{
	// TODO: 在此加入您的命令處理常式程式碼
	VedioDialog m_VedioDialog;
m_VedioDialog.DoModal();
}
