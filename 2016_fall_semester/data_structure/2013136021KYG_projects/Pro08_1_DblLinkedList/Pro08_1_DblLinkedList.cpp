#include "KYGDblLinkedList.h"				// DLinkledList 클래스 포함

void main()
{

	printf("\n************* [ 2016년도 2학기 자료구조 실습과제 8 ] *************\n\n");
	printf("            1. 링크드 리스트 테스트 프로그램(헤드포인트)\n\n");

	CKYGDblLinkedList	list;					// 새로운 리스트 객체 list를 만듦

	list.insert( 0, new CKYGNode2(1.0) );			// 리스트 맨 앞에 10 삽입
	list.insert( 0, new CKYGNode2(2.0) );			// 리스트 맨 앞에 20 삽입
	list.insert( 1, new CKYGNode2(3.0) );			// 리스트 1위치에 30 삽입
	list.insert( list.size(), new CKYGNode2(4.0) );	// 리스트 마지막에 40 삽입
	list.insert( 2, new CKYGNode2(5.0) );			// 리스트 1위치에 50 삽입
	list.display();									// 리스트내용 화면출력

	list.remove( 2 );							// 리스트 2위치의 항목 삭제
	list.remove(list.size()-1);					// 리스트 마지막 항목 삭제
	list.remove(0);								// 리스트 맨 앞 항목 삭제
	list.replace(1, new CKYGNode2(9.0));		// 리스트의 1위치 항목 값 변경
	list.display();								// 리스트내용 화면출력

	list.replace(0, new CKYGNode2(8.0));		// 리스트의 1위치 항목 값 변경
	list.display();								// 리스트내용 화면출력
	
	list.clear();								// 리스트의 모든 항목 삭제
	list.display();								// 리스트내용 화면출력

	getchar();
	getchar();
}