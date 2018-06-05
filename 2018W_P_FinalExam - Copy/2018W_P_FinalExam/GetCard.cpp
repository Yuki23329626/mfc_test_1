#include "stdafx.h"
#include "GetCard.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <winioctl.h>   //macdrv
#include "ntddndis.h"   //macdrv  This defines the IOCTL constants.
#include <wincon.h>     //netbios
#include <time.h>       //netbios
#include <nb30.h>       //netbios
#include <Rpc.h>
#include <winsock2.h>
//include winsock2.h nb30.h 和linkws2_32.lib netapi32.lib 
#pragma comment(lib,"ws2_32.lib") 
#pragma comment(lib,"Rpcrt4.lib") 
#pragma comment(lib,"Iphlpapi.lib")  
#pragma comment(lib, "netapi32.lib")
#define DEVICE_PREFIX   "\\\\.\\"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

typedef struct _ASTAT_
{  ADAPTER_STATUS adapt;
   NAME_BUFFER NameBuff [30];
}
ASTAT, * PASTAT;


NetCard::NetCard()
{
  ErrNum=0;
}

NetCard::~NetCard()
{
}

BOOL NetCard::GetCardNumber(int Number[6])
{
  BOOL   SuccessFlag;
  SuccessFlag=FALSE;
  GetByNet();
  SuccessFlag=GetByNetBios(Number);
  if (SuccessFlag==FALSE) 
     SuccessFlag=GetByMacDrv(Number);
  return SuccessFlag;
}
BOOL NetCard::GetByNet()
{

	CString m_static1,m_static2,m_static3;
	 WORD wVersionRequested;
     WSADATA wsaData;
     char name[255];
     CString ip;
     PHOSTENT hostinfo;
     wVersionRequested = MAKEWORD( 2, 0 );
     if ( WSAStartup( wVersionRequested, &wsaData ) == 0 )
     {
     if( gethostname ( name, sizeof(name)) == 0)
     {
     if((hostinfo = gethostbyname(name)) != NULL)
     {
     ip = inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list);
     }
     }
m_static1.Format("Host Name: %s\r\n", name);
m_static2.Format("IP: " + ip );
//UpdateData(false);
     WSACleanup( );
}
///////////////////////////////////////////////////////////////////////////////
CString sMAC;
NCB Ncb;
    memset(&Ncb, 0, sizeof(Ncb));
    Ncb.ncb_command = NCBRESET;
    Ncb.ncb_lana_num = 0;
    if (Netbios(&Ncb) != NRC_GOODRET) {
    }
memset(&Ncb, 0, sizeof(Ncb));
    Ncb.ncb_command = NCBASTAT;
    Ncb.ncb_lana_num = 0;
    strcpy((char *) Ncb.ncb_callname, "*");
    struct ASTAT {
     ADAPTER_STATUS adapt;
     NAME_BUFFER NameBuff[30];
    } Adapter;

    memset(&Adapter, 0, sizeof(Adapter));
    Ncb.ncb_buffer = (unsigned char *)&Adapter;
    Ncb.ncb_length = sizeof(Adapter);
if (Netbios(&Ncb) == 0) {
     char acMAC[18];
     sprintf(acMAC, "%02X:%02X:%02X:%02X:%02X:%02X",
int (Adapter.adapt.adapter_address[0]),
     int (Adapter.adapt.adapter_address[1]),
     int (Adapter.adapt.adapter_address[2]),
     int (Adapter.adapt.adapter_address[3]),
     int (Adapter.adapt.adapter_address[4]),
     int (Adapter.adapt.adapter_address[5]));
     sMAC = acMAC;
m_static3.Format("Mac Address: %s", acMAC);
//UpdateData(false);
if(Adapter.adapt.adapter_address[9] != 0x00 || Adapter.adapt.adapter_address[1] != 0x90)
{
AfxMessageBox("LAN Mac address error !!\r\n" + m_static3, IDOK);
//KillTimer(IDC_TIME);
}
    }
    else 
{
AfxMessageBox("LAN Mac address error !!");
    }
	 return 0; 
}




