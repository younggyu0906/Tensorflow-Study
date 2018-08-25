#pragma once
#include "afxcmn.h"


// CGammaCorrectionDlg ��ȭ �����Դϴ�.

class CGammaCorrectionDlg : public CDialog
{
	DECLARE_DYNAMIC(CGammaCorrectionDlg)

public:
	CGammaCorrectionDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGammaCorrectionDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GAMMA_CORRECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CSliderCtrl m_sliderGamma;
	float m_fGamma;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeGammaEdit();
};
