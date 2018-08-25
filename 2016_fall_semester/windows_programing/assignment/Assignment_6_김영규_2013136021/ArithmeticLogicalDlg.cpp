// ArithmeticLogicalDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "KYGImageTool.h"
#include "KYGImageToolDoc.h"
#include "ArithmeticLogicalDlg.h"
#include "afxdialogex.h"


// CArithmeticLogicalDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CArithmeticLogicalDlg, CDialogEx)

CArithmeticLogicalDlg::CArithmeticLogicalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CArithmeticLogicalDlg::IDD, pParent)
	, m_nFunction(0), m_pDoc1(NULL), m_pDoc2(NULL)
{

}

CArithmeticLogicalDlg::~CArithmeticLogicalDlg()
{
}

void CArithmeticLogicalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMAGE1, m_comboImage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE2, m_comboImage2);
	DDX_Radio(pDX, IDC_FUNCTION1, m_nFunction);
}


// CArithmeticLogicalDlg 메시지 처리기입니다.


BOOL CArithmeticLogicalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	//콤보 박스에 차일드 윈도우 창의 이름을 삽입
	int nIndex = 0;
	CString strTitle;

	CKYGImageToolApp* pApp = (CKYGImageToolApp*)AfxGetApp();
	POSITION pos = pApp->m_pImageDocTemplate->GetFirstDocPosition();

	while (pos != NULL)
	{
		//pDoc을 이용하여 도큐먼트에 접근!
		CKYGImageToolDoc* pDoc = (CKYGImageToolDoc*)pApp->m_pImageDocTemplate->GetNextDoc(pos);
		if (pDoc->m_Dib.GetBitCount() != 8)
			continue;

		strTitle = pDoc->GetTitle();

		m_comboImage1.InsertString(nIndex, strTitle);
		m_comboImage2.InsertString(nIndex, strTitle);

		m_comboImage1.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboImage2.SetItemDataPtr(nIndex, (void*)pDoc);

		nIndex++;
	}

	m_comboImage1.SetCurSel(0);
	m_comboImage2.SetCurSel(0);
	if (nIndex > 1) m_comboImage2.SetCurSel(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}BEGIN_MESSAGE_MAP(CArithmeticLogicalDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CArithmeticLogicalDlg::OnBnClickedOk)
	END_MESSAGE_MAP()


void CArithmeticLogicalDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pDoc1 = (CKYGImageToolDoc*)m_comboImage1.GetItemDataPtr(m_comboImage1.GetCurSel());
	m_pDoc2 = (CKYGImageToolDoc*)m_comboImage2.GetItemDataPtr(m_comboImage2.GetCurSel());

	CDialogEx::OnOK();
}
