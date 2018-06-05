// BaseStruct.h :  基本幾何結構資料
#ifndef __BaseStruct_H__ // __TEST_H__ 由 progrmmer 自己取名
#define __BaseStruct_H__
#include "Base_Function.h" 
#include "stdafx.h"
#include <fstream>
#include <string>
using namespace std;
//Basefun m_Basefun;

class Shape	//形狀類別的基礎類別
{
public:
	CPoint StartPnt, EndPnt,Prepoint;	//定義形狀的終點與起點
	int LineWidth;
	int LineType;
 	COLORREF color;
	int Fill_Selected;
	int FillHatchType;
 	 BOOL Filled;
	 COLORREF fcolor;
 // BOOL Draw1;
	int shapenum;	//形狀代號
	public:
	//建構子
		Shape ()
		{
		LineWidth=1;
		LineType=0;
		fcolor=color = RGB(255, 0, 0);
		Fill_Selected=0;
		FillHatchType=5;
		}
	//過載=運算子
	Shape & operator= (Shape & s)
	{
		StartPnt = s.StartPnt;	//設定起點
		EndPnt = s.EndPnt;	//設定終點
		LineWidth= s.LineWidth;
   	    LineType= s.LineType;
		return *this;
	}
	virtual void draw(CDC & aDC, COLORREF color, COLORREF fcolor,int width, BOOL Filled = false) = 0;
	int GetShapeNum()	//取得形狀代號
	{ return shapenum; }
	void SetPoint(CPoint SPnt, CPoint EPnt)	//設定形狀的起點、終點
	{
		StartPnt = SPnt;
		EndPnt = EPnt;
	}
};

class MyPoint 
{
public:
	CPoint point;	//定義形狀的終點與起點
	int shapenum ;
	COLORREF color;
	MyPoint()
	{
		color = RGB(255, 0, 0);
		shapenum = 1;
		point=(0,0);

	}
	//過載=運算子
	MyPoint & operator= (MyPoint & p)
	{
		point = p.point;
		color = p.color;
	    shapenum = p.shapenum;
		return *this;		
	}
};

class MyLine : public Shape	//直線類別
{
public:
	MyLine ()
	{
		color = RGB(255, 0, 0);
		shapenum = 2;
		StartPnt=(0,0);
	}

	//建構子
	MyLine(CPoint StartPnt2, CPoint EndPnt2,COLORREF color2) 
	{
	    color =color2;
		shapenum = 2;
		StartPnt=StartPnt2;
		EndPnt=EndPnt2;

	}
	//過載=運算子
	MyLine & operator= (MyLine & l)
	{
		StartPnt = l.StartPnt;
		color = l.color;
		LineWidth = l.LineWidth;
		LineType = l.LineType;
		EndPnt = l.EndPnt;
        shapenum = l.shapenum;
		return *this;		
	}
void draw(CDC &dc, COLORREF color, COLORREF fcolor,
		 int width, BOOL Filled = false)
	{
		CPen pen(LineType, width, color);	//建立畫筆物件
	    CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);	//移至直線起點
		dc.LineTo(EndPnt);	//移至直線終點
		dc.SelectObject(oldPen);	//還原選取的畫筆物件
	}
void draw2(CDC &dc)
	{

//LOGBRUSH logBrush;
//logBrush.lbStyle = BS_SOLID;
//logBrush.lbColor = color;
//CPen pen(PS_DOT|PS_GEOMETRIC|PS_ENDCAP_ROUND, 1, &logBrush);


		CPen pen(LineType, LineWidth, color);	//建立畫筆物件//PS_DASHDOT LineType
	    CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);	//移至直線起點
		dc.LineTo(EndPnt);	//移至直線終點
		dc.SelectObject(oldPen);	//還原選取的畫筆物件
	}
void draw3(CDC &dc)
	{
		CPen pen(LineType, LineWidth, RGB(0,0,0));	//建立畫筆物件
	    CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);	//移至直線起點
		dc.LineTo(EndPnt);	//移至直線終點
		dc.SelectObject(oldPen);	//還原選取的畫筆物件
	}
};

