// ImageToolDoc.cpp : CImageToolDoc Ŭ������ ����
//

#include "stdafx.h"
#include "ImageTool.h"

#include "ImageToolDoc.h"

#include "Dib.h"
#include "DibEnhancement.h"
#include "DibFilter.h"
#include "DibGeometry.h"
#include "DibFourier.h"

#include "FileNewDlg.h"
#include "BrightnessDlg.h"
#include "ContrastDlg.h"
#include "GammaCorrectionDlg.h"
#include "HistogramDlg.h"
#include "ArithmeticDlg.h"
#include "GaussianDlg.h"
#include "AddNoiseDlg.h"
#include "DiffusionDlg.h"
#include "TranslateDlg.h"
#include "ResizeDlg.h"
#include "RotateDlg.h"
#include "FreqFilterDlg.h"
#include "HarrisDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageToolDoc

IMPLEMENT_DYNCREATE(CImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CImageToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_EDIT_COPY, &CImageToolDoc::OnEditCopy)
	ON_COMMAND(ID_IMAGE_INVERSE, &CImageToolDoc::OnImageInverse)
	ON_COMMAND(ID_IMAGE_BRIGHTNESS, &CImageToolDoc::OnImageBrightness)
	ON_COMMAND(ID_IMAGE_CONTRAST, &CImageToolDoc::OnImageContrast)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageToolDoc::OnGammaCorrection)
	ON_COMMAND(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnViewHistogram)
	ON_COMMAND(ID_HISTO_EQUALIZE, &CImageToolDoc::OnHistoEqualize)
	ON_COMMAND(ID_IMAGE_ARITHMETIC, &CImageToolDoc::OnImageArithmetic)
	ON_COMMAND(ID_BITPLANE_SLICING, &CImageToolDoc::OnBitplaneSlicing)
	ON_COMMAND(ID_FILTER_MEAN, &CImageToolDoc::OnFilterMean)
	ON_COMMAND(ID_FILTER_WEIGHTED_MEAN, &CImageToolDoc::OnFilterWeightedMean)
	ON_COMMAND(ID_FILTER_GAUSSIAN, &CImageToolDoc::OnFilterGaussian)
	ON_COMMAND(ID_FILTER_UNSHARP_MASK, &CImageToolDoc::OnFilterUnsharpMask)
	ON_COMMAND(ID_ADD_NOISE, &CImageToolDoc::OnAddNoise)
	ON_COMMAND(ID_FILTER_MEDIAN, &CImageToolDoc::OnFilterMedian)
	ON_COMMAND(ID_FILTER_DIFFUSION, &CImageToolDoc::OnFilterDiffusion)
	ON_COMMAND(ID_FILTER_LAPLACIAN, &CImageToolDoc::OnFilterLaplacian)
	ON_COMMAND(ID_IMAGE_TRANSLATION, &CImageToolDoc::OnImageTranslation)
	ON_COMMAND(ID_IMAGE_RESIZE, &CImageToolDoc::OnImageResize)
	ON_COMMAND(ID_IMAGE_ROTATE, &CImageToolDoc::OnImageRotate)
	ON_COMMAND(ID_IMAGE_MIRROR, &CImageToolDoc::OnImageMirror)
	ON_COMMAND(ID_IMAGE_FLIP, &CImageToolDoc::OnImageFlip)
	ON_COMMAND(ID_FOURIER_DFT, &CImageToolDoc::OnFourierDft)
	ON_COMMAND(ID_FOURIER_DFTRC, &CImageToolDoc::OnFourierDftrc)
	ON_COMMAND(ID_FOURIER_FFT, &CImageToolDoc::OnFourierFft)
	ON_COMMAND(ID_IDEAL_LOWPASS, &CImageToolDoc::OnIdealLowpass)
	ON_COMMAND(ID_IDEAL_HIGHPASS, &CImageToolDoc::OnIdealHighpass)
	ON_COMMAND(ID_GAUSSIAN_LOWPASS, &CImageToolDoc::OnGaussianLowpass)
	ON_COMMAND(ID_GAUSSIAN_HIGHPASS, &CImageToolDoc::OnGaussianHighpass)
	ON_COMMAND(ID_EDGE_ROBERTS, &CImageToolDoc::OnEdgeRoberts)
	ON_COMMAND(ID_EDGE_PREWITT, &CImageToolDoc::OnEdgePrewitt)
	ON_COMMAND(ID_EDGE_SOBEL, &CImageToolDoc::OnEdgeSobel)
	ON_COMMAND(ID_HOUGH_LINE, &CImageToolDoc::OnHoughLine)
	ON_COMMAND(ID_HARRIS_CORNER, &CImageToolDoc::OnHarrisCorner)
