#pragma once


// CTranslateDlg ��ȭ �����Դϴ�.

class CTranslateDlg : public CDialog
{
	DECLARE_DYNAMIC(CTranslateDlg)

public:
	CTranslateDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTranslateDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TRANSLATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	int m_nNewSX;
	int m_nNewSY;
};
