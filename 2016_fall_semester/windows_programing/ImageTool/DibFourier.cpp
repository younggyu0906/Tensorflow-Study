#include "StdAfx.h"
#include "Dib.h"
#include "DibFourier.h"

#include <math.h>

const double PI = acos(-1.0);

CDibFourier::CDibFourier(void)
: m_nWidth(0), m_nHeight(0), m_pRe(NULL), m_pIm(NULL)
{
}

CDibFourier::~CDibFourier(void)
{
	Free();
}

void CDibFourier::Free()
{
	register int i;

	//-------------------------------------------------------------------------
	// ���� �Ҵ�� �޸𸮰� �����Ѵٸ� �����Ѵ�. 
	//-------------------------------------------------------------------------

	if( m_pRe )
	{
		for( i = 0 ; i < m_nHeight ; i++ )
			delete [] m_pRe[i];
		delete [] m_pRe;
	}

	if( m_pIm )
	{
		for( i = 0 ; i < m_nHeight ; i++ )
			delete [] m_pIm[i];
		delete [] m_pIm;
	}
}

void CDibFourier::SetImage(CDib& dib)
{
	//-------------------------------------------------------------------------
	// ��� ���� �� ���� 
	//-------------------------------------------------------------------------

	Free();

	register int i, j;

	m_nWidth  = dib.GetWidth();
	m_nHeight = dib.GetHeight();

	//-------------------------------------------------------------------------
	// Ǫ���� ��ȯ ��� ���� ������ �޸� ���� �Ҵ�
	//-------------------------------------------------------------------------

	m_pRe = new double*[m_nHeight];
	m_pIm = new double*[m_nHeight];

	for( i = 0 ; i < m_nHeight ; i++ )
	{
		m_pRe[i] = new double[m_nWidth];
		m_pIm[i] = new double[m_nWidth];

		memset(m_pRe[i], 0, sizeof(double)*m_nWidth);
		memset(m_pIm[i], 0, sizeof(double)*m_nWidth);
	}

	//-------------------------------------------------------------------------
	// ���Ҽ� �迭�� �Ǽ��ο� ������ �׷��̽����� ���� ����
	//-------------------------------------------------------------------------

	BYTE** ptr = dib.GetPtr();

	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		m_pRe[j][i] = (double)ptr[j][i];
	}
}

void CDibFourier::GetImage(CDib& dib)
{
	if( m_pRe == NULL )
		return;

	//-------------------------------------------------------------------------
	// ���Ҽ��� �Ǽ����� ���� �̿��Ͽ� ��� ������ �����Ѵ�. 
	//-------------------------------------------------------------------------

	register int i, j;

	dib.CreateGrayImage(m_nWidth, m_nHeight);

	BYTE** ptr = dib.GetPtr();

	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		ptr[j][i] = (BYTE)limit(m_pRe[j][i] + 0.5);
	}
}

void CDibFourier::GetSpectrumImage(CDib& dib)
{
	register int i, j;

	dib.CreateGrayImage(m_nWidth, m_nHeight);

	BYTE** ptr = dib.GetPtr();

	//-------------------------------------------------------------------------
	// ����Ʈ�� ���� ������ �ӽ� ���� �޸� ���� �Ҵ�
	//-------------------------------------------------------------------------

	double** pSpectrum = new double*[m_nHeight];
	for( i = 0 ; i < m_nHeight ; i++ )
	{
		pSpectrum[i] = new double[m_nWidth];
		memset(pSpectrum[i], 0, sizeof(double)*m_nWidth);
	}

	//-------------------------------------------------------------------------
	// ���Ҽ� ���� ���밪�� �α� ��ȯ�Ͽ� ����. 
	// ����ȭ�� ��� �̹��� ������ ���Ͽ� ����Ʈ���� �ִ밪 ���.
	//-------------------------------------------------------------------------

	double mag, max_value = 0;
	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		mag = sqrt(m_pRe[j][i]*m_pRe[j][i] + m_pIm[j][i]*m_pIm[j][i]);
		pSpectrum[j][i] = log(mag + 1);

		if( pSpectrum[j][i] > max_value ) 
			max_value = pSpectrum[j][i];
	}

	//-------------------------------------------------------------------------
	// ��� ���� ����. Ǫ���� ��ȯ ����� SHIFT �ϰ�, 
	// ��� ������ �ִ밪�� 255�� �ǵ��� �׷��̽����� ���� ����ȭ.
	//-------------------------------------------------------------------------

	int x, y;
	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		x = i + m_nWidth/2;
		y = j + m_nHeight/2;

		if( x >= m_nWidth  ) x -= m_nWidth;
		if( y >= m_nHeight ) y -= m_nHeight;

		ptr[j][i] = (BYTE)limit(pSpectrum[y][x]*255/max_value);
	}

	//-------------------------------------------------------------------------
	// �ӽ� ���� �޸� ���� ����
	//-------------------------------------------------------------------------

	for( i = 0 ; i < m_nHeight ; i++ )
		delete [] pSpectrum[i];
	delete [] pSpectrum;
}

