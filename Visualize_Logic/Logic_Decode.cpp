// Logic_Decode.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Project.h"
#include "Logic_Decode.h"


// Logic_Decode

Logic_Decode::Logic_Decode()
{

}

Logic_Decode::Logic_Decode(CPoint _center, bool _not)
{
	type=6;
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
	m_InData3  = -2;
	m_InData4  = -2;
	m_InData5  = -2;
	m_InData6  = -2;

	m_OutData1 = -1;
	m_OutData2 = -1;
	m_OutData3 = -1;
	m_OutData4 = -1;
}

void Logic_Decode::Logic()
{
	if(m_InData1 == 0 && m_InData2 == 0)
	{
		m_OutData1 = 1;
		m_OutData2 = 0;
		m_OutData3 = 0;
		m_OutData4 = 0;
	}
	else if(m_InData1 == 0 && m_InData2 ==1)
	{
		m_OutData1 = 0;
		m_OutData2 = 1;
		m_OutData3 = 0;
		m_OutData4 = 0;
	}
	else if(m_InData1 == 1 && m_InData2 ==0)
	{
		m_OutData1 = 0;
		m_OutData2 = 0;
		m_OutData3 = 1;
		m_OutData4 = 0;
	}
	else
	{
		m_OutData1 = 0;
		m_OutData2 = 0;
		m_OutData3 = 0;
		m_OutData4 = 1;
	}

}

Logic_Decode::~Logic_Decode()
{
}


// Logic_Decode member functions
