
// noteTest.h : noteTest ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CnoteTestApp:
// �� Ŭ������ ������ ���ؼ��� noteTest.cpp�� �����Ͻʽÿ�.
//

class CnoteTestApp : public CWinApp
{
public:
	CnoteTestApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CnoteTestApp theApp;
