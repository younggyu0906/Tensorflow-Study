// KYGImageToolDoc.h : CKYGImageToolDoc 클래스의 인터페이스
//


#pragma once

#include "dib.h"

class CKYGImageToolDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CKYGImageToolDoc();
	DECLARE_DYNCREATE(CKYGImageToolDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 구현입니다.
public:
	virtual ~CKYGImageToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

public:
	// 이미지 객체
	CDib m_Dib;

	// 파일 불러오기 & 저장하기
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
