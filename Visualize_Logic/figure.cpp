// figure.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Project.h"
#include "figure.h"
#include "ChildView.h"

// figure

figure::figure(CPoint temp_center, bool _not)
{
	type=-1;
	center = temp_center;
	not = _not;

	prev1 = NULL;
	prev2 = NULL;
	prev3 = NULL;
	prev4 = NULL;
	prev5 = NULL;
	prev6 = NULL;

	next = NULL;
	next2 = NULL;
	next3 = NULL;
	next4 = NULL;
}

figure::~figure()
{

}

void figure::draw(CDC* dc)
{
	CBitmap bitmap;
	BITMAP bmpinfo;
	CDC dcmem;
	switch(type)
	{
	case 0:
		bitmap.LoadBitmapA(IDB_BITMAP1);
		bitmap.GetBitmap(&bmpinfo);
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		dc->BitBlt(center.x - 20,center.y - 20, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0,0, SRCCOPY);
		dcmem.Rectangle(5,5,15,15);
		
		//output 선
		dc->MoveTo(center.x + 35, center.y + 8);
		dc->LineTo(center.x + 57, center.y + 8);
		output.x = center.x + 57;
		output.y = center.y + 8;
		//input 선
		dc->MoveTo(center.x - 14, center.y - 4);
		dc->LineTo(center.x - 39, center.y - 4);
		dc->MoveTo(center.x - 14, center.y + 18);
		dc->LineTo(center.x - 39, center.y + 18);
		input1.x = center.x - 39;
		input1.y = center.y - 4;
		input2.x = center.x - 39;
		input2.y = center.y + 18;
		if( not == 1)
			dc->Ellipse(center.x+35,center.y + 13, center.x + 45, center.y + 3);
		break;
	case 1:
		bitmap.LoadBitmapA(IDB_BITMAP2);
		bitmap.GetBitmap(&bmpinfo);
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		dc->BitBlt(center.x - 20,center.y - 20, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0,0, SRCCOPY);
		dcmem.Rectangle(5,5,15,15);
		//output 선
		dc->MoveTo(center.x + 48, center.y + 3);
		dc->LineTo(center.x + 70, center.y + 3);
		output.x = center.x + 70;
		output.y = center.y + 3;
		//input 선
		dc->MoveTo(center.x - 11, center.y - 8);
		dc->LineTo(center.x - 36, center.y - 8);
		dc->MoveTo(center.x - 11, center.y + 14);
		dc->LineTo(center.x - 36, center.y + 14);
		input1.x = center.x - 36;
		input1.y = center.y - 8;
		input2.x = center.x - 36;
		input2.y = center.y + 14;
		if( not == 1)
			dc->Ellipse(center.x+48,center.y + 8, center.x + 58, center.y - 2);
		break;
	case 2:
		bitmap.LoadBitmapA(IDB_BITMAP3);
		bitmap.GetBitmap(&bmpinfo);
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		dc->BitBlt(center.x - 20,center.y - 20, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0,0, SRCCOPY);
		dcmem.Rectangle(5,5,15,15);
		//output 선
		dc->MoveTo(center.x + 56, center.y + 5);
		dc->LineTo(center.x + 78, center.y + 5);
		output.x = center.x + 78;
		output.y = center.y + 5;
		//input 선
		dc->MoveTo(center.x - 11, center.y - 8);
		dc->LineTo(center.x - 36, center.y - 8);
		dc->MoveTo(center.x - 11, center.y + 14);
		dc->LineTo(center.x - 36, center.y + 14);
		input1.x = center.x - 36;
		input1.y = center.y - 8;
		input2.x = center.x - 36;
		input2.y = center.y + 14;
		if( not == 1)
			dc->Ellipse(center.x+56,center.y + 10, center.x + 66, center.y + 0);
		break;
	case 3:
		bitmap.LoadBitmapA(IDB_BITMAP5);
		bitmap.GetBitmap(&bmpinfo);
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		dc->BitBlt(center.x - 30,center.y - 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0,0, SRCCOPY);
		dcmem.Rectangle(5,5,15,15);
		//output 선
		dc->MoveTo(center.x + 40, center.y);
		dc->LineTo(center.x + 62, center.y);
		output.x = center.x + 62;
		output.y = center.y;
		if( m_InData1 == 1)
			dc->TextOutA(center.x+ 30, center.y,"1");
		else if(m_InData1 == 0)
			dc->TextOutA(center.x+ 30, center.y,"0");
		break;
	case 4:
		bitmap.LoadBitmapA(IDB_BITMAP6);
		bitmap.GetBitmap(&bmpinfo);
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		dc->BitBlt(center.x - 65,center.y - 85, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0,0, SRCCOPY);
		dcmem.Rectangle(5,5,15,15);
		//input 선
		dc->MoveTo(center.x - 63, center.y - 30);
		dc->LineTo(center.x - 88, center.y - 30);
		dc->MoveTo(center.x - 63, center.y);
		dc->LineTo(center.x - 88, center.y);
		dc->MoveTo(center.x - 63, center.y + 30);
		dc->LineTo(center.x - 88, center.y + 30);
		dc->MoveTo(center.x - 63, center.y + 60);
		dc->LineTo(center.x - 88, center.y + 60);
		input1.x = center.x - 88;
		input1.y = center.y - 30;
		input2.x = center.x - 88;
		input2.y = center.y;
		input3.x = center.x - 88;
		input3.y = center.y + 30;
		input4.x = center.x - 88;
		input4.y = center.y + 60;
		break;
	case 5:
		bitmap.LoadBitmapA(IDB_BITMAP4);
		bitmap.GetBitmap(&bmpinfo);
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		dc->BitBlt(center.x - 40,center.y - 45, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0,0, SRCCOPY);
		dcmem.Rectangle(5,5,15,15);
		//output 선
		dc->MoveTo(center.x + 36, center.y - 5);
		dc->LineTo(center.x + 58, center.y - 5);
		output.x = center.x + 58;
		output.y = center.y - 5;
		dc->MoveTo(center.x + 36, center.y + 21);
		dc->LineTo(center.x + 58, center.y + 21);
		output2.x = center.x + 58;
		output2.y = center.y + 21;
		//input 선
		dc->MoveTo(center.x - 38, center.y - 31);
		dc->LineTo(center.x - 63, center.y - 31);
		dc->MoveTo(center.x - 38, center.y - 5);
		dc->LineTo(center.x - 63, center.y - 5);
		dc->MoveTo(center.x - 38, center.y + 21);
		dc->LineTo(center.x - 63, center.y + 21);
		dc->MoveTo(center.x - 38, center.y + 47);
		dc->LineTo(center.x - 63, center.y + 47);
		input1.x = center.x - 63;
		input1.y = center.y - 31;
		input2.x = center.x - 63;
		input2.y = center.y - 5;
		input3.x = center.x - 63;
		input3.y = center.y + 21;
		input4.x = center.x - 63;
		input4.y = center.y + 47;
		break;
	case 6:
		bitmap.LoadBitmapA(IDB_BITMAP7);
		bitmap.GetBitmap(&bmpinfo);
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		dc->BitBlt(center.x - 40,center.y - 45, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0,0, SRCCOPY);
		dcmem.Rectangle(5,5,15,15);
		//input 선
		dc->MoveTo(center.x - 38, center.y - 5);
		dc->LineTo(center.x - 63, center.y - 5);
		input1.x = center.x - 63;
		input1.y = center.y - 5;
		dc->MoveTo(center.x - 38, center.y + 21);
		dc->LineTo(center.x - 63, center.y + 21);
		input2.x = center.x - 63;
		input2.y = center.y + 21;
		//output 선
		dc->MoveTo(center.x + 36, center.y - 31);
		dc->LineTo(center.x + 58, center.y - 31);
		dc->MoveTo(center.x + 36, center.y - 5);
		dc->LineTo(center.x + 58, center.y - 5);
		dc->MoveTo(center.x + 36, center.y + 21);
		dc->LineTo(center.x + 58, center.y + 21);
		dc->MoveTo(center.x + 36, center.y + 47);
		dc->LineTo(center.x + 58, center.y + 47);
		output.x = center.x + 58;
		output.y = center.y - 31;
		output2.x = center.x + 58;
		output2.y = center.y - 5;
		output3.x = center.x + 58;
		output3.y = center.y + 21;
		output4.x = center.x + 58;
		output4.y = center.y + 47;
		break;
	case 7:
		bitmap.LoadBitmapA(IDB_BITMAP8);
		bitmap.GetBitmap(&bmpinfo);
		dcmem.CreateCompatibleDC(dc);
		dcmem.SelectObject(&bitmap);
		dc->BitBlt(center.x - 40,center.y - 45, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0,0, SRCCOPY);
		dcmem.Rectangle(5,5,15,15);
		//output 선
		dc->MoveTo(center.x + 56, center.y + 5);
		dc->LineTo(center.x + 78, center.y + 5);
		output.x = center.x + 78;
		output.y = center.y + 5;
		//input 선
		dc->MoveTo(center.x - 38, center.y - 31);
		dc->LineTo(center.x - 63, center.y - 31);
		dc->MoveTo(center.x - 38, center.y - 5);
		dc->LineTo(center.x - 63, center.y - 5);
		dc->MoveTo(center.x - 38, center.y + 21);
		dc->LineTo(center.x - 63, center.y + 21);
		dc->MoveTo(center.x - 38, center.y + 47);
		dc->LineTo(center.x - 63, center.y + 47);
		input1.x = center.x - 63;
		input1.y = center.y - 31;
		input2.x = center.x - 63;
		input2.y = center.y - 5;
		input3.x = center.x - 63;
		input3.y = center.y + 21;
		input4.x = center.x - 63;
		input4.y = center.y + 47;
		//switch 선
		dc->MoveTo(center.x + 10, center.y + 60);
		dc->LineTo(center.x + 10, center.y + 82);
		dc->MoveTo(center.x + 40, center.y + 60);
		dc->LineTo(center.x + 40, center.y + 82);
		input5.x = center.x + 10;
		input5.y = center.y + 82;
		input6.x = center.x + 40;
		input6.y = center.y + 82;
		break;
	}
}

