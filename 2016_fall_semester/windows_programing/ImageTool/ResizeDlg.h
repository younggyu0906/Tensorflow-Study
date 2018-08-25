#pragma once


// CResizeDlg ��ȭ �����Դϴ�.

class CResizeDlg : public CDialog
{
	DECLARE_DYNAMIC(CResizeDlg)

public:
	CResizeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CResizeDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RESIZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	int m_nOldWidth;
	int m_nOldHeight;
	int m_nNewWidth;
	int m_nNewHeight;
	BOOL m_bAspectRatio;
	int m_nInterpolation;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeNewWidth();
	afx_msg void OnEnChangeNewHeight();
	afx_msg void OnBnClickedAspectRatio();
};
