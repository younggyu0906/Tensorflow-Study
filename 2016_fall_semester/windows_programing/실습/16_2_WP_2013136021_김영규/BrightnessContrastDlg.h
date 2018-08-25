#pragma once
#include "afxcmn.h"


// CBrightnessContrastDlg ��ȭ �����Դϴ�.

class CBrightnessContrastDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBrightnessContrastDlg)

public:
	CBrightnessContrastDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBrightnessContrastDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BRIGHTNESS_CONTRAST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeBrightnessEdit();
	int m_nBrightness;
	int m_nContrast;
	CSliderCtrl m_sliderBrightness;
	afx_msg void OnNMCustomdrawContrastSlider(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_sliderContrast;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeContrastEdit();
};
