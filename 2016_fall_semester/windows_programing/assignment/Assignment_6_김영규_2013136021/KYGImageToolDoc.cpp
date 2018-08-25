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
#include "ResizeDlg.h"
#include "RotateDlg.h"
#include "DibColor.h"
#include "ColorCombineDlg.h"

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
	ON_COMMAND(ID_IMAGE_RESIZE, &CKYGImageToolDoc::OnImageResize)
	ON_COMMAND(ID_IMAGE_ROTATE, &CKYGImageToolDoc::OnImageRotate)
	ON_COMMAND(ID_IMAGE_MIRROR, &CKYGImageToolDoc::OnImageMirror)
	ON_COMMAND(ID_IMAGE_FLIP, &CKYGImageToolDoc::OnImageFlip)
	ON_COMMAND(ID_COLOR_SPLIT_RGB, &CKYGImageToolDoc::OnColorSplitRgb)
	ON_UPDATE_COMMAND_UI(ID_COLOR_SPLIT_RGB, &CKYGImageToolDoc::OnUpdateColorSplitRgb)
	ON_COMMAND(ID_COLOR_SPLIT_HSI, &CKYGImageToolDoc::OnColorSplitHsi)
	ON_UPDATE_COMMAND_UI(ID_COLOR_SPLIT_HSI, &CKYGImageToolDoc::OnUpdateColorSplitHsi)
	ON_COMMAND(ID_COLOR_SPLIT_YUV, &CKYGImageToolDoc::OnColorSplitYuv)
	ON_UPDATE_COMMAND_UI(ID_COLOR_SPLIT_YUV, &CKYGImageToolDoc::OnUpdateColorSplitYuv)
	ON_COMMAND(ID_COLOR_CONBINE_RGB, &CKYGImageToolDoc::OnColorConbineRgb)
	ON_COMMAND(ID_COLOR_CONBINE_HSI, &CKYGImageToolDoc::OnColorConbineHsi)
	ON_COMMAND(ID_COLOR_CONBINE_YUV, &CKYGImageToolDoc::OnColorConbineYuv)
	ON_COMMAND(ID_COLOR_EDGE, &CKYGImageToolDoc::OnColorEdge)
	ON_UPDATE_COMMAND_UI(ID_COLOR_EDGE, &CKYGImageToolDoc::OnUpdateColorEdge)
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

/*
void CKYGImageToolDoc::OnHistoEqualization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibHistogramEqualization(dib);

	AfxNewImage(dib);
}
*/

void CKYGImageToolDoc::OnHistoEqualization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	
	if (m_Dib.GetBitCount() == 8)
	{
		CDib dib = m_Dib;
		DibHistogramEqualization(dib);
		AfxNewImage(dib);
	}
	else if (m_Dib.GetBitCount() == 24)
	{
		CDib dib = m_Dib;
		CDib dibY, dibU, dibV;
		DibColorSplitYUV(dib, dibY, dibU, dibV);
		DibHistogramEqualization(dibY);
		CDib dibRes;
		DibColorCombineYUV(dibY, dibU, dibV, dibRes);
		AfxNewImage(dibRes);
	}
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

void CKYGImageToolDoc::OnImageResize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CResizeDlg dlg;
	dlg.m_nOldWidth = m_Dib.GetWidth();
	dlg.m_nOldHeight = m_Dib.GetHeight();
	if(dlg.DoModal() == IDOK) {
		CDib dib = m_Dib;
		switch(dlg.m_nInterpolation)
		{
		case 0: DibResizeNearest(dib, dlg.m_nNewWidth, dlg.m_nNewHeight);	break;
		case 1: DibResizeBilinear(dib, dlg.m_nNewWidth, dlg.m_nNewHeight);	break;
		case 2: DibResizeCubic(dib, dlg.m_nNewWidth, dlg.m_nNewHeight);		break;
		}

	//	TCHAR* interpolation[] = { _T("�ֱٹ� �̿� ������"), _T("�缱�� ������"),
	//		_T("3�� ȸ�� ������") };

		AfxNewImage(dib);
	}
}


void CKYGImageToolDoc::OnImageRotate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CRotateDlg dlg;

	if(dlg.DoModal() == IDOK) {
		CDib dib = m_Dib;
		switch(dlg.m_nRotate)
		{
		case 0: DibRotate90(dib);	break;
		case 1: DibRotate180(dib);	break;
		case 2: DibRotate270(dib);	break;
		case 3: DibRotate(dib, (double)dlg.m_fAngle); break;
		}
		AfxNewImage(dib);
	}
}


