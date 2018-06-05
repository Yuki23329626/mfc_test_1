#if !defined(AFX_NETCARDNO_H__310CDEAA_0876_4697_8116_189FEBAE24C8__INCLUDED_)
#define AFX_NETCARDNO_H__310CDEAA_0876_4697_8116_189FEBAE24C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NetCardNO.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNetCardNO window

class CNetCardNO : public CWnd
{
// Construction
public:
   CNetCardNO();
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetCardNO)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL GetCardNumber(int Number[6]);
	virtual ~CNetCardNO();
	// Generated message map functions
protected:
	//{{AFX_MSG(CNetCardNO)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETCARDNO_H__310CDEAA_0876_4697_8116_189FEBAE24C8__INCLUDED_)
