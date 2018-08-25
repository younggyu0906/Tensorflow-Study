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

	// ����Ʈ���� inorder ��ȸ ����
	void inorder() { printf("\n   inorder : "); inorder(mRoot); }
	void inorder(CKYGBinaryNode* node) {	// ��ȯ���� Ʈ���� ��ȸ �Լ�
		if(node != NULL) {
			if(node->getLeft() != NULL) inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if(node->getRight() != NULL) inorder(node->getRight());
		}
	}
	
	// ����Ʈ���� preorder ��ȸ ����
	void preorder()	{ printf("\n  preorder : "); preorder(mRoot); }
	void preorder( CKYGBinaryNode* node) {	// ��ȯ���� Ʈ���� ��ȸ �Լ�
		if(node != NULL) {
			printf(" [%c] ", node->getData());
			if(node->getLeft() != NULL) preorder(node->getLeft());
			if(node->getRight() != NULL) preorder(node->getRight());
		}
	}

	// ����Ʈ���� postorder ��ȸ ����
	void postorder() { printf("\n postorder : "); postorder(mRoot); }
	void postorder(CKYGBinaryNode* node) {
		if(node != NULL) {
			if(node->getLeft() != NULL) postorder(node->getLeft());
			if(node->getRight() != NULL) postorder(node->getRight());
			printf(" [%c] ", node->getData());
		}
	}

	// ����Ʈ���� ���� ��ȸ ����
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
	
	// Ʈ���� ��� ������ ���ϴ� �Լ�
	int getCount() { return isEmpty() ? 0 : getCount(mRoot); }
	int getCount(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	// Ʈ���� �ܸ���� ������ ���ϴ� �Լ�
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(mRoot); }
	int getLeafCount(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		if(node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	// Ʈ���� ���̸� ���ϴ� ��� �Լ�
	int getHeight() { return isEmpty() ? 0 : getHeight(mRoot); }
	int getHeight(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
	}

	// ���� Ʈ�� ��� �Լ�
	int evaluate() { return evaluate(mRoot); }
	// ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ���� Ʈ���� ��� �Լ�
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

	// ���͸� �뷮 ��� �Լ�
	int calcSize() { return calcSize(mRoot); }
	// ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� Ʈ���� ��ü �뷮 ��� �Լ�
	int calcSize(CKYGBinaryNode* node) {
		if(node == NULL) return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}
};