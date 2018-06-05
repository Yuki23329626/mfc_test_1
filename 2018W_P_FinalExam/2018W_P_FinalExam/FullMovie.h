 #if !defined(AFX_FULLMOVIE_H__E5CBAC7B_9650_4439_80C3_4F8341C8EB19__INCLUDED_)
#define AFX_FULLMOVIE_H__E5CBAC7B_9650_4439_80C3_4F8341C8EB19__INCLUDED_

#include "easyplayer.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FullMovie.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFullMovie dialog

class CFullMovie : public CDialog
{
// Construction
public:

	int lVol;
	int iPlaying;
	CString sPath;
	long lPos;
	CFullMovie(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFullMovie)
	enum { IDD = IDD_DIALOGFullMovie };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullMovie)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CEasyPlayer ep;
	// Generated message map functions
	//{{AFX_MSG(CFullMovie)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLMOVIE_H__E5CBAC7B_9650_4439_80C3_4F8341C8EB19__INCLUDED_)
