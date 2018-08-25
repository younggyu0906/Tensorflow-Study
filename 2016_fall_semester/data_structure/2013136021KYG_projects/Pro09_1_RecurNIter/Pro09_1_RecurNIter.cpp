#include <stdio.h>

int factoriIterCnt = 0;
int factoriRecurCnt = 0;
int powerIterCnt = 0;
int powerRecurCnt = 0;
int fibIterCnt = 0;
int fibRecurCnt = 0;

int KYGFactorialIter( int n );				// �ݺ� ���丮��
int KYGFactorialRecur( int n );				// ��ȯ ���丮��
int KYGPowerIter( int x, int n );			// �ݺ� �ŵ�����
int KYGPowerRecur( int x, int n );			// ��ȯ �ŵ�����
int KYGFiboIter(int n);						// �ݺ� �Ǻ���ġ
int KYGFiboRecur(int n);					// ��ȯ �Ǻ���ġ

void Usage() {
	printf("  [�޴�] 1-���丮��, 2-�ŵ�����, 3-�Ǻ���ġ, q-���� => ");
}
int inputN(char c = 'n'){
	int n;
	printf("   -> %c �Է� : ", c);
	scanf("%d", &n);
	return n;
}

void main()
{
	printf("\n*************** [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 9 ] ***************\n\n");
	printf("         1. ��ȯ & �ݺ� (factori, power, fibo) �׽�Ʈ ���α׷�\n\n");


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
			printf("\n    factorilIter() ���Ƚ�� = %d,	factorilRecur() ȣ��Ƚ�� = %d\n\n", factoriIterCnt, factoriRecurCnt);
			factoriIterCnt = 0;
			factoriRecurCnt = 0;
			break;
		case '2' : 
			printf("\n  [Power Test]\n");
			x = inputN('x');
			n = inputN('n');
			printf("\n    powerIter()  = %d\n    powerRecur() = %d\n", KYGPowerIter(x, n), KYGPowerRecur(x, n));
			printf("\n    powerIter() ���Ƚ�� = %d,	powerRecur() ȣ��Ƚ�� = %d\n\n", powerIterCnt, powerRecurCnt);
			powerIterCnt = 0;
			powerRecurCnt = 0;
			break;
		case '3' : 
			printf("\n  [Fibonacci Test]\n");
			n = inputN('n');	
			printf("\n    fibIter()  = %d\n    fibRecur() = %d\n", KYGFiboIter(n), KYGFiboRecur(n));
			printf("\n    fibIter() ���Ƚ�� = %d,	fibRecur() ȣ��Ƚ�� = %d\n\n", fibIterCnt, fibRecurCnt);
			fibIterCnt = 0;
			fibRecurCnt = 0;
			break;
		case 'q' : 
			printf("\n  [���α׷��� �����մϴ�!!]\n");
			break;
		}
		fflush(stdin);
	} while (command != 'q');

	getchar();
	getchar();
}
// �ݺ����� ���丮�� ��� �Լ�
int KYGFactorialIter(int n) {
	int result = 1;
	for(int k = n; k > 0; k--) {
		result = result * k;
		factoriIterCnt++;
	}
	return result;
}
// ��ȯ���� ���丮�� ��� �Լ�
int KYGFactorialRecur(int n) {
	factoriRecurCnt++;
	if(n == 1)
		return 1;
	else
		return (n * KYGFactorialRecur(n - 1));
}
// �ݺ����� �ŵ����� ��� �Լ�
int KYGPowerIter(int x, int n) {
	int result = 1.0;
	for(int i = 0; i < n; i++) {
		result = result * x;
		powerIterCnt++;
	}
	return result;
}
// ��ȯ���� �ŵ����� ��� �Լ�
int KYGPowerRecur(int x, int n) {
	powerRecurCnt++;
	if(n == 0) return 1;
	else if ((n%2) == 0)	// n�� ¦���� ���
		return KYGPowerRecur(x * x, n / 2);
	else
		return x * KYGPowerRecur(x * x, (n - 1) / 2);	// n�� Ȧ���� ���
}
// �ݺ����� �Ǻ���ġ �Լ�
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
// ��ȯ���� �Ǻ���ġ �Լ�
int KYGFiboRecur(int n) {
	fibRecurCnt++;
	if(n == 0) return 0;
	if(n == 1) return 1;
	return (KYGFiboRecur(n - 1) + KYGFiboRecur(n - 2));
}
