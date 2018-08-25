#include <stdio.h>

int factoriIterCnt = 0;
int factoriRecurCnt = 0;
int powerIterCnt = 0;
int powerRecurCnt = 0;
int fibIterCnt = 0;
int fibRecurCnt = 0;

int KYGFactorialIter( int n );				// 반복 팩토리알
int KYGFactorialRecur( int n );				// 순환 팩토리알
int KYGPowerIter( int x, int n );			// 반복 거듭제곱
int KYGPowerRecur( int x, int n );			// 순환 거듭제곱
int KYGFiboIter(int n);						// 반복 피보나치
int KYGFiboRecur(int n);					// 순환 피보나치

void Usage() {
	printf("  [메뉴] 1-팩토리알, 2-거듭제곱, 3-피보나치, q-종료 => ");
}
int inputN(char c = 'n'){
	int n;
	printf("   -> %c 입력 : ", c);
	scanf("%d", &n);
	return n;
}

void main()
{
	printf("\n*************** [ 2016년도 2학기 자료구조 실습과제 9 ] ***************\n\n");
	printf("         1. 순환 & 반복 (factori, power, fibo) 테스트 프로그램\n\n");


	char command; 
	int n, x;
	do{
		Usage();
		command = getchar();
		switch( command ) {
		case '1' : 
			printf("\n  [Factorial Test]\n");
			n = inputN('n');
			printf("\n    factorilIter()  = %d\n    factorilRecur() = %d\n", KYGFactorialIter(n), KYGFactorialRecur(n));
			printf("\n    factorilIter() 계산횟수 = %d,	factorilRecur() 호출횟수 = %d\n\n", factoriIterCnt, factoriRecurCnt);
			factoriIterCnt = 0;
			factoriRecurCnt = 0;
			break;
		case '2' : 
			printf("\n  [Power Test]\n");
			x = inputN('x');
			n = inputN('n');
			printf("\n    powerIter()  = %d\n    powerRecur() = %d\n", KYGPowerIter(x, n), KYGPowerRecur(x, n));
			printf("\n    powerIter() 계산횟수 = %d,	powerRecur() 호출횟수 = %d\n\n", powerIterCnt, powerRecurCnt);
			powerIterCnt = 0;
			powerRecurCnt = 0;
			break;
		case '3' : 
			printf("\n  [Fibonacci Test]\n");
			n = inputN('n');	
			printf("\n    fibIter()  = %d\n    fibRecur() = %d\n", KYGFiboIter(n), KYGFiboRecur(n));
			printf("\n    fibIter() 계산횟수 = %d,	fibRecur() 호출횟수 = %d\n\n", fibIterCnt, fibRecurCnt);
			fibIterCnt = 0;
			fibRecurCnt = 0;
			break;
		case 'q' : 
			printf("\n  [프로그램을 종료합니다!!]\n");
			break;
		}
		fflush(stdin);
	} while (command != 'q');

	getchar();
	getchar();
}
// 반복적인 팩토리얼 계산 함수
int KYGFactorialIter(int n) {
	int result = 1;
	for(int k = n; k > 0; k--) {
		result = result * k;
		factoriIterCnt++;
	}
	return result;
}
// 순환적인 팩토리얼 계산 함수
int KYGFactorialRecur(int n) {
	factoriRecurCnt++;
	if(n == 1)
		return 1;
	else
		return (n * KYGFactorialRecur(n - 1));
}
// 반복적인 거듭제곱 계산 함수
int KYGPowerIter(int x, int n) {
	int result = 1.0;
	for(int i = 0; i < n; i++) {
		result = result * x;
		powerIterCnt++;
	}
	return result;
}
// 순환적인 거듭제곱 계산 함수
int KYGPowerRecur(int x, int n) {
	powerRecurCnt++;
	if(n == 0) return 1;
	else if ((n%2) == 0)	// n이 짝수인 경우
		return KYGPowerRecur(x * x, n / 2);
	else
		return x * KYGPowerRecur(x * x, (n - 1) / 2);	// n이 홀수인 경우
}
// 반복적인 피보나치 함수
int KYGFiboIter(int n) {
	if(n < 2) return n;
	else {
		int tmp, current = 1, last = 0;
		for(int i = 2; i <= n; i++) {
			fibIterCnt++;
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}
// 순환적인 피보나치 함수
int KYGFiboRecur(int n) {
	fibRecurCnt++;
	if(n == 0) return 0;
	if(n == 1) return 1;
	return (KYGFiboRecur(n - 1) + KYGFiboRecur(n - 2));
}
