
// 2013136021_1View.h : CMy2013136021_1View Ŭ������ �������̽�
//

#pragma once


class CMy2013136021_1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2013136021_1View();
	DECLARE_DYNCREATE(CMy2013136021_1View)

// Ư���Դϴ�.
public:
	CMy2013136021_1Doc* GetDocument() const;

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
	virtual ~CMy2013136021_1View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint SP;
	CPoint EP;
	bool m_DrawMove;
	int cntLine;
};

#ifndef _DEBUG  // 2013136021_1View.cpp�� ����� ����
inline CMy2013136021_1Doc* CMy2013136021_1View::GetDocument() const
   { return reinterpret_cast<CMy2013136021_1Doc*>(m_pDocument); }
#endif

