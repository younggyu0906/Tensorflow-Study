#include "KYGPolynomial.h"

void main()
{

	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 2 ] *************\n\n");
	printf("                         1. ���׽� ���\n\n");

	KYGPolynomial a, b, c, d;
	a.read("A"); // ù ��° ���׽��� �Է� ����
	b.read("B"); // �� ��° ���׽��� �Է� ����

	printf("\n******************************************************************\n\n");

	a.display("    display(A) = ");
	b.display("    display(B) = ");

	a.display2("   display2(A) = ");
	b.display2("   display2(B) = ");

	c.sub (a, b); // �� ���׽��� ���� ���
	c.display2("      A - B  = ");
	c.trim();
	c.display2(" Trim(A - B) = ");

	d.mult (a, b); // �� ���׽��� ���� ���
	d.display2("      A * B  = ");
	d.trim();
	d.display2(" Trim(A * B) = ");
	 
	getchar();
	getchar();
}