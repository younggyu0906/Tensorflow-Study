
// character1.h : character1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Ccharacter1App:
// �� Ŭ������ ������ ���ؼ��� character1.cpp�� �����Ͻʽÿ�.
//

class Ccharacter1App : public CWinApp
{
public:
	Ccharacter1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ccharacter1App theApp;
