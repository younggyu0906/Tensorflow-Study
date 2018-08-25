// ArithmeticDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "ArithmeticDlg.h"
#include "afxdialogex.h"


// CArithmeticDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CArithmeticDlg, CDialogEx)

CArithmeticDlg::CArithmeticDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CArithmeticDlg::IDD, pParent)
	, m_nFunction(0)
{

}

CArithmeticDlg::~CArithmeticDlg()
{
}

void CArithmeticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMAGE1, m_comboImage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE2, m_comboImage2);
	DDX_Radio(pDX, IDC_FUNCTION1, m_nFunction);
}


BEGIN_MESSAGE_MAP(CArithmeticDlg, CDialogEx)
END_MESSAGE_MAP()


// CArithmeticDlg 메시지 처리기입니다.
