#ifndef __GETCARD__H
#define __GETCARD__H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class NetCard
{
public:
    NetCard();
	virtual ~NetCard();
	BOOL GetCardNumber(int Number[6]);
protected:
    int ErrNum;
    BOOL GetByMacDrv(int Number[6]);
   BOOL GetByNetBios(int Number[6]);
     BOOL GetByNet();
};

#endif 