
// 2013136021_4View.cpp : CMy2013136021_4View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "2013136021_4.h"
#endif

#include "2013136021_4Doc.h"
#include "2013136021_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136021_4View

IMPLEMENT_DYNCREATE(CMy2013136021_4View, CView)

BEGIN_MESSAGE_MAP(CMy2013136021_4View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136021_4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_LINE, &CMy2013136021_4View::OnLine)
	ON_COMMAND(ID_ELLIPSE, &CMy2013136021_4View::OnEllipse)
	ON_COMMAND(ID_RECTANGLE, &CMy2013136021_4View::OnRectangle)
	ON_COMMAND(ID_CLEAR, &CMy2013136021_4View::OnClear)
END_MESSAGE_MAP()

// CMy2013136021_4View 생성/소멸

CMy2013136021_4View::CMy2013136021_4View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	choice = 0;
}

CMy2013136021_4View::~CMy2013136021_4View()
{
}

BOOL CMy2013136021_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2013136021_4View 그리기

void CMy2013136021_4View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136021_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy2013136021_4View 인쇄


void CMy2013136021_4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136021_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2013136021_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2013136021_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy2013136021_4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136021_4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136021_4View 진단

#ifdef _DEBUG
void CMy2013136021_4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136021_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136021_4Doc* CMy2013136021_4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136021_4Doc)));
	return (CMy2013136021_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136021_4View 메시지 처리기


void CMy2013136021_4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	DrawMove = true;
	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMy2013136021_4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_COPYPEN);
		EP.x = point.x;
		EP.y = point.y;
		dc.MoveTo(SP.x, SP.y);
		if(choice == 1)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 2)
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 3)
			dc.LineTo(EP.x, EP.y);
		DrawMove = false;

		CView::OnLButtonUp(nFlags, point);
}


void CMy2013136021_4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CClientDC dc(this);

	if(DrawMove == true) {
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);
		dc.MoveTo(SP.x, SP.y);

		if(choice == 1)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 2)
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 3)
			dc.LineTo(EP.x, EP.y);

		EP.x = point.x;
		EP.y = point.y;
		dc.MoveTo(SP.x, SP.y);

		if(choice == 1)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 2)
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
		else if(choice == 3)
			dc.LineTo(EP.x, EP.y);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2013136021_4View::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CClientDC dc(this);
	choice = 3;
}


void CMy2013136021_4View::OnEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CClientDC dc(this);
	choice = 2;
}


void CMy2013136021_4View::OnRectangle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CClientDC dc(this);
	choice = 1;
}



void CMy2013136021_4View::OnClear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CClientDC dc(this);
	Invalidate(TRUE);
}
