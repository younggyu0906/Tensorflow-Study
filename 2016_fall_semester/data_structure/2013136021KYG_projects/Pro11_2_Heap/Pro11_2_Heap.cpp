#include "MaxHeap.h"
#include <cstdlib>

void main(){
	printf("\n*************** [ 2016년도 2학기 자료구조 실습과제 11 ] ***************\n\n");
	printf("              2. 최대 힙 테스트 프로그램(노드클래스 구현)\n\n");
	printf(" 11.2-1) 최대 힙 테스트 \n\n");
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
	
	printf(" 11.2-2) 힙 정렬 테스트 \n");
	MaxHeap	heap2;
	int data[10];

	for( int i = 0 ; i < 10 ; i++ )	data[i] = rand() % 100;
	printf("\n	정렬전 : ");
	for( int i = 0 ; i < 10 ; i++ )	printf("%4d", data[i]);
	heap2.heapSort(data, 10);
	printf("\n	정렬후 : ");
	for( int i = 0 ; i < 10 ; i++ )	printf("%4d", data[i]);
	printf("\n");

	getchar();
	getchar(); 

}