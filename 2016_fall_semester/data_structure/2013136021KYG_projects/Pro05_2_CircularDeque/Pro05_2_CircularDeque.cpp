#include "KYGCircularDeque.h"

void main(){

	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 5 ] *************\n\n");
	printf("                       2. �� �׽�Ʈ ���α׷�\n\n");

	KYGCircularDeque q;
	
	
	printf(" CDeQueue ���ܻ��� 8�� ���� => ");
	for( int i=21 ; i<29 ; i++){
		q.addFront(i);
	}
	q.display();
	
	printf(" CDeQueue ���ܻ��� 3�� ���� => ");
	q.deleteFront();
	q.deleteFront();
	q.deleteFront();
	
	q.display();

	printf(" CDeQueue �Ĵܻ��� 3�� ���� => ");
	q.addRear(29);
	q.addRear(30);
	q.addRear(31);
	
	q.display();

	printf(" CDeQueue �Ĵܻ��� 2�� ���� => ");
	q.deleteRear();
	q.deleteRear();

	q.display();

	getchar();
	getchar();

}