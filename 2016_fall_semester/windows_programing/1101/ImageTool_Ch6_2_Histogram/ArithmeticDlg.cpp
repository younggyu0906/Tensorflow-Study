// ArithmeticDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "ArithmeticDlg.h"
#include "afxdialogex.h"


// CArithmeticDlg ��ȭ �����Դϴ�.

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


// CArithmeticDlg �޽��� ó�����Դϴ�.
