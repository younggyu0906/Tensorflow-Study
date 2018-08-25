#pragma once
#include "KYGBinaryNode.h"
#include "KYGCircularQueue.h"

class CKYGBinaryTree {
protected:
	CKYGBinaryNode* mRoot;
public:
	CKYGBinaryTree() : mRoot(NULL) {}
	void setRoot(CKYGBinaryNode* node)	{ mRoot = node; }
	CKYGBinaryNode* getRoot()			{ return mRoot; }
	bool isEmpty()	{ return mRoot == NULL; }

	// 이진트리의 inorder 순회 연산
	void inorder() { printf("\n   inorder : "); inorder(mRoot); }
	void inorder(CKYGBinaryNode* node) {	// 순환적인 트리의 순회 함수
		if(node != NULL) {
			if(node->getLeft() != NULL) inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if(node->getRight() != NULL) inorder(node->getRight());
		}
	}
	
	// 이진트리의 preorder 순회 연산
	void preorder()	{ printf("\n  preorder : "); preorder(mRoot); }
	void preorder( CKYGBinaryNode* node) {	// 순환적인 트리의 순회 함수
		if(node != NULL) {
			printf(" [%c] ", node->getData());
			if(node->getLeft() != NULL) preorder(node->getLeft());
			if(node->getRight() != NULL) preorder(node->getRight());
		}
	}

	// 이진트리의 postorder 순회 연산
	void postorder() { printf("\n postorder : "); postorder(mRoot); }
	void postorder(CKYGBinaryNode* node) {
		if(node != NULL) {
			if(node->getLeft() != NULL) postorder(node->getLeft());
			if(node->getRight() != NULL) postorder(node->getRight());
			printf(" [%c] ", node->getData());
		}
	}

	// 이진트리의 레벨 순회 연산
	void levelorder() {
		printf("\nlevelorder : ");
		if(!isEmpty()) {
			CKYGCircularQueue q;
			q.enqueue(mRoot);
			while (!q.isEmpty()) {
				CKYGBinaryNode* n = q.dequeue();
				if(n != NULL) {
					printf(" [%c] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}
	
	// 트리의 노드 개수를 구하는 함수
	int getCount() { return isEmpty() ? 0 : getCount(mRoot); }
	int getCount(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	// 트리의 단말노드 개수를 구하는 함수
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(mRoot); }
	int getLeafCount(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		if(node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	// 트리의 높이를 구하는 멤버 함수
	int getHeight() { return isEmpty() ? 0 : getHeight(mRoot); }
	int getHeight(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
	}

	// 수식 트리 계산 함수
	int evaluate() { return evaluate(mRoot); }
	// 순환 호출에 의해 node를 루트로 하는 수식 트리의 계산 함수
	int evaluate(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		if(node->isLeaf()) return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch(node->getData()) {
				case '+' : return op1 + op2;
				case '-' : return op1 - op2;
				case '*' : return op1 * op2;
				case '/' : return op1 / op2;
			}
			return 0;
		}
	}

	// 디렉터리 용량 계산 함수
	int calcSize() { return calcSize(mRoot); }
	// 순환 호출에 의해 node를 루트로 하는 트리의 전체 용량 계산 함수
	int calcSize(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}
};