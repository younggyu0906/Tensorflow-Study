#include <cstdio>
#include <ctime>
#include <windows.h>

void KYG_sumAlgorithmA ( int ); //�˰��� A ���� �Լ�
void KYG_sumAlgorithmB ( int ); //�˰��� B ���� �Լ�

void main()
{
	printf("\n*************** [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 1 ] ***************\n");
	printf("\n               2. �ð� ���⵵�� �ٸ� �� �˰����� ��\n\n");

	clock_t t0, t1, t2;//�˰����� ����ð��� ���ϱ� ���� �ð��� ������ ����

	for(int i = 0; i < 20; i += 1) {
		t0 = clock();//�˰���A�� ���� �ð�
		KYG_sumAlgorithmA(i);
		t1 = clock();//�˰���A�� ���� �ð�, �˰���B�� ���� �ð�
		KYG_sumAlgorithmB(i);
		t2 = clock();//�˰���B�� ���� �ð�

		printf("A �ð� : %lf\t", (double)(t1 - t0) / CLOCKS_PER_SEC);
		printf("B �ð� : %lf\t", (double)(t2 - t1) / CLOCKS_PER_SEC);
		
		if ((t1 - t0) > (t2 - t1)) //�˰���A�� ����ð��� B�� ����ð����� Ŭ ��� �� �ٲ� 
			printf("\n");
		else
			printf("����\n");//�˰��� B�� �ð��� A���� ũ�ų� ���� ���� ����ð��� ���� �� ����̹Ƿ� "����" ���
	}
	getchar();
}

void KYG_sumAlgorithmA ( int n ) //�˰��� A ���� �Լ�
{
	int sum = (n * (n + 1)) / 2;
	Sleep(2);
}

void KYG_sumAlgorithmB ( int n ) //�˰��� B ���� �Լ�
{
	int sum = 0;
	for ( int i = 1; i <= n; i++ )
	{
		sum += i;
		Sleep(2);
	}
}