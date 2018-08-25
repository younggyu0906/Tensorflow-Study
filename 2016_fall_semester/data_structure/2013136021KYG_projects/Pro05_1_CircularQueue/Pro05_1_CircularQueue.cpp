#include "KYGCircularQueue.h"

void main(){

	printf("\n************* [ 2016년도 2학기 자료구조 실습과제 5 ] *************\n\n");
	printf("                       1. 큐 테스트 프로그램\n\n");

	KYGCircularQueue q;
	
	printf("	큐 삽입연산 8번 실행\n\n");
	for( int i=0 ; i<8 ; i++){
		q.enqueue(i);
	}
	q.display();
	
	printf("	큐 삭제연산 3번 실행\n\n");
	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.display();

	printf("	큐 삽입연산 2번 실행(새로운값 : 11, 12)\n\n");
	q.enqueue(11);
	q.enqueue(12);

	q.display();


	getchar();
	getchar();
}