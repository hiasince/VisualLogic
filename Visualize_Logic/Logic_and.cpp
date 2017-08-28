
// Logic_and.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Project.h"
#include "Logic_and.h"


// Logic_and


Logic_and::Logic_and(CPoint _center, bool _not)
{
	type=0;
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

Logic_and::~Logic_and()
{

}

void Logic_and::Logic()
{
	if(!not)
	{
		if(m_InData1 == 1 && m_InData2 == 1)
			m_OutData1 = 1;
		else 
			m_OutData1 = 0;
	}
	else
	{
		if(m_InData1 == 1 && m_InData2 == 1)
			m_OutData1 = 0;
		else
			m_OutData1 = 1;
	}
}


// Logic_and member functions
