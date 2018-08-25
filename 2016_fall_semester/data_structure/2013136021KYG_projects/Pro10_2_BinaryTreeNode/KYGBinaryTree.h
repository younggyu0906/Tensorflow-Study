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

	// ����Ʈ���� ���� ��ȸ ����
	void inorder() {
		printf("\n   inorder : ");
		if(!isEmpty()) mRoot->inorder();		// ������ �ƴ� ���� ó��
	}
	
	// ����Ʈ���� ���� ��ȸ ����
	void preorder()	{
		printf("\n  preorder : ");
		if(!isEmpty()) mRoot->preorder();
	}

	// ����Ʈ���� ���� ��ȸ ����
	void postorder() {
		printf("\n postorder : ");
		if(!isEmpty()) mRoot->postorder();
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