// KYGCircularQueue.h : 노드의 포인터를 저장하는 큐 클래스
#pragma once
#include "KYGBinaryNode.h"
#include <stdlib.h>

inline void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE	100

class CKYGCircularQueue {
	int mFront;	// 첫 번째 요소 앞의 위치
	int mRear;	// 마지막 요소 위치
	CKYGBinaryNode* mData[MAX_QUEUE_SIZE];	// 요소의 배열
public:
	CKYGCircularQueue() { mFront = mRear = 0; }
	bool isEmpty()		{ return mFront == mRear; }
	bool isFull()		{ return (mRear + 1) % MAX_QUEUE_SIZE == mFront; }
	void enqueue(CKYGBinaryNode* n) {
		if(isFull()) error("  Error : 큐가 포화상태입니다\n");
		else {
			mRear = (mRear + 1) % MAX_QUEUE_SIZE;
			mData[mRear] = n;
		}
	}
	CKYGBinaryNode* dequeue() {
		if(isEmpty()) error("  Error : 큐가 공백상태입니다\n");
		else {
			mFront = (mFront + 1) % MAX_QUEUE_SIZE;
			return mData[mFront];
		}
	}
};