void figure::drawline(CDC* dc)
{
	if( next != NULL)		//next가 존재하는 경우
	{
		if( next->Get_prev1() == this)		//input 1에 들어간 경우
		{
			dc->MoveTo(output.x,output.y);
			dc->LineTo((output.x+next->Get_input1().x)/2 , output.y);		
			dc->MoveTo((output.x+next->Get_input1().x)/2 , output.y);			
			dc->LineTo((output.x+next->Get_input1().x)/2 , next->Get_input1().y);
			dc->MoveTo((output.x+next->Get_input1().x)/2 , next->Get_input1().y);
			dc->LineTo(next->Get_input1().x, next->Get_input1().y);
		}
		else if( next->Get_prev2() == this)	//input 2에 들어간 경우
		{
			dc->MoveTo(output.x,output.y);
			dc->LineTo((output.x+next->Get_input2().x)/2 , output.y);		
			dc->MoveTo((output.x+next->Get_input2().x)/2 , output.y);			
			dc->LineTo((output.x+next->Get_input2().x)/2 , next->Get_input2().y);
			dc->MoveTo((output.x+next->Get_input2().x)/2 , next->Get_input2().y);
			dc->LineTo(next->Get_input2().x, next->Get_input2().y);
		}
		else if( next->Get_prev3() == this)	//input 3에 들어간 경우
		{
			dc->MoveTo(output.x,output.y);
			dc->LineTo((output.x+next->Get_input3().x)/2 , output.y);		
			dc->MoveTo((output.x+next->Get_input3().x)/2 , output.y);			
			dc->LineTo((output.x+next->Get_input3().x)/2 , next->Get_input3().y);
			dc->MoveTo((output.x+next->Get_input3().x)/2 , next->Get_input3().y);
			dc->LineTo(next->Get_input3().x, next->Get_input3().y);
		}
		else if( next->Get_prev4() == this)	//input 4에 들어간 경우
		{
			dc->MoveTo(output.x,output.y);
			dc->LineTo((output.x+next->Get_input4().x)/2 , output.y);		
			dc->MoveTo((output.x+next->Get_input4().x)/2 , output.y);			
			dc->LineTo((output.x+next->Get_input4().x)/2 , next->Get_input4().y);
			dc->MoveTo((output.x+next->Get_input4().x)/2 , next->Get_input4().y);
			dc->LineTo(next->Get_input4().x, next->Get_input4().y);
		}
		else if( next->Get_prev5() == this)	//input 5에 들어간 경우
		{
			dc->MoveTo(output.x,output.y);
			dc->LineTo((output.x+next->Get_input5().x)/2 , output.y);		
			dc->MoveTo((output.x+next->Get_input5().x)/2 , output.y);			
			dc->LineTo((output.x+next->Get_input5().x)/2 , next->Get_input5().y);
			dc->MoveTo((output.x+next->Get_input5().x)/2 , next->Get_input5().y);
			dc->LineTo(next->Get_input5().x, next->Get_input5().y);
		}
		else if( next->Get_prev6() == this)	//input 6에 들어간 경우
		{
			dc->MoveTo(output.x,output.y);
			dc->LineTo((output.x+next->Get_input6().x)/2 , output.y);		
			dc->MoveTo((output.x+next->Get_input6().x)/2 , output.y);			
			dc->LineTo((output.x+next->Get_input6().x)/2 , next->Get_input6().y);
			dc->MoveTo((output.x+next->Get_input6().x)/2 , next->Get_input6().y);
			dc->LineTo(next->Get_input6().x, next->Get_input6().y);
		}
	}
	if( next2 != NULL)		//next2가 존재하는 경우
	{
		if( next2->Get_prev1() == this)		//input 1에 들어간 경우
		{
			dc->MoveTo(output2.x,output2.y);
			dc->LineTo((output2.x+next2->Get_input1().x)/2 , output2.y);		
			dc->MoveTo((output2.x+next2->Get_input1().x)/2 , output2.y);			
			dc->LineTo((output2.x+next2->Get_input1().x)/2 , next2->Get_input1().y);
			dc->MoveTo((output2.x+next2->Get_input1().x)/2 , next2->Get_input1().y);
			dc->LineTo(next2->Get_input1().x, next2->Get_input1().y);
		}
		else if( next2->Get_prev2() == this)	//input 2에 들어간 경우
		{
			dc->MoveTo(output2.x,output2.y);
			dc->LineTo((output2.x+next2->Get_input2().x)/2 , output2.y);		
			dc->MoveTo((output2.x+next2->Get_input2().x)/2 , output2.y);			
			dc->LineTo((output2.x+next2->Get_input2().x)/2 , next2->Get_input2().y);
			dc->MoveTo((output2.x+next2->Get_input2().x)/2 , next2->Get_input2().y);
			dc->LineTo(next2->Get_input2().x, next2->Get_input2().y);
		}
		else if( next2->Get_prev3() == this)	//input 3에 들어간 경우
		{
			dc->MoveTo(output2.x,output2.y);
			dc->LineTo((output2.x+next2->Get_input3().x)/2 , output2.y);		
			dc->MoveTo((output2.x+next2->Get_input3().x)/2 , output2.y);			
			dc->LineTo((output2.x+next2->Get_input3().x)/2 , next2->Get_input3().y);
			dc->MoveTo((output2.x+next2->Get_input3().x)/2 , next2->Get_input3().y);
			dc->LineTo(next2->Get_input3().x, next2->Get_input3().y);
		}
		else if( next2->Get_prev4() == this)	//input 4에 들어간 경우
		{
			dc->MoveTo(output2.x,output2.y);
			dc->LineTo((output2.x+next2->Get_input4().x)/2 , output2.y);		
			dc->MoveTo((output2.x+next2->Get_input4().x)/2 , output2.y);			
			dc->LineTo((output2.x+next2->Get_input4().x)/2 , next2->Get_input4().y);
			dc->MoveTo((output2.x+next2->Get_input4().x)/2 , next2->Get_input4().y);
			dc->LineTo(next2->Get_input4().x, next2->Get_input4().y);
		}
		else if( next2->Get_prev5() == this)	//input 5에 들어간 경우
		{
			dc->MoveTo(output2.x,output2.y);
			dc->LineTo((output2.x+next2->Get_input5().x)/2 , output2.y);		
			dc->MoveTo((output2.x+next2->Get_input5().x)/2 , output2.y);			
			dc->LineTo((output2.x+next2->Get_input5().x)/2 , next2->Get_input5().y);
			dc->MoveTo((output2.x+next2->Get_input5().x)/2 , next2->Get_input5().y);
			dc->LineTo(next2->Get_input5().x, next2->Get_input5().y);
		}
		else if( next2->Get_prev6() == this)	//input 6에 들어간 경우
		{
			dc->MoveTo(output2.x,output2.y);
			dc->LineTo((output2.x+next2->Get_input6().x)/2 , output2.y);		
			dc->MoveTo((output2.x+next2->Get_input6().x)/2 , output2.y);			
			dc->LineTo((output2.x+next2->Get_input6().x)/2 , next2->Get_input6().y);
			dc->MoveTo((output2.x+next2->Get_input6().x)/2 , next2->Get_input6().y);
			dc->LineTo(next2->Get_input6().x, next2->Get_input6().y);
		}
	}
	if( next3 != NULL)		//next3가 존재하는 경우
	{
		if( next3->Get_prev1() == this)		//input 1에 들어간 경우
		{
			dc->MoveTo(output3.x,output3.y);
			dc->LineTo((output3.x+next3->Get_input1().x)/2 , output3.y);		
			dc->MoveTo((output3.x+next3->Get_input1().x)/2 , output3.y);			
			dc->LineTo((output3.x+next3->Get_input1().x)/2 , next3->Get_input1().y);
			dc->MoveTo((output3.x+next3->Get_input1().x)/2 , next3->Get_input1().y);
			dc->LineTo(next3->Get_input1().x, next3->Get_input1().y);
		}
		else if( next3->Get_prev2() == this)	//input 2에 들어간 경우
		{
			dc->MoveTo(output3.x,output3.y);
			dc->LineTo((output3.x+next3->Get_input2().x)/2 , output3.y);		
			dc->MoveTo((output3.x+next3->Get_input2().x)/2 , output3.y);			
			dc->LineTo((output3.x+next3->Get_input2().x)/2 , next3->Get_input2().y);
			dc->MoveTo((output3.x+next3->Get_input2().x)/2 , next3->Get_input2().y);
			dc->LineTo(next3->Get_input2().x, next3->Get_input2().y);
		}
		else if( next3->Get_prev3() == this)	//input 3에 들어간 경우
		{
			dc->MoveTo(output3.x,output3.y);
			dc->LineTo((output3.x+next3->Get_input3().x)/2 , output3.y);		
			dc->MoveTo((output3.x+next3->Get_input3().x)/2 , output3.y);			
			dc->LineTo((output3.x+next3->Get_input3().x)/2 , next3->Get_input3().y);
			dc->MoveTo((output3.x+next3->Get_input3().x)/2 , next3->Get_input3().y);
			dc->LineTo(next3->Get_input3().x, next3->Get_input3().y);
		}
		else if( next3->Get_prev4() == this)	//input 4에 들어간 경우
		{
			dc->MoveTo(output3.x,output3.y);
			dc->LineTo((output3.x+next3->Get_input4().x)/2 , output3.y);		
			dc->MoveTo((output3.x+next3->Get_input4().x)/2 , output3.y);			
			dc->LineTo((output3.x+next3->Get_input4().x)/2 , next3->Get_input4().y);
			dc->MoveTo((output3.x+next3->Get_input4().x)/2 , next3->Get_input4().y);
			dc->LineTo(next3->Get_input4().x, next3->Get_input4().y);
		}
		else if( next3->Get_prev5() == this)	//input 5에 들어간 경우
		{
			dc->MoveTo(output3.x,output3.y);
			dc->LineTo((output3.x+next3->Get_input5().x)/2 , output3.y);		
			dc->MoveTo((output3.x+next3->Get_input5().x)/2 , output3.y);			
			dc->LineTo((output3.x+next3->Get_input5().x)/2 , next3->Get_input5().y);
			dc->MoveTo((output3.x+next3->Get_input5().x)/2 , next3->Get_input5().y);
			dc->LineTo(next3->Get_input5().x, next3->Get_input5().y);
		}
		else if( next3->Get_prev6() == this)	//input 6에 들어간 경우
		{
			dc->MoveTo(output3.x,output3.y);
			dc->LineTo((output3.x+next3->Get_input6().x)/2 , output3.y);		
			dc->MoveTo((output3.x+next3->Get_input6().x)/2 , output3.y);			
			dc->LineTo((output3.x+next3->Get_input6().x)/2 , next3->Get_input6().y);
			dc->MoveTo((output3.x+next3->Get_input6().x)/2 , next3->Get_input6().y);
			dc->LineTo(next3->Get_input6().x, next3->Get_input6().y);
		}
	}
	if( next4 != NULL)		//next4가 존재하는 경우
	{
		if( next4->Get_prev1() == this)		//input 1에 들어간 경우
		{
			dc->MoveTo(output4.x,output4.y);
			dc->LineTo((output4.x+next4->Get_input1().x)/2 , output4.y);		
			dc->MoveTo((output4.x+next4->Get_input1().x)/2 , output4.y);			
			dc->LineTo((output4.x+next4->Get_input1().x)/2 , next4->Get_input1().y);
			dc->MoveTo((output4.x+next4->Get_input1().x)/2 , next4->Get_input1().y);
			dc->LineTo(next4->Get_input1().x, next4->Get_input1().y);
		}
		else if( next4->Get_prev2() == this)	//input 2에 들어간 경우
		{
			dc->MoveTo(output4.x,output4.y);
			dc->LineTo((output4.x+next4->Get_input2().x)/2 , output4.y);		
			dc->MoveTo((output4.x+next4->Get_input2().x)/2 , output4.y);			
			dc->LineTo((output4.x+next4->Get_input2().x)/2 , next4->Get_input2().y);
			dc->MoveTo((output4.x+next4->Get_input2().x)/2 , next4->Get_input2().y);
			dc->LineTo(next4->Get_input2().x, next4->Get_input2().y);
		}
		else if( next4->Get_prev3() == this)	//input 3에 들어간 경우
		{
			dc->MoveTo(output4.x,output4.y);
			dc->LineTo((output4.x+next4->Get_input3().x)/2 , output4.y);		
			dc->MoveTo((output4.x+next4->Get_input3().x)/2 , output4.y);			
			dc->LineTo((output4.x+next4->Get_input3().x)/2 , next4->Get_input3().y);
			dc->MoveTo((output4.x+next4->Get_input3().x)/2 , next4->Get_input3().y);
			dc->LineTo(next4->Get_input3().x, next4->Get_input3().y);
		}
		else if( next4->Get_prev4() == this)	//input 4에 들어간 경우
		{
			dc->MoveTo(output4.x,output4.y);
			dc->LineTo((output4.x+next4->Get_input4().x)/2 , output4.y);		
			dc->MoveTo((output4.x+next4->Get_input4().x)/2 , output4.y);			
			dc->LineTo((output4.x+next4->Get_input4().x)/2 , next4->Get_input4().y);
			dc->MoveTo((output4.x+next4->Get_input4().x)/2 , next4->Get_input4().y);
			dc->LineTo(next4->Get_input4().x, next4->Get_input4().y);
		}
		else if( next4->Get_prev5() == this)	//input 5에 들어간 경우
		{
			dc->MoveTo(output4.x,output4.y);
			dc->LineTo((output4.x+next4->Get_input5().x)/2 , output4.y);		
			dc->MoveTo((output4.x+next4->Get_input5().x)/2 , output4.y);			
			dc->LineTo((output4.x+next4->Get_input5().x)/2 , next4->Get_input5().y);
			dc->MoveTo((output4.x+next4->Get_input5().x)/2 , next4->Get_input5().y);
			dc->LineTo(next4->Get_input5().x, next4->Get_input5().y);
		}
		else if( next4->Get_prev6() == this)	//input 6에 들어간 경우
		{
			dc->MoveTo(output4.x,output4.y);
			dc->LineTo((output4.x+next4->Get_input6().x)/2 , output4.y);		
			dc->MoveTo((output4.x+next4->Get_input6().x)/2 , output4.y);			
			dc->LineTo((output4.x+next4->Get_input6().x)/2 , next4->Get_input6().y);
			dc->MoveTo((output4.x+next4->Get_input6().x)/2 , next4->Get_input6().y);
			dc->LineTo(next4->Get_input6().x, next4->Get_input6().y);
		}
	}
}

