#pragma once


// CGaussianDlg ��ȭ �����Դϴ�.

class CGaussianDlg : public CDialog
{
	DECLARE_DYNAMIC(CGaussianDlg)

public:
	CGaussianDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGaussianDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GAUSSIAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CSliderCtrl m_sliderSigma;
	float m_fSigma;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeSigmaEdit();
};
