
// 2018W_P_FinalExamView.h : CMy2018W_P_FinalExamView ���O������
//

#pragma once
#include "Introduce.h"
#include "BaseStruct.h" 
class CMy2018W_P_FinalExamView : public CView
{
protected: // �ȱq�ǦC�ƫإ�
	CMy2018W_P_FinalExamView();
	DECLARE_DYNCREATE(CMy2018W_P_FinalExamView)

// �ݩ�
public:
	CMy2018W_P_FinalExamDoc* GetDocument() const;
	 Introduce *IntroduceDlg;
// �@�~
public:

// �мg
public:
	virtual void OnDraw(CDC* pDC);  // �мg�H�yø���˵�
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �{���X��@
public:
	virtual ~CMy2018W_P_FinalExamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	int CheckTime;
	afx_msg void OnDemo();
};

#ifndef _DEBUG  // 2018W_P_FinalExamView.cpp ������������
inline CMy2018W_P_FinalExamDoc* CMy2018W_P_FinalExamView::GetDocument() const
   { return reinterpret_cast<CMy2018W_P_FinalExamDoc*>(m_pDocument); }
#endif

