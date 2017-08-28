// Logic_Mux.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Project.h"
#include "Logic_Mux.h"


// Logic_Mux

Logic_Mux::Logic_Mux()
{
}

Logic_Mux::Logic_Mux(CPoint _center, bool _not)
{
	type=7;
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
	m_InData5  = -1;
	m_InData6  = -1;

	m_OutData1 = -1;
	m_OutData2 = -1;
	m_OutData3 = -1;
	m_OutData4 = -1;
}

void Logic_Mux::Logic()
{
	if(m_InData5 == 0 && m_InData6 == 0)
		m_OutData1 = m_InData1;
	else if(m_InData5 == 0 && m_InData6 == 1)
		m_OutData1 = m_InData2;
	else if(m_InData5 == 1 && m_InData6 == 0)
		m_OutData1 = m_InData3;
	else if(m_InData5 == 1 && m_InData6 == 1)
		m_OutData1 = m_InData4;
}

Logic_Mux::~Logic_Mux()
{
}


// Logic_Mux member functions