int figure::Check_On(CPoint point, CDC* dc)
{
	CRgn rgn;
	
	////////////////////point가 input1에 있을 경우///////////////////////
	rgn.CreateRectRgn(input1.x-10, input1.y-10, input1.x+10, input1.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(input1.x-10, input1.y-10, input1.x+10, input1.y+10);
		return 1;
	}
	
	rgn.DeleteObject();
	////////////////////point가 input2에 있을 경우///////////////////////
	rgn.CreateRectRgn(input2.x-10, input2.y-10, input2.x+10, input2.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(input2.x-10, input2.y-10, input2.x+10, input2.y+10);
		return 2;
	}

	rgn.DeleteObject();
	////////////////////point가 input3에 있을 경우///////////////////////
	rgn.CreateRectRgn(input3.x-10, input3.y-10, input3.x+10, input3.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(input3.x-10, input3.y-10, input3.x+10, input3.y+10);
		return 3;
	}


	rgn.DeleteObject();
	////////////////////point가 input4에 있을 경우///////////////////////
	rgn.CreateRectRgn(input4.x-10, input4.y-10, input4.x+10, input4.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(input4.x-10, input4.y-10, input4.x+10, input4.y+10);
		return 4;
	}

	rgn.DeleteObject();
	////////////////////point가 input5에 있을 경우///////////////////////
	rgn.CreateRectRgn(input5.x-10, input5.y-10, input5.x+10, input5.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(input5.x-10, input5.y-10, input5.x+10, input5.y+10);
		return 5;
	}
	
	rgn.DeleteObject();
	////////////////////point가 input6에 있을 경우///////////////////////
	rgn.CreateRectRgn(input6.x-10, input6.y-10, input6.x+10, input6.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(input6.x-10, input6.y-10, input6.x+10, input6.y+10);
		return 6;
	}

	rgn.DeleteObject();
	////////////////////point가 output에 있을 경우///////////////////////
	rgn.CreateRectRgn(output.x-10, output.y-10, output.x+10, output.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(output.x-10, output.y-10, output.x+10, output.y+10);
		return 7;
	}

	rgn.DeleteObject();
	////////////////////point가 output2에 있을 경우///////////////////////
	rgn.CreateRectRgn(output2.x-10, output2.y-10, output2.x+10, output2.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(output2.x-10, output2.y-10, output2.x+10, output2.y+10);
		return 8;
	}

	rgn.DeleteObject();
	////////////////////point가 output3에 있을 경우///////////////////////
	rgn.CreateRectRgn(output3.x-10, output3.y-10, output3.x+10, output3.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(output3.x-10, output3.y-10, output3.x+10, output3.y+10);
		return 9;
	}

	rgn.DeleteObject();
	////////////////////point가 output4에 있을 경우///////////////////////
	rgn.CreateRectRgn(output4.x-10, output4.y-10, output4.x+10, output4.y+10);
	
	if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
	{
		dc->Ellipse(output4.x-10, output4.y-10, output4.x+10, output4.y+10);
		return 10;
	}

	rgn.DeleteObject();
	////////////////////point가 도형 위에 있을 경우///////////////////////
	if( type == 3)
	{
		rgn.CreateRectRgn(center.x-25, center.y-15, center.x+35, center.y+15);
		
		if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
			return 11;
	}
	else if(type == 0)
	{
		rgn.CreateRectRgn(center.x-20, center.y-20, center.x+35, center.y+30);
		
		if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
			return 11;
	}
	else if(type == 2 || type == 1)
	{
		rgn.CreateRectRgn(center.x-15, center.y-20, center.x+45, center.y+30);
		
		if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
			return 11;
	}
	else if(type == 4)
	{
		rgn.CreateRectRgn(center.x-60, center.y-80, center.x+80, center.y+100);
		
		if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
			return 11;
	}
	else
	{
		rgn.CreateRectRgn(center.x-35, center.y-40, center.x+35, center.y+55);
		
		if(rgn.PtInRegion(point)) //생성한 리전 위에 point가 존재하는 경우
			return 11;
		
	}
	rgn.DeleteObject();

	return -1;
}

int figure::Check_Data()
{
	if( m_InData1 == -1)
		return 1;
	else if (m_InData2 == -1)
		return 2;
	else if (m_InData3 == -1)
		return 3;
	else if (m_InData4 == -1)
		return 4;
	else if (m_InData5 == -1)
		return 5;
	else if (m_InData6 == -1)
		return 6;
	return 0;
}
// figure member functions
