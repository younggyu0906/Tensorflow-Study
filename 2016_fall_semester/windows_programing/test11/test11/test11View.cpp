
// test11View.cpp : Ctest11View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// Ctest11View ����/�Ҹ�

Ctest11View::Ctest11View()
	: CFormView(Ctest11View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Ctest11View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Ctest11View ����

#ifdef _DEBUG
void Ctest11View::AssertValid() const
{
	CFormView::AssertValid();
}

void Ctest11View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Ctest11Doc* Ctest11View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest11Doc)));
	return (Ctest11Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest11View �޽��� ó����


void Ctest11View::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("1"));
	m_Edit.SetWindowTextW(str);
}


void Ctest11View::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
