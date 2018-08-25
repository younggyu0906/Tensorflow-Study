
// button1125View.cpp : Cbutton1125View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "button1125.h"
#endif

#include "button1125Doc.h"
#include "button1125View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbutton1125View

IMPLEMENT_DYNCREATE(Cbutton1125View, CFormView)

BEGIN_MESSAGE_MAP(Cbutton1125View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Cbutton1125View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_0, &Cbutton1125View::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &Cbutton1125View::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &Cbutton1125View::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &Cbutton1125View::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &Cbutton1125View::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &Cbutton1125View::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &Cbutton1125View::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &Cbutton1125View::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &Cbutton1125View::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &Cbutton1125View::OnBnClicked9)
END_MESSAGE_MAP()

// Cbutton1125View 생성/소멸

Cbutton1125View::Cbutton1125View()
	: CFormView(Cbutton1125View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cbutton1125View::~Cbutton1125View()
{
}

void Cbutton1125View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BOOL Cbutton1125View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cbutton1125View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


	m_checkbox.SetCheck(1);
	m_3state.SetCheck(1);
	m_radio2.SetCheck(1);
	m_edit.SetLimitText(20);
}


// Cbutton1125View 진단

#ifdef _DEBUG
void Cbutton1125View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cbutton1125View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cbutton1125Doc* Cbutton1125View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cbutton1125Doc)));
	return (Cbutton1125Doc*)m_pDocument;
}
#endif //_DEBUG


// Cbutton1125View 메시지 처리기


void Cbutton1125View::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int state_checker = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("버튼 상태 : %d, %d, %d, %d"), state_checker, state_3state, state_radio1, state_radio2);
//	MessageBox(str,_T("버튼예제"),MB_ICONINFORMATION);
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("0"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("1"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("2"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("3"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("4"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("5"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("6"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("7"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("8"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("9"));
	m_edit.SetWindowTextW(str);
}
