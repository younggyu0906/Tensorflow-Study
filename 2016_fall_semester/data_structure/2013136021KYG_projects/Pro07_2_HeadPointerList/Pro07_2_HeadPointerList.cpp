// ���ϸ� : Pro07_1_List.cpp : �ܼ� ���� ����Ʈ Ŭ���� �׽�Ʈ ���α׷�
#include "KYGLinkedList.h"

void main() {

	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 7 ] *************\n\n");
	printf("            2. ��ũ�� ����Ʈ �׽�Ʈ ���α׷�(���������)\n\n");

	KYGLinkedList list;
	list.mKYGInsert(0, new KYGNode(1.0));
	list.mKYGInsert(0, new KYGNode(2.0));
	list.mKYGInsert(1, new KYGNode(3.0));
	list.mKYGInsert(list.mKYGSize(), new KYGNode(4.0));
	list.mKYGInsert(2, new KYGNode(5.0));
	list.mKYGDisplay();

	list.mKYGRemove(2);
	list.mKYGRemove(list.mKYGSize() - 1);
	list.mKYGRemove(0);
	list.mKYGDisplay();
	
	list.mKYGReplace(1, new KYGNode(9.0));
	list.mKYGDisplay();

	list.mKYGClear();
	list.mKYGDisplay();
	
	getchar();
	getchar();
}