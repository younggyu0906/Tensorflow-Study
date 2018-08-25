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
	int mFront;	// ù ��° ��� ���� ��ġ
	int mRear;	// ������ ��� ��ġ
	CKYGBinaryNode* mData[MAX_QUEUE_SIZE];	// ����� �迭
public:
	CKYGCircularQueue() { mFront = mRear = 0; }
	bool isEmpty()		{ return mFront == mRear; }
	bool isFull()		{ return (mRear + 1) % MAX_QUEUE_SIZE == mFront; }
	void enqueue(CKYGBinaryNode* n) {
		if(isFull()) error("  Error : ť�� ��ȭ�����Դϴ�\n");
		else {
			mRear = (mRear + 1) % MAX_QUEUE_SIZE;
			mData[mRear] = n;
		}
	}
	CKYGBinaryNode* dequeue() {
		if(isEmpty()) error("  Error : ť�� ��������Դϴ�\n");
		else {
			mFront = (mFront + 1) % MAX_QUEUE_SIZE;
			return mData[mFront];
		}
	}
};