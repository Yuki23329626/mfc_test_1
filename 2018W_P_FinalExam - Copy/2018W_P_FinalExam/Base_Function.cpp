#include "stdafx.h"
#include "Base_Function.h" 
//設定Console全螢幕
void Basefun::SetConsoleFullScreen(){
	HWND hWnd;
        keybd_event(VK_MENU,0x38,0,0); 
        keybd_event(VK_RETURN,0x1c,0,0); 
        keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0);
        keybd_event(VK_RETURN,0x9c,KEYEVENTF_KEYUP,0);

		hWnd = GetConsoleWindow(); //How to do???
}
 
int Basefun::Dice()
   {
       SYSTEMTIME st;
      GetSystemTime(&st);
   // srand( (unsigned)time(NULL));
	  Sleep(3);
	   srand((unsigned)(st.wMilliseconds));
     return (rand() % 6 + 1);
	 
   }
   int Basefun::RandInt(int min, int max)
   {
       SYSTEMTIME st;
	   int randnum;
      GetSystemTime(&st);
   // srand( (unsigned)time(NULL));
	 // Sleep(3);
	   srand((unsigned)(st.wMilliseconds));
	   randnum=rand() %(max-min+1);
	   randnum+=(min);
     return (randnum);
	 
   }
   float Basefun::RandFloat(int min, int max)
   {
       SYSTEMTIME st;
	   int randnum;
	   min*=100;
	   max*=100;
      GetSystemTime(&st);
   // srand( (unsigned)time(NULL));
	  Sleep(30);
	   srand((unsigned)(st.wMilliseconds));
	   randnum=rand() %(max-min+1);
	   randnum+=(min);
     return ((float)randnum/100);
	 
   }
    char* Basefun::Rand_Gender()
   {
       SYSTEMTIME st;
	   char* randnum;
      GetSystemTime(&st);
   	   srand((unsigned)(st.wMilliseconds));
	   if((rand()%2)==0)
		   randnum="男生";
	   else
	       randnum="女生";
       return randnum;
	 
   }
   
   int Basefun::Add3P_I(int a,int b,int c)
   {
    
     return (a+b+c);  
   }
    int Add3P_A(int *a,int num)
   {
	   int i,total=0;;
	   for(i=0;i<num;i++)
	   {

         total+=a[i];
	   }
    
     return (total);  
   }