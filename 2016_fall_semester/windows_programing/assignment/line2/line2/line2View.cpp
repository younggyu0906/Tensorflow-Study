
// line2View.cpp : Cline2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "line2.h"
#endif

#include "line2Doc.h"
#include "line2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cline2View

IMPLEMENT_DYNCREATE(Cline2View, CView)

BEGIN_MESSAGE_MAP(Cline2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cline2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cline2View 생성/소멸

Cline2View::Cline2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	DrawMove = false;
}

Cline2View::~Cline2View()
{
}

BOOL Cline2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cline2View 그리기

void Cline2View::OnDraw(CDC* /*pDC*/)
{
	Cline2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cline2View 인쇄


void Cline2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cline2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cline2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cline2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cline2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cline2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cline2View 진단

#ifdef _DEBUG
void Cline2View::AssertValid() const
{
	CView::AssertValid();
}

void Cline2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cline2Doc* Cline2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cline2Doc)));
	return (Cline2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cline2View 메시지 처리기


void Cline2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	
	if(DrawMove == true) {
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


void Cline2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	
	DrawMove = true;
	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void Cline2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);
	EP.x = point.x;
	EP.y = point.y;
	dc.MoveTo(SP.x, SP.y);
	dc.LineTo(EP.x, EP.y);
	DrawMove = false;
	CView::OnLButtonUp(nFlags, point);
}
