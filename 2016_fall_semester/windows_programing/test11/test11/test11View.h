
// test11View.h : Ctest11View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Ctest11View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Ctest11View();
	DECLARE_DYNCREATE(Ctest11View)

public:
	enum{ IDD = IDD_TEST11_FORM };

// Ư���Դϴ�.
public:
	Ctest11Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~Ctest11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit;
	CButton m_check;
	CButton m_triButton;
	CButton m_radio;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // test11View.cpp�� ����� ����
inline Ctest11Doc* Ctest11View::GetDocument() const
   { return reinterpret_cast<Ctest11Doc*>(m_pDocument); }
#endif

