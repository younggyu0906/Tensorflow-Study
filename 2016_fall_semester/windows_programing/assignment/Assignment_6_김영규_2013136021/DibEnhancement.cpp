#include "StdAfx.h"
#include "Dib.h"
#include "DibEnhancement.h"

#include <math.h>

void DibInverse(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr[j][i] = 255 - ptr[j][i];
	}
}

void DibBrightness(CDib& dib, int n)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr[j][i] = limit(ptr[j][i] + n);
	}
}

void DibContrast(CDib& dib, int n)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr[j][i] = static_cast<BYTE>(limit(ptr[j][i] + (ptr[j][i] - 128) * n / 100));
	}
}

void DibHistogram(CDib& dib, float histo[256])
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	// 히스토그램 계산

	int temp[256];
	memset(temp, 0, sizeof(int)*256);
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		temp[ ptr[j][i] ]++;
	}

	// 히스토그램 정규화(histogram normalization)

	float area = (float)w*h;
	for( i = 0 ; i < 256 ; i++ )
		histo[i] = temp[i] / area;
}

void DibHistogramEqualization(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	// 히스토그램 계산
	float histo[256];
	DibHistogram(dib, histo);

	// 히스토그램 누적 함수 계산
	float cdf[256] = {0.0, };
	cdf[0] = histo[0];
	for(int i = 1; i < 256; i++)
		cdf[i] = cdf[i - 1] + histo[i];

	// 히스토그램 균등화
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr[j][i] = static_cast<BYTE>(limit(cdf[ptr[j][i]] * 255));
	}
}

BOOL DibAdd(CDib& dib1, CDib& dib2, CDib& dib3)	// 덧셈 연산
{
	register int i, j;

	int w = dib1.GetWidth();
	int h = dib1.GetHeight();

	if( w != dib2.GetWidth() || h != dib2.GetHeight() )
		return FALSE;

	dib3.CreateGrayImage(w, h);

	BYTE** ptr1 = dib1.GetPtr();
	BYTE** ptr2 = dib2.GetPtr();
	BYTE** ptr3 = dib3.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr3[j][i] = limit(ptr1[j][i] + ptr2[j][i]);
	}

	return TRUE;
}

BOOL DibSub(CDib& dib1, CDib& dib2, CDib& dib3)	// 뺄셈 연산
{
	register int i, j;

	int w = dib1.GetWidth();
	int h = dib1.GetHeight();

	if( w != dib2.GetWidth() || h != dib2.GetHeight() )
		return FALSE;

	dib3.CreateGrayImage(w, h);

	BYTE** ptr1 = dib1.GetPtr();
	BYTE** ptr2 = dib2.GetPtr();
	BYTE** ptr3 = dib3.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr3[j][i] = limit(ptr1[j][i] - ptr2[j][i]);
	}

	return TRUE;
}

BOOL DibAve(CDib& dib1, CDib& dib2, CDib& dib3)	// 평균 연산
{
	register int i, j;

	int w = dib1.GetWidth();
	int h = dib1.GetHeight();

	if( w != dib2.GetWidth() || h != dib2.GetHeight() )
		return FALSE;

	dib3.CreateGrayImage(w, h);

	BYTE** ptr1 = dib1.GetPtr();
	BYTE** ptr2 = dib2.GetPtr();
	BYTE** ptr3 = dib3.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr3[j][i] = (BYTE)((ptr1[j][i] + ptr2[j][i])/2);
	}

	return TRUE;
}

BOOL DibDif(CDib& dib1, CDib& dib2, CDib& dib3)	// 차이 연산
{
	register int i, j;

	int w = dib1.GetWidth();
	int h = dib1.GetHeight();

	if( w != dib2.GetWidth() || h != dib2.GetHeight() )
		return FALSE;

	dib3.CreateGrayImage(w, h);

	BYTE** ptr1 = dib1.GetPtr();
	BYTE** ptr2 = dib2.GetPtr();
	BYTE** ptr3 = dib3.GetPtr();

	int temp;
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		temp = ptr1[j][i] - ptr2[j][i];
		ptr3[j][i] = (BYTE)((temp >= 0 ) ? temp:-temp);
	}

	return TRUE;
}

BOOL DibAND(CDib& dib1, CDib& dib2, CDib& dib3)	// AND 연산 (논리곱)
{
	register int i, j;

	int w = dib1.GetWidth();
	int h = dib1.GetHeight();

	if( w != dib2.GetWidth() || h != dib2.GetHeight() )
		return FALSE;

	dib3.CreateGrayImage(w, h);

	BYTE** ptr1 = dib1.GetPtr();
	BYTE** ptr2 = dib2.GetPtr();
	BYTE** ptr3 = dib3.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr3[j][i] = (BYTE)(ptr1[j][i] & ptr2[j][i]);
	}

	return TRUE;
}

BOOL DibOR(CDib& dib1, CDib& dib2, CDib& dib3)	// OR 연산 (논리합)
{
	register int i, j;

	int w = dib1.GetWidth();
	int h = dib1.GetHeight();

	if( w != dib2.GetWidth() || h != dib2.GetHeight() )
		return FALSE;

	dib3.CreateGrayImage(w, h);

	BYTE** ptr1 = dib1.GetPtr();
	BYTE** ptr2 = dib2.GetPtr();
	BYTE** ptr3 = dib3.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr3[j][i] = (BYTE)(ptr1[j][i] | ptr2[j][i]);
	}

	return TRUE;
}