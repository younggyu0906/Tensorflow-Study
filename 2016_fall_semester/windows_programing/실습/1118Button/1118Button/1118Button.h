
// 1118Button.h : 1118Button ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy1118ButtonApp:
// �� Ŭ������ ������ ���ؼ��� 1118Button.cpp�� �����Ͻʽÿ�.
//

class CMy1118ButtonApp : public CWinApp
{
public:
	CMy1118ButtonApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1118ButtonApp theApp;
