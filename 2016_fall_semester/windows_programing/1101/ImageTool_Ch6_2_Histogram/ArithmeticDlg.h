#pragma once
#include "afxwin.h"


// CArithmeticDlg ��ȭ �����Դϴ�.

class CArithmeticDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CArithmeticDlg)

public:
	CArithmeticDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CArithmeticDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ARITHMETIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboImage1;
	CComboBox m_comboImage2;
	int m_nFunction;
};
