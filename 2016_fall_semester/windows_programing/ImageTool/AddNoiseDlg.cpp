// AddNoiseDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "AddNoiseDlg.h"


// CAddNoiseDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAddNoiseDlg, CDialog)

CAddNoiseDlg::CAddNoiseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddNoiseDlg::IDD, pParent)
	, m_nNoiseType(0)
	, m_nAmount(10)
{

}

CAddNoiseDlg::~CAddNoiseDlg()
{
}

void CAddNoiseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_NOISE_RADIO1, m_nNoiseType);
	DDX_Text(pDX, IDC_NOISE_AMOUNT, m_nAmount);
	DDV_MinMaxInt(pDX, m_nAmount, 0, 100);
}


BEGIN_MESSAGE_MAP(CAddNoiseDlg, CDialog)
END_MESSAGE_MAP()


// CAddNoiseDlg �޽��� ó�����Դϴ�.
