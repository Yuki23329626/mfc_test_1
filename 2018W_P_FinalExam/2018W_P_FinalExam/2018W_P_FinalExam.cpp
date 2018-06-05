
// 2018W_P_FinalExam.cpp : 定義應用程式的類別行為。
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
	// 依據文件命令的標準檔案
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_OPEN, &CMy2018W_P_FinalExamApp::OnFileOpen)
END_MESSAGE_MAP()


// CMy2018W_P_FinalExamApp 建構

CMy2018W_P_FinalExamApp::CMy2018W_P_FinalExamApp()
{
	// TODO: 以唯一的 ID 字串取代下面的應用程式 ID 字串; 建議的
	// 字串格式為 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("2018W_P_FinalExam.AppID.NoVersion"));
	strcpy_s(AppName,sizeof(AppName),"2018W_P_FinalExam");
    closestr="超過繳交時間，系統即將自動關閉 ! ";
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}

// 僅有的一個 CMy2018W_P_FinalExamApp 物件

CMy2018W_P_FinalExamApp theApp;


// CMy2018W_P_FinalExamApp 初始設定

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


	// 需要有 AfxInitRichEdit2() 才能使用 RichEdit 控制項	
	// AfxInitRichEdit2();

	// 標準初始設定
	// 如果您不使用這些功能並且想減少
	// 最後完成的可執行檔大小，您可以
	// 從下列程式碼移除不需要的初始化常式，
	// 變更儲存設定值的登錄機碼
	// TODO: 您應該適度修改此字串
	// (例如，公司名稱或組織名稱)
    SetRegistryKey(_T("2018_WP_HW"));
	LoadStdProfileSettings(4);  // 載入標準 INI 檔選項 (包含 MRU)

	  ShowSplash();
	// 登錄應用程式的文件範本。文件範本負責在文件、
	// 框架視窗與檢視間進行連接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMy2018W_P_FinalExamDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架視窗
		RUNTIME_CLASS(CMy2018W_P_FinalExamView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	//CString str;
	//GetIP(str);
	// 剖析標準 Shell 命令、DDE、檔案開啟舊檔的命令列
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// 在命令列中指定的分派命令。如果已使用 
	// /RegServer、/Register、/Unregserver 或 /Unregister 啟動應用程式，將傳回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
    	m_pMainWnd->SetIcon(LoadIcon(IDR_MAINFRAME), TRUE);
	 m_pMainWnd->SetWindowText("2018W_P_FinalExam_請輸入團隊學號_姓名");

	// 僅初始化一個視窗，所以顯示並更新該視窗
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	// 只有在 SDI 應用程式中有後置字元時，才呼叫 DragAcceptFiles
	// 這會發生於 ProcessShellCommand 之後
	
	return TRUE;
}

// CMy2018W_P_FinalExamApp 訊息處理常式


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
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

// 執行對話方塊的應用程式命令
void CMy2018W_P_FinalExamApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMy2018W_P_FinalExamApp 訊息處理常式





void CMy2018W_P_FinalExamApp::OnFileOpen()
{
	// TODO: 在此加入您的命令處理常式程式碼
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
