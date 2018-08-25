#pragma once
#include "afxcmn.h"


// CBrightnessDlg ��ȭ �����Դϴ�.

class CBrightnessDlg : public CDialog
{
	DECLARE_DYNAMIC(CBrightnessDlg)

public:
	CBrightnessDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBrightnessDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BRIGHTNESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CSliderCtrl m_sliderBrightness;
	int         m_nBrightness;  // ��� ��ȭ��

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeBrightnessEdit();
};
