#include "MaxHeap.h"
#include <cstdlib>

void main(){
	printf("\n*************** [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 11 ] ***************\n\n");
	printf("              2. �ִ� �� �׽�Ʈ ���α׷�(���Ŭ���� ����)\n\n");
	printf(" 11.2-1) �ִ� �� �׽�Ʈ \n\n");
	MaxHeap	heap;

	heap.insert(10);
	heap.insert( 5);
	heap.insert(30);
	heap.insert( 8);
	heap.insert( 9);
	heap.insert( 3);
	heap.insert( 7);
	heap.display();
	
	heap.remove();
	heap.display();
	heap.remove();
	heap.display();

	printf("\n\n\n");
	
	printf(" 11.2-2) �� ���� �׽�Ʈ \n");
	MaxHeap	heap2;
	int data[10];

	for( int i = 0 ; i < 10 ; i++ )	data[i] = rand() % 100;
	printf("\n	������ : ");
	for( int i = 0 ; i < 10 ; i++ )	printf("%4d", data[i]);
	heap2.heapSort(data, 10);
	printf("\n	������ : ");
	for( int i = 0 ; i < 10 ; i++ )	printf("%4d", data[i]);
	printf("\n");

	getchar();
	getchar(); 

}