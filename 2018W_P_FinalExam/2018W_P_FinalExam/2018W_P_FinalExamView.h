
// 2018W_P_FinalExamView.h : CMy2018W_P_FinalExamView 類別的介面
//

#pragma once
#include "Introduce.h"
#include "BaseStruct.h" 
class CMy2018W_P_FinalExamView : public CView
{
protected: // 僅從序列化建立
	CMy2018W_P_FinalExamView();
	DECLARE_DYNCREATE(CMy2018W_P_FinalExamView)

// 屬性
public:
	CMy2018W_P_FinalExamDoc* GetDocument() const;
	 Introduce *IntroduceDlg;
// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 程式碼實作
public:
	virtual ~CMy2018W_P_FinalExamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	int CheckTime;
	afx_msg void OnDemo();
};

#ifndef _DEBUG  // 2018W_P_FinalExamView.cpp 中的偵錯版本
inline CMy2018W_P_FinalExamDoc* CMy2018W_P_FinalExamView::GetDocument() const
   { return reinterpret_cast<CMy2018W_P_FinalExamDoc*>(m_pDocument); }
#endif

