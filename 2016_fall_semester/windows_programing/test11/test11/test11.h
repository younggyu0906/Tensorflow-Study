
// test11.h : test11 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Ctest11App:
// �� Ŭ������ ������ ���ؼ��� test11.cpp�� �����Ͻʽÿ�.
//

class Ctest11App : public CWinApp
{
public:
	Ctest11App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctest11App theApp;
