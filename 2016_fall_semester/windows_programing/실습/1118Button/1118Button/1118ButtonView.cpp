
// 1118ButtonView.cpp : CMy1118ButtonView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1118Button.h"
#endif

#include "1118ButtonDoc.h"
#include "1118ButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1118ButtonView

IMPLEMENT_DYNCREATE(CMy1118ButtonView, CView)

	BEGIN_MESSAGE_MAP(CMy1118ButtonView, CView)
		// ǥ�� �μ� ����Դϴ�.
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_WM_CREATE()
		//101�� ��ư Ŭ�������� üũ������ ��ȯ����
		ON_BN_CLICKED(101, bClick1)
   //2,3�� �߰�
		ON_BN_CLICKED(107, bClick2)
		ON_BN_CLICKED(108, bClick3)
	END_MESSAGE_MAP()

	// CMy1118ButtonView ����/�Ҹ�

	CMy1118ButtonView::CMy1118ButtonView()
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	}

	CMy1118ButtonView::~CMy1118ButtonView()
	{
	}

	BOOL CMy1118ButtonView::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
		//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

		return CView::PreCreateWindow(cs);
	}

	// CMy1118ButtonView �׸���

	void CMy1118ButtonView::OnDraw(CDC* /*pDC*/)
	{
		CMy1118ButtonDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	}


	// CMy1118ButtonView �μ�

	BOOL CMy1118ButtonView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// �⺻���� �غ�
		return DoPreparePrinting(pInfo);
	}

	void CMy1118ButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	}

	void CMy1118ButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
	}


	// CMy1118ButtonView ����

#ifdef _DEBUG
	void CMy1118ButtonView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CMy1118ButtonView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CMy1118ButtonDoc* CMy1118ButtonView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1118ButtonDoc)));
		return (CMy1118ButtonDoc*)m_pDocument;
	}
#endif //_DEBUG


	// CMy1118ButtonView �޽��� ó����


	int CMy1118ButtonView::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CView::OnCreate(lpCreateStruct) == -1)
			return -1;

		// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
		// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
		//��ư ��Ʈ�� ����
		m_pushbutton.Create(_T("Ǫ�� ��ư"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			CRect(20,20,160,50),this,101);
		m_checkbox.Create(_T("üũ �ڽ�"), WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX,
			CRect(20,60,160,90),this,102);
		m_3state.Create(_T("3���� üũ �ڽ�"), WS_CHILD|WS_VISIBLE|BS_AUTO3STATE,
			CRect(20,100,160,130),this,103);
		//���� ��ư�� �׷����� ������
		m_radio1.Create(_T("���� ��ư 1"), WS_CHILD|WS_VISIBLE|WS_GROUP|BS_AUTORADIOBUTTON,
			CRect(20,170,160,200),this,104);
		m_radio2.Create(_T("���� ��ư 2"), WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,
			CRect(20,210,160,240),this,105);
		m_groupbox.Create(_T("�׷� �ڽ�"), WS_CHILD|WS_VISIBLE|BS_GROUPBOX,
			CRect(10,140,170,250),this,106);


		//�ΰ��� Ǫ�ù�ư ��
		m_pushbutton2.Create(_T("Ǫ�� ��ư2"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			CRect(170,20,300,50),this,107);
		m_pushbutton3.Create(_T("Ǫ�� ��ư3"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			CRect(310,20,500,50),this,108);

		//��ư �ʱ�ȭ
		m_checkbox.SetCheck(1);
		m_3state.SetCheck(2);
		m_radio2.SetCheck(1);
		return 0;
	}


	void CMy1118ButtonView::bClick1(void)
	{
		int state_checkbox = m_checkbox.GetCheck();
		int state_3state = m_3state.GetCheck();
		int state_radio1 = m_radio1.GetCheck();
		int state_radio2 = m_radio2.GetCheck();

		CString str;
		str.Format(_T("��ư ���� : %d, %d, %d, %d"),
			state_checkbox, state_3state, state_radio1, state_radio2);
		MessageBox(str, _T("Button1 exam"), MB_ICONINFORMATION);
	}


	void CMy1118ButtonView::bClick2(void)
	{
		CString str;
		str.Format(_T("Button2 Click"));
		MessageBox(str, _T("Button1 exam"), MB_ICONINFORMATION);
	}


	void CMy1118ButtonView::bClick3(void)
	{
		CString str;
		str.Format(_T("Button3 Click"));
		MessageBox(str, _T("Button1 exam"), MB_ICONINFORMATION);
	}
