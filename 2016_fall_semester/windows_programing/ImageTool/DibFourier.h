#pragma once

class CDib;
class CDibFourier
{
public:
	CDibFourier(void);
	~CDibFourier(void);

public:
	int m_nWidth, m_nHeight;

	double** m_pRe;  // �Ǽ���
	double** m_pIm;  // �����

public:
	void SetImage(CDib& dib);
	void GetImage(CDib& dib);
	void GetSpectrumImage(CDib& dib);
	void GetPhaseImage(CDib& dib);

	// Ǫ���� ��ȯ �Լ���
	void DFT(int dir);
	void DFTRC(int dir);
	void FFT(int dir);

	// ���ļ� ���������� ���͸� ���� �Լ�
	void IdealLowpass(int cutoff);
	void IdealHighpass(int cutoff);
	void GaussianLowpass(int cutoff);
	void GaussianHighpass(int cutoff);

protected:
	void Free();
};

//-------------------------------------------------------------------------
// ���� �Լ� ����
//-------------------------------------------------------------------------

void DFT1d(double* re, double* im, int N, int dir);
void FFT1d(double* re, double* im, int N, int dir);
BOOL IsPowerOf2(int n);
