
// HW02View.h : CHW02View 클래스의 인터페이스
//

#pragma once


class CHW02View : public CView
{
protected: // serialization에서만 만들어집니다.
	CHW02View();
	DECLARE_DYNCREATE(CHW02View)

// 특성입니다.
public:
	CHW02Doc* GetDocument() const;

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
	virtual ~CHW02View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint SP;
	CPoint EP;
	bool DrawMove;
	bool leftB;
};

#ifndef _DEBUG  // HW02View.cpp의 디버그 버전
inline CHW02Doc* CHW02View::GetDocument() const
   { return reinterpret_cast<CHW02Doc*>(m_pDocument); }
#endif

