#include "KYGPolynomial.h"

void main()
{

	printf("\n************* [ 2016년도 2학기 자료구조 실습과제 2 ] *************\n\n");
	printf("                         1. 다항식 계산\n\n");

	KYGPolynomial a, b, c, d;
	a.read("A"); // 첫 번째 다항식을 입력 받음
	b.read("B"); // 두 번째 다항식을 입력 받음

	printf("\n******************************************************************\n\n");

	a.display("    display(A) = ");
	b.display("    display(B) = ");

	a.display2("   display2(A) = ");
	b.display2("   display2(B) = ");

	c.sub (a, b); // 두 다항식의 차를 계산
	c.display2("      A - B  = ");
	c.trim();
	c.display2(" Trim(A - B) = ");

	d.mult (a, b); // 두 다항식의 곱을 계산
	d.display2("      A * B  = ");
	d.trim();
	d.display2(" Trim(A * B) = ");
	 
	getchar();
	getchar();
}