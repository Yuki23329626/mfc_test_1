// VedioDialog.cpp : 實作檔
//

#include "stdafx.h"
#include "VedioDialog.h"
#include "afxdialogex.h"


// VedioDialog 對話方塊

IMPLEMENT_DYNAMIC(VedioDialog, CBkDialogST)

VedioDialog::VedioDialog(CWnd* pParent /*=NULL*/)
	: CBkDialogST(VedioDialog::IDD, pParent)
{

}

VedioDialog::~VedioDialog()
{
	lVol=1000;
}

void VedioDialog::DoDataExchange(CDataExchange* pDX)
{
	CBkDialogST::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_Bt1);
	DDX_Control(pDX, IDC_BUTTON2, m_Bt2);
	DDX_Control(pDX, IDC_BUTTON3, m_Bt3);
	DDX_Control(pDX, IDC_BUTTON4, m_Bt4);
	DDX_Control(pDX, IDC_STATIC1, c_Static);
	DDX_Control(pDX, IDC_SLIDER1, c_Slider);
	DDX_Slider(pDX, IDC_SLIDER1, m_Pos);
	DDX_Control(pDX, IDC_STATUS, c_Status);
}


BEGIN_MESSAGE_MAP(VedioDialog, CBkDialogST)
	ON_BN_CLICKED(IDC_BUTTON1, &VedioDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &VedioDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &VedioDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &VedioDialog::OnBnClickedButton4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, OnCustomdrawSlider1)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// VedioDialog 訊息處理常式


void VedioDialog::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	myPlayer.SetPosition(c_Slider.GetPos());
	lPos=myPlayer.GetPosition();
	if (iPlaying==PLAY)
		myPlayer.Play();
	
	*pResult = 0;
}
BOOL VedioDialog::OnInitDialog()
{
	CBkDialogST::OnInitDialog();
	CRect tabRect,itemRect;
	int nX, nY, nXc, nYc;
	GetClientRect(&tabRect);
	CBitmap tempbimat;
	BITMAP bitmap;
	tempbimat.LoadBitmap(IDB_BITMAP15);
	tempbimat.GetBitmap(&bitmap);
     SetWindowPos(&wndTop,tabRect.Width()/2,0,bitmap.bmWidth,bitmap.bmHeight, SWP_FRAMECHANGED   );
	 c_Static.SetWindowPos(&wndTop,74,(int)(bitmap.bmHeight/3+15),(int)(bitmap.bmWidth/1.35),(int)(bitmap.bmHeight/2.2), SWP_FRAMECHANGED   );

	 // TODO:  在此加入額外的初始化
//	CRect tabRect, itemRect;
//	GetClientRect(&tabRect);
////	ScreenToClient(tabRect);
//	ScreenToClient(itemRect);
//	//ClientToScreen(itemRect);
//
	 SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME),0);
	SetBitmap(IDB_BITMAP15,RGB(255, 255, 255));
	//SetBitmap(IDB_BITMAP15);
