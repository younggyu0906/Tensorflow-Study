
// keyView.cpp : CkeyView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
		// ǥ�� �μ� ����Դϴ�.
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

	// CkeyView ����/�Ҹ�

	CkeyView::CkeyView()
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
		// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
		//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

		return CView::PreCreateWindow(cs);
	}

	// CkeyView �׸���

	void CkeyView::OnDraw(CDC* /*pDC*/)
	{
		CkeyDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	}


	// CkeyView �μ�


	void CkeyView::OnFilePrintPreview()
	{
#ifndef SHARED_HANDLERS
		AFXPrintPreview(this);
#endif
	}

	BOOL CkeyView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// �⺻���� �غ�
		return DoPreparePrinting(pInfo);
	}

	void CkeyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	}

	void CkeyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


	// CkeyView ����

#ifdef _DEBUG
	void CkeyView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CkeyView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CkeyDoc* CkeyView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CkeyDoc)));
		return (CkeyDoc*)m_pDocument;
	}
#endif //_DEBUG


	// CkeyView �޽��� ó����


	void CkeyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
		xMax = cx;
		yMax = cy;
	}


	void CkeyView::OnPaint()
	{
		CPaintDC dc(this); // device context for painting
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
		// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
		dc.SelectStockObject(BLACK_BRUSH);
		dc.Ellipse(m_xPos-20, m_yPos-20,m_xPos+20, m_yPos+20);
	}


	void CkeyView::OnRectangle()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		CClientDC dc(this);
		choice = 1;
	}


	void CkeyView::OnLine()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		CClientDC dc(this);
		choice = 3;
	}


	void CkeyView::OnEllipse()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		CClientDC dc(this);
		choice = 2;
	}


	void CkeyView::OnLButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
		CClientDC dc(this);

		DrawMove = true;
		SP.x = EP.x = point.x;
		SP.y = EP.y = point.y;

		CView::OnLButtonDown(nFlags, point);
	}


	void CkeyView::OnLButtonUp(UINT nFlags, CPoint point)
	{
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
