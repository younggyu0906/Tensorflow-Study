#include "KYGDblLinkedList.h"				// DLinkledList Ŭ���� ����

void main()
{

	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 8 ] *************\n\n");
	printf("            1. ��ũ�� ����Ʈ �׽�Ʈ ���α׷�(�������Ʈ)\n\n");

	CKYGDblLinkedList	list;					// ���ο� ����Ʈ ��ü list�� ����

	list.insert( 0, new CKYGNode2(1.0) );			// ����Ʈ �� �տ� 10 ����
	list.insert( 0, new CKYGNode2(2.0) );			// ����Ʈ �� �տ� 20 ����
	list.insert( 1, new CKYGNode2(3.0) );			// ����Ʈ 1��ġ�� 30 ����
	list.insert( list.size(), new CKYGNode2(4.0) );	// ����Ʈ �������� 40 ����
	list.insert( 2, new CKYGNode2(5.0) );			// ����Ʈ 1��ġ�� 50 ����
	list.display();									// ����Ʈ���� ȭ�����

	list.remove( 2 );							// ����Ʈ 2��ġ�� �׸� ����
	list.remove(list.size()-1);					// ����Ʈ ������ �׸� ����
	list.remove(0);								// ����Ʈ �� �� �׸� ����
	list.replace(1, new CKYGNode2(9.0));		// ����Ʈ�� 1��ġ �׸� �� ����
	list.display();								// ����Ʈ���� ȭ�����

	list.replace(0, new CKYGNode2(8.0));		// ����Ʈ�� 1��ġ �׸� �� ����
	list.display();								// ����Ʈ���� ȭ�����
	
	list.clear();								// ����Ʈ�� ��� �׸� ����
	list.display();								// ����Ʈ���� ȭ�����

	getchar();
	getchar();
}