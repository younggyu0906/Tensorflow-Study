
// 2013136021_3.h : 2013136021_3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy2013136021_3App:
// �� Ŭ������ ������ ���ؼ��� 2013136021_3.cpp�� �����Ͻʽÿ�.
//

class CMy2013136021_3App : public CWinAppEx
{
public:
	CMy2013136021_3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2013136021_3App theApp;
