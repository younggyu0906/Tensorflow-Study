
// test11View.cpp : Ctest11View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "test11.h"
#endif

#include "test11Doc.h"
#include "test11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest11View

IMPLEMENT_DYNCREATE(Ctest11View, CFormView)

BEGIN_MESSAGE_MAP(Ctest11View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest11View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest11View::OnBnClickedButton2)
END_MESSAGE_MAP()

// Ctest11View 생성/소멸

Ctest11View::Ctest11View()
	: CFormView(Ctest11View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Ctest11View::~Ctest11View()
{
}

void Ctest11View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_CHECK1, m_check);
	DDX_Control(pDX, IDC_CHECK2, m_triButton);
	DDX_Control(pDX, IDC_RADIO1, m_radio);
}

BOOL Ctest11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Ctest11View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Ctest11View 진단

#ifdef _DEBUG
void Ctest11View::AssertValid() const
{
	CFormView::AssertValid();
}

void Ctest11View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Ctest11Doc* Ctest11View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest11Doc)));
	return (Ctest11Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest11View 메시지 처리기


void Ctest11View::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("1"));
	m_Edit.SetWindowTextW(str);
}


void Ctest11View::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
