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
	// 현재 노드를 루트로 갖는 서브트리에서의 중위 순회
	void inorder() {
		if(mLeft != NULL) mLeft->inorder();			// 왼쪽 서브 트리 처리
		printf(" [%c] ", mData);					// 현재 노드 처리
		if(mRight != NULL) mRight->inorder();		// 오른쪽 서브트리 순회
	}
	// 현재 노드를 루트로 갖는 서브트리에서의 전위 순회
	void preorder() {
		printf(" [%c] ", mData);					// 현재 노드 처리
		if(mLeft != NULL) mLeft->preorder();			// 왼쪽서브트리 처리
		if(mRight != NULL) mRight->preorder();		// 오른쪽 서브트리 순회
	}
	// 현재 노드를 루트로 갖는 서브트리에서의 후위 순회
	void postorder() {
		if(mLeft != NULL) mLeft->postorder();		// 왼쪽 서브 트리 처리
		if(mRight != NULL) mRight->postorder();		// 오른쪽 서브트리 순회
		printf(" [%c] ", mData);					// 현재 노드 처리
	}
};