// ContrastDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "ContrastDlg.h"


// CContrastDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CContrastDlg, CDialog)

CContrastDlg::CContrastDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CContrastDlg::IDD, pParent)
	, m_nContrast(0)
{

}

CContrastDlg::~CContrastDlg()
{
}

void CContrastDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTRAST_EDIT, m_nContrast);
	DDV_MinMaxInt(pDX, m_nContrast, -100, 100);
	DDX_Control(pDX, IDC_CONTRAST_SLIDER, m_sliderContrast);
}


BEGIN_MESSAGE_MAP(CContrastDlg, CDialog)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_CONTRAST_EDIT, &CContrastDlg::OnEnChangeContrastEdit)
END_MESSAGE_MAP()


// CContrastDlg �޽��� ó�����Դϴ�.

BOOL CContrastDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_sliderContrast.SetRange(-100, 100);
	m_sliderContrast.SetTicFreq(20);
	m_sliderContrast.SetPageSize(20);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CContrastDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// �����̵���̼� �߻��� WM_HSCROLL �޽����� ��� ó��
	if( m_sliderContrast.GetSafeHwnd() == pScrollBar->GetSafeHwnd() )
	{
		int nPos = m_sliderContrast.GetPos();
		m_nContrast = nPos;
		UpdateData(FALSE);
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CContrastDlg::OnEnChangeContrastEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� �������ϰ�  ����ũ�� OR �����Ͽ� ������
	// ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ���ؾ߸�
	// �ش� �˸� �޽����� �����ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_sliderContrast.SetPos(m_nContrast);
}
