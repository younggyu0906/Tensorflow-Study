#pragma once
#include "KYGCircleQueue.h"

class KYGCircularDeque : public KYGCircleQueue {
public:
	KYGCircularDeque() {}
	void addRear(int val) { enqueue(val); }
	int deleteFront() { return dequeue(); }
	int getFront() { return peek(); }
	void addFront(int val) {
		if(isFull())
			error(" error : ���� ��ȭ�����Դϴ�.\n");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	int deleteRear() {
		if(isEmpty())
			error(" error : ���� ��������Դϴ�.\n");
		else {
			int ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}
	int getRear() {
		if(isEmpty())
			error(" error : ���� ��������Դϴ�.\n");
		else return data[rear];
	}
	void display() {
		printf("�� ���� : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for(int i = front + 1 ; i <= maxi; i++)
			printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};

