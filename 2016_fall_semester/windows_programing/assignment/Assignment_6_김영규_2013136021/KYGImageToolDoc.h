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
	afx_msg void OnImageResize();
	afx_msg void OnImageRotate();
	afx_msg void OnImageMirror();
	afx_msg void OnImageFlip();
	afx_msg void OnColorSplitRgb();
	afx_msg void OnUpdateColorSplitRgb(CCmdUI *pCmdUI);
	afx_msg void OnColorSplitHsi();
	afx_msg void OnUpdateColorSplitHsi(CCmdUI *pCmdUI);
	afx_msg void OnColorSplitYuv();
	afx_msg void OnUpdateColorSplitYuv(CCmdUI *pCmdUI);
	afx_msg void OnColorConbineRgb();
	afx_msg void OnColorConbineHsi();
	afx_msg void OnColorConbineYuv();
	afx_msg void OnColorEdge();
	afx_msg void OnUpdateColorEdge(CCmdUI *pCmdUI);
};
