#include "KYGCalculator.h"

void main()
{

	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 4 ] *************\n\n");
	printf("                       1. ��ȣ �ݱ� ���α׷�\n\n");

	// �߰� ���� ��ҷ� ���� ����, ���� : ���� ����
	FILE *fp = fopen("postfix.txt", "w");
	if( fp == NULL ) {
		printf("Uable to save postfix.txt\n");
		return;
	}

	printf("  ���� �Է� (Infix) = ");
	infix2Postfix( stdin, fp);	// Infix�� �� ������ Postfix �������� ��ȯ�ϴ� �Լ�, �Է����� ������ �����͸� ����

	fclose (fp);

	
	fp = fopen("postfix.txt", "r");	// ���� : �� ����
	if( fp == NULL ) {
		printf("Uable to read postfix.txt\n");
		return;
	}

	double res = calcPostfixExpr( fp ); // Postfix ������ ����ϴ� �Լ�, �Է����� ������ �����͸� ����
	fclose (fp);
	printf("  ��� ��� => %f\n\n", res);	

	getchar();
	getchar();
}