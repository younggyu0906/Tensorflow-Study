#pragma once
#include "KYGBinaryNode.h"
#include "KYGCircularQueue.h"

class CKYGBinaryTree {
	CKYGBinaryNode* mRoot;
public:
	CKYGBinaryTree() : mRoot(NULL) {}
	void setRoot(CKYGBinaryNode* node)	{ mRoot = node; }
	CKYGBinaryNode* getRoot()			{ return mRoot; }
	bool isEmpty()	{ return mRoot == NULL; }

	// 이진트리의 중위 순회 연산
	void inorder() {
		printf("\n   inorder : ");
		if(!isEmpty()) mRoot->inorder();		// 공백이 아닐 때만 처리
	}
	
	// 이진트리의 전위 순회 연산
	void preorder()	{
		printf("\n  preorder : ");
		if(!isEmpty()) mRoot->preorder();
	}

	// 이진트리의 후위 순회 연산
	void postorder() {
		printf("\n postorder : ");
		if(!isEmpty()) mRoot->postorder();
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