void CDibFourier::GetPhaseImage(CDib& dib)
{
	register int i, j;

	dib.CreateGrayImage(m_nWidth, m_nHeight);

	BYTE** ptr = dib.GetPtr();

	//-------------------------------------------------------------------------
	// ������ ������ �ӽ� ���� �޸� ���� �Ҵ�
	//-------------------------------------------------------------------------

	double** pPhase = new double*[m_nHeight];
	for( i = 0 ; i < m_nHeight ; i++ )
	{
		pPhase[i] = new double[m_nWidth];
		memset(pPhase[i], 0, sizeof(double)*m_nWidth);
	}

	//-------------------------------------------------------------------------
	// ���Ҽ� ���� ������ ����. atan2 �Լ��� ��ȯ ���� -PI ~ PI �̴�.
	//-------------------------------------------------------------------------

	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		pPhase[j][i] = atan2(m_pIm[j][i], m_pRe[j][i]); // ����� ����
	}

	//-------------------------------------------------------------------------
	// ��� ���� ����. Ǫ���� ��ȯ ����� SHIFT �ϰ�, 
	// ��� ������ �ִ밪�� 255�� �ǵ��� �׷��̽����� ���� ����ȭ.
	//-------------------------------------------------------------------------

	int x, y;
	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		x = i + m_nWidth/2;
		y = j + m_nHeight/2;

		if( x >= m_nWidth  ) x -= m_nWidth;
		if( y >= m_nHeight ) y -= m_nHeight;

		ptr[j][i] = (BYTE)limit(pPhase[y][x]*128/PI + 128);
	}

	//-------------------------------------------------------------------------
	// �ӽ� ���� �޸� ���� ����
	//-------------------------------------------------------------------------

	for( i = 0 ; i < m_nHeight ; i++ )
		delete [] pPhase[i];
	delete [] pPhase;
}

void CDibFourier::DFT(int dir)
{
	if( m_pRe == NULL || m_pIm == NULL )
		return;

	register int i, j, x, y;

	//-------------------------------------------------------------------------
	// m_pRe, m_pIm �� ������ �޸� ������ �ӽ÷� �����Ѵ�. 
	//-------------------------------------------------------------------------

	double** re = new double*[m_nHeight];
	double** im = new double*[m_nHeight];

	for( i = 0 ; i < m_nHeight ; i++ )
	{
		re[i] = new double[m_nWidth];
		im[i] = new double[m_nWidth];

		memcpy(re[i], m_pRe[i], sizeof(double)*m_nWidth);
		memcpy(im[i], m_pIm[i], sizeof(double)*m_nWidth);
	}

	//-------------------------------------------------------------------------
	// �̻� Ǫ���� ��ȯ (�Ǵ� ����ȯ)
	//-------------------------------------------------------------------------

	double sum_re, sum_im, temp;

	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		sum_re = sum_im = 0;

		for( y = 0 ; y < m_nHeight ; y++ )
		for( x = 0 ; x < m_nWidth  ; x++ )
		{
			temp = 2*dir*PI*((double)i*x/m_nWidth + (double)j*y/m_nHeight);
			sum_re += (re[y][x]*cos(temp) - im[y][x]*sin(temp));
			sum_im += (re[y][x]*sin(temp) + im[y][x]*sin(temp));
		}

		m_pRe[j][i] = sum_re;
		m_pIm[j][i] = sum_im;

 		if( dir == -1 ) // Backward transform
		{
			m_pRe[j][i] /= (m_nWidth*m_nHeight);
			m_pIm[j][i] /= (m_nWidth*m_nHeight);
		}
	}

	//-------------------------------------------------------------------------
	// �ӽ÷� ������ �޸� ������ �����Ѵ�. 
	//-------------------------------------------------------------------------

	for( i = 0 ; i < m_nHeight ; i++ )
	{
		delete [] re[i];
		delete [] im[i];
	}
	delete [] re;
	delete [] im;
}

