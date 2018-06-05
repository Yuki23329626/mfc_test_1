#pragma once


// Introduce 對話方塊

class Introduce : public CDialogEx
{
	DECLARE_DYNAMIC(Introduce)

public:
	Introduce(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~Introduce();

// 對話方塊資料
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
//	virtual void PreInitDialog();
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
