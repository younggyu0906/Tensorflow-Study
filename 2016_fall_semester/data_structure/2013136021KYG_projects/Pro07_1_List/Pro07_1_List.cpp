// ���ϸ� : Pro07_1_List.cpp : �ܼ� ���� ����Ʈ Ŭ���� �׽�Ʈ ���α׷�
#include "KYGLinkedList.h"

void main() {

	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 7 ] *************\n\n");
	printf("            1. ��ũ�� ����Ʈ �׽�Ʈ ���α׷�(�����)\n\n");

	KYGLinkedList list;
	list.mKYGInsert(0, new KYGNode(1.0));
	list.mKYGInsert(0, new KYGNode(2.0));
	list.mKYGInsert2(1, new KYGNode(3.0));
	list.mKYGInsert2(list.mKYGSize(), new KYGNode(4.0));
	list.mKYGInsert2(2, new KYGNode(5.0));
	list.mKYGDisplay();

	list.mKYGRemove(2);
	list.mKYGRemove2(list.mKYGSize() - 1);
	list.mKYGRemove2(0);
	list.mKYGDisplay();
	
	list.mKYGReplace(1, new KYGNode(9.0));
	list.mKYGDisplay();

	list.mKYGClear();
	list.mKYGDisplay();
	
	getchar();
	getchar();
}