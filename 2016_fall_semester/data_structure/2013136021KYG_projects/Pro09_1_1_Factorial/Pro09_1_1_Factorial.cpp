#include <cstdio>
// ��ȯ���� ���丮�� ��� �Լ�
int KYGFactorialRecur(int n) {
	printf("factorial(%d)\n", n);
	if(n == 1)
		return 1;
	else
		return (n * KYGFactorialRecur(n - 1));
}
// �ݺ����� ���丮�� ��� �Լ�
int KYGFactorialIter(int n) {
	int result = 1;
	for(int k = n; k > 0; k--)
		result = result * k;
	return result;
}

void main() {
	int n = 10;
	printf("%d, %d", KYGFactorialRecur(n), KYGFactorialIter(n));
}