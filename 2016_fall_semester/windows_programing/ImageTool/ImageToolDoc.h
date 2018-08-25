// ImageToolDoc.h : CImageToolDoc Ŭ������ �������̽�
//


#pragma once
#include "dib.h"


class CImageToolDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CImageToolDoc();
	DECLARE_DYNCREATE(CImageToolDoc)

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
	virtual ~CImageToolDoc();
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
	// 5�忡�� �߰��� �Լ�
	afx_msg void OnWindowDuplicate();
	afx_msg void OnEditCopy();

	// 6�忡�� �߰��� �Լ�
	afx_msg void OnImageInverse();
	afx_msg void OnImageBrightness();
	afx_msg void OnImageContrast();
	afx_msg void OnGammaCorrection();
	afx_msg void OnViewHistogram();
	afx_msg void OnHistoEqualize();

	// 7�忡�� �߰��� �Լ�
	afx_msg void OnImageArithmetic();
	afx_msg void OnBitplaneSlicing();

	// 8�忡�� �߰��� �Լ�
	afx_msg void OnFilterMean();
	afx_msg void OnFilterWeightedMean();
	afx_msg void OnFilterGaussian();
	afx_msg void OnFilterLaplacian();
	afx_msg void OnFilterUnsharpMask();
	afx_msg void OnAddNoise();
	afx_msg void OnFilterMedian();
	afx_msg void OnFilterDiffusion();

	// 9�忡�� �߰��� �Լ�
	afx_msg void OnImageTranslation();
	afx_msg void OnImageResize();
	afx_msg void OnImageRotate();
	afx_msg void OnImageMirror();
	afx_msg void OnImageFlip();

	// 10�忡�� �߰��� �Լ�
	afx_msg void OnFourierDft();
	afx_msg void OnFourierDftrc();
	afx_msg void OnFourierFft();
	afx_msg void OnIdealLowpass();
	afx_msg void OnIdealHighpass();
	afx_msg void OnGaussianLowpass();
	afx_msg void OnGaussianHighpass();

	// 11�忡�� �߰��� �Լ�
	afx_msg void OnEdgeRoberts();
	afx_msg void OnEdgePrewitt();
	afx_msg void OnEdgeSobel();
	afx_msg void OnHoughLine();
	afx_msg void OnHarrisCorner();
};
