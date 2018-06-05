
// 2018W_P_FinalExamView.cpp : CMy2018W_P_FinalExamView ���O����@
//

#include "stdafx.h"
// SHARED_HANDLERS �i�H�w�q�b��@�w���B�Y�ϩM�j�M�z�����B�z�`����
// ATL �M�פ��A�ä��\�P�ӱM�צ@�Τ��{���X�C
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

// CMy2018W_P_FinalExamView �غc/�Ѻc

CMy2018W_P_FinalExamView::CMy2018W_P_FinalExamView()
	: CheckTime(0)
{
	// TODO: �b���[�J�غc�{���X
	IntroduceDlg=new Introduce();

}

CMy2018W_P_FinalExamView::~CMy2018W_P_FinalExamView()
{
}

BOOL CMy2018W_P_FinalExamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �b���g�ѭק� CREATESTRUCT cs 
	// �F��ק�������O�μ˦����ت�

	return CView::PreCreateWindow(cs);
}

// CMy2018W_P_FinalExamView �yø

void CMy2018W_P_FinalExamView::OnDraw(CDC* /*pDC*/)
{
	CMy2018W_P_FinalExamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �b���[�J��͸�ƪ��yø�{���X
}


// CMy2018W_P_FinalExamView �E�_

#ifdef _DEBUG
void CMy2018W_P_FinalExamView::AssertValid() const
{
	CView::AssertValid();
}

void CMy2018W_P_FinalExamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2018W_P_FinalExamDoc* CMy2018W_P_FinalExamView::GetDocument() const // ���O�D��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2018W_P_FinalExamDoc)));
	return (CMy2018W_P_FinalExamDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy2018W_P_FinalExamView �T���B�z�`��


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
	  AfxMessageBox(" ��ú��ɶ�����@�p�ɡA�Х[�ָ}�B�`�N�ɶ� ! ");
	 AfxGetApp()->WriteProfileInt(_T("InitData"),_T("CheckTime"),checknum);
  }
	// TODO: �b���[�J�S�w���{���X�M (��) �I�s�����O
}


void CMy2018W_P_FinalExamView::OnDemo()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
	VedioDialog m_VedioDialog;
m_VedioDialog.DoModal();
}
