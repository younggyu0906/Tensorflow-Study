// RotateDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "RotateDlg.h"


// CRotateDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRotateDlg, CDialog)

CRotateDlg::CRotateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRotateDlg::IDD, pParent)
	, m_nRotate(0)
	, m_fAngle(0.f)
{

}

CRotateDlg::~CRotateDlg()
{
}

void CRotateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_ROTATE1, m_nRotate);
	DDX_Text(pDX, IDC_ANGLE, m_fAngle);
}


BEGIN_MESSAGE_MAP(CRotateDlg, CDialog)
END_MESSAGE_MAP()


// CRotateDlg �޽��� ó�����Դϴ�.

