
// RectangleView.cpp : CRectangleView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Rectangle.h"
#endif

#include "RectangleDoc.h"
#include "RectangleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRectangleView

IMPLEMENT_DYNCREATE(CRectangleView, CView)

BEGIN_MESSAGE_MAP(CRectangleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRectangleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CRectangleView 생성/소멸

CRectangleView::CRectangleView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CRectangleView::~CRectangleView()
{
}

BOOL CRectangleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CRectangleView 그리기

void CRectangleView::OnDraw(CDC* /*pDC*/)
{
	CRectangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CRectangleView 인쇄


void CRectangleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRectangleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CRectangleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CRectangleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CRectangleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRectangleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRectangleView 진단

#ifdef _DEBUG
void CRectangleView::AssertValid() const
{
	CView::AssertValid();
}

void CRectangleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRectangleDoc* CRectangleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRectangleDoc)));
	return (CRectangleDoc*)m_pDocument;
}
#endif //_DEBUG


// CRectangleView 메시지 처리기


void CRectangleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Invalidate(false);
	
	CView::OnLButtonDown(nFlags, point);
}
