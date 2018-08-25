
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "character1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(0, 0, 0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_COMMAND(ID_RED, &CChildView::OnRed)
	ON_COMMAND(ID_GREEN, &CChildView::OnGreen)
	ON_COMMAND(ID_BLUE, &CChildView::OnBlue)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
	CFont font;
	font.CreatePointFont(150,_T("�ü�"));
	dc.SelectObject(&font);
	dc.SetTextColor(m_color);
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);
}



void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if(nChar == _T('\b')) {
		if(m_str.GetSize() > 0)
			m_str.RemoveAt(m_str.GetSize() - 1);
	}
	else { m_str.Add(nChar); }
	Invalidate();

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}


void CChildView::OnRed()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_color = RGB(255, 0, 0);
	Invalidate();
}


void CChildView::OnGreen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_color = RGB(0, 255, 0);
	Invalidate();
}


void CChildView::OnBlue()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_color = RGB(0, 0, 255);
	Invalidate();
}


void CChildView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)	// ��Ŭ�� �޴�
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);
	CMenu* pMenu = menu.GetSubMenu(3); // ���� �����ӿ��� ���� �޴� ���� (0, 1, 2, 3 ... ����)
	pMenu->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd() );
}
