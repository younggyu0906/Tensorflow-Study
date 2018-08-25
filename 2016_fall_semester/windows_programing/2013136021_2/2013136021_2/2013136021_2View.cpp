
// 2013136021_2View.cpp : CMy2013136021_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2013136021_2.h"
#endif

#include "2013136021_2Doc.h"
#include "2013136021_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136021_2View

IMPLEMENT_DYNCREATE(CMy2013136021_2View, CView)

BEGIN_MESSAGE_MAP(CMy2013136021_2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136021_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
//	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CMy2013136021_2View ����/�Ҹ�

CMy2013136021_2View::CMy2013136021_2View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	
}

CMy2013136021_2View::~CMy2013136021_2View()
{
}

BOOL CMy2013136021_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2013136021_2View �׸���

void CMy2013136021_2View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136021_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy2013136021_2View �μ�


void CMy2013136021_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136021_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2013136021_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2013136021_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2013136021_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136021_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136021_2View ����

#ifdef _DEBUG
void CMy2013136021_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136021_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136021_2Doc* CMy2013136021_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136021_2Doc)));
	return (CMy2013136021_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136021_2View �޽��� ó����


void CMy2013136021_2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.Rectangle(0, 0, 500, 100);

	for(int i = 100; i <= 400; i += 100) {
		dc.MoveTo(i, 0);
		dc.LineTo(i, 100);
	}
}


void CMy2013136021_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(point.y > 0 && point.y < 100) {
		if(point.x > 0 && point.x < 100) {
			Changed = AfxGetApp()->LoadCursor(IDC_CURSOR1); // ���콺 ������ ELL�����ͷ� ����
			SetCursor(Changed);
		}
		else if(point.x > 100 && point.x < 200) {
			Changed = AfxGetApp()->LoadCursor(IDC_CURSOR2); // ���콺 ������ ELL�����ͷ� ����
			SetCursor(Changed);
		}
		else if(point.x > 200 && point.x < 300) {
			Changed = AfxGetApp()->LoadCursor(IDC_CURSOR3); // ���콺 ������ ELL�����ͷ� ����
			SetCursor(Changed);
		}
		else if(point.x > 300 && point.x < 400) {
			Changed = AfxGetApp()->LoadCursor(IDC_CURSOR4); // ���콺 ������ ELL�����ͷ� ����
			SetCursor(Changed);
		}
		else if(point.x > 400 && point.x < 500) {
			Changed = AfxGetApp()->LoadCursor(IDC_CURSOR5); // ���콺 ������ ELL�����ͷ� ����
			SetCursor(Changed);
		}
	}

	CView::OnMouseMove(nFlags, point);
}
