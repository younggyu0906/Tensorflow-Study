// KYGImageToolDoc.cpp : CKYGImageToolDoc 클래스의 구현
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


// CKYGImageToolDoc 생성/소멸

CKYGImageToolDoc::CKYGImageToolDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

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
			if( dlg.m_nType == 0 ) // 그레이스케일 이미지
				bSuccess = m_Dib.CreateGrayImage(dlg.m_nWidth, dlg.m_nHeight);
			else // 트루칼라 이미지
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
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CKYGImageToolDoc 진단

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


// CKYGImageToolDoc 명령


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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	DibInverse(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnImageBrightness()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHistogramDlg dlg;
	dlg.SetImage(m_Dib);
	dlg.DoModal();
}

/*
void CKYGImageToolDoc::OnHistoEqualization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	DibHistogramEqualization(dib);

	AfxNewImage(dib);
}
*/

void CKYGImageToolDoc::OnHistoEqualization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
			TCHAR* op[] = { _T("덧셈"), _T("뺄셈"), _T("평균"), _T("차이"), _T("논리 AND"), _T("논리 OR") };
			/*AfxPrintInfo(_T("[산술 및 논리 연산] [%s] 입력 영상 #1: %s, 입력 영상 #2: %s"),
				op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());*/
			AfxNewImage(img3);
		}
		else
			AfxMessageBox(_T("영상의 크기가 다릅니다"));
	}
}


void CKYGImageToolDoc::OnFilterMean()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	DibFilterMean(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnFilterWeightedMean()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	DibFilterWeightedMean(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnGaussian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTranslateDlg dlg;
	if(dlg.DoModal() == IDOK) {
		CDib dib = m_Dib;
		DibTranslate(dib, dlg.m_nNewSX, dlg.m_nNewSY);
		AfxNewImage(dib);
	}
}

void CKYGImageToolDoc::OnImageResize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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

	//	TCHAR* interpolation[] = { _T("최근방 이웃 보간법"), _T("양선형 보간법"),
	//		_T("3차 회선 보간법") };

		AfxNewImage(dib);
	}
}


void CKYGImageToolDoc::OnImageRotate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	DibMirror(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnImageFlip()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	DibFlip(dib);
	AfxNewImage(dib);
}


void CKYGImageToolDoc::OnColorSplitRgb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	CDib dibR, dibG, dibB;
	DibColorSplitRGB(dib, dibR, dibG, dibB);
	AfxNewImage(dibR);
	AfxNewImage(dibG);
	AfxNewImage(dibB);
}


void CKYGImageToolDoc::OnUpdateColorSplitRgb(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CKYGImageToolDoc::OnColorSplitHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	CDib dibH, dibS, dibI;
	DibColorSplitHSI(dib, dibH, dibS, dibI);
	AfxNewImage(dibH);
	AfxNewImage(dibS);
	AfxNewImage(dibI);
}


void CKYGImageToolDoc::OnUpdateColorSplitHsi(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CKYGImageToolDoc::OnColorSplitYuv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	CDib dibY, dibU, dibV;
	DibColorSplitHSI(dib, dibY, dibU, dibV);
	AfxNewImage(dibY);
	AfxNewImage(dibU);
	AfxNewImage(dibV);
}


void CKYGImageToolDoc::OnUpdateColorSplitYuv(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CKYGImageToolDoc::OnColorConbineRgb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("RGB 색상 평면 합치기");
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
			AfxMessageBox(_T("영상의 크기가 다릅니다!"));
			return;
		}

		AfxNewImage(dibColor);
	}
}


void CKYGImageToolDoc::OnColorConbineHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("RGB 색상 평면 합치기");
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
			AfxMessageBox(_T("영상의 크기가 다릅니다!"));
			return;
		}

		AfxNewImage(dibColor);
	}
}


void CKYGImageToolDoc::OnColorConbineYuv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("RGB 색상 평면 합치기");
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
			AfxMessageBox(_T("영상의 크기가 다릅니다!"));
			return;
		}

		DibColorCombineYUV(dibY, dibU, dibV, dibColor);

		AfxNewImage(dibColor);
	}
}

void CKYGImageToolDoc::OnColorEdge()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	CDib dibEdge;
	DibColorEdge(dib, dibEdge);
	AfxNewImage(dibEdge);
}


void CKYGImageToolDoc::OnUpdateColorEdge(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}