
// RButton.h : RButton ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CRButtonApp:
// �� Ŭ������ ������ ���ؼ��� RButton.cpp�� �����Ͻʽÿ�.
//

class CRButtonApp : public CWinApp
{
public:
	CRButtonApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRButtonApp theApp;
