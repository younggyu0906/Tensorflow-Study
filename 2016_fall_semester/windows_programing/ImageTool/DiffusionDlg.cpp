// DiffusionDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "DiffusionDlg.h"


// CDiffusionDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDiffusionDlg, CDialog)

CDiffusionDlg::CDiffusionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiffusionDlg::IDD, pParent)
	, m_fLambda(0.25f)
	, m_fK(4.f)
	, m_nIteration(10)
{

}

CDiffusionDlg::~CDiffusionDlg()
{
}

void CDiffusionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DIFFUSION_LAMBDA, m_fLambda);
	DDX_Text(pDX, IDC_DIFFUSION_K, m_fK);
	DDX_Text(pDX, IDC_DIFFUSION_ITER, m_nIteration);
	DDV_MinMaxInt(pDX, m_nIteration, 0, 100);
}


BEGIN_MESSAGE_MAP(CDiffusionDlg, CDialog)
END_MESSAGE_MAP()


// CDiffusionDlg �޽��� ó�����Դϴ�.
