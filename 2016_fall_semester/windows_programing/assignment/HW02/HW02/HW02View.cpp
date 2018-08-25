
// HW02View.cpp : CHW02View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "HW02.h"
#endif

#include "HW02Doc.h"
#include "HW02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW02View

IMPLEMENT_DYNCREATE(CHW02View, CView)

BEGIN_MESSAGE_MAP(CHW02View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHW02View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHW02View ����/�Ҹ�

CHW02View::CHW02View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
}

CHW02View::~CHW02View()
{
}

BOOL CHW02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CHW02View �׸���

void CHW02View::OnDraw(CDC* /*pDC*/)
{
	CHW02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CHW02View �μ�


void CHW02View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHW02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CHW02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CHW02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CHW02View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHW02View ����

#ifdef _DEBUG
void CHW02View::AssertValid() const
{
	CView::AssertValid();
}

void CHW02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW02Doc* CHW02View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW02Doc)));
	return (CHW02Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW02View �޽��� ó����

void CHW02View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	if(DrawMove == true) {
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);
		dc.MoveTo(SP.x, SP.y);
		if(leftB)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);

		EP.x = point.x;
		EP.y = point.y;
		dc.MoveTo(SP.x, SP.y);
		if(leftB)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);

	}

	CView::OnMouseMove(nFlags, point);
}


void CHW02View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	leftB = true;
	DrawMove = true;
	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CHW02View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);
	EP.x = point.x;
	EP.y = point.y;
	dc.MoveTo(SP.x, SP.y);
	dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
	DrawMove = false;

	CView::OnLButtonUp(nFlags, point);
}


void CHW02View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	leftB = false;
	DrawMove = true;
	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	
	CView::OnRButtonDown(nFlags, point);
}


void CHW02View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	CClientDC dc(this);

	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);
	EP.x = point.x;
	EP.y = point.y;
	dc.MoveTo(SP.x, SP.y);
	dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
	DrawMove = false;

	OnContextMenu(this, point);
}