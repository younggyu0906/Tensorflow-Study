
// 2013136021_3View.cpp : CMy2013136021_3View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2013136021_3.h"
#endif

#include "2013136021_3Doc.h"
#include "2013136021_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136021_3View

IMPLEMENT_DYNCREATE(CMy2013136021_3View, CView)

BEGIN_MESSAGE_MAP(CMy2013136021_3View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136021_3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMy2013136021_3View ����/�Ҹ�

CMy2013136021_3View::CMy2013136021_3View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_xPos = 0;
	m_yPos = 0;
	xMax = 0;
	yMax = 0;
}

CMy2013136021_3View::~CMy2013136021_3View()
{
}

BOOL CMy2013136021_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2013136021_3View �׸���

void CMy2013136021_3View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136021_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy2013136021_3View �μ�


void CMy2013136021_3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136021_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2013136021_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2013136021_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2013136021_3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136021_3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136021_3View ����

#ifdef _DEBUG
void CMy2013136021_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136021_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136021_3Doc* CMy2013136021_3View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136021_3Doc)));
	return (CMy2013136021_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136021_3View �޽��� ó����


void CMy2013136021_3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch(nChar) {
	case VK_LEFT:
		m_xPos -=10;
		break;
	case VK_RIGHT:
		m_xPos +=10;
		break;
	case VK_UP:
		m_yPos -=10;
		break;
	case VK_DOWN:
		m_yPos +=10;
		break;
	}

	if(m_xPos >= 400 && m_yPos >= 400 && m_xPos+100 <= 600 && m_yPos+100 <= 600) {
		m_xPos = 0;
		m_yPos = 0;
	}

	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy2013136021_3View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.SelectStockObject(NULL_BRUSH);
	dc.Ellipse(m_xPos, m_yPos,m_xPos+100, m_yPos+100);
	dc.Rectangle(400, 400, 600, 600);
}



void CMy2013136021_3View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	xMax = cx;
	yMax = cy;
}
