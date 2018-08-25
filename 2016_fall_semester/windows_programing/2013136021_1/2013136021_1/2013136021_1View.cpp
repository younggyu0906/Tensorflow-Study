
// 2013136021_1View.cpp : CMy2013136021_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2013136021_1.h"
#endif

#include "2013136021_1Doc.h"
#include "2013136021_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136021_1View

IMPLEMENT_DYNCREATE(CMy2013136021_1View, CView)

BEGIN_MESSAGE_MAP(CMy2013136021_1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136021_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy2013136021_1View ����/�Ҹ�

CMy2013136021_1View::CMy2013136021_1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_DrawMove = false;
	cntLine = 0;
}

CMy2013136021_1View::~CMy2013136021_1View()
{
}

BOOL CMy2013136021_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2013136021_1View �׸���

void CMy2013136021_1View::OnDraw(CDC* pDC/*pDC*/)
{
	CMy2013136021_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CString str;

	str.Format(_T("���� ���� : %d"), cntLine);  // �簢���� ������ ���
	pDC->TextOut(20, 20, str);
}


// CMy2013136021_1View �μ�


void CMy2013136021_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136021_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2013136021_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2013136021_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2013136021_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136021_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136021_1View ����

#ifdef _DEBUG
void CMy2013136021_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136021_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136021_1Doc* CMy2013136021_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136021_1Doc)));
	return (CMy2013136021_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136021_1View �޽��� ó����


void CMy2013136021_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	
	if(m_DrawMove == true) {
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);
		dc.MoveTo(SP.x, SP.y);
		dc.LineTo(EP.x, EP.y);

		EP.x = point.x;
		EP.y = point.y;
		dc.MoveTo(SP.x, SP.y);
		dc.LineTo(EP.x, EP.y);
	}

	CView::OnMouseMove(nFlags, point);
}


void CMy2013136021_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	
	m_DrawMove = true;
	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMy2013136021_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);
	EP.x = point.x;
	EP.y = point.y;
	dc.MoveTo(SP.x, SP.y);
	dc.LineTo(EP.x, EP.y);
	m_DrawMove = false;
	Invalidate(false);
	cntLine++;

	CView::OnLButtonUp(nFlags, point);
}
