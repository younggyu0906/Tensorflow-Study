
// 2013136021_3View.cpp : CMy2013136021_3View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136021_3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMy2013136021_3View 생성/소멸

CMy2013136021_3View::CMy2013136021_3View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2013136021_3View 그리기

void CMy2013136021_3View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136021_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy2013136021_3View 인쇄


void CMy2013136021_3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136021_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2013136021_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2013136021_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CMy2013136021_3View 진단

#ifdef _DEBUG
void CMy2013136021_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136021_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136021_3Doc* CMy2013136021_3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136021_3Doc)));
	return (CMy2013136021_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136021_3View 메시지 처리기


void CMy2013136021_3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	dc.SelectStockObject(NULL_BRUSH);
	dc.Ellipse(m_xPos, m_yPos,m_xPos+100, m_yPos+100);
	dc.Rectangle(400, 400, 600, 600);
}



void CMy2013136021_3View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	xMax = cx;
	yMax = cy;
}
