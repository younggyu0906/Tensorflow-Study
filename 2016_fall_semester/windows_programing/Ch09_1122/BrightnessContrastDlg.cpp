// BrightnessContrastDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "KYGImageTool.h"
#include "BrightnessContrastDlg.h"
#include "afxdialogex.h"

#include "KYGImageToolDoc.h"
#include "DibEnhancement.h"
#include "BrightnessDlg.h"
#include "FileNewDlg.h"


// CBrightnessContrastDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CBrightnessContrastDlg, CDialogEx)

CBrightnessContrastDlg::CBrightnessContrastDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBrightnessContrastDlg::IDD, pParent)
	, m_nBrightness(0)
	, m_nContrast(0)
{

}

CBrightnessContrastDlg::~CBrightnessContrastDlg()
{
}

void CBrightnessContrastDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BRIGHTNESS_EDIT, m_nBrightness);
	DDV_MinMaxInt(pDX, m_nBrightness, -255, 255);
	DDX_Text(pDX, IDC_CONTRAST_EDIT, m_nContrast);
	DDV_MinMaxInt(pDX, m_nContrast, -100, 100);
	DDX_Control(pDX, IDC_BRIGHTNESS_SLIDER, m_sliderBrightness);
	DDX_Control(pDX, IDC_CONTRAST_SLIDER, m_sliderContrast);
}


BEGIN_MESSAGE_MAP(CBrightnessContrastDlg, CDialogEx)
	ON_EN_CHANGE(IDC_BRIGHTNESS_EDIT, &CBrightnessContrastDlg::OnEnChangeBrightnessEdit)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_CONTRAST_SLIDER, &CBrightnessContrastDlg::OnNMCustomdrawContrastSlider)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_CONTRAST_EDIT, &CBrightnessContrastDlg::OnEnChangeContrastEdit)
END_MESSAGE_MAP()


// CBrightnessContrastDlg �޽��� ó�����Դϴ�.



void CBrightnessContrastDlg::OnNMCustomdrawContrastSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


BOOL CBrightnessContrastDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// ��� ���� �����̴� ��Ʈ�� �ʱ�ȭ
	m_sliderBrightness.SetRange(-255,255);
	m_sliderBrightness.SetTicFreq(32);
	m_sliderBrightness.SetPageSize(32);

	// ���Ϻ� ���� �����̴� ��Ʈ�� �ʱ�ȭ
	m_sliderContrast.SetRange(-100,100);
	m_sliderContrast.SetTicFreq(20);
	m_sliderContrast.SetPageSize(20);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CBrightnessContrastDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ��� ���� �����̵�ٿ��� �߻��� WM_HSCROLL �޽��� ó��
	if(m_sliderBrightness.GetSafeHwnd() == pScrollBar->GetSafeHwnd()) {
		m_nBrightness = m_sliderBrightness.GetPos();
		UpdateData(FALSE);
	}
	else if(m_sliderContrast.GetSafeHwnd() == pScrollBar->GetSafeHwnd()) {
		m_nContrast = m_sliderContrast.GetPos();
		UpdateData(FALSE);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBrightnessContrastDlg::OnEnChangeBrightnessEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_sliderBrightness.SetPos(m_nBrightness);
}


void CBrightnessContrastDlg::OnEnChangeContrastEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_sliderContrast.SetPos(m_nContrast);
}