void CDibFourier::DFTRC(int dir)
{
	if( m_pRe == NULL || m_pIm == NULL )
		return;

	register int i, j;

	//-------------------------------------------------------------------------
	// ��(Row) ���� �̻� Ǫ���� ��ȯ (�Ǵ� ����ȯ)
	//-------------------------------------------------------------------------

	double* re = new double[m_nWidth];
	double* im = new double[m_nWidth];

	memset(re, 0, sizeof(double)*m_nWidth);
	memset(im, 0, sizeof(double)*m_nWidth);

	for( j = 0 ; j < m_nHeight ; j++ )
	{
		for( i = 0 ; i < m_nWidth ; i++ )
		{
			re[i] = m_pRe[j][i];
			im[i] = m_pIm[j][i];
		}

		DFT1d(re, im, m_nWidth, dir);

		for( i = 0 ; i < m_nWidth ; i++ )
		{
			m_pRe[j][i] = re[i];
			m_pIm[j][i] = im[i];
		}
	}

	delete [] re;
	delete [] im;

	//-------------------------------------------------------------------------
	// ��(Column) ���� �̻� Ǫ���� ��ȯ (�Ǵ� ����ȯ)
	//-------------------------------------------------------------------------

	re = new double[m_nHeight];
	im = new double[m_nHeight];

	memset(re, 0, sizeof(double)*m_nHeight);
	memset(im, 0, sizeof(double)*m_nHeight);

	for( i = 0 ; i < m_nWidth ; i++ )
	{
		for( j = 0 ; j < m_nHeight ; j++ )
		{
			re[j] = m_pRe[j][i];
			im[j] = m_pIm[j][i];
		}

		DFT1d(re, im, m_nHeight, dir);

		for( j = 0 ; j < m_nHeight ; j++ )
		{
			m_pRe[j][i] = re[j];
			m_pIm[j][i] = im[j];
		}
	}

	delete [] re;
	delete [] im;
}

void CDibFourier::FFT(int dir)
{
	if( m_pRe == NULL || m_pIm == NULL )
		return;

	if( !IsPowerOf2(m_nWidth) || !IsPowerOf2(m_nHeight) )
		return;

	register int i, j;

	//-------------------------------------------------------------------------
	// ��(Row) ���� FFT (�Ǵ� IFFT)
	//-------------------------------------------------------------------------

	double* re = new double[m_nWidth];
	double* im = new double[m_nWidth];

	memset(re, 0, sizeof(double)*m_nWidth);
	memset(im, 0, sizeof(double)*m_nWidth);

	for( j = 0 ; j < m_nHeight ; j++ )
	{
		for( i = 0 ; i < m_nWidth ; i++ )
		{
			re[i] = m_pRe[j][i];
			im[i] = m_pIm[j][i];
		}

		FFT1d(re, im, m_nWidth, dir);

		for( i = 0 ; i < m_nWidth ; i++ )
		{
			m_pRe[j][i] = re[i];
			m_pIm[j][i] = im[i];
		}
	}

	delete [] re;
	delete [] im;

	//-------------------------------------------------------------------------
	// ��(Column) ���� FFT (�Ǵ� IFFT)
	//-------------------------------------------------------------------------

	re = new double[m_nHeight];
	im = new double[m_nHeight];

	memset(re, 0, sizeof(double)*m_nHeight);
	memset(im, 0, sizeof(double)*m_nHeight);

	for( i = 0 ; i < m_nWidth ; i++ )
	{
		for( j = 0 ; j < m_nHeight ; j++ )
		{
			re[j] = m_pRe[j][i];
			im[j] = m_pIm[j][i];
		}

		FFT1d(re, im, m_nHeight, dir);

		for( j = 0 ; j < m_nHeight ; j++ )
		{
			m_pRe[j][i] = re[j];
			m_pIm[j][i] = im[j];
		}
	}

	delete [] re;
	delete [] im;
}

void CDibFourier::IdealLowpass(int cutoff)
{
	register int i, j;

	int w2 = m_nWidth  / 2;
	int h2 = m_nHeight / 2;

	int x, y;
	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		x = i + w2;
		y = j + h2;

		if( x >= m_nWidth  ) x -= m_nWidth;
		if( y >= m_nHeight ) y -= m_nHeight;

		if( sqrt( (double)(x-w2)*(x-w2) + (y-h2)*(y-h2) ) > cutoff )
			m_pRe[j][i] = m_pIm[j][i] = 0;
	}
}

void CDibFourier::IdealHighpass(int cutoff)
{
	register int i, j;

	int w2 = m_nWidth  / 2;
	int h2 = m_nHeight / 2;

	int x, y;
	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		x = i + w2;
		y = j + h2;

		if( x >= m_nWidth  ) x -= m_nWidth;
		if( y >= m_nHeight ) y -= m_nHeight;

		if( sqrt( (double)(x-w2)*(x-w2) + (y-h2)*(y-h2) ) < cutoff )
			m_pRe[j][i] = m_pIm[j][i] = 0;
	}
}

