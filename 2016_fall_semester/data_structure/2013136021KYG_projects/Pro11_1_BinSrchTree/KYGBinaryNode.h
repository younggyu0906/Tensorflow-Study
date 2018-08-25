// KYGBinaryNode.h : 이진트리를 위한 노드 클래스
#pragma once
#include <cstdio>

class CKYGBinaryNode {
protected:
	int mData;				// 트리에 저장 할 데이터
	CKYGBinaryNode* mLeft;	// 왼쪽 자식 노드의 포인터
	CKYGBinaryNode* mRight;	// 오른쪽 자식 노드의 포인터
public:
	CKYGBinaryNode(int val = 0, CKYGBinaryNode* l = NULL, CKYGBinaryNode* r = NULL)
		: mData(val), mLeft(l), mRight(r) { }
	void setData	(int val)			{ mData = val; }
	void setLeft	(CKYGBinaryNode *l)	{ mLeft = l; }
	void setRight	(CKYGBinaryNode *r) { mRight = r; }
	int getData()	{ return mData; }
	CKYGBinaryNode* getLeft()	{ return mLeft; }
	CKYGBinaryNode* getRight()	{ return mRight; }
	bool isLeaf()	{ return mLeft == NULL && mRight == NULL; }
};