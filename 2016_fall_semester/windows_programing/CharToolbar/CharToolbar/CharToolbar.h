
// CharToolbar.h : CharToolbar ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CCharToolbarApp:
// �� Ŭ������ ������ ���ؼ��� CharToolbar.cpp�� �����Ͻʽÿ�.
//

class CCharToolbarApp : public CWinApp
{
public:
	CCharToolbarApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCharToolbarApp theApp;
