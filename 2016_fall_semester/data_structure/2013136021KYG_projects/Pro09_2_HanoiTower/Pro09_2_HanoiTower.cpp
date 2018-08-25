#include <cstdio>

int hanoiTowerCnt = 0;	// ������ �ű�� Ƚ��

void Usage() {
	printf("  [�޴�] 1-�ϳ���ž, q-���� => ");
}
int inputN(char c = 'n'){
	int n;
	printf("   -> %c �Է� : ", c);
	scanf("%d", &n);
	return n;
}

void KYGHanoiTower(int n, char from, char tmp, char to) {
	if(n == 1) printf("    [%4d] ���� %d�� %c���� %c���� �ű��.\n", ++hanoiTowerCnt, n, from, to);
	else {
		KYGHanoiTower(n - 1, from, to, tmp);
		printf("    [%4d] ���� %d�� %c���� %c���� �ű��.\n", ++hanoiTowerCnt, n, from, to);
		KYGHanoiTower(n - 1, tmp, from, to);
	}
}

void main() {
	printf("\n*************** [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 9 ] ***************\n\n");
	printf("         1. ��ȯ & �ݺ� (factori, power, fibo) �׽�Ʈ ���α׷�\n\n");


	char command; 
	int n;
	do{
		Usage();
		command = getchar();
		switch( command ) {
		case '1' : 
			printf("\n  [Hanoi Tower Test]\n");
			n = inputN('n');
			KYGHanoiTower(n, 'A', 'B', 'C');
			printf("\n    hanoiTower() ȣ��Ƚ�� = %d\n\n", hanoiTowerCnt);
			hanoiTowerCnt = 0;
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