#include "KYGCircularQueue.h"

void main(){

	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 5 ] *************\n\n");
	printf("                       1. ť �׽�Ʈ ���α׷�\n\n");

	KYGCircularQueue q;
	
	printf("	ť ���Կ��� 8�� ����\n\n");
	for( int i=0 ; i<8 ; i++){
		q.enqueue(i);
	}
	q.display();
	
	printf("	ť �������� 3�� ����\n\n");
	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.display();

	printf("	ť ���Կ��� 2�� ����(���ο : 11, 12)\n\n");
	q.enqueue(11);
	q.enqueue(12);

	q.display();


	getchar();
	getchar();
}