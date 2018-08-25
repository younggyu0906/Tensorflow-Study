#include <cstdio>
#include <ctime>
#include <windows.h>

void KYG_sumAlgorithmA ( int ); //알고리즘 A 구현 함수
void KYG_sumAlgorithmB ( int ); //알고리즘 B 구현 함수
void KYG_sumAlgorithmC ( int ); //알고리즘 C 구현 함수

void main() {
	printf("\n*************** [ 2016년도 2학기 자료구조 실습과제 1 ] ***************\n");
	printf("\n                  1. 프로그램의 실제 실행 시간 측정\n\n");

	clock_t t0, t1, t2, t3;//알고리즘의 실행시간을 구하기 위한 시간을 저장할 변수

	for(int i = 0; i < 1000; i += 5) {
		t0 = clock();//알고리즘A의 시작 시간
		KYG_sumAlgorithmA(i);
		t1 = clock();//알고리즘A의 종료 시간, 알고리즘B의 시작 시간
		KYG_sumAlgorithmB(i);
		t2 = clock();//알고리즘B의 종료 시간, 알고리즘C의 시작 시간
		KYG_sumAlgorithmC(i);
		t3 = clock();//알고리즘C의 종료 시간

		printf("A 시간 : %lf\t", (double)(t1 - t0) / CLOCKS_PER_SEC);
		printf("B 시간 : %lf\t", (double)(t2 - t1) / CLOCKS_PER_SEC);
		printf("C 시간 : %lf\n", (double)(t3 - t2) / CLOCKS_PER_SEC);
	}
	getchar();
}

void KYG_sumAlgorithmA ( int n ) { //알고리즘 A 구현 함수
	int sum = (n * (n + 1)) / 2;
	Sleep(1);
}

void KYG_sumAlgorithmB ( int n ) { //알고리즘 B 구현 함수
	int sum = 0;
	for ( int i = 1; i <= n; i++ ) {
		sum += i;
		Sleep(1);
	}
}

void KYG_sumAlgorithmC ( int n ) {//알고리즘 C 구현 함수
	int sum = 0;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= i; j++ ) {
			sum += 1;
			Sleep(1);
		}
	}
}