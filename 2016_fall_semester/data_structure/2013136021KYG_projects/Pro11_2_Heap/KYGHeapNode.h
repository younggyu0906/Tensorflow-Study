// HeapNode.h : 힙에 저장할 노드 클래스
#pragma once
#include <cstdio>

class CKYGHeapNode {
	int mKey;
public:
	CKYGHeapNode(int k = 0) : mKey(k) {}
	void setKey(int k)	{ mKey = k; }
	int getKey()		{ return mKey; }
	void display()		{ printf("%4d", mKey); }
};