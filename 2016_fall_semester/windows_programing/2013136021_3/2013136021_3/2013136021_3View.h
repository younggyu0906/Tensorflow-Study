
// 2013136021_3View.h : CMy2013136021_3View Ŭ������ �������̽�
//

#pragma once


class CMy2013136021_3View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2013136021_3View();
	DECLARE_DYNCREATE(CMy2013136021_3View)

// Ư���Դϴ�.
public:
	CMy2013136021_3Doc* GetDocument() const;

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
	virtual ~CMy2013136021_3View();
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
	afx_msg void OnPaint();
	int m_xPos;
	int m_yPos;
	int xMax;
	int yMax;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // 2013136021_3View.cpp�� ����� ����
inline CMy2013136021_3Doc* CMy2013136021_3View::GetDocument() const
   { return reinterpret_cast<CMy2013136021_3Doc*>(m_pDocument); }
#endif

