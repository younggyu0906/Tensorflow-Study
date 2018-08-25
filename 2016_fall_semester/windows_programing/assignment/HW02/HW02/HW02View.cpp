
// HW02View.cpp : CHW02View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HW02.h"
#endif

#include "HW02Doc.h"
#include "HW02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW02View

IMPLEMENT_DYNCREATE(CHW02View, CView)

BEGIN_MESSAGE_MAP(CHW02View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHW02View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHW02View 생성/소멸

CHW02View::CHW02View()
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CHW02View::~CHW02View()
{
}

BOOL CHW02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHW02View 그리기

void CHW02View::OnDraw(CDC* /*pDC*/)
{
	CHW02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CHW02View 인쇄


void CHW02View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHW02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CHW02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CHW02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CHW02View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHW02View 진단

#ifdef _DEBUG
void CHW02View::AssertValid() const
{
	CView::AssertValid();
}

void CHW02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW02Doc* CHW02View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW02Doc)));
	return (CHW02Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW02View 메시지 처리기

void CHW02View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	if(DrawMove == true) {
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);
		dc.MoveTo(SP.x, SP.y);
		if(leftB)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);

		EP.x = point.x;
		EP.y = point.y;
		dc.MoveTo(SP.x, SP.y);
		if(leftB)
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);

	}

	CView::OnMouseMove(nFlags, point);
}


void CHW02View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	leftB = true;
	DrawMove = true;
	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CHW02View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);
	EP.x = point.x;
	EP.y = point.y;
	dc.MoveTo(SP.x, SP.y);
	dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
	DrawMove = false;

	CView::OnLButtonUp(nFlags, point);
}


void CHW02View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	leftB = false;
	DrawMove = true;
	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	
	CView::OnRButtonDown(nFlags, point);
}


void CHW02View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	CClientDC dc(this);

	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);
	EP.x = point.x;
	EP.y = point.y;
	dc.MoveTo(SP.x, SP.y);
	dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
	DrawMove = false;

	OnContextMenu(this, point);
}