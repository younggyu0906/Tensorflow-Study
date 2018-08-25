#include <cstdio>

int hanoiTowerCnt = 0;	// 원판을 옮기는 횟수

void Usage() {
	printf("  [메뉴] 1-하노이탑, q-종료 => ");
}
int inputN(char c = 'n'){
	int n;
	printf("   -> %c 입력 : ", c);
	scanf("%d", &n);
	return n;
}

void KYGHanoiTower(int n, char from, char tmp, char to) {
	if(n == 1) printf("    [%4d] 원판 %d을 %c에서 %c으로 옮긴다.\n", ++hanoiTowerCnt, n, from, to);
	else {
		KYGHanoiTower(n - 1, from, to, tmp);
		printf("    [%4d] 원판 %d을 %c에서 %c으로 옮긴다.\n", ++hanoiTowerCnt, n, from, to);
		KYGHanoiTower(n - 1, tmp, from, to);
	}
}

void main() {
	printf("\n*************** [ 2016년도 2학기 자료구조 실습과제 9 ] ***************\n\n");
	printf("         1. 순환 & 반복 (factori, power, fibo) 테스트 프로그램\n\n");


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
			printf("\n    hanoiTower() 호출횟수 = %d\n\n", hanoiTowerCnt);
			hanoiTowerCnt = 0;
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