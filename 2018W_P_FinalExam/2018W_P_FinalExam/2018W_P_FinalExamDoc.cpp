
// 2018W_P_FinalExamDoc.cpp : CMy2018W_P_FinalExamDoc ���O����@
//

#include "stdafx.h"
// SHARED_HANDLERS �i�H�w�q�b��@�w���B�Y�ϩM�j�M�z�����B�z�`����
// ATL �M�פ��A�ä��\�P�ӱM�צ@�Τ��{���X�C
#ifndef SHARED_HANDLERS
#include "2018W_P_FinalExam.h"
#endif

#include "2018W_P_FinalExamDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy2018W_P_FinalExamDoc

IMPLEMENT_DYNCREATE(CMy2018W_P_FinalExamDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy2018W_P_FinalExamDoc, CDocument)
END_MESSAGE_MAP()


// CMy2018W_P_FinalExamDoc �غc/�Ѻc

CMy2018W_P_FinalExamDoc::CMy2018W_P_FinalExamDoc()
{
	// TODO: �b���[�J�@���غc�{���X


}

CMy2018W_P_FinalExamDoc::~CMy2018W_P_FinalExamDoc()
{
	
}

BOOL CMy2018W_P_FinalExamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// TODO: �b���[�J���s��l�Ƶ{���X
	// (SDI ���|���Φ����)


	return TRUE;
}




// CMy2018W_P_FinalExamDoc �ǦC��

void CMy2018W_P_FinalExamDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �b���[�J�x�s�{���X
	}
	else
	{
		// TODO: �b���[�J���J�{���X
		//ar.getpath
		int c=9;
	}
}

#ifdef SHARED_HANDLERS

// �Y�Ϫ��䴩
void CMy2018W_P_FinalExamDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �ק�o�q�{���X�Hø�s��󪺸��
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �j�M�B�z�`�����䴩
void CMy2018W_P_FinalExamDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// �]�w�Ӧۤ���ƪ��j�M���e�C
	// ���e�������ӥH ";" �j�}

	// �d��:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy2018W_P_FinalExamDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy2018W_P_FinalExamDoc �E�_

#ifdef _DEBUG
void CMy2018W_P_FinalExamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy2018W_P_FinalExamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy2018W_P_FinalExamDoc �R�O


BOOL CMy2018W_P_FinalExamDoc::CanCloseFrame(CFrameWnd* pFrame)
{
	// TODO: �b���[�J�S�w���{���X�M (��) �I�s�����O
	int val;
	val=AfxMessageBox("Close Windows ? Yes or NO.", MB_YESNO|MB_ICONSTOP);
	if(val!=IDYES)
	  return 0; 
	return CDocument::CanCloseFrame(pFrame);
}
