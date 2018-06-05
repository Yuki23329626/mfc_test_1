// NetCardNO.cpp : implementation file
//

#include "stdafx.h"
//#include "Register.h"
#include "NetCardNO.h"
#include <nb30.h>       //netbios
//#include "MibAccess.h"     


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

typedef struct _ASTAT_
{  ADAPTER_STATUS adapt;
   NAME_BUFFER NameBuff [30];
}
ASTAT, * PASTAT;

/////////////////////////////////////////////////////////////////////////////
// CNetCardNO

CNetCardNO::CNetCardNO()
{
}

CNetCardNO::~CNetCardNO()
{
}


BEGIN_MESSAGE_MAP(CNetCardNO, CWnd)
	//{{AFX_MSG_MAP(CNetCardNO)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CNetCardNO message handlers

/*
BOOL CNetCardNO::GetCardNumber(int Number[6])
{

  BOOL SuccessFlag=FALSE;
  MibII	m;
  UINT m_NICCount;
  BOOL  m_bDialup = FALSE ;
  BOOL  m_bLoopback = FALSE;

  int rv = m.Init();
  if (rv < 0)
	 return SuccessFlag;
  int i,j,num;
  
  tSTRUCTNICINFO *m_pNICInfo;
  m_NICCount = m.GetNICCount(m_bDialup, m_bLoopback);
  if (m_NICCount > 0)
  {
	  m_pNICInfo = new tSTRUCTNICINFO [m_NICCount];
	  num=m.GetNICInfo(m_pNICInfo,m_NICCount);
	  if (num>0)
      {
		  for (j=0;j<num;j++)
		  {
			  for (i=0;i<(&m_pNICInfo[j])->MACLength;i++)
			  {
				  if (i<6)
					  Number[i]=(&m_pNICInfo[0])->MAC[i];
              }
             SuccessFlag=TRUE;
		  }
		  delete m_pNICInfo;
      }
  }
  return SuccessFlag; 
}
*/


BOOL CNetCardNO::GetCardNumber(int Number[6])
{
  NCB ncb;
  UCHAR uRetCode; 
  int i, lana_num = -1; 
  BOOL  SuccessFlag, Netflag;
  ASTAT Adapter;

  SuccessFlag=FALSE;
  Netflag = FALSE ;
  do 
  {
	 lana_num ++ ;
     memset( &ncb, 0, sizeof(ncb) ); 
     ncb.ncb_command = NCBRESET;
     ncb.ncb_lana_num = lana_num ;
     uRetCode =Netbios( &ncb );

     if ( uRetCode == 0 )
	 {
		 memset( &ncb, 0, sizeof(ncb) );   
		 ncb.ncb_command = NCBASTAT;
		 ncb.ncb_lana_num = lana_num ;  
		 strcpy( (char *)ncb.ncb_callname,  "*               " );
		 memset(&Adapter, '0', sizeof(Adapter));
		 ncb.ncb_buffer = (unsigned char *) &Adapter; 
		 ncb.ncb_length = sizeof(Adapter);
		 uRetCode = Netbios( &ncb );
		 
		 if ( uRetCode == 0 && Adapter.adapt.adapter_address[0] == 0 )    
		 {
			 for (i=0;i<6;i++)
				 Number[i]=Adapter.adapt.adapter_address[i];    
			 SuccessFlag = TRUE;
		 }
	 }
  }
  while ( lana_num < 256 && SuccessFlag == FALSE ) ;

  return SuccessFlag; 
}