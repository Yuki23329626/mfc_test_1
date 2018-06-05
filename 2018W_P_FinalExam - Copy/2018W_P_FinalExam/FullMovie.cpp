// FullMovie.cpp : implementation file
//

#include "stdafx.h"
#include "2018W_P_FinalExam.h"
#include "FullMovie.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFullMovie dialog


CFullMovie::CFullMovie(CWnd* pParent /*=NULL*/)
: CDialog(CFullMovie::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFullMovie)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFullMovie::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFullMovie)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFullMovie, CDialog)
//{{AFX_MSG_MAP(CFullMovie)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullMovie message handlers

BOOL CFullMovie::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	int cx, cy; 
	HDC dc = ::GetDC(NULL); 
	cx = GetDeviceCaps(dc,HORZRES) + 
		GetSystemMetrics(SM_CXBORDER); 
	cy = GetDeviceCaps(dc,VERTRES) +
		GetSystemMetrics(SM_CYBORDER); 
	::ReleaseDC(0,dc); 
	
	SetWindowLong(m_hWnd, GWL_STYLE, 
		GetWindowLong(m_hWnd, GWL_STYLE) & 
		(~(WS_CAPTION | WS_BORDER))); 
	
	::SetWindowPos(m_hWnd, HWND_TOPMOST, 
		-(GetSystemMetrics(SM_CXBORDER)+1), 
		-(GetSystemMetrics(SM_CYBORDER)+1), 
		cx+1,cy+1, SWP_NOZORDER); 
	
	ep.SetParent(m_hWnd);
	ep.SetPath(sPath);
	ep.Initialize();
	ep.Play();
	ep.SetPosition(lPos);
	ep.SetVolume(lVol);
	ep.Pause();

	::ShowWindow(ep.GetWindowHandle(),SW_MAXIMIZE); 	
	
	if (iPlaying==PLAY)
		ep.Play();

	SetTimer(ID_TIMER_POSITION,500,NULL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CFullMovie::OnTimer(UINT nIDEvent) 
{
	lPos=ep.GetPosition();
	lVol=ep.GetVolume();
	
	//if (lPos==ep.GetLength())
	//{
	////	if(rs.GetPlayRewind())
	////		ep.SetPosition(0);
	////	if (rs.GetPlayLoop())
	///		ep.Play();
	//	else
	//		iPlaying=STOP;
	//}
	
	CDialog::OnTimer(nIDEvent);
}

BOOL CFullMovie::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN)
	{
		if (pMsg->wParam==VK_SPACE)
		{
			if (iPlaying==PLAY)
			{
				ep.Pause();
				iPlaying=PAUSE;
			}
			else
			{
				ep.Play();
				iPlaying=PLAY;
			}
		}
		else if (pMsg->wParam==VK_ESCAPE)
		{
			iPlaying=PAUSE;
			OnOK();
		}
		else if (pMsg->wParam==VK_UP)
		{
			ep.IncreaseVolume();
			lVol=ep.GetVolume();
		}
		else if (pMsg->wParam==VK_DOWN)
		{
			ep.DecreaseVolume();
			lVol=ep.GetVolume();
		}
		if (pMsg->wParam==VK_LEFT)
		{
			ep.Rwd();
			if (iPlaying==PLAY)
				ep.Play();
			lPos=ep.GetPosition();
		}
		if (pMsg->wParam==VK_RIGHT)
		{
			ep.Fwd();
			if (iPlaying==PLAY)
				ep.Play();
			lPos=ep.GetPosition();
		}
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CFullMovie::OnOK() 
{
	ep.Pause();
	lPos=ep.GetPosition();
	lVol=ep.GetVolume();

//	KillTimer(ID_TIMER_POSITION);
	
	CDialog::OnOK();
}
