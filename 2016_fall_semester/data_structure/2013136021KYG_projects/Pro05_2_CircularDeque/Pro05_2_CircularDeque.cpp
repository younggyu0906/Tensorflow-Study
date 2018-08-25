#include "KYGCircularDeque.h"

void main(){

	printf("\n************* [ 2016년도 2학기 자료구조 실습과제 5 ] *************\n\n");
	printf("                       2. 덱 테스트 프로그램\n\n");

	KYGCircularDeque q;
	
	
	printf(" CDeQueue 전단삽입 8번 실행 => ");
	for( int i=21 ; i<29 ; i++){
		q.addFront(i);
	}
	q.display();
	
	printf(" CDeQueue 전단삭제 3번 실행 => ");
	q.deleteFront();
	q.deleteFront();
	q.deleteFront();
	
	q.display();

	printf(" CDeQueue 후단삽입 3번 실행 => ");
	q.addRear(29);
	q.addRear(30);
	q.addRear(31);
	
	q.display();

	printf(" CDeQueue 후단삭제 2번 실행 => ");
	q.deleteRear();
	q.deleteRear();

	q.display();

	getchar();
	getchar();

}