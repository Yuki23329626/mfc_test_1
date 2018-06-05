#pragma once
#include "stdafx.h"
#include "2018W_P_FinalExam.h"
#include "bs\bkdialogst.h"
#include "bs\BkDialogST.h"
#include "bs\BtnST.h"
#include "vfw.h"
#include "definition.h"
#include "easyplayer.h"
// VedioDialog 對話方塊
#define Vedio "play.wmv"
#include "FullMovie.h"	// Added by ClassView
#include "MySliderControl.h"
class VedioDialog : public CBkDialogST
{
	DECLARE_DYNAMIC(VedioDialog)

public:
	VedioDialog(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~VedioDialog();
	CEasyPlayer myPlayer;
	HWND m_Video;
		long lPos;
	int lVol;
		int iPlaying;
			CString myPath;
			CFullMovie dlgFullSize;
   CSliderCtrl	c_Slider;
	int		m_PlayPauseStop;
	int		m_Pos;
// 對話方塊資料
	enum { IDD = IDD_DIALOG_Vediio };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CButtonST m_Bt1;
	CButtonST m_Bt2;
	CButtonST m_Bt3;
	CButtonST m_Bt4;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	void MDiPlay(void);
	CStatic c_Static;
	void OnViewFullscreen(void);
	void OnPlaybackVolumeUp(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CStatic c_Status;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
