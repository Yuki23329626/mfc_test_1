#pragma once


// Introduce ��ܤ��

class Introduce : public CDialogEx
{
	DECLARE_DYNAMIC(Introduce)

public:
	Introduce(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~Introduce();

// ��ܤ�����
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
//	virtual void PreInitDialog();
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
