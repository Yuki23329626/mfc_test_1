
// 2018W_P_FinalExam.h : 2018W_P_FinalExam ���ε{�����D���Y��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"       // �D�n�Ÿ�


// CMy2018W_P_FinalExamApp:
// �аѾ\��@�����O�� 2018W_P_FinalExam.cpp
//

class CMy2018W_P_FinalExamApp : public CWinApp
{
public:
	CMy2018W_P_FinalExamApp();
	CString closestr;

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnFileOpen();
	unsigned long GetIP(CString &ipstr);
	char AppName[200];
	void ShowSplash(void);
};

extern CMy2018W_P_FinalExamApp theApp;