class MyEllipse : public Shape	//橢圓形類別
{public:
	 BOOL Filled;
	 COLORREF fcolor;
	MyEllipse () 
	{
	    color = RGB(0, 255, 0);
	    fcolor = RGB(0, 0, 255);
		shapenum = 3;
		StartPnt=(0,0);
		Filled=1;
	}
	MyEllipse(CPoint StartPnt2, CPoint EndPnt2,COLORREF color2) 
	{
	    color =color2;
		shapenum = 2;
		StartPnt=StartPnt2;
		EndPnt=EndPnt2;
		
	}
	//過載=運算子
	MyEllipse & operator= (MyEllipse & l)	//過載=運算子
	{
	   Filled = l.Filled;
		fcolor = l.fcolor;
		StartPnt = l.StartPnt;
		color = l.color;
		LineWidth = l.LineWidth;
		LineType = l.LineType;
		EndPnt = l.EndPnt;
        shapenum = l.shapenum;
        FillHatchType = l.FillHatchType;
        Fill_Selected = l.Fill_Selected;
		return *this;		
	}
	void draw(CDC & dc, COLORREF color, COLORREF fcolor,int width, BOOL Filled = false)
	{ 
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , width, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件		
		
 	if(Filled)
	 {
   if(Fill_Selected==0)
	   m_newbrush.CreateSolidBrush(fcolor);
		 else
            m_newbrush.CreateHatchBrush(FillHatchType,fcolor);    	//    m_newbrush.CreateSolidBrush(fcolor);
                dc.SelectObject(&m_newbrush);
	 }
	 else
	 {
		dc.SelectStockObject(NULL_BRUSH   );	//設定DC物件不使用畫筆
	 }
	 	dc.Ellipse(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
	//	m_newbrush.DeleteObject();
	}
	void drawa(CDC & dc)
	{ 
			Basefun m_Basefun;
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , LineWidth, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件	
         COLORREF ftempcolor;
		  int R,G,B;
	   R=m_Basefun.RandInt(100,255);
	   G=m_Basefun.RandInt(0,123);
	   B=m_Basefun.RandInt(121,255);
	   ftempcolor=RGB(R,G,B);
 	   	  if(fcolor==RGB(255,255,255))
			ftempcolor=RGB(255,255,255);
		  else if(fcolor==RGB(0,0,0))
			ftempcolor=RGB(0,0,0);

	if(Filled)
	 {
   if(Fill_Selected==0)
	   m_newbrush.CreateSolidBrush(ftempcolor);
		 else
            m_newbrush.CreateHatchBrush(FillHatchType,ftempcolor);    	//    m_newbrush.CreateSolidBrush(fcolor);
                dc.SelectObject(&m_newbrush);
	 }
	 else
	 {
		dc.SelectStockObject(NULL_BRUSH   );	//設定DC物件不使用畫筆
	 }
	 	dc.Ellipse(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
	//	m_newbrush.DeleteObject();
	}

void draw2(CDC & dc)
	{ 
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , LineWidth, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		
 	 if(Filled)
	 {
   if(Fill_Selected==0)
	   m_newbrush.CreateSolidBrush(fcolor);
		 else
            m_newbrush.CreateHatchBrush(FillHatchType,fcolor);    	//    m_newbrush.CreateSolidBrush(fcolor);
                dc.SelectObject(&m_newbrush);
	 }
	 else
	 {
		dc.SelectStockObject(NULL_BRUSH   );	//設定DC物件不使用畫筆
	 }
	 	dc.Ellipse(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
	//	m_newbrush.DeleteObject();
	}
void draw3(CDC & dc)
	{ 
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , LineWidth, RGB(0,0,0));	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件

		
 	 if(Filled)
	 {
                    if(Fill_Selected==0)
	               m_newbrush.CreateSolidBrush( RGB(0,0,0));
		 else
                    m_newbrush.CreateHatchBrush(FillHatchType, RGB(0,0,0));                   dc.SelectObject(&m_newbrush);
	 }
	 else
	 {
		dc.SelectStockObject(NULL_BRUSH   );	//設定DC物件不使用畫筆
	 }
	 	dc.Ellipse(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
	//	m_newbrush.DeleteObject();
	}
};


class MyRectangle : public Shape	//矩形類別
{
public:
	// BOOL Filled;
	// COLORREF fcolor;
	MyRectangle () 
	{
	    color = RGB(255, 0, 0);
		shapenum = 3;
		StartPnt=(0,0);
		Filled=1;
		Fill_Selected=0;
	}
	MyRectangle(CPoint StartPnt2, CPoint EndPnt2,COLORREF color2) 
	{
	    color =color2;
		shapenum = 2;
		StartPnt=StartPnt2;
		EndPnt=EndPnt2;
	}
	//過載=運算子
	MyRectangle & operator= (MyRectangle & l)	//過載=運算子
	{
		Filled = l.Filled;
		fcolor = l.fcolor;
        FillHatchType = l.FillHatchType;
        Fill_Selected = l.Fill_Selected;
		StartPnt = l.StartPnt;
		color = l.color;
		LineType = l.LineType;
		LineWidth = l.LineWidth;
		EndPnt = l.EndPnt;
        shapenum = l.shapenum;
		return *this;		
	}
void drawa(CDC & dc)
	{ 
		
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , LineWidth, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
			Basefun m_Basefun;
      COLORREF ftempcolor;
	 int R,G,B;
	   R=m_Basefun.RandInt(0,125);
	   G=m_Basefun.RandInt(125,255);
	   B=m_Basefun.RandInt(0,255);
	   ftempcolor=RGB(R,G,B);	
 	   	  if(fcolor==RGB(255,255,255))
			ftempcolor=RGB(255,255,255);
		  else if(fcolor==RGB(0,0,0))
			ftempcolor=RGB(0,0,0);
	 if(Filled)
	 {
    if(Fill_Selected==0)
 	         m_newbrush.CreateSolidBrush(ftempcolor);
		 else
            m_newbrush.CreateHatchBrush(FillHatchType,ftempcolor);    	//    m_newbrush.CreateSolidBrush(fcolor);
                dc.SelectObject(&m_newbrush);
	 }
	 else
	 {
		dc.SelectStockObject(NULL_BRUSH   );	//設定DC物件不使用畫筆
	 }
	 	dc.Rectangle(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
	//	m_newbrush.DeleteObject();
	}


	void draw(CDC & dc, COLORREF color, COLORREF fcolor,int width, BOOL Filled = false)
	{ 
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , width, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
	 
 		 if(Filled)
	 {
    if(Fill_Selected==0)
 	         m_newbrush.CreateSolidBrush(fcolor);
		 else
            m_newbrush.CreateHatchBrush(FillHatchType,fcolor);    	//    m_newbrush.CreateSolidBrush(fcolor);
                dc.SelectObject(&m_newbrush);
	 }
	 else
	 {
		dc.SelectStockObject(NULL_BRUSH   );	//設定DC物件不使用畫筆
	 }
	 	dc.Rectangle(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
	//	m_newbrush.DeleteObject();
	}
void draw6(CDC & dc)
	{
	 //   CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , LineWidth, color);	//建立畫筆物件
		CPen pen2(2 , 1, RGB(234,123,123));	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		m_newbrush.CreateSolidBrush(fcolor);
		  dc.SelectObject(&m_newbrush);
		int i=0;
		CPoint pt[5];
		pt[i].x=0;
		pt[i++].y=0;
		pt[i].x=10;
		pt[i++].y=20;
		pt[i].x=130;
		pt[i++].y=550;
		pt[i].x=540;
		pt[i++].y=230;
		pt[i].x=730;
		pt[i++].y=150;

		CPoint pt2[5];
		i=0;
		pt2[i].x=540;
		pt2[i++].y=230;
		pt2[i].x=830;
		pt2[i++].y=600;
		pt2[i].x=930;
		pt2[i++].y=250;
		pt2[i].x=1030;
		pt2[i++].y=20;
		pt2[i].x=0;
		pt2[i++].y=0;
	//	 dc.PolyBezier(pt,4);
	     // dc.Polyline(pt, 5); 
	      dc.Polygon(pt, 5); 
		  dc.SelectObject(&pen2);	//設定DC物件使用pen物件
	//	 dc.PolyBezier(pt2,4);
	   dc.Polyline(pt2, 5); 
	//	CRect rect(pt[0], pt[4]);	//建立CRect物件
	// dc.Rectangle(rect);	//繪出矩形
		 	dc.SelectObject(oldPen);	//還原畫筆物件
	}

void draw2(CDC & dc)
	{ 
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , LineWidth, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		
 	 if(Filled)
	 {
    if(Fill_Selected==0)
 	         m_newbrush.CreateSolidBrush(fcolor);
		 else
            m_newbrush.CreateHatchBrush(FillHatchType,fcolor);    	//    m_newbrush.CreateSolidBrush(fcolor);
                dc.SelectObject(&m_newbrush);
	 }
	 else
	 {
		dc.SelectStockObject(NULL_BRUSH   );	//設定DC物件不使用畫筆
	 }
	 	dc.Rectangle(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
	//	m_newbrush.DeleteObject();
	}

void draw3(CDC & dc)
	{ 
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
  	    CBrush m_newbrush;
		CPen pen(LineType , LineWidth, RGB(0,0,0));	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		
 	 if(Filled)
	 {
    if(Fill_Selected==0)
 	         m_newbrush.CreateSolidBrush(fcolor);
		 else
            m_newbrush.CreateHatchBrush(FillHatchType,fcolor);    	//    m_newbrush.CreateSolidBrush(fcolor);
            //	m_newbrush.CreateHatchBrush(HS_FDIAGONAL,RGB(0,55,55));
                dc.SelectObject(&m_newbrush);
	 }
	 else
	 {
		dc.SelectStockObject(NULL_BRUSH   );	//設定DC物件不使用畫筆
	 }
	 	dc.Rectangle(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
	//	m_newbrush.DeleteObject();
	}
void drawBMP(CDC & aDC,CString FileNamePath,CBitmap &m_bitmap,CDC &m_dc)
	{ 
	   CPoint BMPSt=StartPnt;
   CPoint BMPEt=EndPnt;
   int bx=abs(BMPSt.x-BMPEt.x);
   int by=abs(BMPSt.y-BMPEt.y);
    m_bitmap.m_hObject  = (HBITMAP)LoadImage(NULL, FileNamePath, IMAGE_BITMAP,bx,by, LR_LOADFROMFILE);
    m_dc.CreateCompatibleDC(&aDC);
    m_dc.SelectObject(&m_bitmap);
    int Sx,Sy;
if((BMPEt.x-BMPSt.x)<0&&(BMPEt.y-BMPSt.y)<0)
{
//aDC.BitBlt(BMPEt.x,BMPEt.y,bx,by,&m_dc,0,0,SRCCOPY);
 Sx=BMPEt.x;
 Sy=BMPEt.y;
}
else if((BMPEt.x-BMPSt.x)<0&&(BMPEt.y-BMPSt.y)>0)
{
   //   aDC.BitBlt(BMPEt.x,BMPSt.y,bx,by,&m_dc,0,0,SRCCOPY);
	  Sx=BMPEt.x;
      Sy=BMPSt.y;
}
else if((BMPEt.x-BMPSt.x)>0&&(BMPEt.y-BMPSt.y)<0)
{
   //   aDC.BitBlt(BMPSt.x,BMPEt.y,bx,by,&m_dc,0,0,SRCCOPY);
	  Sx=BMPSt.x;
      Sy=BMPEt.y;

}
else 
{
//aDC.BitBlt(BMPSt.x,BMPSt.y,bx,by,&m_dc,0,0,SRCCOPY);
	  Sx=BMPSt.x;
      Sy=BMPSt.y;

}
//aDC.BitBlt(Sx,Sy,bx,by,&m_dc,0,0,SRCCOPY);
COLORREF transparent_color = RGB(255, 255, 255);
aDC.TransparentBlt(Sx,Sy, bx, by,&m_dc, 0, 0, bx,by,transparent_color);

m_dc.DeleteDC();

	}

};

#endif