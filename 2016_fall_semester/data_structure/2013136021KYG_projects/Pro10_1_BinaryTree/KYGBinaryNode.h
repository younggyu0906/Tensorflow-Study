// KYGBinaryNode.h : ����Ʈ���� ���� ��� Ŭ����
#pragma once
#include <cstdio>

class CKYGBinaryNode {
protected:
	int mData;				// Ʈ���� ���� �� ������
	CKYGBinaryNode* mLeft;	// ���� �ڽ� ����� ������
	CKYGBinaryNode* mRight;	// ������ �ڽ� ����� ������
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