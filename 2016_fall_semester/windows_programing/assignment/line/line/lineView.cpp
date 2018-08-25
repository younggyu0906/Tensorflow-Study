
// lineView.cpp : ClineView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &ClineView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// ClineView 생성/소멸

ClineView::ClineView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

ClineView::~ClineView()
{
}

BOOL ClineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// ClineView 그리기

void ClineView::OnDraw(CDC* /*pDC*/)
{
	ClineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// ClineView 인쇄


void ClineView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL ClineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void ClineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void ClineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// ClineView 진단

#ifdef _DEBUG
void ClineView::AssertValid() const
{
	CView::AssertValid();
}

void ClineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ClineDoc* ClineView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ClineDoc)));
	return (ClineDoc*)m_pDocument;
}
#endif //_DEBUG


// ClineView 메시지 처리기


void ClineView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
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
