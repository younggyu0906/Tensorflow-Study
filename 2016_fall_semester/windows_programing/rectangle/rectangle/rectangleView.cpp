
// rectangleView.cpp : CrectangleView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "rectangle.h"
#endif

#include "rectangleDoc.h"
#include "rectangleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CrectangleView

static int cnt = 0; // �簢���� ������ ������ ��������

IMPLEMENT_DYNCREATE(CrectangleView, CView)

BEGIN_MESSAGE_MAP(CrectangleView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CrectangleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CrectangleView ����/�Ҹ�

CrectangleView::CrectangleView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CrectangleView::~CrectangleView()
{
}

BOOL CrectangleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CrectangleView �׸���

void CrectangleView::OnDraw(CDC* pDC)
{
	CrectangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString str;

	str.Format(_T("�簢�� ��� ���� : %d"), cnt);  // �簢���� ������ ���
	pDC->TextOut(20, 20, str);
}


// CrectangleView �μ�


void CrectangleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CrectangleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CrectangleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CrectangleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CrectangleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CrectangleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CrectangleView ����

#ifdef _DEBUG
void CrectangleView::AssertValid() const
{
	CView::AssertValid();
}

void CrectangleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CrectangleDoc* CrectangleView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CrectangleDoc)));
	return (CrectangleDoc*)m_pDocument;
}
#endif //_DEBUG


// CrectangleView �޽��� ó����


void CrectangleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Invalidate(false); // ȭ���� ������ �Լ�
	cnt++; // Ŭ���� ������ �簢���� ����Ƿ� �簢���� ������ ������Ŵ.
	CView::OnLButtonDown(nFlags, point); 
	CClientDC dc(this);
	dc.Rectangle(point.x-20, point.y-20, point.x+20, point.y+20); // ���� Ŭ���� �ϸ� �簢�� ���
	CView::OnLButtonDown(nFlags, point);
}
