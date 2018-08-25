// ArithmeticLogicalDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "KYGImageTool.h"
#include "KYGImageToolDoc.h"
#include "ArithmeticLogicalDlg.h"
#include "afxdialogex.h"


// CArithmeticLogicalDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CArithmeticLogicalDlg, CDialogEx)

CArithmeticLogicalDlg::CArithmeticLogicalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CArithmeticLogicalDlg::IDD, pParent)
	, m_nFunction(0), m_pDoc1(NULL), m_pDoc2(NULL)
{

}

CArithmeticLogicalDlg::~CArithmeticLogicalDlg()
{
}

void CArithmeticLogicalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMAGE1, m_comboImage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE2, m_comboImage2);
	DDX_Radio(pDX, IDC_FUNCTION1, m_nFunction);
}


// CArithmeticLogicalDlg �޽��� ó�����Դϴ�.


BOOL CArithmeticLogicalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	//�޺� �ڽ��� ���ϵ� ������ â�� �̸��� ����
	int nIndex = 0;
	CString strTitle;

	CKYGImageToolApp* pApp = (CKYGImageToolApp*)AfxGetApp();
	POSITION pos = pApp->m_pImageDocTemplate->GetFirstDocPosition();

	while (pos != NULL)
	{
		//pDoc�� �̿��Ͽ� ��ť��Ʈ�� ����!
		CKYGImageToolDoc* pDoc = (CKYGImageToolDoc*)pApp->m_pImageDocTemplate->GetNextDoc(pos);
		if (pDoc->m_Dib.GetBitCount() != 8)
			continue;

		strTitle = pDoc->GetTitle();

		m_comboImage1.InsertString(nIndex, strTitle);
		m_comboImage2.InsertString(nIndex, strTitle);

		m_comboImage1.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboImage2.SetItemDataPtr(nIndex, (void*)pDoc);

		nIndex++;
	}

	m_comboImage1.SetCurSel(0);
	m_comboImage2.SetCurSel(0);
	if (nIndex > 1) m_comboImage2.SetCurSel(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}BEGIN_MESSAGE_MAP(CArithmeticLogicalDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CArithmeticLogicalDlg::OnBnClickedOk)
	END_MESSAGE_MAP()


void CArithmeticLogicalDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pDoc1 = (CKYGImageToolDoc*)m_comboImage1.GetItemDataPtr(m_comboImage1.GetCurSel());
	m_pDoc2 = (CKYGImageToolDoc*)m_comboImage2.GetItemDataPtr(m_comboImage2.GetCurSel());

	CDialogEx::OnOK();
}
