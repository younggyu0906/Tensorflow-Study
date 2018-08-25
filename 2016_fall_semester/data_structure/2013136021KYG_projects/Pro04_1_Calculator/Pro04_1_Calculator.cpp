#include "KYGCalculator.h"

void main()
{

	printf("\n************* [ 2016년도 2학기 자료구조 실습과제 4 ] *************\n\n");
	printf("                       1. 괄호 닫기 프로그램\n\n");

	// 중간 저장 장소로 사용될 파일, 파일 : 쓰기 형식
	FILE *fp = fopen("postfix.txt", "w");
	if( fp == NULL ) {
		printf("Uable to save postfix.txt\n");
		return;
	}

	printf("  수식 입력 (Infix) = ");
	infix2Postfix( stdin, fp);	// Infix로 된 수식을 Postfix 수식으로 변환하는 함수, 입력으로 파일의 포인터를 받음

	fclose (fp);

	
	fp = fopen("postfix.txt", "r");	// 파일 : 읽 형식
	if( fp == NULL ) {
		printf("Uable to read postfix.txt\n");
		return;
	}

	double res = calcPostfixExpr( fp ); // Postfix 수식을 계산하는 함수, 입력으로 파일의 포인터를 받음
	fclose (fp);
	printf("  계산 결과 => %f\n\n", res);	

	getchar();
	getchar();
}