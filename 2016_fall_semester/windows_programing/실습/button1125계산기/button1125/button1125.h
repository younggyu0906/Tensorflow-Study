
// button1125.h : button1125 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cbutton1125App:
// �� Ŭ������ ������ ���ؼ��� button1125.cpp�� �����Ͻʽÿ�.
//

class Cbutton1125App : public CWinApp
{
public:
	Cbutton1125App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cbutton1125App theApp;
