// Logic_Seg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Project.h"
#include "Logic_Seg.h"


// Logic_Seg

Logic_Seg::Logic_Seg()
{
}

Logic_Seg::Logic_Seg(CPoint _center, bool _not)
{
	type=4;
	center = _center;
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

	m_InData1  = -1;
	m_InData2  = -1;
	m_InData3  = -1;
	m_InData4  = -1;
	m_InData5  = -2;
	m_InData6  = -2;

	m_OutData1 = -1;
	m_OutData2 = -1;
	m_OutData3 = -1;
	m_OutData4 = -1;
}

Logic_Seg::~Logic_Seg()
{
}

void Logic_Seg::Logic()
{
	if(m_InData1 == 0 && m_InData2 == 0 && m_InData3 == 0 && m_InData4 == 0)
	{
		segout1 = 1; segout2= 1; segout3 = 1; segout4 = 1; segout5 = 1; segout6 = 1; segout7 = 0;
	}
	else if (m_InData1 == 0 && m_InData2 == 0 && m_InData3 == 0 && m_InData4 == 1)
	{
		segout1 = 0; segout2= 1; segout3 = 1; segout4 = 0; segout5 = 0; segout6 = 0; segout7 = 0;
	}
	else if (m_InData1 == 0 && m_InData2 == 0 && m_InData3 == 1 && m_InData4 == 0)
	{
		segout1 = 1; segout2= 1; segout3 = 0; segout4 = 1; segout5 = 1; segout6 = 0; segout7 = 1;
	}
	else if (m_InData1 == 0 && m_InData2 == 0 && m_InData3 == 1 && m_InData4 == 1)
	{
		segout1 = 1; segout2= 1; segout3 = 1; segout4 = 1; segout5 = 0; segout6 = 0; segout7 = 1;
	}
	else if (m_InData1 == 0 && m_InData2 == 1 && m_InData3 == 0 && m_InData4 == 0)
	{
		segout1 = 0; segout2= 1; segout3 = 1; segout4 = 0; segout5 = 0; segout6 = 1; segout7 = 1;
	}
	else if (m_InData1 == 0 && m_InData2 == 1 && m_InData3 == 0 && m_InData4 == 1)
	{
		segout1 = 1; segout2= 0; segout3 = 1; segout4 = 1; segout5 = 0; segout6 = 1; segout7 = 1;
	}
	else if (m_InData1 == 0 && m_InData2 == 1 && m_InData3 == 1 && m_InData4 == 0)
	{
		segout1 = 0; segout2= 0; segout3 = 1; segout4 = 1; segout5 = 1; segout6 = 1; segout7 = 1;
	}
	else if (m_InData1 == 0 && m_InData2 == 1 && m_InData3 == 1 && m_InData4 == 1)
	{
		segout1 = 1; segout2= 1; segout3 = 1; segout4 = 0; segout5 = 0; segout6 = 0; segout7 = 0;
	}
	else if (m_InData1 == 1 && m_InData2 == 0 && m_InData3 == 0 && m_InData4 == 0)
	{
		segout1 = 1; segout2= 1; segout3 = 1; segout4 = 1; segout5 = 1; segout6 = 1; segout7 = 1;
	}
	else if (m_InData1 == 1 && m_InData2 == 0 && m_InData3 == 0 && m_InData4 == 1)
	{
		segout1 = 1; segout2= 1; segout3 = 1; segout4 = 0; segout5 = 0; segout6 = 1; segout7 = 1;
	}
	
}

