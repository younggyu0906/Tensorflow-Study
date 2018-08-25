// GaussianDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "GaussianDlg.h"


// CGaussianDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CGaussianDlg, CDialog)

CGaussianDlg::CGaussianDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGaussianDlg::IDD, pParent)
	, m_fSigma(2.20f)
{

}

CGaussianDlg::~CGaussianDlg()
{
}

void CGaussianDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SIGMA_SLIDER, m_sliderSigma);
	DDX_Text(pDX, IDC_SIGMA_EDIT, m_fSigma);
	DDV_MinMaxFloat(pDX, m_fSigma, 0.20f, 5.00f);
}


BEGIN_MESSAGE_MAP(CGaussianDlg, CDialog)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_SIGMA_EDIT, &CGaussianDlg::OnEnChangeSigmaEdit)
END_MESSAGE_MAP()


// CGaussianDlg �޽��� ó�����Դϴ�.

BOOL CGaussianDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �����̴� ��Ʈ���� �ʱ�ȭ
	m_sliderSigma.SetRange(10, 250);
	m_sliderSigma.SetTicFreq(20);
	m_sliderSigma.SetPageSize(20);
	m_sliderSigma.SetPos((int)(m_fSigma*50));

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CGaussianDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// �����̵���̼� �߻��� WM_HSCROLL �޽����� ��� ó��
	if( m_sliderSigma.GetSafeHwnd() == pScrollBar->GetSafeHwnd() )
	{
		int nPos = m_sliderSigma.GetPos();
		m_fSigma = (nPos/50.f);
		UpdateData(FALSE);
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CGaussianDlg::OnEnChangeSigmaEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� �������ϰ�  ����ũ�� OR �����Ͽ� ������
	// ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ���ؾ߸�
	// �ش� �˸� �޽����� �����ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_sliderSigma.SetPos((int)(m_fSigma*50));
}
