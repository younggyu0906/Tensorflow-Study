
// line2View.h : Cline2View Ŭ������ �������̽�
//

#pragma once


class Cline2View : public CView
{
protected: // serialization������ ��������ϴ�.
	Cline2View();
	DECLARE_DYNCREATE(Cline2View)

// Ư���Դϴ�.
public:
	Cline2Doc* GetDocument() const;

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
	virtual ~Cline2View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint SP;
	bool DrawMove;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint EP;
};

#ifndef _DEBUG  // line2View.cpp�� ����� ����
inline Cline2Doc* Cline2View::GetDocument() const
   { return reinterpret_cast<Cline2Doc*>(m_pDocument); }
#endif

