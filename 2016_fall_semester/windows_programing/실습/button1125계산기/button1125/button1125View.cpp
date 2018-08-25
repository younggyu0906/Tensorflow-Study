
// button1125View.cpp : Cbutton1125View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// Cbutton1125View ����/�Ҹ�

Cbutton1125View::Cbutton1125View()
	: CFormView(Cbutton1125View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

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


// Cbutton1125View ����

#ifdef _DEBUG
void Cbutton1125View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cbutton1125View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cbutton1125Doc* Cbutton1125View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cbutton1125Doc)));
	return (Cbutton1125Doc*)m_pDocument;
}
#endif //_DEBUG


// Cbutton1125View �޽��� ó����


void Cbutton1125View::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int state_checker = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("��ư ���� : %d, %d, %d, %d"), state_checker, state_3state, state_radio1, state_radio2);
//	MessageBox(str,_T("��ư����"),MB_ICONINFORMATION);
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("0"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("1"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("2"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("3"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("4"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("5"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("6"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("7"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("8"));
	m_edit.SetWindowTextW(str);
}


void Cbutton1125View::OnBnClicked9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format(_T("9"));
	m_edit.SetWindowTextW(str);
}
