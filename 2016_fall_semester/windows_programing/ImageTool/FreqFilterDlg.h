#pragma once


// CFreqFilterDlg ��ȭ �����Դϴ�.

class CFreqFilterDlg : public CDialog
{
	DECLARE_DYNAMIC(CFreqFilterDlg)

public:
	CFreqFilterDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFreqFilterDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FREQUENCY_FILTERING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strFilterType;
	CString m_strFilterShape;
	int     m_nCutoff;
	CString m_strRange;
};
