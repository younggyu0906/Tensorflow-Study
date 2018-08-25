
// 1118ButtonView.h : CMy1118ButtonView Ŭ������ �������̽�
//

#pragma once


class CMy1118ButtonView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1118ButtonView();
	DECLARE_DYNCREATE(CMy1118ButtonView)

// Ư���Դϴ�.
public:
	CMy1118ButtonDoc* GetDocument() const;

	  //��ư����
   CButton m_pushbutton;
   CButton m_pushbutton2;
   CButton m_pushbutton3;
   CButton m_checkbox;
   CButton m_3state;
   CButton m_radio1;
   CButton m_radio2;
   CButton m_groupbox;


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
	virtual ~CMy1118ButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void bClick1(void);
	void bClick2(void);
	void bClick3(void);
};

#ifndef _DEBUG  // 1118ButtonView.cpp�� ����� ����
inline CMy1118ButtonDoc* CMy1118ButtonView::GetDocument() const
   { return reinterpret_cast<CMy1118ButtonDoc*>(m_pDocument); }
#endif

