
// keyView.h : CkeyView Ŭ������ �������̽�
//

#pragma once


class CkeyView : public CView
{
protected: // serialization������ ��������ϴ�.
	CkeyView();
	DECLARE_DYNCREATE(CkeyView)

// Ư���Դϴ�.
public:
	CkeyDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CkeyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int m_xPos;
	int xMax;
	int m_yPos;
	int yMax;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnRectangle();
	afx_msg void OnLine();
	afx_msg void OnEllipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint SP;
	CPoint EP;
	bool DrawMove;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int choice;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	bool m_rectangleCursor;
	bool m_ellipseCursor;
	bool m_lineCursor;
};

#ifndef _DEBUG  // keyView.cpp�� ����� ����
inline CkeyDoc* CkeyView::GetDocument() const
   { return reinterpret_cast<CkeyDoc*>(m_pDocument); }
#endif

