// KYGMaxHeap.h : 배열을 이용한 최대 힙 클래스
#pragma once
#include "KYGHeapNode.h"
#define MAX_ELEMENT 200

class CKYGMaxHeap {
	CKYGHeapNode mNode[MAX_ELEMENT];	// 요소의 배열
	int mSize;							// 힙의 현재 요소 개수
public:
	CKYGMaxHeap() : mSize(0) {}
	bool isEmpty()	{ return mSize == 0; }
	bool isFull()	{ return mSize == MAX_ELEMENT - 1; }

	CKYGHeapNode& getParent(int i)	{ return mNode[i / 2]; }
	CKYGHeapNode& getLeft(int i)	{ return mNode[i * 2]; }
	CKYGHeapNode& getRight(int i)	{ return mNode[i * 2 + 1]; }

	void insert(int key) {
	
	}
	CKYGHeapNode remove() {

	}
	CKYGHeapNode find() { return mNode[1]; }

	void display() {
		for(int i = 1, level = 1; i <= mSize; i++) {
			if(i == level) {
				printf("\n");
				level *= 2;
			}
			mNode[i].display();
		}
		printf("\n------------------------------------------------");
	}
};