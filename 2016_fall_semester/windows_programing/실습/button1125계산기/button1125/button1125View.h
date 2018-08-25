
// button1125View.h : Cbutton1125View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cbutton1125View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cbutton1125View();
	DECLARE_DYNCREATE(Cbutton1125View)

public:
	enum{ IDD = IDD_BUTTON1125_FORM };

// 특성입니다.
public:
	Cbutton1125Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~Cbutton1125View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	afx_msg void OnBnClickedButton1();
	CEdit m_edit;
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
};

#ifndef _DEBUG  // button1125View.cpp의 디버그 버전
inline Cbutton1125Doc* Cbutton1125View::GetDocument() const
   { return reinterpret_cast<Cbutton1125Doc*>(m_pDocument); }
#endif

