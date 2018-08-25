#include <cstdio>

double KYGSlowPower(double x, int n) {	// �ݺ����� �ŵ����� ��� �Լ�
	double result = 1.0;
	for(int i = 0; i < n; i++)
		result = result * x;
	return result;
}

double KYGFastPower(double x, int n) {	// ��ȯ���� �ŵ����� ��� �Լ�
	if(n == 0) return 1;
	else if ((n%2) == 0)	// n�� ¦���� ���
		return KYGFastPower(x * x, n / 2);
	else
		return x * KYGFastPower(x * x, (n - 1) / 2);	// n�� Ȧ���� ���
}

void main() {
	double x = 2;
	int n = 10;

	printf("�ݺ�: %.2lf, ��ȯ: %.2lf\n", KYGSlowPower(x, n), KYGFastPower(x, n));
}