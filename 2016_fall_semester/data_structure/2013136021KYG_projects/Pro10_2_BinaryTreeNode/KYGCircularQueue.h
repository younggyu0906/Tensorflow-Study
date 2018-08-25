// KYGCircularQueue.h : ����� �����͸� �����ϴ� ť Ŭ����
#pragma once
#include "KYGBinaryNode.h"
#include <stdlib.h>

inline void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE	100

class CKYGCircularQueue {
	int front;	// ù ��° ��� ���� ��ġ
	int rear;	// ������ ��� ��ġ
	CKYGBinaryNode* data[MAX_QUEUE_SIZE];	// ����� �迭
public:
	CKYGCircularQueue() { front = rear = 0; }
	bool isEmpty()		{ return front == rear; }
	bool isFull()		{ return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(CKYGBinaryNode* n) {
		if(isFull()) error("  Error : ť�� ��ȭ�����Դϴ�\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	CKYGBinaryNode* dequeue() {
		if(isEmpty()) error("  Error : ť�� ��������Դϴ�\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};