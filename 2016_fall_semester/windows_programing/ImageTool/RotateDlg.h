#pragma once


// CRotateDlg ��ȭ �����Դϴ�.

class CRotateDlg : public CDialog
{
	DECLARE_DYNAMIC(CRotateDlg)

public:
	CRotateDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRotateDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ROTATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	int m_nRotate;
	float m_fAngle;
};
