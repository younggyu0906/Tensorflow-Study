#pragma once


// CContrastDlg ��ȭ �����Դϴ�.

class CContrastDlg : public CDialog
{
	DECLARE_DYNAMIC(CContrastDlg)

public:
	CContrastDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CContrastDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CONTRAST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:

	int         m_nContrast;  // ��Ʈ��Ʈ ��ȭ��
	CSliderCtrl m_sliderContrast;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeContrastEdit();
};
