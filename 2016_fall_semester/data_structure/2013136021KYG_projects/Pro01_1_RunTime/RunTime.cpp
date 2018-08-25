#include <cstdio>
#include <ctime>
#include <windows.h>

void KYG_sumAlgorithmA ( int ); //�˰��� A ���� �Լ�
void KYG_sumAlgorithmB ( int ); //�˰��� B ���� �Լ�
void KYG_sumAlgorithmC ( int ); //�˰��� C ���� �Լ�

void main() {
	printf("\n*************** [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 1 ] ***************\n");
	printf("\n                  1. ���α׷��� ���� ���� �ð� ����\n\n");

	clock_t t0, t1, t2, t3;//�˰����� ����ð��� ���ϱ� ���� �ð��� ������ ����

	for(int i = 0; i < 1000; i += 5) {
		t0 = clock();//�˰���A�� ���� �ð�
		KYG_sumAlgorithmA(i);
		t1 = clock();//�˰���A�� ���� �ð�, �˰���B�� ���� �ð�
		KYG_sumAlgorithmB(i);
		t2 = clock();//�˰���B�� ���� �ð�, �˰���C�� ���� �ð�
		KYG_sumAlgorithmC(i);
		t3 = clock();//�˰���C�� ���� �ð�

		printf("A �ð� : %lf\t", (double)(t1 - t0) / CLOCKS_PER_SEC);
		printf("B �ð� : %lf\t", (double)(t2 - t1) / CLOCKS_PER_SEC);
		printf("C �ð� : %lf\n", (double)(t3 - t2) / CLOCKS_PER_SEC);
	}
	getchar();
}

void KYG_sumAlgorithmA ( int n ) { //�˰��� A ���� �Լ�
	int sum = (n * (n + 1)) / 2;
	Sleep(1);
}

void KYG_sumAlgorithmB ( int n ) { //�˰��� B ���� �Լ�
	int sum = 0;
	for ( int i = 1; i <= n; i++ ) {
		sum += i;
		Sleep(1);
	}
}

void KYG_sumAlgorithmC ( int n ) {//�˰��� C ���� �Լ�
	int sum = 0;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= i; j++ ) {
			sum += 1;
			Sleep(1);
		}
	}
}