
// 2013136021_4View.h : CMy2013136021_4View Ŭ������ �������̽�
//

#pragma once


class CMy2013136021_4View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2013136021_4View();
	DECLARE_DYNCREATE(CMy2013136021_4View)

// Ư���Դϴ�.
public:
	CMy2013136021_4Doc* GetDocument() const;

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
	virtual ~CMy2013136021_4View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint SP;
	CPoint EP;
	bool DrawMove;
	int choice;
	afx_msg void OnLine();
	afx_msg void OnEllipse();
	afx_msg void OnRectangle();
	afx_msg void OnClear();
};

#ifndef _DEBUG  // 2013136021_4View.cpp�� ����� ����
inline CMy2013136021_4Doc* CMy2013136021_4View::GetDocument() const
   { return reinterpret_cast<CMy2013136021_4Doc*>(m_pDocument); }
#endif

