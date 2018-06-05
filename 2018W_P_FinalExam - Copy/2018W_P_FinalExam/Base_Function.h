
#ifndef __Base_Function_H__ // __TEST_H__ 由 progrmmer 自己取名
#define __Base_Function_H__

#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include <conio.h>
#include <string>
#include <time.h>
#include <stdlib.h> // RAND_MAX
#include <windows.h>
#include<vector>//STL
#include <iomanip>
#include <stdarg.h>  // For va_start, etc.
#include <fstream>
#define CSV_FileName "D:\\OOP_BMI.csv"
#define BMI_FileName "D:\\OOP_BMI.bmi" 

using namespace std;

class Basefun
{
public:
	 void SetConsoleFullScreen();
   int Dice();
  
   int RandInt(int min, int max);
  
   float RandFloat(int min, int max);
 
    char* Rand_Gender();
  
   
   int Add3P_I(int a,int b,int c);
 
    int Add3P_A(int *a,int num);
  ;
};
#endif