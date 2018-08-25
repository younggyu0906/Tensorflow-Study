#include "ArrayStack.h"
#include "KYGBracketChecker.h"

void main() {
	printf("\n************* [ 2016년도 2학기 자료구조 실습과제 3 ] *************\n\n");
	printf("                       1. 괄호 닫기 프로그램\n\n");

	KYGBracketChecker checker;
	checker.checkMatching("ArrayStack.h");
	checker.checkMatching("KYGBracketChecker.h");
	checker.checkMatching("Pro03_1_ChechMatching.cpp");

	printf("********************* [ 괄호 닫기 문제 해결 ] ********************\n\n");
	checker.checkMatching2("KYGBracketChecker.h");
	checker.checkMatching2("TestText.txt");

	getchar();
	getchar();
}