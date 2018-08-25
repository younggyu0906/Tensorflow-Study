
// lineView.cpp : ClineView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "line.h"
#endif

#include "lineDoc.h"
#include "lineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClineView

IMPLEMENT_DYNCREATE(ClineView, CView)

BEGIN_MESSAGE_MAP(ClineView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &ClineView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// ClineView ����/�Ҹ�

ClineView::ClineView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

ClineView::~ClineView()
{
}

BOOL ClineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// ClineView �׸���

void ClineView::OnDraw(CDC* /*pDC*/)
{
	ClineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// ClineView �μ�


void ClineView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL ClineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void ClineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void ClineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void ClineView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ClineView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ClineView ����

#ifdef _DEBUG
void ClineView::AssertValid() const
{
	CView::AssertValid();
}

void ClineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ClineDoc* ClineView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ClineDoc)));
	return (ClineDoc*)m_pDocument;
}
#endif //_DEBUG


// ClineView �޽��� ó����


void ClineView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.MoveTo(10, 10);
	dc.LineTo(50, 50);

	dc.MoveTo(10, 10);
	dc.LineTo(10, 50);
	
	dc.MoveTo(10, 10);
	dc.LineTo(50, 10);

	dc.MoveTo(50, 10);
	dc.LineTo(10, 50);

	dc.MoveTo(50, 10);
	dc.LineTo(50, 50);

	dc.MoveTo(50, 50);
	dc.LineTo(50, 10);
}
