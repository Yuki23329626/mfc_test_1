// Introduce.cpp : 實作檔
//

#include "stdafx.h"
#include "2018W_P_FinalExam.h"
#include "Introduce.h"
#include "afxdialogex.h"


// Introduce 對話方塊

IMPLEMENT_DYNAMIC(Introduce, CDialogEx)

Introduce::Introduce(CWnd* pParent /*=NULL*/)
	: CDialogEx(Introduce::IDD, pParent)
{

}

Introduce::~Introduce()
{
}

void Introduce::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Introduce, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Introduce 訊息處理常式


//void Introduce::PreInitDialog()
//{
//	// TODO: 在此加入特定的程式碼和 (或) 呼叫基底類別
//
//	CDialogEx::PreInitDialog();
//}


BOOL Introduce::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	COLORREF color=RGB(255, 230, 190);
	//m_clrBkGround = COLORREF(RGB(255, 230, 190));
	CString introducestr;
   introducestr="首先，先歡迎同學參與本次視窗程式學期上機測驗，本次測驗有幾個注意事項請同學仔細閱讀:\r\n";
	introducestr+="(1)注意事項說明只有程式第一次開啟使會起動，請同學務必仔細閱讀後才可將其關閉。\r\n";
	introducestr+="(2)關於考試題目說明請點選系統工具列_說明_。\r\n";
	introducestr+="(3)本次系統考試時間6/4 24:00~6/5 24:00，時間到之前起務必上傳您的測驗程式和相關要求資料，超過時間程式有可能無法執行。\r\n";
	introducestr+="(4)考試分組與作業相同，考試期間只可使用一台電腦，除非電腦有問題，則不可以隨意換。\r\n";
	introducestr+="(5)考試期間除不可與非組員討論與對傳資料和上述要求外，其餘皆可。\r\n";
	introducestr+="(6)本次考試為本學期唯一的考試，同學務必把握。\r\n";
	introducestr+="(7)考試期間如果和任何問題可以打電話給老師，電話:0978269622。\r\n\r\n";
	introducestr+="                     最後祝同學考試順利!!!。\r\n";
   // TODO:  在此加入額外的初始化
	CFont * f; 
     f = new CFont; 
     f->CreateFont(22, // nHeight 
     0, // nWidth 
     0, // nEscapement 
     0, // nOrientation 
     FW_BOLD, // nWeight 
     FALSE, // bItalic 
     FALSE, // bUnderline 
     0, // cStrikeOut 
     ANSI_CHARSET, // nCharSet 
     OUT_DEFAULT_PRECIS, // nOutPrecision 
     CLIP_DEFAULT_PRECIS, // nClipPrecision 
     DEFAULT_QUALITY, // nQuality 
     DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
     _T("Arial")); // lpszFac 
   
     GetDlgItem(IDC_EDIT1)->SetFont(f); 
	 GetDlgItem(IDC_STATICtitle)->SetFont(f); 
	// GetDlgItem(IDC_STATICtitle)->SetTextColor(color);
	GetDlgItem(IDC_EDIT1)->SetWindowTextA(introducestr); 
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX 屬性頁應傳回 FALSE
}


HBRUSH Introduce::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此變更 DC 的任何屬性
	  if (pWnd->GetDlgCtrlID() == IDC_STATICtitle)
     {
		 		  
          pDC->SetBkColor(RGB(0,255,0));//背景色为绿色
     //    pDC->SelectObject(&Wordfont);//文字为15号字体，华文行楷
         pDC->SetTextColor(RGB(0, 0, 250));
     }
	// TODO:  如果預設值並非想要的，則傳回不同的筆刷
	return hbr;
}
