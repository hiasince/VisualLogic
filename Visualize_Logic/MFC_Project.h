
// MFC_Project.h : MFC_Project ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC_ProjectApp:
// �� Ŭ������ ������ ���ؼ��� MFC_Project.cpp�� �����Ͻʽÿ�.
//

class CMFC_ProjectApp : public CWinApp
{
public:
	CMFC_ProjectApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_ProjectApp theApp;