void Logic_Seg::Print_Segment(CDC* dc)
{
	CBrush SolidBrush;
	SolidBrush.CreateSolidBrush(RGB(255,0, 0));

	if(segout1 == 0)
	{
		dc->SelectStockObject(NULL_BRUSH);
		POINT points[] = {{center.x+150, center.y-85}, {center.x+220, center.y-85}, {center.x+210, center.y-75}, {center.x+160, center.y-75}};
		dc->Polygon(points, 4);			//얘네 좌표는 만나서 직접 보면서 계산해서 넣어요 
	}
	else
	{
		dc->SelectObject(&SolidBrush);
		POINT points[] = {{center.x+150, center.y-85}, {center.x+220, center.y-85}, {center.x+210, center.y-75}, {center.x+160, center.y-75}};
		dc->Polygon(points, 4);
	}

	if(segout2 == 0)
	{
		dc->SelectStockObject(NULL_BRUSH);
		POINT points[] = {{center.x+220, center.y-75}, {center.x+220, center.y-5}, {center.x+210, center.y-15}, {center.x+210, center.y-65}};
		dc->Polygon(points, 4);
	}
	else
	{
		dc->SelectObject(&SolidBrush);
		POINT points[] = {{center.x+220, center.y-75}, {center.x+220, center.y-5}, {center.x+210, center.y-15}, {center.x+210, center.y-65}};
		dc->Polygon(points, 4);
	}

	if(segout3 == 0)
	{
		dc->SelectStockObject(NULL_BRUSH);
		POINT points[] = {{center.x+220, center.y+75}, {center.x+220, center.y+5}, {center.x+210, center.y+15}, {center.x+210, center.y+65}};
		dc->Polygon(points, 4);
	}
	else
	{
		dc->SelectObject(&SolidBrush);
		POINT points[] = {{center.x+220, center.y+75}, {center.x+220, center.y+5}, {center.x+210, center.y+15}, {center.x+210, center.y+65}};
		dc->Polygon(points, 4);
	}

	if(segout4 == 0)
	{
		dc->SelectStockObject(NULL_BRUSH);
		POINT points[] = {{center.x+150, center.y+85}, {center.x+220, center.y+85}, {center.x+210, center.y+75}, {center.x+160, center.y+75}};
		dc->Polygon(points, 4);
	}
	else
	{
		dc->SelectObject(&SolidBrush);
		POINT points[] = {{center.x+150, center.y+85}, {center.x+220, center.y+85}, {center.x+210, center.y+75}, {center.x+160, center.y+75}};
		dc->Polygon(points, 4);
	}

	if(segout5 == 0)
	{
		dc->SelectStockObject(NULL_BRUSH);
		POINT points[] = {{center.x+150, center.y+75}, {center.x+150, center.y+5}, {center.x+160, center.y+15}, {center.x+160, center.y+65}};
		dc->Polygon(points, 4);
	}
	else
	{
		dc->SelectObject(&SolidBrush);
		POINT points[] = {{center.x+150, center.y+75}, {center.x+150, center.y+5}, {center.x+160, center.y+15}, {center.x+160, center.y+65}};
		dc->Polygon(points, 4);
	}

	if(segout6 == 0)
	{
		dc->SelectStockObject(NULL_BRUSH);
		POINT points[] = {{center.x+150, center.y-75}, {center.x+150, center.y-5}, {center.x+160, center.y-15}, {center.x+160, center.y-65}};
		dc->Polygon(points, 4);
	}
	else
	{
		dc->SelectObject(&SolidBrush);
		POINT points[] = {{center.x+150, center.y-75}, {center.x+150, center.y-5}, {center.x+160, center.y-15}, {center.x+160, center.y-65}};
		dc->Polygon(points, 4);
	}

	if(segout7 == 0)
	{
		dc->SelectStockObject(NULL_BRUSH);
		POINT points[] = {{center.x+150, center.y}, {center.x+160, center.y-5}, {center.x+210, center.y-5}, {center.x+220, center.y}, {center.x+210, center.y+5}, {center.x+160, center.y+5}};
		dc->Polygon(points, 6);
	}
	else
	{
		dc->SelectObject(&SolidBrush);
		POINT points[] = {{center.x+150, center.y}, {center.x+160, center.y-5}, {center.x+210, center.y-5}, {center.x+220, center.y}, {center.x+210, center.y+5}, {center.x+160, center.y+5}};
		dc->Polygon(points, 6);
	}
}
// Logic_Seg member functions
