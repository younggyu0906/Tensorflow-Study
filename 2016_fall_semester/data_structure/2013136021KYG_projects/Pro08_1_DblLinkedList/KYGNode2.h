#pragma once
#include <cstdio>

class CKYGNode2 {
	CKYGNode2* mPrev;	// ���� ��带 ����Ű�� ������ ����
	CKYGNode2* mNext;	// �ļ� ��带 ����Ű�� ������ ����
	double mData;		// ������ �ʵ�
public:
	CKYGNode2(double val = 0) : mData(val), mPrev(NULL), mNext(NULL) { }
	CKYGNode2* getPrev()		{ return mPrev; }
	CKYGNode2* getNext()		{ return mNext; }
	void setPrev(CKYGNode2* p)	{ mPrev = p; }
	void setNext(CKYGNode2* n)	{ mNext = n; }
	void display()				{ printf(" <%1.1lf>", mData); }
	bool hasData(double val)	{ return mData == val; }

	// �ڽ��� ������ ���ο� ��� n�� �����ϴ� �Լ�
	void insertNext( CKYGNode2* n ) {
		if(n != NULL) {
			n->mPrev = this;
			n->mNext = mNext;
			if(mNext != NULL) mNext->mPrev = n;
			mNext = n;
		}
	}
	// ���� ��带 ���� ����Ʈ���� �����ϴ� �Լ�
	CKYGNode2* remove() {
		if(mPrev != NULL) mPrev->mNext = mNext;
		if(mNext != NULL) mNext->mPrev = mPrev;
		return this;
	}
};