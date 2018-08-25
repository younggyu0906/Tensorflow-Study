#include <cstdio>

double KYGSlowPower(double x, int n) {	// 반복적인 거듭제곱 계산 함수
	double result = 1.0;
	for(int i = 0; i < n; i++)
		result = result * x;
	return result;
}

double KYGFastPower(double x, int n) {	// 순환적인 거듭제곱 계산 함수
	if(n == 0) return 1;
	else if ((n%2) == 0)	// n이 짝수인 경우
		return KYGFastPower(x * x, n / 2);
	else
		return x * KYGFastPower(x * x, (n - 1) / 2);	// n이 홀수인 경우
}

void main() {
	double x = 2;
	int n = 10;

	printf("반복: %.2lf, 순환: %.2lf\n", KYGSlowPower(x, n), KYGFastPower(x, n));
}