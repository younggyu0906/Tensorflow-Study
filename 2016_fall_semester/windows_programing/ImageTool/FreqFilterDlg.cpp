// FreqFilterDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "FreqFilterDlg.h"


// CFreqFilterDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFreqFilterDlg, CDialog)

CFreqFilterDlg::CFreqFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFreqFilterDlg::IDD, pParent)
	, m_strFilterType(_T(""))
	, m_strFilterShape(_T(""))
	, m_nCutoff(32)
	, m_strRange(_T(""))
{

}

CFreqFilterDlg::~CFreqFilterDlg()
{
}

void CFreqFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FILTER_TYPE, m_strFilterType);
	DDX_Text(pDX, IDC_FILTER_SHAPE, m_strFilterShape);
	DDX_Text(pDX, IDC_CUTOFF_FREQ, m_nCutoff);
	DDX_Text(pDX, IDC_CUTOFF_RANGE, m_strRange);
}


BEGIN_MESSAGE_MAP(CFreqFilterDlg, CDialog)
END_MESSAGE_MAP()


// CFreqFilterDlg �޽��� ó�����Դϴ�.
