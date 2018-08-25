// KYGImageToolDoc.h : CKYGImageToolDoc Ŭ������ �������̽�
//


#pragma once

#include "dib.h"

class CKYGImageToolDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CKYGImageToolDoc();
	DECLARE_DYNCREATE(CKYGImageToolDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CKYGImageToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

public:
	// �̹��� ��ü
	CDib m_Dib;

	// ���� �ҷ����� & �����ϱ�
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);

public:
	afx_msg void OnWindowDuplicate();
	afx_msg void OnEditCopy();
	afx_msg void OnImageBrightness();
	afx_msg void OnImageBrightnessContrast();
	afx_msg void OnHistogram();
	afx_msg void OnHistoEqualization();
	afx_msg void OnArithmeticLogical();
	afx_msg void OnFilterMean();
	afx_msg void OnFilterWeightedMean();
	afx_msg void OnGaussian();
	afx_msg void OnAddNoise();
	afx_msg void OnImageTranslation();
	afx_msg void OnImageInverse();
};