//	SetBitmap(IDB_SKY,RGB(255, 255, 255));
	//SetBitmap(IDB_BITMAP9);
    m_Bt1. GetClientRect(&itemRect);
	nX=itemRect.left;
	nY=itemRect.top;
	nXc=itemRect.right;
	nYc=(int)(itemRect.bottom*1.5);
	int by=bitmap.bmHeight-itemRect.Height()*2;
	int bx=tabRect.left-itemRect.Width()/2;
	m_Bt1. SetWindowPos(&wndTop,bx+itemRect.Width()+5,by,itemRect.Width(),itemRect.Height(), SWP_FRAMECHANGED   );
	m_Bt2. SetWindowPos(&wndTop,bx+itemRect.Width()*2+5,by,itemRect.Width(),itemRect.Height(), SWP_FRAMECHANGED   );
	m_Bt3. SetWindowPos(&wndTop,bx+itemRect.Width()*3+5,by,itemRect.Width(),itemRect.Height(), SWP_FRAMECHANGED   );
	m_Bt4. SetWindowPos(&wndTop,bx+itemRect.Width()*4+5,by,itemRect.Width(),itemRect.Height(), SWP_FRAMECHANGED   );
	m_Bt1.SetBitmaps(IDB_BITMAP16, RGB(255, 255, 255), (int)BTNST_AUTO_DARKER);
	m_Bt1.DrawTransparent();
	m_Bt2.SetBitmaps(IDB_BITMAP17, RGB(255, 255, 255), (int)BTNST_AUTO_DARKER);
	m_Bt2.DrawTransparent();
	m_Bt3.SetBitmaps(IDB_BITMAP18, RGB(255, 255, 255), (int)BTNST_AUTO_DARKER);
	m_Bt3.DrawTransparent();
	m_Bt4.SetBitmaps(IDB_BITMAP19, RGB(255, 255, 255), (int)BTNST_AUTO_DARKER);
	m_Bt4.DrawTransparent();
	
	myPlayer.SetParent(c_Static.GetSafeHwnd());
	//myPath="";
	// myPath=Vedio;
		myPlayer.SetPath(Vedio);
	myPlayer.Initialize();
	lVol=1000;
	myPlayer.SetVolume(lVol);
	//c_Volume.SetRange(0,1000,TRUE);
	//c_Volume.SetPos(lVol);
	int ss=myPlayer.GetLength();
	c_Slider.SetRange(0,myPlayer.GetLength());
	c_Slider.SetPos(0);
		SetTimer(ID_TIMER_POSITION,500,NULL);
	
	//myPlayer.SetPath("play.avi");
	//myPlayer.Initialize();
	//myPlayer.SetVolume(lVol);
	//myPlayer.c_Player=MCIWndCreate(this->GetSafeHwnd(),AfxGetInstanceHandle(), WS_CHILD | WS_VISIBLE|MCIWNDF_NOMENU,"play.avi");
	//myPlayer.lVolume=MCIWndGetVolume(myPlayer.c_Player);
	//	myPlayer.Play();	
		MDiPlay();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX 屬性頁應傳回 FALSE
}

void VedioDialog::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
            iPlaying=PLAY;
		myPlayer.Play();	
		//OnOK();
}


void VedioDialog::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	iPlaying=PAUSE;
		myPlayer.Pause();
}


void VedioDialog::OnBnClickedButton3()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	OnOK();
}

void VedioDialog::OnBnClickedButton4()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	OnViewFullscreen();
}
void VedioDialog::MDiPlay(void)
{
	 //    m_Video=NULL;
		//  m_Video = MCIWndCreate(this->GetSafeHwnd(),AfxGetInstanceHandle(), WS_CHILD | WS_VISIBLE|MCIWNDF_NOMENU,"play.avi");
	 ////   m_Video.GetWindowHandle()->ShowWindow(SW_MAXIMIZE); 
  //       MCIWndPlay(m_Video);
	    iPlaying=STOP;
		myPlayer.Stop();
		myPlayer.Close();
	   myPath=Vedio;
		//myPath=MediaFile.GetPathName();
		myPlayer.SetPath(myPath);
		myPlayer.Initialize();		
		myPlayer.SetPosition(0);
		//myPlayer.SetVolume(lVol);
		::ShowWindow(myPlayer.GetWindowHandle(),SW_MAXIMIZE); 	
		
		iPlaying=PAUSE;
		myPlayer.Pause();
		/*	iPlaying=PLAY;
		myPlayer.Play();*/
		
}


