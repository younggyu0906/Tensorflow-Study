// KYGBinSrchTree.h : 이진 탐색 트리 클래스
#pragma once
#include "KYGBinaryTree.h"

class CKYGBinSrchTree : public CKYGBinaryTree {
public:
	// 이진 탐색 트리의 탐색 연산
	CKYGBinaryNode* search(int key) {
		CKYGBinaryNode* node = searchRecur(mRoot, key);
		if(node != NULL)
			printf("탐색 성공 : 키 값이 %d인 노드 = 0x%x\n",
					node->getData(), node);
		else
			printf("탐색 실패 : 키 값이 %d인 노드 없음\n", key);
		return node;
	}
	// n을 루트로 갖는 서브트리에서 key를 키값으로 갖는 노드 탐색 함수
	CKYGBinaryNode* searchRecur(CKYGBinaryNode* n, int key) {
		if(n == NULL) return NULL;
		if(key == n->getData())
			return n;
		else if(key < n->getData())
			return searchRecur(n->getLeft(), key);
		else
			return searchRecur(n->getRight(), key);
	}
	// 이진 탐색 트리의 삽입 연산
	void insert(CKYGBinaryNode* n) {
		if(n == NULL) return;
		if(isEmpty()) mRoot = n;
		else insertRecur(mRoot, n);
	}
	//r을 루트로 갖는 서브트리에 새로운 노드 n을 삽입하는 함수
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
	// 이진 탐색 트리의 삭제 연산
	void remove(int key) {
		if(isEmpty()) return;	// 빈트리이면 return

		//없앨 노드와 그 노드의 부모 노드를 찾는다.
		CKYGBinaryNode* parent = NULL;	// 없앨 노드의 부모
		CKYGBinaryNode* node = mRoot;	// 없앨 노드
		while(node != NULL && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}
		// 없앨 노드가 트리에 없음
		if(node == NULL) {
			printf("Error : key is not in the tree!\n");
			return;
		}
		// 없앨 노드가 트리에 있음
		else remove(parent, node);
	}
	// parent를 부모로 갖는 노드 node를 이진 탐색 트리에서 삭제하는 함수
	void remove(CKYGBinaryNode* parent, CKYGBinaryNode* node) {
	
	}
};

