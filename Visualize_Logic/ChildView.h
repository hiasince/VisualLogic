
// ChildView.h : CChildView Ŭ������ �������̽�
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
// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
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
	POSITION Check_Position(CPoint point);	//���� ��ġ�� ���� �ִ��� Ȯ��
	// ������ �޽��� �� �Լ�
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

