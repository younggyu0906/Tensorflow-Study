// KYGMaxHeap.h : �迭�� �̿��� �ִ� �� Ŭ����
#pragma once
#include "KYGHeapNode.h"
#define MAX_ELEMENT 200

class CKYGMaxHeap {
	CKYGHeapNode mNode[MAX_ELEMENT];	// ����� �迭
	int mSize;							// ���� ���� ��� ����
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