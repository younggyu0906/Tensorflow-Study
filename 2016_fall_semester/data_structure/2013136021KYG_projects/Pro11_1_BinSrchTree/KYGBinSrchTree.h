// KYGBinSrchTree.h : ���� Ž�� Ʈ�� Ŭ����
#pragma once
#include "KYGBinaryTree.h"

class CKYGBinSrchTree : public CKYGBinaryTree {
public:
	// ���� Ž�� Ʈ���� Ž�� ����
	CKYGBinaryNode* search(int key) {
		CKYGBinaryNode* node = searchRecur(mRoot, key);
		if(node != NULL)
			printf("Ž�� ���� : Ű ���� %d�� ��� = 0x%x\n",
					node->getData(), node);
		else
			printf("Ž�� ���� : Ű ���� %d�� ��� ����\n", key);
		return node;
	}
	// n�� ��Ʈ�� ���� ����Ʈ������ key�� Ű������ ���� ��� Ž�� �Լ�
	CKYGBinaryNode* searchRecur(CKYGBinaryNode* n, int key) {
		if(n == NULL) return NULL;
		if(key == n->getData())
			return n;
		else if(key < n->getData())
			return searchRecur(n->getLeft(), key);
		else
			return searchRecur(n->getRight(), key);
	}
	// ���� Ž�� Ʈ���� ���� ����
	void insert(CKYGBinaryNode* n) {
		if(n == NULL) return;
		if(isEmpty()) mRoot = n;
		else insertRecur(mRoot, n);
	}
	//r�� ��Ʈ�� ���� ����Ʈ���� ���ο� ��� n�� �����ϴ� �Լ�
	void insertRecur(CKYGBinaryNode* r, CKYGBinaryNode* n) {
		if(n->getData() == r->getData())
			return;
		else if(n->getData() <r->getData()) {
			if(r->getLeft() == NULL)
				r->setLeft(n);
			else
				insertRecur(r->getLeft(), n);
		}
		else {
			if(r->getRight() == NULL)
				r->setRight(n);
			else
				insertRecur(r->getRight(), n);
		}
	}
	// ���� Ž�� Ʈ���� ���� ����
	void remove(int key) {
		if(isEmpty()) return;	// ��Ʈ���̸� return

		//���� ���� �� ����� �θ� ��带 ã�´�.
		CKYGBinaryNode* parent = NULL;	// ���� ����� �θ�
		CKYGBinaryNode* node = mRoot;	// ���� ���
		while(node != NULL && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}
		// ���� ��尡 Ʈ���� ����
		if(node == NULL) {
			printf("Error : key is not in the tree!\n");
			return;
		}
		// ���� ��尡 Ʈ���� ����
		else remove(parent, node);
	}
	// parent�� �θ�� ���� ��� node�� ���� Ž�� Ʈ������ �����ϴ� �Լ�
	void remove(CKYGBinaryNode* parent, CKYGBinaryNode* node) {
	
	}
};

