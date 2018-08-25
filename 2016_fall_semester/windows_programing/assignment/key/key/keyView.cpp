
// keyView.cpp : CkeyView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "key.h"
#endif

#include "keyDoc.h"
#include "keyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkeyView

IMPLEMENT_DYNCREATE(CkeyView, CView)

	BEGIN_MESSAGE_MAP(CkeyView, CView)
		// 표준 인쇄 명령입니다.
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CkeyView::OnFilePrintPreview)
		ON_WM_CONTEXTMENU()
		ON_WM_RBUTTONUP()
		ON_WM_KEYDOWN()
		ON_WM_SIZE()
		ON_WM_PAINT()
		ON_COMMAND(ID_RECTANGLE, &CkeyView::OnRectangle)
		ON_COMMAND(ID_LINE, &CkeyView::OnLine)
		ON_COMMAND(ID_ELLIPSE, &CkeyView::OnEllipse)
		ON_WM_LBUTTONDOWN()
		ON_WM_LBUTTONUP()
		ON_WM_MOUSEMOVE()
	END_MESSAGE_MAP()

	// CkeyView 생성/소멸

	CkeyView::CkeyView()
	{
		// TODO: 여기에 생성 코드를 추가합니다.

		m_xPos = 60;
		m_yPos = 60;
		xMax = 0;
		yMax = 0;
		choice = 0;
	}

	CkeyView::~CkeyView()
	{
	}

	BOOL CkeyView::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: CREATESTRUCT cs를 수정하여 여기에서
		//  Window 클래스 또는 스타일을 수정합니다.

		return CView::PreCreateWindow(cs);
	}

	// CkeyView 그리기

	void CkeyView::OnDraw(CDC* /*pDC*/)
	{
		CkeyDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	}


	// CkeyView 인쇄


	void CkeyView::OnFilePrintPreview()
	{
#ifndef SHARED_HANDLERS
		AFXPrintPreview(this);
#endif
	}

	BOOL CkeyView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// 기본적인 준비
		return DoPreparePrinting(pInfo);
	}

	void CkeyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
	}

	void CkeyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: 인쇄 후 정리 작업을 추가합니다.
	}

	void CkeyView::OnRButtonUp(UINT /* nFlags */, CPoint point)
	{
		ClientToScreen(&point);
		OnContextMenu(this, point);
	}

	void CkeyView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
	{
#ifndef SHARED_HANDLERS
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
	}


	// CkeyView 진단

#ifdef _DEBUG
	void CkeyView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CkeyView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CkeyDoc* CkeyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CkeyDoc)));
		return (CkeyDoc*)m_pDocument;
	}
#endif //_DEBUG


	// CkeyView 메시지 처리기


	void CkeyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		switch(nChar) {
		case VK_LEFT:
			m_xPos -=20;
			break;
		case VK_RIGHT:
			m_xPos +=20;
			break;
		case VK_UP:
			m_yPos -=20;
			break;
		case VK_DOWN:
			m_yPos +=20;
			break;
		}
		//	m_Pos = min(max(20,m_yPos), m_yMax-20);
		Invalidate();

		CView::OnKeyDown(nChar, nRepCnt, nFlags);
	}


	void CkeyView::OnSize(UINT nType, int cx, int cy)
	{
		CView::OnSize(nType, cx, cy);

		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		xMax = cx;
		yMax = cy;
	}


	void CkeyView::OnPaint()
	{
		CPaintDC dc(this); // device context for painting
		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
		dc.SelectStockObject(BLACK_BRUSH);
		dc.Ellipse(m_xPos-20, m_yPos-20,m_xPos+20, m_yPos+20);
	}


	void CkeyView::OnRectangle()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		CClientDC dc(this);
		choice = 1;
	}


	void CkeyView::OnLine()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		CClientDC dc(this);
		choice = 3;
	}


	void CkeyView::OnEllipse()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		CClientDC dc(this);
		choice = 2;
	}


	void CkeyView::OnLButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		CClientDC dc(this);

		DrawMove = true;
		SP.x = EP.x = point.x;
		SP.y = EP.y = point.y;

		CView::OnLButtonDown(nFlags, point);
	}


	void CkeyView::OnLButtonUp(UINT nFlags, CPoint point)
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
		else
			dc.LineTo(EP.x, EP.y);
		DrawMove = false;

		CView::OnLButtonUp(nFlags, point);
	}


	void CkeyView::OnMouseMove(UINT nFlags, CPoint point)
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
			else
				dc.LineTo(EP.x, EP.y);

			EP.x = point.x;
			EP.y = point.y;
			dc.MoveTo(SP.x, SP.y);

			if(choice == 1)
				dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
			else if(choice == 2)
				dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
			else
				dc.LineTo(EP.x, EP.y);
		}
		CView::OnMouseMove(nFlags, point);
	}
