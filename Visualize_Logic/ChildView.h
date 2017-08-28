
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once

#include "Logic_and.h"
#include "Logic_or.h"
#include "Logic_xor.h"
#include "Logic_Encode.h"
#include "Input.h"
#include "Logic_Seg.h"
#include "Logic_Decode.h"
#include "Logic_Mux.h"
// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	int location;
	int pre_location;
	figure* m_temp;
	int m_Gatetype;

	bool m_drag;
	bool m_onGate;
	bool m_moveGate;
	CList<figure*> Gate_list;

	bool Check_Circuit();
	void Logic_Circuit(figure* node);
	POSITION Check_Position(CPoint point);	//현재 위치에 점이 있는지 확인
	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnToolbarAnd();
	afx_msg void OnToolbarOr();
	afx_msg void OnToolbarXor2();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnToolbarIncoder();
	afx_msg void OnToolbarInput();
	afx_msg void OnToolbarSegment();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnToolbarMux();
	afx_msg void OnToolbarDecode();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

