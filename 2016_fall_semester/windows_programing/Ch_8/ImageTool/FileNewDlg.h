#pragma once


// CFileNewDlg ��ȭ �����Դϴ�.

class CFileNewDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileNewDlg)

public:
	CFileNewDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFileNewDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FILE_NEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// �̹��� ����, ���� ũ��
	int m_nWidth;
	int m_nHeight;

	// �̹��� ���� Ÿ��(�׷��̽����� �Ǵ� Ʈ��Į��)
	int m_nType;
};
