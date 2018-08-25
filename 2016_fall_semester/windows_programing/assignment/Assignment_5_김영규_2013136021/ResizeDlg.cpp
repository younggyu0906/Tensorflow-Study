// ResizeDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "KYGImageTool.h"
#include "ResizeDlg.h"
#include "afxdialogex.h"


// CResizeDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CResizeDlg, CDialogEx)

CResizeDlg::CResizeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CResizeDlg::IDD, pParent)
	, m_nOldWidth(0)
	, m_nOldHeight(0)
	, m_nNewWidth(0)
	, m_nNewHeight(0)
	, m_bAspectRatio(FALSE)
	, m_nInterpolation(0)
{

}

CResizeDlg::~CResizeDlg()
{
}

void CResizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_OLD_WIDTH, m_nOldWidth);
	DDX_Text(pDX, IDC_OLD_HEIGHT, m_nOldHeight);
	DDX_Text(pDX, IDC_NEW_WIDTH, m_nNewWidth);
	DDV_MinMaxInt(pDX, m_nNewWidth, 1, 4096);
	DDX_Text(pDX, IDC_NEW_HEIGHT, m_nNewHeight);
	DDV_MinMaxInt(pDX, m_nNewHeight, 1, 4096);
	DDX_Check(pDX, IDC_ASPECT_RATIO, m_bAspectRatio);
	DDX_CBIndex(pDX, IDC_INTERPOLATION, m_nInterpolation);
}


BEGIN_MESSAGE_MAP(CResizeDlg, CDialogEx)
	ON_EN_CHANGE(IDC_NEW_WIDTH, &CResizeDlg::OnEnChangeNewWidth)
	ON_EN_CHANGE(IDC_NEW_HEIGHT, &CResizeDlg::OnEnChangeNewHeight)
	ON_BN_CLICKED(IDC_ASPECT_RATIO, &CResizeDlg::OnBnClickedAspectRatio)
END_MESSAGE_MAP()


// CResizeDlg 메시지 처리기입니다.
BOOL CResizeDlg::OnInitDialog() {	// CResizeDlg 클래스 대화상자 초기화
	CDialogEx::OnInitDialog();

	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_WIDTH))->SetRange(1, 4096);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_HEIGHT))->SetRange(1, 4096);

	m_nNewWidth = m_nOldWidth;
	m_nNewHeight = m_nOldHeight;
	UpdateData(FALSE);

	return TRUE;
}

void CResizeDlg::OnEnChangeNewWidth()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(GetDlgItem(IDC_INTERPOLATION) == NULL)	// UpdateData함수 호출 시 프로그램이 멈추는 에러방지
		return;

	if(m_bAspectRatio) {
		UpdateData(TRUE);
		m_nNewHeight = m_nNewWidth * m_nOldHeight / m_nOldWidth;
		UpdateData(FALSE);
	}
}


void CResizeDlg::OnEnChangeNewHeight()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(GetDlgItem(IDC_INTERPOLATION) == NULL)	// UpdateData함수 호출 시 프로그램이 멈추는 에러방지
		return;

	if(m_bAspectRatio) {
		UpdateData(TRUE);
		m_nNewWidth = m_nNewHeight * m_nOldWidth / m_nOldHeight;
		UpdateData(FALSE);
	}
}


void CResizeDlg::OnBnClickedAspectRatio()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);

	if(m_bAspectRatio)
	{
		m_nNewHeight = m_nNewWidth * m_nOldHeight / m_nOldWidth;
		UpdateData(false);
	}
}
