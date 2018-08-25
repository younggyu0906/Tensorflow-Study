
// 2013136021_4View.h : CMy2013136021_4View 클래스의 인터페이스
//

#pragma once


class CMy2013136021_4View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy2013136021_4View();
	DECLARE_DYNCREATE(CMy2013136021_4View)

// 특성입니다.
public:
	CMy2013136021_4Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy2013136021_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // 2013136021_4View.cpp의 디버그 버전
inline CMy2013136021_4Doc* CMy2013136021_4View::GetDocument() const
   { return reinterpret_cast<CMy2013136021_4Doc*>(m_pDocument); }
#endif

