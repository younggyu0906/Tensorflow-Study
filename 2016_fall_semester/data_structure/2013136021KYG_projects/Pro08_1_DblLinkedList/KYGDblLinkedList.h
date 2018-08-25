#pragma once
#include "KYGNode2.h"

class CKYGDblLinkedList {
	CKYGNode2* mHead;		// ��� ������
public :
	CKYGDblLinkedList(void) : mHead(NULL) { }	// ������
	~CKYGDblLinkedList(void)	{ clear(); }	// �Ҹ���
	CKYGNode2* getHead()	{ return mHead; }
	bool isEmpty()			{ return getHead() == NULL; }
	void clear()			{ while(!isEmpty()) delete remove(0); }

	CKYGNode2* getEntry(int pos) {	// pos ��° ��� ��ȯ
		if(pos < 0) return NULL;	// ��ġ�� 0���� ���� ��� (Head Pointer�� ���) NULL ��ȯ
		CKYGNode2* n = getHead();	// Head Pointer�� �ƴ� ���
		for(int i = 0; i < pos; i++, n = n->getNext())
			if(n == NULL) break;
		return n;
	}
	void insert(int pos, CKYGNode2* n) {	// pos ��ġ�� ��� ����
		CKYGNode2* prevNode = getEntry(pos - 1);	// ������ ��ġ�� ���� ��� �����Ͱ�ü ����
		if(prevNode == NULL) {	// ������ ��ġ�� ���� ��尡 NULL�� ���(Head Pointer)
			if(mHead != NULL) {	// Head Pointer�� NULL�� �ƴ� ���
				n->setNext(mHead);	// ���� �� ����� next�� ���� ��ü�� ����Ű�� ��
				mHead->setPrev(n);	// ���� ��ü�� prev�� ���� ��带 ����Ű�� ��
			}
			mHead = n;		// Head Pointer�� NULL�� ��쿡�� �� ���길 ����
		}
		else
			prevNode->insertNext(n);	// ���� �� ��ġ�� 0��°�� �ƴ� ���
	}
	CKYGNode2* remove(int pos) {		// pos ��ġ�� ��� ����
		CKYGNode2* n = getEntry(pos);	// ������ ��ġ�� ��� ������ ��ü ����
		if(n->getPrev() == NULL) {		// ������ ���� ��ü�� ���� ��� (������ ��尡 0��° �׸�)
			if(n != NULL) {				// ������ ��ü�� NULL�� �ƴ� ���
				if(n->getNext() != NULL)// ������ ��ü�� ���� ��尡 ������ ���
					n->getNext()->setPrev(NULL);	// ������ ���� ����� prev�� NULL����
				mHead = n->getNext();	// Head Ponter�� ������ ���� ��带 ����Ű����
			}
			return n;	// ������ ��ü�� NULL�� ���� NULL ��ȯ
		}
		else
			return n->remove();	// ���� �� ��ġ�� 0��°�� �ƴ� ���
	}
	CKYGNode2* find(double val) {	// ���� val�� ��� Ž��
		for(CKYGNode2* p = getHead();p != NULL; p = p->getNext())
			if(p->hasData(val)) return p;
		return NULL;
	}
	void replace(int pos, CKYGNode2* n) {	// pos ��ġ�� ��� ��ü
		CKYGNode2* prev = getEntry(pos - 1);
		if(prev != NULL) {	// ��ȯ�� ��ġ�� 0��° �׸��� �ƴ� ���
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
		else {				// ��ȯ�� ��ġ�� 0��° �׸��� ���
			n->setNext(mHead->getNext());
			delete mHead->remove();
			mHead = n;
		}
	}
	int size() {	// ����Ʈ�� ��ü ��� �� ��ȯ
		int count = 0;
		for(CKYGNode2* p = getHead(); p != NULL; p = p->getNext())
			count++;
		return count;
	}
	void display() {	// ����Ʈ�� ȭ�鿡 ���� ���� ���
		printf(" [���߿��Ḯ��Ʈ �׸� �� = %d] : ", size());
		for(CKYGNode2* p = getHead(); p != NULL ; p = p->getNext())
			p->display();
		printf("\n");
	}
};