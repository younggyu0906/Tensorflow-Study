#include "ArrayStack.h"
#include "KYGBracketChecker.h"

void main() {
	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 3 ] *************\n\n");
	printf("                       1. ��ȣ �ݱ� ���α׷�\n\n");

	KYGBracketChecker checker;
	checker.checkMatching("ArrayStack.h");
	checker.checkMatching("KYGBracketChecker.h");
	checker.checkMatching("Pro03_1_ChechMatching.cpp");

	printf("********************* [ ��ȣ �ݱ� ���� �ذ� ] ********************\n\n");
	checker.checkMatching2("KYGBracketChecker.h");
	checker.checkMatching2("TestText.txt");

	getchar();
	getchar();
}