END_MESSAGE_MAP()


// CImageToolDoc ����/�Ҹ�

CImageToolDoc::CImageToolDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CImageToolDoc::~CImageToolDoc()
{
}

BOOL CImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL bSuccess = TRUE;

	if( theApp.m_pNewDib != NULL )
	{
		m_Dib.Copy(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}
	else
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

	return bSuccess;
}

// CImageToolDoc serialization

void CImageToolDoc::Serialize(CArchive& ar)
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


// CImageToolDoc ����

#ifdef _DEBUG
void CImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageToolDoc ���


BOOL CImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	return  m_Dib.Load(lpszPathName);
}

BOOL CImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return  m_Dib.Save(lpszPathName);
}

void CImageToolDoc::OnWindowDuplicate()
{
	AfxNewImage(m_Dib);
}

void CImageToolDoc::OnEditCopy()
{
	if( m_Dib.IsValid() )
		m_Dib.CopyToClipboard();
}

void CImageToolDoc::OnImageInverse()
{
	CDib dib = m_Dib;
	DibInverse(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnImageBrightness()
{
	CBrightnessDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibBrightness(dib, dlg.m_nBrightness);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnImageContrast()
{
	CContrastDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibContrast(dib, dlg.m_nContrast);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnGammaCorrection()
{
	CGammaCorrectionDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibGammaCorrection(dib, dlg.m_fGamma);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnViewHistogram()
{
	CHistogramDlg dlg;
	dlg.SetImage(m_Dib);
	dlg.DoModal();
}

void CImageToolDoc::OnHistoEqualize()
{
	CDib dib = m_Dib;
	DibHistEqual(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnImageArithmetic()
{
	CArithmeticDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;

		CDib dib;
		BOOL ret = FALSE;

		switch( dlg.m_nFunction )
		{
		case 0: ret = DibAdd(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 1: ret = DibSub(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 2: ret = DibAve(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 3: ret = DibDif(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 4: ret = DibAND(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 5: ret = DibOR(pDoc1->m_Dib, pDoc2->m_Dib, dib);  break;
		}

		if( ret )
			AfxNewImage(dib);
		else
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
	}
}

void CImageToolDoc::OnBitplaneSlicing()
{
	register int i;

	int w = m_Dib.GetWidth();
	int h = m_Dib.GetHeight();

	CDib dib;
	dib.CreateGrayImage(w, h);

	for( i = 0 ; i < 8 ; i++ )
	{
		DibBitPlane(m_Dib, i, dib);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnFilterMean()
{
	CDib dib = m_Dib;
	DibFilterMean(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnFilterWeightedMean()
{
	CDib dib = m_Dib;
	DibFilterWeightedMean(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnFilterGaussian()
{
	CGaussianDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibFilterGaussian(dib, dlg.m_fSigma);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnFilterLaplacian()
{
	CDib dib = m_Dib;
	DibFilterLaplacian(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnFilterUnsharpMask()
{
	CDib dib = m_Dib;
	DibFilterUnsharpMask(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnAddNoise()
{
	CAddNoiseDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;

		if( dlg.m_nNoiseType == 0 )
			DibNoiseGaussian(dib, dlg.m_nAmount);
		else
			DibNoiseSaltNPepper(dib, dlg.m_nAmount);

		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnFilterMedian()
{
	CDib dib = m_Dib;
	DibFilterMedean(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnFilterDiffusion()
{
	CDiffusionDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibFilterDiffusion(dib, dlg.m_fLambda, dlg.m_fK, dlg.m_nIteration);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnImageTranslation()
{
	CTranslateDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibTranslate(dib, dlg.m_nNewSX, dlg.m_nNewSY);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnImageResize()
{
	CResizeDlg dlg;
	dlg.m_nOldWidth = m_Dib.GetWidth();
	dlg.m_nOldHeight = m_Dib.GetHeight();
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		switch( dlg.m_nInterpolation )
		{
		case 0: DibResizeNearest(dib, dlg.m_nNewWidth, dlg.m_nNewHeight); break;
		case 1: DibResizeBilinear(dib, dlg.m_nNewWidth, dlg.m_nNewHeight); break;
		case 2: DibResizeCubic(dib, dlg.m_nNewWidth, dlg.m_nNewHeight); break;
		}

		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnImageRotate()
{
	CRotateDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		switch( dlg.m_nRotate )
		{
		case 0: DibRotate90(dib); break;
		case 1: DibRotate180(dib); break;
		case 2: DibRotate270(dib); break;
		case 3: DibRotate(dib, (double)dlg.m_fAngle); break;
		}

		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnImageMirror()
{
	CDib dib = m_Dib;
	DibMirror(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnImageFlip()
{
	CDib dib = m_Dib;
	DibFlip(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnFourierDft()
{
	int w = m_Dib.GetWidth();
	int h = m_Dib.GetHeight();

	if( w*h > 128*128 )
	{
		CString str = _T("������ ũ�Ⱑ Ŀ�� �ð��� ���� �ɸ� �� �ֽ��ϴ�.\n��� �Ͻðڽ��ϱ�?");

		if( AfxMessageBox(str, MB_OKCANCEL) != IDOK )
			return;
	}

	CDibFourier fourier;
	fourier.SetImage(m_Dib);
	fourier.DFT(1);

	CDib dib;

	fourier.GetSpectrumImage(dib);
	AfxNewImage(dib);

	fourier.GetPhaseImage(dib);
	AfxNewImage(dib);

	fourier.DFT(-1);
	fourier.GetImage(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnFourierDftrc()
{
	CDibFourier fourier;
	fourier.SetImage(m_Dib);
	fourier.DFTRC(1);

	CDib dib;

	fourier.GetSpectrumImage(dib);
	AfxNewImage(dib);

	fourier.GetPhaseImage(dib);
	AfxNewImage(dib);

	fourier.DFTRC(-1);
	fourier.GetImage(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnFourierFft()
{
	int w = m_Dib.GetWidth();
	int h = m_Dib.GetHeight();

	if( !IsPowerOf2(w) || !IsPowerOf2(h) )
	{
		AfxMessageBox(_T("���� �Ǵ� ������ ũ�Ⱑ 2�� �¼��� �ƴմϴ�."));
		return;
	}

	CDibFourier fourier;
	fourier.SetImage(m_Dib);
	fourier.FFT(1);

	CDib dib;

	fourier.GetSpectrumImage(dib);
	AfxNewImage(dib);

	fourier.GetPhaseImage(dib);
	AfxNewImage(dib);

	fourier.FFT(-1);
	fourier.GetImage(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnIdealLowpass()
{
	int w = m_Dib.GetWidth();
	int h = m_Dib.GetHeight();

	if( !IsPowerOf2(w) || !IsPowerOf2(h) )
	{
		AfxMessageBox(_T("���� �Ǵ� ������ ũ�Ⱑ 2�� �¼��� �ƴմϴ�."));
		return;
	}

	CFreqFilterDlg dlg;
	dlg.m_strFilterType = _T("���� ��� ����");
	dlg.m_strFilterShape = _T("�̻���(Ideal)");
	dlg.m_strRange.Format(_T("(0 ~ %d)"), min(w/2, h/2));
	if( dlg.DoModal() == IDOK )
	{
		CDibFourier fourier;
		fourier.SetImage(m_Dib);
		fourier.FFT(1);
		fourier.IdealLowpass(dlg.m_nCutoff);
		fourier.FFT(-1);

		CDib dib;
		fourier.GetImage(dib);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnIdealHighpass()
{
	int w = m_Dib.GetWidth();
	int h = m_Dib.GetHeight();

	if( !IsPowerOf2(w) || !IsPowerOf2(h) )
	{
		AfxMessageBox(_T("���� �Ǵ� ������ ũ�Ⱑ 2�� �¼��� �ƴմϴ�."));
		return;
	}

	CFreqFilterDlg dlg;
	dlg.m_strFilterType = _T("�� ��� ����");
	dlg.m_strFilterShape = _T("�̻���(Ideal)");
	dlg.m_strRange.Format(_T("(0 ~ %d)"), min(w/2, h/2));
	if( dlg.DoModal() == IDOK )
	{
		CDibFourier fourier;
		fourier.SetImage(m_Dib);
		fourier.FFT(1);
		fourier.IdealHighpass(dlg.m_nCutoff);
		fourier.FFT(-1);

		CDib dib;
		fourier.GetImage(dib);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnGaussianLowpass()
{
	int w = m_Dib.GetWidth();
	int h = m_Dib.GetHeight();

	if( !IsPowerOf2(w) || !IsPowerOf2(h) )
	{
		AfxMessageBox(_T("���� �Ǵ� ������ ũ�Ⱑ 2�� �¼��� �ƴմϴ�."));
		return;
	}

	CFreqFilterDlg dlg;
	dlg.m_strFilterType = _T("���� ��� ����");
	dlg.m_strFilterShape = _T("����þ�(Gaussian)");
	dlg.m_strRange.Format(_T("(0 ~ %d)"), min(w/2, h/2));
	if( dlg.DoModal() == IDOK )
	{
		CDibFourier fourier;
		fourier.SetImage(m_Dib);
		fourier.FFT(1);
		fourier.GaussianLowpass(dlg.m_nCutoff);
		fourier.FFT(-1);

		CDib dib;
		fourier.GetImage(dib);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnGaussianHighpass()
{
	int w = m_Dib.GetWidth();
	int h = m_Dib.GetHeight();

	if( !IsPowerOf2(w) || !IsPowerOf2(h) )
	{
		AfxMessageBox(_T("���� �Ǵ� ������ ũ�Ⱑ 2�� �¼��� �ƴմϴ�."));
		return;
	}

	CFreqFilterDlg dlg;
	dlg.m_strFilterType = _T("�� ��� ����");
	dlg.m_strFilterShape = _T("����þ�(Gaussian)");
	dlg.m_strRange.Format(_T("(0 ~ %d)"), min(w/2, h/2));
	if( dlg.DoModal() == IDOK )
	{
		CDibFourier fourier;
		fourier.SetImage(m_Dib);
		fourier.FFT(1);
		fourier.GaussianHighpass(dlg.m_nCutoff);
		fourier.FFT(-1);

		CDib dib;
		fourier.GetImage(dib);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnEdgeRoberts()
{
	CDib dib = m_Dib;
	DibEdgeRoberts(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnEdgePrewitt()
{
	CDib dib = m_Dib;
	DibEdgePrewitt(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnEdgeSobel()
{
	CDib dib = m_Dib;
	DibEdgeSobel(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnHoughLine()
{
	CDib dib = m_Dib;
	LineParam line = DibHoughLine(dib);
	DibDrawLine(dib, line, 255);

	AfxNewImage(dib);

	CString str;
	str.Format(_T("���� ��ȯ ���:\n\nrho = %lf, ang = %lf"), line.rho, line.ang);
	AfxMessageBox(str);
}

void CImageToolDoc::OnHarrisCorner()
{
	CHarrisDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CornerPoints cp;
		cp = DibHarrisCorner(m_Dib, dlg.m_nThreshold);

		CDib dib = m_Dib;
		BYTE** ptr = dib.GetPtr();

		int i, x, y;
		for( i = 0 ; i < cp.num ; i++ )
		{
			x = cp.x[i];
			y = cp.y[i];

			ptr[y-1][x-1] = ptr[y-1][x] = ptr[y-1][x+1] = 0;
			ptr[y  ][x-1] = ptr[y  ][x] = ptr[y  ][x+1] = 0;
			ptr[y+1][x-1] = ptr[y+1][x] = ptr[y+1][x+1] = 0;
		}

		AfxNewImage(dib);
	}
}