BOOL NetCard::GetByNetBios(int Number[6])
{
  NCB ncb;//jerry:NCB是一個網路卡控制的結構,裏面有一些指令可供執行,
  UCHAR uRetCode; 
  int i; 
  BOOL  SuccessFlag;
  ASTAT Adapter;
    
  SuccessFlag=FALSE;
  memset( &ncb, 0, sizeof(ncb) ); 

  ncb.ncb_command = NCBRESET;//ncb_command是一個無號字串
                             //Resets a LAN adapter
  ncb.ncb_lana_num = 0;
  uRetCode =Netbios( &ncb );
  //printf( "The NCBRESET return code is: 0x%x \n", uRetCode );
  memset( &ncb, 0, sizeof(ncb) );   
  ncb.ncb_command = NCBASTAT;
  ncb.ncb_lana_num = 0;  
  strcpy( (char *)ncb.ncb_callname,  "*               " );
  ncb.ncb_buffer = (unsigned char *) &Adapter; 
  ncb.ncb_length = sizeof(Adapter);
  uRetCode = Netbios( &ncb );
  //printf( "The NCBASTAT return code is: 0x%x \n", uRetCode );
  
  if ( uRetCode == 0 )    
   { for (i=0;i<6;i++)
         Number[i]=Adapter.adapt.adapter_address[i];
     SuccessFlag=TRUE;
   } 
  else
     ErrNum=2;  
  return SuccessFlag; 
}

BOOL NetCard::GetByMacDrv(int Number[6])
{
//  LP LinkName[512];
  UCHAR LinkName[512];
  UCHAR DeviceName[80];
  UCHAR szMACFileName[80];
  UCHAR OidData[4096];
  NDIS_OID OidCode;
  DWORD ReturnedCount;
  HANDLE hMAC;
  UCHAR *NextStr,*CUR;
  int   i,counter;
  BOOL  SuccessFlag;

  ErrNum=0;
  SuccessFlag=FALSE;
 // QueryDosDeviceA (LinkName,(char*)DeviceName ,sizeof(LinkName));
 QueryDosDevice(0, (char*)LinkName, sizeof(LinkName));  //取得所有電腦上的device name放於linkname
  i=0;
  CUR = LinkName;
  while(1)
     { NextStr = CUR;
       strcpy((char*)szMACFileName,(char*)DEVICE_PREFIX);
       strcat((char*)szMACFileName, (char*)NextStr);
       if (strchr((char*)NextStr,':')==NULL&&strcmpi((char*)NextStr,(char*)"SymEvent")!=0)
        { hMAC = CreateFile((char*)szMACFileName,GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,INVALID_HANDLE_VALUE);
          if (hMAC != INVALID_HANDLE_VALUE)
           { OidCode = OID_802_3_CURRENT_ADDRESS;
             DeviceIoControl(hMAC,IOCTL_NDIS_QUERY_GLOBAL_STATS,&OidCode,sizeof(OidCode),OidData,sizeof(OidData),&ReturnedCount,NULL);
             if (ReturnedCount == 6 && OidData)
              { SuccessFlag=TRUE;
                for (i=0;i<6;i++)
                    Number[i]=OidData[i];
                break;
              }
           }
        }
	   counter = strlen((char*)CUR);
	   counter = (int)(CUR +strlen((char*)CUR)+1);
       CUR     = (UCHAR*)counter;
       if (strlen((char*)CUR)==0)
        { SuccessFlag=FALSE;
          ErrNum=3;  
          break;
        }
    }
  DefineDosDevice(DDD_RAW_TARGET_PATH | DDD_REMOVE_DEFINITION |DDD_EXACT_MATCH_ON_REMOVE,(char*)NextStr,(char*)DeviceName);                
  return SuccessFlag;
}