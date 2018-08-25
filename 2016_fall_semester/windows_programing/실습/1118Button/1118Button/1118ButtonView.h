
// 1118ButtonView.h : CMy1118ButtonView 클래스의 인터페이스
//

#pragma once


class CMy1118ButtonView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy1118ButtonView();
	DECLARE_DYNCREATE(CMy1118ButtonView)

// 특성입니다.
public:
	CMy1118ButtonDoc* GetDocument() const;

	  //버튼선언
   CButton m_pushbutton;
   CButton m_pushbutton2;
   CButton m_pushbutton3;
   CButton m_checkbox;
   CButton m_3state;
   CButton m_radio1;
   CButton m_radio2;
   CButton m_groupbox;


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
	virtual ~CMy1118ButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void bClick1(void);
	void bClick2(void);
	void bClick3(void);
};

#ifndef _DEBUG  // 1118ButtonView.cpp의 디버그 버전
inline CMy1118ButtonDoc* CMy1118ButtonView::GetDocument() const
   { return reinterpret_cast<CMy1118ButtonDoc*>(m_pDocument); }
#endif

