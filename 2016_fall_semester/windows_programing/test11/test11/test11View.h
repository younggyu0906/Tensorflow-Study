
// test11View.h : Ctest11View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Ctest11View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Ctest11View();
	DECLARE_DYNCREATE(Ctest11View)

public:
	enum{ IDD = IDD_TEST11_FORM };

// 특성입니다.
public:
	Ctest11Doc* GetDocument() const;

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
	virtual ~Ctest11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // test11View.cpp의 디버그 버전
inline Ctest11Doc* Ctest11View::GetDocument() const
   { return reinterpret_cast<Ctest11Doc*>(m_pDocument); }
#endif

