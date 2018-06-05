
// 2018W_P_FinalExam.h : 2018W_P_FinalExam 應用程式的主標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// CMy2018W_P_FinalExamApp:
// 請參閱實作此類別的 2018W_P_FinalExam.cpp
//

class CMy2018W_P_FinalExamApp : public CWinApp
{
public:
	CMy2018W_P_FinalExamApp();
	CString closestr;

// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnFileOpen();
	unsigned long GetIP(CString &ipstr);
	char AppName[200];
	void ShowSplash(void);
};

extern CMy2018W_P_FinalExamApp theApp;
