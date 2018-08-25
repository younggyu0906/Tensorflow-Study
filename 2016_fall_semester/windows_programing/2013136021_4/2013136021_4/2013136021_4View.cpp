
// 2013136021_4View.cpp : CMy2013136021_4View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2013136021_4.h"
#endif

#include "2013136021_4Doc.h"
#include "2013136021_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136021_4View

IMPLEMENT_DYNCREATE(CMy2013136021_4View, CView)

BEGIN_MESSAGE_MAP(CMy2013136021_4View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136021_4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_LINE, &CMy2013136021_4View::OnLine)
	ON_COMMAND(ID_ELLIPSE, &CMy2013136021_4View::OnEllipse)
	ON_COMMAND(ID_RECTANGLE, &CMy2013136021_4View::OnRectangle)
	ON_COMMAND(ID_CLEAR, &CMy2013136021_4View::OnClear)
END_MESSAGE_MAP()

// CMy2013136021_4View ����/�Ҹ�

CMy2013136021_4View::CMy2013136021_4View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	choice = 0;
}

CMy2013136021_4View::~CMy2013136021_4View()
{
}

BOOL CMy2013136021_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2013136021_4View �׸���

void CMy2013136021_4View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136021_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy2013136021_4View �μ�


void CMy2013136021_4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136021_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2013136021_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2013136021_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2013136021_4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136021_4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136021_4View ����

#ifdef _DEBUG
void CMy2013136021_4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136021_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136021_4Doc* CMy2013136021_4View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136021_4Doc)));
	return (CMy2013136021_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136021_4View �޽��� ó����


void CMy2013136021_4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	DrawMove = true;
	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMy2013136021_4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_COPYPEN);
		EP.x = point.x;
		EP.y = point.y;
		dc.MoveTo(SP.x, SP.y);
		if(choice == 1)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 2)
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 3)
			dc.LineTo(EP.x, EP.y);
		DrawMove = false;

		CView::OnLButtonUp(nFlags, point);
}


void CMy2013136021_4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CClientDC dc(this);

	if(DrawMove == true) {
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);
		dc.MoveTo(SP.x, SP.y);

		if(choice == 1)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 2)
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 3)
			dc.LineTo(EP.x, EP.y);

		EP.x = point.x;
		EP.y = point.y;
		dc.MoveTo(SP.x, SP.y);

		if(choice == 1)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 2)
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 3)
			dc.LineTo(EP.x, EP.y);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2013136021_4View::OnLine()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CClientDC dc(this);
	choice = 3;
}


void CMy2013136021_4View::OnEllipse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CClientDC dc(this);
	choice = 2;
}


void CMy2013136021_4View::OnRectangle()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CClientDC dc(this);
	choice = 1;
}



void CMy2013136021_4View::OnClear()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CClientDC dc(this);
	Invalidate(TRUE);
}
