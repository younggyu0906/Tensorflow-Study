// KYGImageTool.h : KYGImageTool ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CKYGImageToolApp:
// �� Ŭ������ ������ ���ؼ��� KYGImageTool.cpp�� �����Ͻʽÿ�.
//

class CDib;
class CKYGImageToolApp : public CWinApp
{
public:
	CKYGImageToolApp();
	~CKYGImageToolApp();

public:
	CDib* m_pNewDib;
	CMultiDocTemplate* m_pImageDocTemplate;
// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnAppAbout();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI *pCmdUI);
};

extern CKYGImageToolApp theApp;

// ���� �Լ� ����

void AfxNewImage(CDib& dib);