void VedioDialog::OnViewFullscreen(void)
{
	if (myPath=="")
		return;
	
	CWinApp* pApp;
	pApp=AfxGetApp();

	KillTimer(ID_TIMER_POSITION);
	dlgFullSize.sPath=myPlayer.GetPath();
	dlgFullSize.lPos=myPlayer.GetPosition();
	dlgFullSize.iPlaying=iPlaying;
	dlgFullSize.lVol=lVol;
	
	myPlayer.Stop();
	myPlayer.Kill();
	
	
	if (dlgFullSize.DoModal())
	{
		myPlayer.SetParent(c_Static.GetSafeHwnd());
		myPlayer.SetPath(myPath);
		myPlayer.Initialize();
		
		lPos=dlgFullSize.lPos;
		c_Slider.SetPos(dlgFullSize.lPos);
		
		lVol=dlgFullSize.lVol;
		//c_Volume.SetPos(dlgFullSize.lVol);		
		
		::ShowWindow(myPlayer.GetWindowHandle(),SW_MAXIMIZE); 	
		
		if (dlgFullSize.iPlaying==PLAY)
		{
			iPlaying=PLAY;
			myPlayer.Play();
			
			
		//	c_Play.EnableWindow(FALSE);
		//	c_Pause.EnableWindow(TRUE);
			//c_Stop.EnableWindow(TRUE);
		}
		else if (dlgFullSize.iPlaying==PAUSE)
		{
			iPlaying=PAUSE;
			myPlayer.Pause();
			
		//	c_Play.EnableWindow(TRUE);
		//	c_Pause.EnableWindow(FALSE);
		//	c_Stop.EnableWindow(TRUE);	
		}
		else
		{
			iPlaying=STOP;
			myPlayer.Stop();
			
		//	c_Play.EnableWindow(TRUE);
		///	c_Pause.EnableWindow(FALSE);
		//	c_Stop.EnableWindow(FALSE);
		}
		
	SetTimer(ID_TIMER_POSITION,750,NULL);
	}
}


void VedioDialog::OnPlaybackVolumeUp(void)
{
	myPlayer.IncreaseVolume();
//	c_Volume.SetPos(myPlayer.GetVolume());
	lVol=myPlayer.GetVolume();
}


void VedioDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	CWinApp* pApp;
	pApp=AfxGetApp();
	
	if (nIDEvent==ID_TIMER_POSITION)
	{
		lPos=myPlayer.GetPosition();
		
		m_Pos=lPos;
	//	c_Status.UpdateWindow();
	//	c_Status.Invalidate;
		UpdateData(FALSE);
//	   c_Status.Invalidate();
		
		if (lPos==myPlayer.GetLength())
		{
		//	if(rs.GetPlayRewind())
			//	myPlayer.SetPosition(0);
		//	if (rs.GetPlayLoop())
			//	myPlayer.Play();
		//	else
				iPlaying=STOP;
		}

		CString sStatus;
		int iMin,iHour,iSec,iMinT,iHourT,iSecT;
		long lLen;
		lLen=myPlayer.GetLength();

		iHourT=(int)(lLen/3600000);
		lLen=lLen-3600000*iHourT;
		iMinT=(int)(lLen/60000);
		lLen=lLen-60000*iMinT;
		iSecT=(int)(lLen/1000);

		lLen=lPos;
		iHour=(int)(lLen/3600000);
		lLen=lLen-3600000*iHour;
		iMin=(int)(lLen/60000);
		lLen=lLen-60000*iMin;
		iSec=(int)(lLen/1000);

		sStatus.Format("%2d:%2d:%2d of %2d:%2d:%2d",iHour,iMin,iSec,iHourT,iMinT,iSecT);
		c_Status.SetWindowText(sStatus);
	}

	CBkDialogST::OnTimer(nIDEvent);
}


HBRUSH VedioDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CBkDialogST::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此變更 DC 的任何屬性
	 if (pWnd->GetDlgCtrlID() == (IDC_STATUS))
 {
    
  pDC->SetBkMode(TRANSPARENT);
  pDC->SetTextColor(RGB(255,225,225));
 // c_Status.Invalidate();
 // c_Status.RedrawWindow();
//c_Status.InvalidateRect(NULL);
  // pDC->SelectStockObject(NULL_BRUSH   );
  return HBRUSH(CreateSolidBrush(RGB(128,64,0)));
   //return HBRUSH(GetStockObject(NULL_BRUSH));  
 }
	// TODO:  如果預設值並非想要的，則傳回不同的筆刷
	return hbr;
}
