// 파일명 : Pro07_1_List.cpp : 단순 연결 리스트 클래스 테스트 프로그램
#include "KYGLinkedList.h"

void main() {

	printf("\n************* [ 2016년도 2학기 자료구조 실습과제 7 ] *************\n\n");
	printf("            1. 링크드 리스트 테스트 프로그램(헤드노드)\n\n");

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