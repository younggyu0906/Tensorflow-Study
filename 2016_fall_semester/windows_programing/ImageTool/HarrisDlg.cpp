// HarrisDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "HarrisDlg.h"


// CHarrisDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHarrisDlg, CDialog)

CHarrisDlg::CHarrisDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHarrisDlg::IDD, pParent)
	, m_nThreshold(20000)
{

}

CHarrisDlg::~CHarrisDlg()
{
}

void CHarrisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_THRESHOLD, m_nThreshold);
}


BEGIN_MESSAGE_MAP(CHarrisDlg, CDialog)
END_MESSAGE_MAP()


// CHarrisDlg �޽��� ó�����Դϴ�.
