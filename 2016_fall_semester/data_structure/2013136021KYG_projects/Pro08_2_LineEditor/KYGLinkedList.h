#pragma once
#include "KYGNode.h"

class CKYGLinkedList {
protected:
	CKYGNode mOrg;
public:
	CKYGLinkedList(void) : mOrg("") { }
	~CKYGLinkedList(void)	{ clear(); }
	void clear()		{ while(!isEmpty()) delete remove(0); }
	CKYGNode* getHead()	{ return mOrg.getLink(); }
	bool isEmpty()		{ return getHead()==NULL; }

	//pos번째 항목을 반환
	CKYGNode* getEntry(int pos) {
		CKYGNode* n = &mOrg;
		for(int i=-1;i<pos;i++, n=n->getLink())
			if(n==NULL) break;
		return n;
	}

	//리스트의 특정 위치에 항목 삽입
	void insert(int pos, CKYGNode* n) {
		CKYGNode* prev = getEntry(pos-1);
		if(prev != NULL)
			prev->insertNext(n);
	}

	//리스트의 특정 위치의 항목을 삭제
	CKYGNode* remove(int pos) {
		CKYGNode* prev = getEntry(pos-1);
		return prev->removeNext();
	}

	//탐색 함수
	CKYGNode* find(char* str) {
		for(CKYGNode* p = getHead() ; p!= NULL ; p=p->getLink())
			if(p->hasData(str))
				return p;
		return NULL;
	}

	//리스트의 특정 위치에 항목 삽입(대체)
	void replace(int pos, CKYGNode* n) {
		CKYGNode* prev =  getEntry(pos-1);
		if(prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	//리스트의 항목 개수를 반환
	int size() {
		int count = 0;
		for(CKYGNode* p = getHead() ; p != NULL ; p=p->getLink())
			count ++;
		return count;
	}
};