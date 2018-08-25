// KYGCircularQueue.h : �迭�� �̿��� ���� ť Ŭ����
#pragma once
#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 100

inline void error(char* str) {
	printf("%s\n", str);
	exit(1);
}

class KYGCircularQueue {
protected :
	int front;					// ù ��° ��� ���� ��ġ
	int rear;					// ������ ��� ��ġ
	int data[MAX_QUEUE_SIZE];	// ����� �迭
public:
	KYGCircularQueue() { front = rear = 0; }
	bool isEmpty()	{ return front == rear; }
	bool isFull()	{ return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(int val) {		// ť�� ����
		if(isFull())
			error(" error : ť�� ��ȭ�����Դϴ�.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	int dequeue() {				// ù �׸��� ť���� ���� ��ȯ
		if(isEmpty())
			error(" error : ť�� ��������Դϴ�.\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek() {				// ù �׸��� ť���� ���� �ʰ� ��ȯ
		if(isEmpty())
			error(" error : ť�� ��������Դϴ�.\n");
		else
			return data[front];
	}
	void display() {			// ť�� ��� ������ ������� ���
		printf("ť ���� : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for(int i = front + 1 ; i <= maxi; i++)
			printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};