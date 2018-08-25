#pragma once
#include <cstdio>

class CKYGNode2 {
	CKYGNode2* mPrev;	// 선행 노드를 가리키는 포인터 변수
	CKYGNode2* mNext;	// 후속 노드를 가리키는 포인터 변수
	double mData;		// 데이터 필드
public:
	CKYGNode2(double val = 0) : mData(val), mPrev(NULL), mNext(NULL) { }
	CKYGNode2* getPrev()		{ return mPrev; }
	CKYGNode2* getNext()		{ return mNext; }
	void setPrev(CKYGNode2* p)	{ mPrev = p; }
	void setNext(CKYGNode2* n)	{ mNext = n; }
	void display()				{ printf(" <%1.1lf>", mData); }
	bool hasData(double val)	{ return mData == val; }

	// 자신의 다음에 새로운 노드 n을 삽입하는 함수
	void insertNext( CKYGNode2* n ) {
		if(n != NULL) {
			n->mPrev = this;
			n->mNext = mNext;
			if(mNext != NULL) mNext->mPrev = n;
			mNext = n;
		}
	}
	// 현재 노드를 연결 리스트에서 제거하는 함수
	CKYGNode2* remove() {
		if(mPrev != NULL) mPrev->mNext = mNext;
		if(mNext != NULL) mNext->mPrev = mPrev;
		return this;
	}
};