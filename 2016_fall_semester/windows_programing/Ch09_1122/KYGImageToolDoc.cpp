// KYGImageToolDoc.cpp : CKYGImageToolDoc Ŭ������ ����
//

#include "stdafx.h"
#include "KYGImageTool.h"

#include "KYGImageToolDoc.h"
#include "DibEnhancement.h"
#include "BrightnessDlg.h"
#include "FileNewDlg.h"
#include "BrightnessContrastDlg.h"
#include "HistogramDlg.h"
#include "ArithmeticLogicalDlg.h"
#include "DibFilter.h"
#include "GaussianDlg.h"
#include "AddNoiseDlg.h"
#include "DibGeometry.h"
#include "TranslateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKYGImageToolDoc

IMPLEMENT_DYNCREATE(CKYGImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CKYGImageToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CKYGImageToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_EDIT_COPY, &CKYGImageToolDoc::OnEditCopy)
	ON_COMMAND(ID_IMAGE_BRIGHTNESS, &CKYGImageToolDoc::OnImageBrightness)
	ON_COMMAND(ID_IMAGE_BRIGHTNESS_CONTRAST, &CKYGImageToolDoc::OnImageBrightnessContrast)
	ON_COMMAND(ID_HISTOGRAM, &CKYGImageToolDoc::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUALIZATION, &CKYGImageToolDoc::OnHistoEqualization)
	ON_COMMAND(ID_ARITHMETIC_LOGICAL, &CKYGImageToolDoc::OnArithmeticLogical)
	ON_COMMAND(ID_FILTER_MEAN, &CKYGImageToolDoc::OnFilterMean)
	ON_COMMAND(ID_FILTER_WEIGHTED_MEAN, &CKYGImageToolDoc::OnFilterWeightedMean)
	ON_COMMAND(ID_GAUSSIAN, &CKYGImageToolDoc::OnGaussian)
	ON_COMMAND(ID_ADD_NOISE, &CKYGImageToolDoc::OnAddNoise)
	ON_COMMAND(ID_IMAGE_TRANSLATION, &CKYGImageToolDoc::OnImageTranslation)
	ON_COMMAND(ID_IMAGE_INVERSE, &CKYGImageToolDoc::OnImageInverse)
END_MESSAGE_MAP()


// CKYGImageToolDoc ����/�Ҹ�

CKYGImageToolDoc::CKYGImageToolDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CKYGImageToolDoc::~CKYGImageToolDoc()
{
}

BOOL CKYGImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL bSuccess = TRUE;

	if( theApp.m_pNewDib == NULL )
	{
		CFileNewDlg dlg;
		if( dlg.DoModal() == IDOK )
		{
			if( dlg.m_nType == 0 ) // �׷��̽����� �̹���
				bSuccess = m_Dib.CreateGrayImage(dlg.m_nWidth, dlg.m_nHeight);
			else // Ʈ��Į�� �̹���
				bSuccess = m_Dib.CreateRGBImage(dlg.m_nWidth, dlg.m_nHeight);
		}
		else
		{
			bSuccess = FALSE;
		}
	}
	else
	{
		m_Dib.Copy(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}

	return bSuccess;
}

// CKYGImageToolDoc serialization

void CKYGImageToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CKYGImageToolDoc ����

#ifdef _DEBUG
void CKYGImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKYGImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKYGImageToolDoc ���


BOOL CKYGImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	return  m_Dib.Load(lpszPathName);
}

BOOL CKYGImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return  m_Dib.Save(lpszPathName);
}

void CKYGImageToolDoc::OnEditCopy()
{
	if( m_Dib.IsValid() )
		m_Dib.CopyToClipboard();
}

void CKYGImageToolDoc::OnWindowDuplicate()
{
	AfxNewImage(m_Dib);
}



void CKYGImageToolDoc::OnImageInverse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibInverse(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnImageBrightness()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CBrightnessDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibBrightness(dib, dlg.m_nBrightness);
		AfxNewImage(dib);
	}
}


void CKYGImageToolDoc::OnImageBrightnessContrast()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CBrightnessContrastDlg dlg;
	if(dlg.DoModal() == IDOK) {
		CDib dib = m_Dib;
		DibBrightness(dib, dlg.m_nBrightness);
		DibContrast(dib, dlg.m_nContrast);
		AfxNewImage(dib);
	}
}


void CKYGImageToolDoc::OnHistogram()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CHistogramDlg dlg;
	dlg.SetImage(m_Dib);
	dlg.DoModal();
}


void CKYGImageToolDoc::OnHistoEqualization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibHistogramEqualization(dib);

	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnArithmeticLogical()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CArithmeticLogicalDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		CKYGImageToolDoc* pDoc1 = (CKYGImageToolDoc*)dlg.m_pDoc1;
		CKYGImageToolDoc* pDoc2 = (CKYGImageToolDoc*)dlg.m_pDoc2;

		CDib img1 = pDoc1->m_Dib;
		CDib img2 = pDoc2->m_Dib;
		CDib img3;

		bool ret = false;

		switch(dlg.m_nFunction)
		{
		case 0: ret = DibAdd(img1,img2,img3); break;
		case 1: ret = DibSub(img1,img2,img3); break;
		case 2: ret = DibAve(img1,img2,img3); break;
		case 3: ret = DibDif(img1,img2,img3); break;
		case 4: ret = DibAND(img1,img2,img3); break;
		case 5: ret = DibOR(img1,img2,img3); break;
		}
		if(ret)
		{
			TCHAR* op[] = { _T("����"), _T("����"), _T("���"), _T("����"), _T("�� AND"), _T("�� OR") };
			/*AfxPrintInfo(_T("[��� �� �� ����] [%s] �Է� ���� #1: %s, �Է� ���� #2: %s"),
				op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());*/
			AfxNewImage(img3);
		}
		else
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�"));
	}
}


void CKYGImageToolDoc::OnFilterMean()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibFilterMean(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnFilterWeightedMean()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibFilterWeightedMean(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnGaussian()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CGaussianDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CDib dib = m_Dib;
		DibFilterGaussian(dib, dlg.m_fSigma);
		AfxNewImage(dib);
	}
}

void CKYGImageToolDoc::OnAddNoise()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CAddNoiseDlg dlg;
	if(dlg.DoModal() == IDOK) {
		CDib dib = m_Dib;
		if(dlg.m_nNoiseType == 0)
			DibNoiseGaussian(dib, dlg.m_nAmount);
		else
			DibNoiseSaltNPepper(dib, dlg.m_nAmount);
		AfxNewImage(dib);
	}
}


void CKYGImageToolDoc::OnImageTranslation()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTranslateDlg dlg;
	if(dlg.DoModal() == IDOK) {
		CDib dib = m_Dib;
		DibTranslate(dib, dlg.m_nNewSX, dlg.m_nNewSY);
		AfxNewImage(dib);
	}
}