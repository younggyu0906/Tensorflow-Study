// KYGImageToolView.cpp : CKYGImageToolView 클래스의 구현
//

#include "stdafx.h"
#include "KYGImageTool.h"

#include "MainFrm.h"
#include "KYGImageToolDoc.h"
#include "KYGImageToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKYGImageToolView

IMPLEMENT_DYNCREATE(CKYGImageToolView, CScrollView)

BEGIN_MESSAGE_MAP(CKYGImageToolView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_VIEW_ZOOM1, &CKYGImageToolView::OnViewZoom1)
	ON_COMMAND(ID_VIEW_ZOOM2, &CKYGImageToolView::OnViewZoom2)
	ON_COMMAND(ID_VIEW_ZOOM3, &CKYGImageToolView::OnViewZoom3)
	ON_COMMAND(ID_VIEW_ZOOM4, &CKYGImageToolView::OnViewZoom4)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM1, &CKYGImageToolView::OnUpdateViewZoom1)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM2, &CKYGImageToolView::OnUpdateViewZoom2)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM3, &CKYGImageToolView::OnUpdateViewZoom3)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM4, &CKYGImageToolView::OnUpdateViewZoom4)
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CKYGImageToolView 생성/소멸

CKYGImageToolView::CKYGImageToolView()
: m_nZoom(1)
{
}

CKYGImageToolView::~CKYGImageToolView()
{
}

BOOL CKYGImageToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CKYGImageToolView 그리기

void CKYGImageToolView::OnDraw(CDC* pDC)
{
	CKYGImageToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if( pDoc->m_Dib.IsValid() )
	{
		int w = pDoc->m_Dib.GetWidth();
		int h = pDoc->m_Dib.GetHeight();
		pDoc->m_Dib.Draw(pDC->m_hDC, 0, 0, w*m_nZoom, h*m_nZoom);
	}
}

void CKYGImageToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	SetScrollSizeToFit();
}

void CKYGImageToolView::SetScrollSizeToFit(void)
{
	CSize sizeTotal;

	CKYGImageToolDoc* pDoc = GetDocument();
	if( pDoc->m_Dib.IsValid() )
	{
		int w = pDoc->m_Dib.GetWidth();
		int h = pDoc->m_Dib.GetHeight();

		sizeTotal.cx = w*m_nZoom;
		sizeTotal.cy = h*m_nZoom;		
	}
	else
	{
		sizeTotal.cx = sizeTotal.cy = 100;
	}

	SetScrollSizes(MM_TEXT, sizeTotal);

	ResizeParentToFit(TRUE);
}

// CKYGImageToolView 인쇄

BOOL CKYGImageToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CKYGImageToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CKYGImageToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CKYGImageToolView 진단

#ifdef _DEBUG
void CKYGImageToolView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CKYGImageToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CKYGImageToolDoc* CKYGImageToolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKYGImageToolDoc)));
	return (CKYGImageToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CKYGImageToolView 메시지 처리기

BOOL CKYGImageToolView::OnEraseBkgnd(CDC* pDC)
{
	CBrush br;
	br.CreateHatchBrush(HS_DIAGCROSS, RGB(200, 200, 200));
	FillOutsideRect(pDC, &br);

	return TRUE;       // Erased
}

void CKYGImageToolView::OnViewZoom1()
{
	m_nZoom = 1;
	SetScrollSizeToFit();
	Invalidate(TRUE);
}

void CKYGImageToolView::OnViewZoom2()
{
	m_nZoom = 2;
	SetScrollSizeToFit();
	Invalidate(TRUE);
}

void CKYGImageToolView::OnViewZoom3()
{
	m_nZoom = 3;
	SetScrollSizeToFit();
	Invalidate(TRUE);
}

void CKYGImageToolView::OnViewZoom4()
{
	m_nZoom = 4;
	SetScrollSizeToFit();
	Invalidate(TRUE);
}


void CKYGImageToolView::OnUpdateViewZoom1(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nZoom == 1);
}

void CKYGImageToolView::OnUpdateViewZoom2(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nZoom == 2);
}

void CKYGImageToolView::OnUpdateViewZoom3(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nZoom == 3);
}

void CKYGImageToolView::OnUpdateViewZoom4(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nZoom == 4);
}

void CKYGImageToolView::OnMouseMove(UINT nFlags, CPoint point)
{
	// 상태바에 마우스 좌표 및 이미지 정보 표시
	CPoint pt = point + GetScrollPosition();
	pt.x /= m_nZoom;
	pt.y /= m_nZoom;
	ShowImageInfo(pt);

	CScrollView::OnMouseMove(nFlags, point);
}

void CKYGImageToolView::ShowImageInfo(CPoint point)
{
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CKYGImageToolDoc* pDoc = GetDocument();
	int w = pDoc->m_Dib.GetWidth();
	int h = pDoc->m_Dib.GetHeight();
	int c = pDoc->m_Dib.GetPaletteNums();

	CString strText;

	// 상태바에 마우스 좌표 표시

	if(point.x >= 0 && point.y >= 0 && point.x < w && point.y < h)
	{
		strText.Format(_T("(%d, %d)"), point.x, point.y);
		pFrame->m_wndStatusBar.SetPaneText(0, strText);
	}

	// 상태바에 이미지 정보 표시

	if( c == 0 )
	{
		strText.Format(_T("w:%d  h:%d  c:16M"), w, h);
	}
	else
	{
		strText.Format(_T("w:%d  h:%d  c:%d"), w, h, c);
	}
	pFrame->m_wndStatusBar.SetPaneText(1, strText);
}

