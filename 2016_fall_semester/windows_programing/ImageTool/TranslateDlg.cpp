// TranslateDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "TranslateDlg.h"


// CTranslateDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTranslateDlg, CDialog)

CTranslateDlg::CTranslateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTranslateDlg::IDD, pParent)
	, m_nNewSX(0)
	, m_nNewSY(0)
{

}

CTranslateDlg::~CTranslateDlg()
{
}

void CTranslateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEW_SX, m_nNewSX);
	DDX_Text(pDX, IDC_NEW_SY, m_nNewSY);
}


BEGIN_MESSAGE_MAP(CTranslateDlg, CDialog)
END_MESSAGE_MAP()


// CTranslateDlg �޽��� ó�����Դϴ�.
