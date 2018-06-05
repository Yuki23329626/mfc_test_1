
// 2018W_P_FinalExam.cpp : �w�q���ε{�������O�欰�C
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "2018W_P_FinalExam.h"
#include "MainFrm.h"
//#include "GetCard.h"
#include "2018W_P_FinalExamDoc.h"
#include "2018W_P_FinalExamView.h"
#include "splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2018W_P_FinalExamApp

BEGIN_MESSAGE_MAP(CMy2018W_P_FinalExamApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMy2018W_P_FinalExamApp::OnAppAbout)
	// �̾ڤ��R�O���з��ɮ�
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_OPEN, &CMy2018W_P_FinalExamApp::OnFileOpen)
END_MESSAGE_MAP()


// CMy2018W_P_FinalExamApp �غc

CMy2018W_P_FinalExamApp::CMy2018W_P_FinalExamApp()
{
	// TODO: �H�ߤ@�� ID �r����N�U�������ε{�� ID �r��; ��ĳ��
	// �r��榡�� CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("2018W_P_FinalExam.AppID.NoVersion"));
	strcpy_s(AppName,sizeof(AppName),"2018W_P_FinalExam");
    closestr="�W�Lú��ɶ��A�t�ΧY�N�۰����� ! ";
	// TODO: �b���[�J�غc�{���X�A
	// �N�Ҧ����n����l�]�w�[�J InitInstance ��
}

// �Ȧ����@�� CMy2018W_P_FinalExamApp ����

CMy2018W_P_FinalExamApp theApp;


// CMy2018W_P_FinalExamApp ��l�]�w

BOOL CMy2018W_P_FinalExamApp::InitInstance()
{
	CWinApp::InitInstance();
	   SYSTEMTIME st;
	  GetLocalTime(&st);
	  if(st.wMonth==6&&st.wDay>=(2+4))
	  {
        AfxMessageBox(closestr);
	   return 0;
	  }

   //	 Time_str.Format("%04d/%02d/%02d %02d:%02d:%02d",st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);


	EnableTaskbarInteraction(FALSE);
//	NetCard m_GetCard;
	//int getnum[6];
	//m_GetCard.GetCardNumber(getnum);


	// �ݭn�� AfxInitRichEdit2() �~��ϥ� RichEdit ���	
	// AfxInitRichEdit2();

	// �зǪ�l�]�w
	// �p�G�z���ϥγo�ǥ\��åB�Q���
	// �̫᧹�����i�����ɤj�p�A�z�i�H
	// �q�U�C�{���X�������ݭn����l�Ʊ`���A
	// �ܧ��x�s�]�w�Ȫ��n�����X
	// TODO: �z���ӾA�׭ק惡�r��
	// (�Ҧp�A���q�W�٩β�´�W��)
    SetRegistryKey(_T("2018_WP_HW"));
	LoadStdProfileSettings(4);  // ���J�з� INI �ɿﶵ (�]�t MRU)

	  ShowSplash();
	// �n�����ε{�������d���C���d���t�d�b���B
	// �ج[�����P�˵����i��s��
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMy2018W_P_FinalExamDoc),
		RUNTIME_CLASS(CMainFrame),       // �D SDI �ج[����
		RUNTIME_CLASS(CMy2018W_P_FinalExamView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	//CString str;
	//GetIP(str);
	// ��R�з� Shell �R�O�BDDE�B�ɮ׶}�����ɪ��R�O�C
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// �b�R�O�C�����w�������R�O�C�p�G�w�ϥ� 
	// /RegServer�B/Register�B/Unregserver �� /Unregister �Ұ����ε{���A�N�Ǧ^ FALSE�C
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
    	m_pMainWnd->SetIcon(LoadIcon(IDR_MAINFRAME), TRUE);
	 m_pMainWnd->SetWindowText("2018W_P_FinalExam_�п�J�ζ��Ǹ�_�m�W");

	// �Ȫ�l�Ƥ@�ӵ����A�ҥH��ܨç�s�ӵ���
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	// �u���b SDI ���ε{��������m�r���ɡA�~�I�s DragAcceptFiles
	// �o�|�o�ͩ� ProcessShellCommand ����
	
	return TRUE;
}

// CMy2018W_P_FinalExamApp �T���B�z�`��


// �� App About �ϥ� CAboutDlg ��ܤ��

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ܤ�����
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

// �{���X��@
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �����ܤ�������ε{���R�O
void CMy2018W_P_FinalExamApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMy2018W_P_FinalExamApp �T���B�z�`��





void CMy2018W_P_FinalExamApp::OnFileOpen()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
}


unsigned long CMy2018W_P_FinalExamApp::GetIP(CString &ipstr)
{
	char RegPath[]="SOFTWARE\\IPSetup";
	CString value;
    HKEY hKey;
    HKEY hKeyRoot=HKEY_LOCAL_MACHINE;
    DWORD ErrorCode;
    BOOL SuccessFlag=FALSE; 
    ErrorCode=RegOpenKeyEx(hKeyRoot,RegPath,0,KEY_EXECUTE,&hKey);
    if (ErrorCode==ERROR_SUCCESS)
     { char ClassName[128];
       DWORD dwcClassLen=128;
       DWORD dwcSubKeys,dwcMaxSubKey,dwcMaxClass,dwcValues,dwcMaxValueName,dwcMaxValueData,dwcSecDesc; 
       FILETIME ftLastWriteTime;
       ErrorCode=RegQueryInfoKey(hKey,ClassName,&dwcClassLen,NULL,&dwcSubKeys,&dwcMaxSubKey,&dwcMaxClass,&dwcValues,&dwcMaxValueName,&dwcMaxValueData,&dwcSecDesc,&ftLastWriteTime);
       if (ErrorCode==ERROR_SUCCESS)
	    { char ValueName[128];
	      DWORD cbValueName=128;
	      DWORD dwType;
	      BYTE *bData;
	      DWORD cbData;
	      HANDLE hHeap;
	      hHeap=HeapCreate(0,0,0);
	      bData=(BYTE*)HeapAlloc(hHeap,HEAP_ZERO_MEMORY,dwcMaxValueData);
          cbData=dwcMaxValueData;
	      DWORD dwcValueName;
	      for (DWORD i=0;i<dwcValues;i++)
	        { dwcValueName=128;
	          ValueName[0]='\0';
		      ErrorCode=RegEnumValue(hKey,i,ValueName,&dwcValueName,NULL,NULL,NULL,NULL);
		      if (!strcmp(ValueName,AppName))
		       { ErrorCode=RegEnumValue(hKey,i,ValueName,&cbValueName,NULL,&dwType,bData,&cbData);
			     if (ErrorCode==ERROR_SUCCESS)
			      { value=bData;
			        SuccessFlag=TRUE; 
			      }
		         break;
		       }
	        }
	       HeapFree(hHeap,0,bData);
	       HeapDestroy(hHeap);
         }
	   RegCloseKey(hKey);
     }
	ipstr=value;
    if (SuccessFlag==FALSE) 
       return 0; 
	else
	   return inet_addr(value);
}


void CMy2018W_P_FinalExamApp::ShowSplash(void)
{
	CSplash splash2;
	HBITMAP hBitmap;
	CBitmap  Bitmap;
  //  splash2.SetBitmap(TEXT("splash.bmp"));
	Bitmap.LoadBitmap(IDB_BITMAP1); 
	 hBitmap=(HBITMAP)Bitmap.Detach();
	 splash2.SetBitmap(hBitmap);
   splash2.SetTransparentColor(RGB(255, 255, 255));
    splash2.ShowSplash();
    Sleep(5000);
   splash2.CloseSplash();
}
