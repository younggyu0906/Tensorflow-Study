#pragma once


// CDiffusionDlg ��ȭ �����Դϴ�.

class CDiffusionDlg : public CDialog
{
	DECLARE_DYNAMIC(CDiffusionDlg)

public:
	CDiffusionDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDiffusionDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIFFUSION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	float m_fLambda;
	float m_fK;
	int m_nIteration;
};
