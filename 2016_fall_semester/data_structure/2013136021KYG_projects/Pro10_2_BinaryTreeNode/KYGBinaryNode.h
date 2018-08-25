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
	// ���� ��带 ��Ʈ�� ���� ����Ʈ�������� ���� ��ȸ
	void inorder() {
		if(mLeft != NULL) mLeft->inorder();			// ���� ���� Ʈ�� ó��
		printf(" [%c] ", mData);					// ���� ��� ó��
		if(mRight != NULL) mRight->inorder();		// ������ ����Ʈ�� ��ȸ
	}
	// ���� ��带 ��Ʈ�� ���� ����Ʈ�������� ���� ��ȸ
	void preorder() {
		printf(" [%c] ", mData);					// ���� ��� ó��
		if(mLeft != NULL) mLeft->preorder();			// ���ʼ���Ʈ�� ó��
		if(mRight != NULL) mRight->preorder();		// ������ ����Ʈ�� ��ȸ
	}
	// ���� ��带 ��Ʈ�� ���� ����Ʈ�������� ���� ��ȸ
	void postorder() {
		if(mLeft != NULL) mLeft->postorder();		// ���� ���� Ʈ�� ó��
		if(mRight != NULL) mRight->postorder();		// ������ ����Ʈ�� ��ȸ
		printf(" [%c] ", mData);					// ���� ��� ó��
	}
};