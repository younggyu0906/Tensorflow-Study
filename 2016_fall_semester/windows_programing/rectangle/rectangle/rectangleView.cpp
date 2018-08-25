
// rectangleView.cpp : CrectangleView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "rectangle.h"
#endif

#include "rectangleDoc.h"
#include "rectangleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CrectangleView

static int cnt = 0; // 사각형의 갯수를 저장할 전역변수

IMPLEMENT_DYNCREATE(CrectangleView, CView)

BEGIN_MESSAGE_MAP(CrectangleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CrectangleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CrectangleView 생성/소멸

CrectangleView::CrectangleView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CrectangleView::~CrectangleView()
{
}

BOOL CrectangleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CrectangleView 그리기

void CrectangleView::OnDraw(CDC* pDC)
{
	CrectangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString str;

	str.Format(_T("사각형 출력 갯수 : %d"), cnt);  // 사각형의 갯수를 출력
	pDC->TextOut(20, 20, str);
}


// CrectangleView 인쇄


void CrectangleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CrectangleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CrectangleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CrectangleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CrectangleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CrectangleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CrectangleView 진단

#ifdef _DEBUG
void CrectangleView::AssertValid() const
{
	CView::AssertValid();
}

void CrectangleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CrectangleDoc* CrectangleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CrectangleDoc)));
	return (CrectangleDoc*)m_pDocument;
}
#endif //_DEBUG


// CrectangleView 메시지 처리기


void CrectangleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Invalidate(false); // 화면을 덮어씌우는 함수
	cnt++; // 클릭할 때마다 사각형이 생기므로 사각형의 갯수를 증가시킴.
	CView::OnLButtonDown(nFlags, point); 
	CClientDC dc(this);
	dc.Rectangle(point.x-20, point.y-20, point.x+20, point.y+20); // 왼쪽 클릭을 하면 사각형 출력
	CView::OnLButtonDown(nFlags, point);
}
