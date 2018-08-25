
// 1118ButtonView.cpp : CMy1118ButtonView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "1118Button.h"
#endif

#include "1118ButtonDoc.h"
#include "1118ButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1118ButtonView

IMPLEMENT_DYNCREATE(CMy1118ButtonView, CView)

	BEGIN_MESSAGE_MAP(CMy1118ButtonView, CView)
		// 표준 인쇄 명령입니다.
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_WM_CREATE()
		//101번 버튼 클릭했을때 체크값들을 반환해줌
		ON_BN_CLICKED(101, bClick1)
   //2,3번 추가
		ON_BN_CLICKED(107, bClick2)
		ON_BN_CLICKED(108, bClick3)
	END_MESSAGE_MAP()

	// CMy1118ButtonView 생성/소멸

	CMy1118ButtonView::CMy1118ButtonView()
	{
		// TODO: 여기에 생성 코드를 추가합니다.

	}

	CMy1118ButtonView::~CMy1118ButtonView()
	{
	}

	BOOL CMy1118ButtonView::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: CREATESTRUCT cs를 수정하여 여기에서
		//  Window 클래스 또는 스타일을 수정합니다.

		return CView::PreCreateWindow(cs);
	}

	// CMy1118ButtonView 그리기

	void CMy1118ButtonView::OnDraw(CDC* /*pDC*/)
	{
		CMy1118ButtonDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	}


	// CMy1118ButtonView 인쇄

	BOOL CMy1118ButtonView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// 기본적인 준비
		return DoPreparePrinting(pInfo);
	}

	void CMy1118ButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
	}

	void CMy1118ButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: 인쇄 후 정리 작업을 추가합니다.
	}


	// CMy1118ButtonView 진단

#ifdef _DEBUG
	void CMy1118ButtonView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CMy1118ButtonView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CMy1118ButtonDoc* CMy1118ButtonView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1118ButtonDoc)));
		return (CMy1118ButtonDoc*)m_pDocument;
	}
#endif //_DEBUG


	// CMy1118ButtonView 메시지 처리기


	int CMy1118ButtonView::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CView::OnCreate(lpCreateStruct) == -1)
			return -1;

		// TODO:  여기에 특수화된 작성 코드를 추가합니다.
		// TODO:  여기에 특수화된 작성 코드를 추가합니다.
		//버튼 컨트롤 생성
		m_pushbutton.Create(_T("푸쉬 버튼"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			CRect(20,20,160,50),this,101);
		m_checkbox.Create(_T("체크 박스"), WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX,
			CRect(20,60,160,90),this,102);
		m_3state.Create(_T("3상태 체크 박스"), WS_CHILD|WS_VISIBLE|BS_AUTO3STATE,
			CRect(20,100,160,130),this,103);
		//라디오 버튼은 그룹으로 묶어줌
		m_radio1.Create(_T("라디오 버튼 1"), WS_CHILD|WS_VISIBLE|WS_GROUP|BS_AUTORADIOBUTTON,
			CRect(20,170,160,200),this,104);
		m_radio2.Create(_T("라디오 버튼 2"), WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,
			CRect(20,210,160,240),this,105);
		m_groupbox.Create(_T("그룹 박스"), WS_CHILD|WS_VISIBLE|BS_GROUPBOX,
			CRect(10,140,170,250),this,106);


		//두개의 푸시버튼 더
		m_pushbutton2.Create(_T("푸쉬 버튼2"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			CRect(170,20,300,50),this,107);
		m_pushbutton3.Create(_T("푸쉬 버튼3"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			CRect(310,20,500,50),this,108);

		//버튼 초기화
		m_checkbox.SetCheck(1);
		m_3state.SetCheck(2);
		m_radio2.SetCheck(1);
		return 0;
	}


	void CMy1118ButtonView::bClick1(void)
	{
		int state_checkbox = m_checkbox.GetCheck();
		int state_3state = m_3state.GetCheck();
		int state_radio1 = m_radio1.GetCheck();
		int state_radio2 = m_radio2.GetCheck();

		CString str;
		str.Format(_T("버튼 상태 : %d, %d, %d, %d"),
			state_checkbox, state_3state, state_radio1, state_radio2);
		MessageBox(str, _T("Button1 exam"), MB_ICONINFORMATION);
	}


	void CMy1118ButtonView::bClick2(void)
	{
		CString str;
		str.Format(_T("Button2 Click"));
		MessageBox(str, _T("Button1 exam"), MB_ICONINFORMATION);
	}


	void CMy1118ButtonView::bClick3(void)
	{
		CString str;
		str.Format(_T("Button3 Click"));
		MessageBox(str, _T("Button1 exam"), MB_ICONINFORMATION);
	}
