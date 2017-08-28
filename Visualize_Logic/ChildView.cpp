
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFC_Project.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_temp = NULL;
	m_Gatetype = 0;
	m_drag = false;
	m_onGate = false;
	m_moveGate = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_TOOLBAR_AND, &CChildView::OnToolbarAnd)
	ON_COMMAND(ID_TOOLBAR_OR, &CChildView::OnToolbarOr)
	ON_COMMAND(ID_TOOLBAR_XOR2, &CChildView::OnToolbarXor2)
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_TOOLBAR_INCODER, &CChildView::OnToolbarIncoder)
	ON_COMMAND(ID_TOOLBAR_INPUT, &CChildView::OnToolbarInput)
	ON_COMMAND(ID_TOOLBAR_SEGMENT, &CChildView::OnToolbarSegment)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_TOOLBAR_MUX, &CChildView::OnToolbarMux)
	ON_COMMAND(ID_TOOLBAR_DECODE, &CChildView::OnToolbarDecode)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CBitmap bitmap;
	BITMAP bmpinfo;
	CDC dcmem;

	POSITION pos;
	for( pos = Gate_list.GetHeadPosition() ; pos != NULL ; Gate_list.GetNext(pos))
	{
		figure* temp;
		temp = Gate_list.GetAt(pos);
		temp->draw(&dc);
		temp->drawline(&dc);
	}
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);

	if(m_onGate)
	{
		m_temp = Gate_list.GetAt(Check_Position(point));
		m_moveGate = true;
		if( nFlags & MK_SHIFT)
		{
			if(m_temp->Get_Type() == 3)
			{
				if(m_temp->Get_Data1() == 1)
					m_temp->Set_Data1(0);
				else if(m_temp->Get_Data1() == 0)
					m_temp->Set_Data1(1);
			}
			else if( m_temp->Get_Type() < 3)
			{
				if(m_temp->Get_not() == 0)
					m_temp->Set_not(1);
				else if(m_temp->Get_not() == 1)
					m_temp->Set_not(0);
			}
			m_moveGate = false;
		}
	}
	else
	{
		if(m_drag)			//input, output 위에 클릭할 경우
		{
			m_temp = Gate_list.GetAt(Check_Position(point));
			pre_location = location;
		}
		else
		{
			figure* add;
			switch(m_Gatetype)
			{
			case 0:
				add = new Logic_and(point,0);
				break;
			case 1:
				add = new Logic_or(point,0);
				break;
			case 2:
				add = new Logic_xor(point,0);
				break;
			case 3:
				add = new Input(point,0);
				break;
			case 4:
				add = new Logic_Seg(point,0);
				break;
			case 5:
				add = new Logic_Encode(point,0);
				break;
			case 6:
				add = new Logic_Decode(point,0);
				break;
			case 7:
				add = new Logic_Mux(point,0);
				break;
			}
			Gate_list.AddTail(add);
		}
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if( m_moveGate)
	{
		m_temp->Set_Center(point);
		CClientDC dc(this);
		m_temp->draw(&dc);
		m_moveGate = false;
	}
	if(m_drag)
	{
		figure* to;
		if( Check_Position(point) != NULL)
		{
			to = Gate_list.GetAt(Check_Position(point));
			if ( to != m_temp && m_temp != NULL)
			{
				switch(location)
				{
				case 1:
					to->Set_prev1(m_temp);
					break;
				case 2:
					to->Set_prev2(m_temp);
					break;
				case 3:
					to->Set_prev3(m_temp);
					break;
				case 4:
					to->Set_prev4(m_temp);
					break;
				case 5:
					to->Set_prev5(m_temp);
					break;
				case 6:
					to->Set_prev6(m_temp);
					break;
				case 7:
					to->Set_next(m_temp);
					break;
				case 8:
					to->Set_next2(m_temp);
					break;
				case 9:
					to->Set_next3(m_temp);
					break;
				case 10:
					to->Set_next4(m_temp);
					break;
				}
				switch(pre_location)
				{
				case 1:
					m_temp->Set_prev1(to);
					break;
				case 2:
					m_temp->Set_prev2(to);
					break;
				case 3:
					m_temp->Set_prev3(to);
					break;
				case 4:
					m_temp->Set_prev4(to);
					break;
				case 5:
					m_temp->Set_prev5(to);
					break;
				case 6:
					m_temp->Set_prev6(to);
					break;
				case 7:
					m_temp->Set_next(to);
					break;
				case 8:
					m_temp->Set_next2(to);
					break;
				case 9:
					m_temp->Set_next3(to);
					break;
				case 10:
					m_temp->Set_next4(to);
					break;
				}
			}
		}
	}
	m_temp = NULL;
	Invalidate();
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnToolbarAnd()
{
	// TODO: Add your command handler code here
	m_Gatetype = 0;
}


void CChildView::OnToolbarOr()
{
	// TODO: Add your command handler code here
	m_Gatetype = 1;
}

void CChildView::OnToolbarXor2()
{
	m_Gatetype = 2;
	// TODO: Add your command handler code here
}

POSITION CChildView::Check_Position(CPoint point)
{
	POSITION pos;
	CClientDC dc(this);

	for( pos = Gate_list.GetHeadPosition() ; pos != NULL ; Gate_list.GetNext(pos))
	{
		figure* temp;
		temp = Gate_list.GetAt(pos);
		switch(temp->Check_On(point,&dc))
		{
		case 1:
			location = 1;
			m_drag = true;
			return pos;
		case 2:
			location = 2;
			m_drag = true;
			return pos;
		case 3:
			location = 3;
			m_drag = true;
			return pos;
		case 4:
			location = 4;
			m_drag = true;
			return pos;
		case 5:
			location = 5;
			m_drag = true;
			return pos;
		case 6:
			location = 6;
			m_drag = true;
			return pos;
		case 7:
			location = 7;
			m_drag = true;
			return pos;
		case 8:
			location = 8;
			m_drag = true;
			return pos;
		case 9:
			location = 9;
			m_drag = true;
			return pos;
		case 10:
			location = 10;
			m_drag = true;
			return pos;
		case 11:
			m_onGate = true;
			return pos;
		}
	}
	if( m_drag == true)
	{
		m_drag = false;
		Invalidate();
	}
	m_onGate = false;
	return NULL;
}

BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	if(nHitTest == HTCLIENT)
	{
		CPoint point;
		::GetCursorPos(&point);
		ScreenToClient(&point);
		Check_Position(point);
	}
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


void CChildView::OnToolbarIncoder()
{
	// TODO: Add your command handler code here
	m_Gatetype = 5;
}


void CChildView::OnToolbarInput()
{
	// TODO: Add your command handler code here
	m_Gatetype = 3;
}


void CChildView::OnToolbarSegment()
{
	// TODO: Add your command handler code here
	m_Gatetype = 4;
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(m_onGate)
	{
		figure* temp = Gate_list.GetAt(Check_Position(point));

		//이전 노드 연결 제거
		if( temp->Get_prev1() != NULL)
		{
			if( temp->Get_prev1()->Get_next() == temp)
				temp->Get_prev1()->Set_next(NULL);
			if( temp->Get_prev1()->Get_next2() == temp)
				temp->Get_prev1()->Set_next2(NULL);
			if( temp->Get_prev1()->Get_next3() == temp)
				temp->Get_prev1()->Set_next3(NULL);
			if( temp->Get_prev1()->Get_next4() == temp)
				temp->Get_prev1()->Set_next4(NULL);
		}
		if( temp->Get_prev2() != NULL)
		{
			if( temp->Get_prev2()->Get_next() == temp)
				temp->Get_prev2()->Set_next(NULL);
			if( temp->Get_prev2()->Get_next2() == temp)
				temp->Get_prev2()->Set_next2(NULL);
			if( temp->Get_prev2()->Get_next3() == temp)
				temp->Get_prev2()->Set_next3(NULL);
			if( temp->Get_prev2()->Get_next4() == temp)
				temp->Get_prev2()->Set_next4(NULL);
		}
		if( temp->Get_prev3() != NULL)
		{
			if( temp->Get_prev3()->Get_next() == temp)
				temp->Get_prev3()->Set_next(NULL);
			if( temp->Get_prev3()->Get_next2() == temp)
				temp->Get_prev3()->Set_next2(NULL);
			if( temp->Get_prev3()->Get_next3() == temp)
				temp->Get_prev3()->Set_next3(NULL);
			if( temp->Get_prev3()->Get_next4() == temp)
				temp->Get_prev3()->Set_next4(NULL);
		}
		if( temp->Get_prev4() != NULL)
		{
			if( temp->Get_prev4()->Get_next() == temp)
				temp->Get_prev4()->Set_next(NULL);
			if( temp->Get_prev4()->Get_next2() == temp)
				temp->Get_prev4()->Set_next2(NULL);
			if( temp->Get_prev4()->Get_next3() == temp)
				temp->Get_prev4()->Set_next3(NULL);
			if( temp->Get_prev4()->Get_next4() == temp)
				temp->Get_prev4()->Set_next4(NULL);
		}
		if( temp->Get_prev5() != NULL)
		{
			if( temp->Get_prev5()->Get_next() == temp)
				temp->Get_prev5()->Set_next(NULL);
			if( temp->Get_prev5()->Get_next2() == temp)
				temp->Get_prev5()->Set_next2(NULL);
			if( temp->Get_prev5()->Get_next3() == temp)
				temp->Get_prev5()->Set_next3(NULL);
			if( temp->Get_prev5()->Get_next4() == temp)
				temp->Get_prev5()->Set_next4(NULL);
		}
		if( temp->Get_prev6() != NULL)
		{
			if( temp->Get_prev6()->Get_next() == temp)
				temp->Get_prev6()->Set_next(NULL);
			if( temp->Get_prev6()->Get_next2() == temp)
				temp->Get_prev6()->Set_next2(NULL);
			if( temp->Get_prev6()->Get_next3() == temp)
				temp->Get_prev6()->Set_next3(NULL);
			if( temp->Get_prev6()->Get_next4() == temp)
				temp->Get_prev6()->Set_next4(NULL);
		}

		//다음 노드 연결 제거 
		if( temp->Get_next() != NULL)
		{
			if( temp->Get_next()->Get_prev1() == temp)
				temp->Get_next()->Set_prev1(NULL);
			if( temp->Get_next()->Get_prev2() == temp)
				temp->Get_next()->Set_prev2(NULL);
			if( temp->Get_next()->Get_prev3() == temp)
				temp->Get_next()->Set_prev3(NULL);
			if( temp->Get_next()->Get_prev4() == temp)
				temp->Get_next()->Set_prev4(NULL);
			if( temp->Get_next()->Get_prev5() == temp)
				temp->Get_next()->Set_prev5(NULL);
			if( temp->Get_next()->Get_prev6() == temp)
				temp->Get_next()->Set_prev6(NULL);
		}
		if( temp->Get_next2() != NULL)
		{
			if( temp->Get_next2()->Get_prev1() == temp)
				temp->Get_next2()->Set_prev1(NULL);
			if( temp->Get_next2()->Get_prev2() == temp)
				temp->Get_next2()->Set_prev2(NULL);
			if( temp->Get_next2()->Get_prev3() == temp)
				temp->Get_next2()->Set_prev3(NULL);
			if( temp->Get_next2()->Get_prev4() == temp)
				temp->Get_next2()->Set_prev4(NULL);
			if( temp->Get_next2()->Get_prev5() == temp)
				temp->Get_next2()->Set_prev5(NULL);
			if( temp->Get_next2()->Get_prev6() == temp)
				temp->Get_next2()->Set_prev6(NULL);
		}
		if( temp->Get_next3() != NULL)
		{
			if( temp->Get_next3()->Get_prev1() == temp)
				temp->Get_next3()->Set_prev1(NULL);
			if( temp->Get_next3()->Get_prev2() == temp)
				temp->Get_next3()->Set_prev2(NULL);
			if( temp->Get_next3()->Get_prev3() == temp)
				temp->Get_next3()->Set_prev3(NULL);
			if( temp->Get_next3()->Get_prev4() == temp)
				temp->Get_next3()->Set_prev4(NULL);
			if( temp->Get_next3()->Get_prev5() == temp)
				temp->Get_next3()->Set_prev5(NULL);
			if( temp->Get_next3()->Get_prev6() == temp)
				temp->Get_next3()->Set_prev6(NULL);
		}
		if( temp->Get_next4() != NULL)
		{
			if( temp->Get_next4()->Get_prev1() == temp)
				temp->Get_next4()->Set_prev1(NULL);
			if( temp->Get_next4()->Get_prev2() == temp)
				temp->Get_next4()->Set_prev2(NULL);
			if( temp->Get_next4()->Get_prev3() == temp)
				temp->Get_next4()->Set_prev3(NULL);
			if( temp->Get_next4()->Get_prev4() == temp)
				temp->Get_next4()->Set_prev4(NULL);
			if( temp->Get_next4()->Get_prev5() == temp)
				temp->Get_next4()->Set_prev5(NULL);
			if( temp->Get_next4()->Get_prev6() == temp)
				temp->Get_next4()->Set_prev6(NULL);
		}

		Gate_list.RemoveAt(Check_Position(point));
		Invalidate();
	}

	CWnd::OnRButtonDown(nFlags, point);
}

bool CChildView::Check_Circuit()
{
	POSITION pos;
	figure* temp;
	for( pos = Gate_list.GetHeadPosition() ; pos != NULL ; Gate_list.GetNext(pos))
	{
		temp = Gate_list.GetAt(pos);

		if(temp->Get_Type() < 3 || temp->Get_Type() == 6)
		{
			if( temp->Get_prev1() ==NULL)
				return false;
			if( temp->Get_prev2() == NULL)
				return false;
		}
		else if( temp->Get_Type() == 4 || temp->Get_Type() == 5)
		{
			if( temp->Get_prev1() ==NULL)
				return false;
			if( temp->Get_prev2() == NULL)
				return false;
			if( temp->Get_prev3() ==NULL)
				return false;
			if( temp->Get_prev4() == NULL)
				return false;
		}
		else if( temp->Get_Type() == 7)
		{
			if( temp->Get_prev1() ==NULL)
				return false;
			if( temp->Get_prev2() == NULL)
				return false;
			if( temp->Get_prev3() ==NULL)
				return false;
			if( temp->Get_prev4() == NULL)
				return false;
			if( temp->Get_prev5() ==NULL)
				return false;
			if( temp->Get_prev6() == NULL)
				return false;
		}
	}
	return true;
}
void CChildView::Logic_Circuit(figure* node)
{
	if( node->Get_next() == NULL && node->Check_Data() == 0)		//마지막 노드
	{
		CClientDC dc(this);
		if(node->Get_Type() == 4)
		{
			node->Logic();
			node->Print_Segment(&dc);
		}
		else
		{
			node->Logic();
			if( node->Get_outData1() == 1)
				MessageBox("결과 : 1");
			else
				MessageBox("결과 : 0");
		}
		// input을 제외한 게이트들의 데이터 초기화
		POSITION pos;
		for( pos = Gate_list.GetHeadPosition() ; pos != NULL ; Gate_list.GetNext(pos))
		{
			figure* temp;
			temp = Gate_list.GetAt(pos);
			if( temp->Get_Type() < 3)
			{
				temp->Set_Data1(-1);
				temp->Set_Data2(-1);
			}
			else if( temp->Get_Type() == 4)		//7 Segment
			{
				temp->Set_Data1(-1);
				temp->Set_Data2(-1);
				temp->Set_Data3(-1);
				temp->Set_Data4(-1);
			}
			else if( temp->Get_Type() == 5)		//Encoder
			{
				temp->Set_Data1(-1);
				temp->Set_Data2(-1);
				temp->Set_Data3(-1);
				temp->Set_Data4(-1);
			}
			else if( temp->Get_Type() == 6)		//Decoder
			{
				temp->Set_Data1(-1);
				temp->Set_Data2(-1);
			}
			else if( temp->Get_Type() == 7)		//Mux
			{
				temp->Set_Data1(-1);
				temp->Set_Data2(-1);
				temp->Set_Data3(-1);
				temp->Set_Data4(-1);
				temp->Set_Data5(-1);
				temp->Set_Data6(-1);
			}
		}
		return;
	}
	if(node->Get_Type() == 3)
	{
		if( node->Get_next()->Get_prev1() == node)
			node->Get_next()->Set_Data1(node->Get_Data1());
		if( node->Get_next()->Get_prev2() == node)
			node->Get_next()->Set_Data2(node->Get_Data1());
		if( node->Get_next()->Get_prev3() == node)
			node->Get_next()->Set_Data3(node->Get_Data1());
		if( node->Get_next()->Get_prev4() == node)
			node->Get_next()->Set_Data4(node->Get_Data1());
		if( node->Get_next()->Get_prev5() == node)
			node->Get_next()->Set_Data5(node->Get_Data1());
		if( node->Get_next()->Get_prev6() == node)
			node->Get_next()->Set_Data6(node->Get_Data1());
		Logic_Circuit(node->Get_next());			//다음 게이트로 이동
	}
	else if( node->Get_Type() == 5)		//인코더
	{
		switch(node->Check_Data()) 	//input이 있는 것에 따라
		{
		case 0:		//모두 있을 경우
			node->Logic();		//논리 실행
			// 정보 설정
			//next 1
			if( node->Get_next()->Get_prev1() == node)
				node->Get_next()->Set_Data1(node->Get_outData1());
			else if( node->Get_next()->Get_prev2() == node)
				node->Get_next()->Set_Data2(node->Get_outData1());
			else if( node->Get_next()->Get_prev3() == node)
				node->Get_next()->Set_Data3(node->Get_outData1());
			else if( node->Get_next()->Get_prev4() == node)
				node->Get_next()->Set_Data4(node->Get_outData1());
			else if( node->Get_next()->Get_prev5() == node)
				node->Get_next()->Set_Data5(node->Get_outData1());
			else if( node->Get_next()->Get_prev6() == node)
				node->Get_next()->Set_Data6(node->Get_outData1());
			//next 2
			if( node->Get_next2()->Get_prev1() == node)
				node->Get_next2()->Set_Data1(node->Get_outData2());
			else if( node->Get_next2()->Get_prev2() == node)
				node->Get_next2()->Set_Data2(node->Get_outData2());
			else if( node->Get_next2()->Get_prev3() == node)
				node->Get_next2()->Set_Data3(node->Get_outData2());
			else if( node->Get_next2()->Get_prev4() == node)
				node->Get_next2()->Set_Data4(node->Get_outData2());
			else if( node->Get_next2()->Get_prev5() == node)
				node->Get_next2()->Set_Data5(node->Get_outData2());
			else if( node->Get_next2()->Get_prev6() == node)
				node->Get_next2()->Set_Data6(node->Get_outData2());

			Logic_Circuit(node->Get_next());			//다음 게이트로 이동
			break;
		case 1:		//input 1이 없는 경우
			Logic_Circuit(node->Get_prev1());
			break;
		case 2:		//input 2가 없는 경우
			Logic_Circuit(node->Get_prev2());
			break;
		case 3:		//input 3가 없는 경우
			Logic_Circuit(node->Get_prev3());
			break;			 
		case 4:		//input 4가 없는 경우
			Logic_Circuit(node->Get_prev4());
			break;			 
		case 5:		//input 5가 없는 경우
			Logic_Circuit(node->Get_prev5());
			break;
		case 6:		//input 6이 없는 경우
			Logic_Circuit(node->Get_prev6());
			break;
		}
	}
	else if( node->Get_Type() == 6)		//디코더
	{
		switch(node->Check_Data()) 	//input이 있는 것에 따라
		{
		case 0:		//모두 있을 경우
			node->Logic();		//논리 실행
			// 정보 설정
			if( node->Get_next()->Get_prev1() == node)
				node->Get_next()->Set_Data1(node->Get_outData1());
			if( node->Get_next()->Get_prev2() == node)
				node->Get_next()->Set_Data2(node->Get_outData1());
			if( node->Get_next()->Get_prev3() == node)
				node->Get_next()->Set_Data3(node->Get_outData1());
			if( node->Get_next()->Get_prev4() == node)
				node->Get_next()->Set_Data4(node->Get_outData1());
			if( node->Get_next()->Get_prev5() == node)
				node->Get_next()->Set_Data5(node->Get_outData1());
			if( node->Get_next()->Get_prev6() == node)
				node->Get_next()->Set_Data6(node->Get_outData1());
			//next 2
			if( node->Get_next2()->Get_prev1() == node)
				node->Get_next2()->Set_Data1(node->Get_outData2());
			else if( node->Get_next2()->Get_prev2() == node)
				node->Get_next2()->Set_Data2(node->Get_outData2());
			else if( node->Get_next2()->Get_prev3() == node)
				node->Get_next2()->Set_Data3(node->Get_outData2());
			else if( node->Get_next2()->Get_prev4() == node)
				node->Get_next2()->Set_Data4(node->Get_outData2());
			else if( node->Get_next2()->Get_prev5() == node)
				node->Get_next2()->Set_Data5(node->Get_outData2());
			else if( node->Get_next2()->Get_prev6() == node)
				node->Get_next2()->Set_Data6(node->Get_outData2());
			//next 3
			if( node->Get_next3()->Get_prev1() == node)
				node->Get_next3()->Set_Data1(node->Get_outData3());
			else if( node->Get_next3()->Get_prev2() == node)
				node->Get_next3()->Set_Data2(node->Get_outData3());
			else if( node->Get_next3()->Get_prev3() == node)
				node->Get_next3()->Set_Data3(node->Get_outData3());
			else if( node->Get_next3()->Get_prev4() == node)
				node->Get_next3()->Set_Data4(node->Get_outData3());
			else if( node->Get_next3()->Get_prev5() == node)
				node->Get_next3()->Set_Data5(node->Get_outData3());
			else if( node->Get_next3()->Get_prev6() == node)
				node->Get_next3()->Set_Data6(node->Get_outData3());
			//next 4
			if( node->Get_next4()->Get_prev1() == node)
				node->Get_next4()->Set_Data1(node->Get_outData4());
			else if( node->Get_next4()->Get_prev2() == node)
				node->Get_next4()->Set_Data2(node->Get_outData4());
			else if( node->Get_next4()->Get_prev3() == node)
				node->Get_next4()->Set_Data3(node->Get_outData4());
			else if( node->Get_next4()->Get_prev4() == node)
				node->Get_next4()->Set_Data4(node->Get_outData4());
			else if( node->Get_next4()->Get_prev5() == node)
				node->Get_next4()->Set_Data5(node->Get_outData4());
			else if( node->Get_next4()->Get_prev6() == node)
				node->Get_next4()->Set_Data6(node->Get_outData4());
			Logic_Circuit(node->Get_next());			//다음 게이트로 이동
			break;
		case 1:		//input 1이 없는 경우
			Logic_Circuit(node->Get_prev1());
			break;
		case 2:		//input 2가 없는 경우
			Logic_Circuit(node->Get_prev2());
			break;
		case 3:		//input 3가 없는 경우
			Logic_Circuit(node->Get_prev3());
			break;			 
		case 4:		//input 4가 없는 경우
			Logic_Circuit(node->Get_prev4());
			break;			 
		case 5:		//input 5가 없는 경우
			Logic_Circuit(node->Get_prev5());
			break;
		case 6:		//input 6이 없는 경우
			Logic_Circuit(node->Get_prev6());
			break;
		}
	}
	else
	{
		switch(node->Check_Data()) 	//input이 있는 것에 따라
		{
		case 0:		//모두 있을 경우
			node->Logic();		//논리 실행
			// 정보 설정
			if( node->Get_next()->Get_prev1() == node)
				node->Get_next()->Set_Data1(node->Get_outData1());
			if( node->Get_next()->Get_prev2() == node)
				node->Get_next()->Set_Data2(node->Get_outData1());
			if( node->Get_next()->Get_prev3() == node)
				node->Get_next()->Set_Data3(node->Get_outData1());
			if( node->Get_next()->Get_prev4() == node)
				node->Get_next()->Set_Data4(node->Get_outData1());
			if( node->Get_next()->Get_prev5() == node)
				node->Get_next()->Set_Data5(node->Get_outData1());
			if( node->Get_next()->Get_prev6() == node)
				node->Get_next()->Set_Data6(node->Get_outData1());
			Logic_Circuit(node->Get_next());			//다음 게이트로 이동
			break;
		case 1:		//input 1이 없는 경우
			Logic_Circuit(node->Get_prev1());
			break;
		case 2:		//input 2가 없는 경우
			Logic_Circuit(node->Get_prev2());
			break;
		case 3:		//input 3가 없는 경우
			Logic_Circuit(node->Get_prev3());
			break;			 
		case 4:		//input 4가 없는 경우
			Logic_Circuit(node->Get_prev4());
			break;			 
		case 5:		//input 5가 없는 경우
			Logic_Circuit(node->Get_prev5());
			break;
		case 6:		//input 6이 없는 경우
			Logic_Circuit(node->Get_prev6());
			break;
		}
	}
}

void CChildView::OnToolbarMux()
{
	m_Gatetype = 7;
	// TODO: Add your command handler code here
}


void CChildView::OnToolbarDecode()
{
	m_Gatetype = 6;
	// TODO: Add your command handler code here
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if(nChar == VK_SPACE)
	{
		POSITION pos;
		figure* temp; 
		CPoint change;
		CClientDC dc(this);
		for( pos = Gate_list.GetHeadPosition() ; pos != NULL ; Gate_list.GetNext(pos))
		{
			temp = Gate_list.GetAt(pos);
			if( temp->Get_Type() < 3 && temp->Get_next() != NULL)
			{
				if( temp->Get_next()->Get_prev1() == temp)
					change = temp->Get_next()->Get_input1();
				if( temp->Get_next()->Get_prev2() == temp)
					change = temp->Get_next()->Get_input2();
				if( temp->Get_next()->Get_prev3() == temp)
					change = temp->Get_next()->Get_input3();
				if( temp->Get_next()->Get_prev4() == temp)
					change = temp->Get_next()->Get_input4();
				if( temp->Get_next()->Get_prev5() == temp)
					change = temp->Get_next()->Get_input5();
				if( temp->Get_next()->Get_prev6() == temp)
					change = temp->Get_next()->Get_input6();
				change.x -= 100;
				change.y = temp->Get_Center().y;
				temp->Set_Center(change);
				temp->draw(&dc);
			}
		}

		for( pos = Gate_list.GetHeadPosition() ; pos != NULL ; Gate_list.GetNext(pos))
		{
			temp = Gate_list.GetAt(pos);
			if(temp->Get_Type() == 3 && temp->Get_next() != NULL)
			{
				if( temp->Get_next()->Get_prev1() == temp)
					change = temp->Get_next()->Get_input1();
				if( temp->Get_next()->Get_prev2() == temp)
					change = temp->Get_next()->Get_input2();
				if( temp->Get_next()->Get_prev3() == temp)
					change = temp->Get_next()->Get_input3();
				if( temp->Get_next()->Get_prev4() == temp)
					change = temp->Get_next()->Get_input4();
				if( temp->Get_next()->Get_prev5() == temp)
					change = temp->Get_next()->Get_input5();
				if( temp->Get_next()->Get_prev6() == temp)
					change = temp->Get_next()->Get_input6();
				change.x -= 50;
				temp->Set_Center(change);
			}
		}
		Invalidate();
	}
	else if(nChar == VK_F5)
	{
		if(Check_Circuit())
			Logic_Circuit(Gate_list.GetHead());
		else
			MessageBox ("회로가 완전하지 않습니다!");
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