void CKYGImageToolDoc::OnImageMirror()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibMirror(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnImageFlip()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibFlip(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnColorSplitRgb()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	CDib dibR, dibG, dibB;
	DibColorSplitRGB(dib, dibR, dibG, dibB);
	AfxNewImage(dibR);
	AfxNewImage(dibG);
	AfxNewImage(dibB);
}


void CKYGImageToolDoc::OnUpdateColorSplitRgb(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CKYGImageToolDoc::OnColorSplitHsi()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	CDib dibH, dibS, dibI;
	DibColorSplitHSI(dib, dibH, dibS, dibI);
	AfxNewImage(dibH);
	AfxNewImage(dibS);
	AfxNewImage(dibI);
}


void CKYGImageToolDoc::OnUpdateColorSplitHsi(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CKYGImageToolDoc::OnColorSplitYuv()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	CDib dibY, dibU, dibV;
	DibColorSplitHSI(dib, dibY, dibU, dibV);
	AfxNewImage(dibY);
	AfxNewImage(dibU);
	AfxNewImage(dibV);
}


void CKYGImageToolDoc::OnUpdateColorSplitYuv(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CKYGImageToolDoc::OnColorConbineRgb()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("RGB ���� ��� ��ġ��");
	if (dlg.DoModal() == IDOK)
	{
		CKYGImageToolDoc* pDoc1 = (CKYGImageToolDoc*)dlg.m_pDoc1;
		CKYGImageToolDoc* pDoc2 = (CKYGImageToolDoc*)dlg.m_pDoc2;
		CKYGImageToolDoc* pDoc3 = (CKYGImageToolDoc*)dlg.m_pDoc3;

		CDib dibR = pDoc1->m_Dib;
		CDib dibG = pDoc2->m_Dib;
		CDib dibB = pDoc3->m_Dib;

		CDib dibColor;
		if (DibColorCombineRGB(dibR, dibG, dibB, dibColor) == false)
		{
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
			return;
		}

		AfxNewImage(dibColor);
	}
}


void CKYGImageToolDoc::OnColorConbineHsi()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("RGB ���� ��� ��ġ��");
	if (dlg.DoModal() == IDOK)
	{
		CKYGImageToolDoc* pDoc1 = (CKYGImageToolDoc*)dlg.m_pDoc1;
		CKYGImageToolDoc* pDoc2 = (CKYGImageToolDoc*)dlg.m_pDoc2;
		CKYGImageToolDoc* pDoc3 = (CKYGImageToolDoc*)dlg.m_pDoc3;

		CDib dibH = pDoc1->m_Dib;
		CDib dibS = pDoc2->m_Dib;
		CDib dibI = pDoc3->m_Dib;

		CDib dibColor;
		if (DibColorCombineHSI(dibH, dibS, dibI, dibColor) == false)
		{
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
			return;
		}

		AfxNewImage(dibColor);
	}
}


void CKYGImageToolDoc::OnColorConbineYuv()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("RGB ���� ��� ��ġ��");
	if (dlg.DoModal() == IDOK)
	{
		CKYGImageToolDoc* pDoc1 = (CKYGImageToolDoc*)dlg.m_pDoc1;
		CKYGImageToolDoc* pDoc2 = (CKYGImageToolDoc*)dlg.m_pDoc2;
		CKYGImageToolDoc* pDoc3 = (CKYGImageToolDoc*)dlg.m_pDoc3;

		CDib dibY = pDoc1->m_Dib;
		CDib dibU = pDoc2->m_Dib;
		CDib dibV = pDoc3->m_Dib;

		CDib dibColor;
		if (DibColorCombineYUV(dibY, dibU, dibV, dibColor) == false)
		{
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
			return;
		}

		DibColorCombineYUV(dibY, dibU, dibV, dibColor);

		AfxNewImage(dibColor);
	}
}

void CKYGImageToolDoc::OnColorEdge()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	CDib dibEdge;
	DibColorEdge(dib, dibEdge);
	AfxNewImage(dibEdge);
}


void CKYGImageToolDoc::OnUpdateColorEdge(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}