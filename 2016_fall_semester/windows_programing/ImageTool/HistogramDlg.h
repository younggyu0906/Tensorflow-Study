#pragma once


// CHistogramDlg ��ȭ �����Դϴ�.


class CHistogramDlg : public CDialog
{
	DECLARE_DYNAMIC(CHistogramDlg)

public:
	CHistogramDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHistogramDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HISTOGRAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	int m_Histogram[256];

public:
	void SetImage(CDib& dib);

	afx_msg void OnPaint();
};