void CDibFourier::GaussianLowpass(int cutoff)
{
	register int i, j;

	int w2 = m_nWidth  / 2;
	int h2 = m_nHeight / 2;

	int x, y;
	double dist2, hval;
	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		x = i + w2;
		y = j + h2;

		if( x >= m_nWidth  ) x -= m_nWidth;
		if( y >= m_nHeight ) y -= m_nHeight;

		dist2 = (double)(x-w2)*(x-w2) + (y-h2)*(y-h2);

		hval = exp( -dist2 / (2*cutoff*cutoff) );

		m_pRe[j][i] *= hval;
		m_pIm[j][i] *= hval;
	}
}

void CDibFourier::GaussianHighpass(int cutoff)
{
	register int i, j;

	int w2 = m_nWidth  / 2;
	int h2 = m_nHeight / 2;

	int x, y;
	double dist2, hval;
	for( j = 0 ; j < m_nHeight ; j++ )
	for( i = 0 ; i < m_nWidth  ; i++ )
	{
		x = i + w2;
		y = j + h2;

		if( x >= m_nWidth  ) x -= m_nWidth;
		if( y >= m_nHeight ) y -= m_nHeight;

		dist2 = (double)(x-w2)*(x-w2) + (y-h2)*(y-h2);

		hval = 1.0 - exp( -dist2 / (2*cutoff*cutoff) );

		m_pRe[j][i] *= hval;
		m_pIm[j][i] *= hval;
	}
}

//-------------------------------------------------------------------------
// ���� �Լ� ����
//-------------------------------------------------------------------------

void DFT1d(double* re, double* im, int N, int dir)
{
	register int i, x;

	double* tr = new double[N];
	double* ti = new double[N];

	memcpy(tr, re, sizeof(double)*N);
	memcpy(ti, im, sizeof(double)*N);

	double sum_re, sum_im, temp;

	for( i = 0 ; i < N ; i++ )
	{
		sum_re = sum_im = 0;

		for( x = 0 ; x < N ; x++ )
		{
			temp = 2*dir*PI*((double)i*x/N);

			sum_re += (tr[x]*cos(temp) + ti[x]*sin(temp));
			sum_im += (ti[x]*cos(temp) - tr[x]*sin(temp));
		}

		re[i] = sum_re;
		im[i] = sum_im;
	}

	if( dir == -1 ) // IDFT
	{
		for( i = 0 ; i < N ; i++ )
		{
			re[i] /= (double)N;
			im[i] /= (double)N;
		}
	}

	delete [] tr;
	delete [] ti;
}

void FFT1d(double* re, double* im, int N, int dir)
{
	register int i, j, k;

	//-------------------------------------------------------------------------
	// �Է� �������� ���� �ٲٱ�
	//-------------------------------------------------------------------------

	int n2 = N >> 1;
	int nb = 0;

	while( N != ( 1 << nb ) )
		nb++;

	for( i = 0, j = 0 ; i < N-1 ; i++ )
	{
		if( i < j )
		{
			swap(re[i], re[j]);
			swap(im[i], im[j]);
		}

		k = n2;
		
		while( k <= j )
		{
			j -= k;
			k >>= 1;
		}

		j += k;
	}

	//-------------------------------------------------------------------------
	// �����ö���(Butterfly) �˰���
	//-------------------------------------------------------------------------

	int i1, l, l1, l2;
	double c1, c2, t1, t2, u1, u2, z;

	c1 = -1.0;
	c2 = 0.0;
	l2 = 1;

	for( l = 0 ; l < nb ; l++ ) 
	{
		l1 = l2;
		l2 <<= 1;
		u1 = 1.0;
		u2 = 0.0;

		for( j = 0 ; j < l1 ; j++ )
		{
			for( i = j ; i < N ; i += l2 )
			{
				i1 = i + l1;
				t1 = u1 * re[i1] - u2 * im[i1];
				t2 = u1 * im[i1] + u2 * re[i1];
				re[i1] = re[i] - t1;
				im[i1] = im[i] - t2;
				re[i] += t1;
				im[i] += t2;
			}

			z =  u1 * c1 - u2 * c2;
			u2 = u1 * c2 + u2 * c1;
			u1 = z;
		}

		c2 = sqrt((1.0 - c1) / 2.0);
		
		if( dir == 1 ) // Forward
			c2 = -c2;
		
		c1 = sqrt((1.0 + c1) / 2.0);
	}

	if( dir == -1 ) // IDFT
	{
		for( i = 0 ; i < N ; i++ )
		{
			re[i] /= (double)N;
			im[i] /= (double)N;
		}
	}
}

BOOL IsPowerOf2(int n)
{
	int ref = 1;
	
	while( ref < n )
		ref <<= 1;
	
	if( ref == n ) 
		return TRUE;
	else
		return FALSE;
}
