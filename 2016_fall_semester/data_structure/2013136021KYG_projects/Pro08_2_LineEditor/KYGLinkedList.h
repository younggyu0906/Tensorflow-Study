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

	//pos��° �׸��� ��ȯ
	CKYGNode* getEntry(int pos) {
		CKYGNode* n = &mOrg;
		for(int i=-1;i<pos;i++, n=n->getLink())
			if(n==NULL) break;
		return n;
	}

	//����Ʈ�� Ư�� ��ġ�� �׸� ����
	void insert(int pos, CKYGNode* n) {
		CKYGNode* prev = getEntry(pos-1);
		if(prev != NULL)
			prev->insertNext(n);
	}

	//����Ʈ�� Ư�� ��ġ�� �׸��� ����
	CKYGNode* remove(int pos) {
		CKYGNode* prev = getEntry(pos-1);
		return prev->removeNext();
	}

	//Ž�� �Լ�
	CKYGNode* find(char* str) {
		for(CKYGNode* p = getHead() ; p!= NULL ; p=p->getLink())
			if(p->hasData(str))
				return p;
		return NULL;
	}

	//����Ʈ�� Ư�� ��ġ�� �׸� ����(��ü)
	void replace(int pos, CKYGNode* n) {
		CKYGNode* prev =  getEntry(pos-1);
		if(prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	//����Ʈ�� �׸� ������ ��ȯ
	int size() {
		int count = 0;
		for(CKYGNode* p = getHead() ; p != NULL ; p=p->getLink())
			count ++;
		return count;
	}
};