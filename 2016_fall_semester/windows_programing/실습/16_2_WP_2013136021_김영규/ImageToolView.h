// ImageToolView.h : CImageToolView Ŭ������ �������̽�
//


#pragma once


class CImageToolView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CImageToolView();
	DECLARE_DYNCREATE(CImageToolView)

// Ư���Դϴ�.
public:
	CImageToolDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CImageToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	// �̹��� Ȯ�� ����
	int m_nZoom;

protected:
	void SetScrollSizeToFit(void);
	void ShowImageInfo(CPoint point);

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	afx_msg void OnViewZoom1();
	afx_msg void OnViewZoom2();
	afx_msg void OnViewZoom3();
	afx_msg void OnViewZoom4();

	afx_msg void OnUpdateViewZoom1(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewZoom2(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewZoom3(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewZoom4(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // ImageToolView.cpp�� ����� ����
inline CImageToolDoc* CImageToolView::GetDocument() const
   { return reinterpret_cast<CImageToolDoc*>(m_pDocument); }
#endif

