#pragma once


// CHarrisDlg ��ȭ �����Դϴ�.

class CHarrisDlg : public CDialog
{
	DECLARE_DYNAMIC(CHarrisDlg)

public:
	CHarrisDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHarrisDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HARRIS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nThreshold;
};
