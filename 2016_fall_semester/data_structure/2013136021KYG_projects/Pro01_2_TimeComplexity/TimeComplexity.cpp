#include <cstdio>
#include <ctime>
#include <windows.h>

void KYG_sumAlgorithmA ( int ); //알고리즘 A 구현 함수
void KYG_sumAlgorithmB ( int ); //알고리즘 B 구현 함수

void main()
{
	printf("\n*************** [ 2016년도 2학기 자료구조 실습과제 1 ] ***************\n");
	printf("\n               2. 시간 복잡도가 다른 두 알고리즘의 비교\n\n");

	clock_t t0, t1, t2;//알고리즘의 실행시간을 구하기 위한 시간을 저장할 변수

	for(int i = 0; i < 20; i += 1) {
		t0 = clock();//알고리즘A의 시작 시간
		KYG_sumAlgorithmA(i);
		t1 = clock();//알고리즘A의 종료 시간, 알고리즘B의 시작 시간
		KYG_sumAlgorithmB(i);
		t2 = clock();//알고리즘B의 종료 시간

		printf("A 시간 : %lf\t", (double)(t1 - t0) / CLOCKS_PER_SEC);
		printf("B 시간 : %lf\t", (double)(t2 - t1) / CLOCKS_PER_SEC);
		
		if ((t1 - t0) > (t2 - t1)) //알고리즘A의 실행시간이 B의 실행시간보다 클 경우 줄 바꿈 
			printf("\n");
		else
			printf("역전\n");//알고리즘 B의 시간이 A보다 크거나 같을 경우는 실행시간이 역전 된 경우이므로 "역전" 출력
	}
	getchar();
}

void KYG_sumAlgorithmA ( int n ) //알고리즘 A 구현 함수
{
	int sum = (n * (n + 1)) / 2;
	Sleep(2);
}

void KYG_sumAlgorithmB ( int n ) //알고리즘 B 구현 함수
{
	int sum = 0;
	for ( int i = 1; i <= n; i++ )
	{
		sum += i;
		Sleep(2);
	}
}