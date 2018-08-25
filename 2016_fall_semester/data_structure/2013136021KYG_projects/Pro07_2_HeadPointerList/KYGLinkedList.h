// ���ϸ� : KYGLinkedList.h : �ܼ� ���� ����Ʈ Ŭ����
#pragma once
#include "KYGNode.h"

class KYGLinkedList {
	KYGNode* mHead;	// ��� ������
public:
	KYGLinkedList() : mHead(NULL) {}	// ������, ��������͸� NULL�� �ʱ�ȭ
	~KYGLinkedList() { mKYGClear(); }	// �Ҹ���
	void mKYGClear()		{ while(!mKYGIsEmpty()) delete mKYGRemove(0); }
	KYGNode* mKYGGetHead()	{ return mHead; }	// ��������͹�ȯ
	bool mKYGIsEmpty()		{ return mKYGGetHead() == NULL; }

	// pos��° �׸��� ��ȯ��
	KYGNode* mKYGGetEntry(int pos) {
		if(pos < 0) return NULL;	// (pos < 0) <- ��� �������� ���
		KYGNode* n = mKYGGetHead();	// ��������Ͱ� �ƴ� ���
		for(int i = 0; i < pos; i++, n = n->mKYGGetLink())
			if(n == NULL) break;
		return n;
	}

	// ����Ʈ�� pos ��ġ�� �׸� ����
	void mKYGInsert(int pos, KYGNode *n) {
		KYGNode* prev = mKYGGetEntry(pos - 1);	// ������ ������ġ�� �׸��� prev�� ����
		if(prev == NULL) {						// prev�� ��ġ�� ����������� ���
			n->mKYGSetLink(mKYGGetHead());		// ������ �׸��� link�� ��������Ͱ� ����Ű�� �ּ� ���� 
			mHead = n;							// ��������Ͱ� n�� ����Ű���� ����
		}
		else
			prev->mKYGInsertNext(n);
	}

	// ����Ʈ�� pos ��ġ�� �׸� ����
	KYGNode* mKYGRemove(int pos) {
		KYGNode* prev = mKYGGetEntry(pos - 1);	// prev��ü�� ������ ������ �׸� ����
		if(prev == NULL) {						// prev�� ��ġ�� ����������� ���
			KYGNode* temp = mKYGGetEntry(pos);	// ������ �׸��� ���� �� �ӽ� ��ü ����
			if(temp != NULL)					// ������ �׸��� NULL�� �ƴ� ���(NULL�� ��� == �����Ұ�ü������)
				mHead = temp->mKYGGetLink();	// ��� �����Ϳ� ������ �׸��� ��ũ�� ����Ű�� �ּ� ����
			return temp;						// ������ �׸��� ���� ���(temp == NULL)
		}
		else
			return prev->mKYGRemoveNext();
	}
/*	
	// �Ϲ��Լ��� ������ insertNest2()�� ȣ���Ͽ� ������ insert()
	void mKYGInsert2(int pos, KYGNode* n) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		if(prev != NULL)
			KYGInsertNext2(prev, n);
	}

	// �Ϲ� �Լ��� ������ removeNext2()�� ȣ���Ͽ� ������ remove()
	KYGNode* mKYGRemove2(int pos) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		return KYGRemoveNext2(prev);
	}
*/
	// Ž�� �Լ�
	KYGNode* mKYGFind(int val) {
		for(KYGNode *p = mKYGGetHead(); p != NULL; p=p->mKYGGetLink())
			if(p->mKYGHasData(val)) return p;
		return NULL;
	}

	// ����Ʈ�� pos ��ġ�� �׸� ��ü
	void mKYGReplace(int pos, KYGNode *n) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		if(prev != NULL) {
			delete prev->mKYGRemoveNext();
			prev->mKYGInsertNext(n);
		}
	}

	// ����Ʈ �׸� ������ ��ȯ
	int mKYGSize() {
		int count = 0;
		for(KYGNode *p = mKYGGetHead(); p != NULL; p = p->mKYGGetLink())
			count++;
		return count;
	}

	// ȭ�鿡 ���� ���� ���
	void mKYGDisplay() {
		printf("[��ü �׸� �� = %2d] : ", mKYGSize());
		for(KYGNode *p = mKYGGetHead() ; p != NULL; p = p->mKYGGetLink())
			p->mKYGDisplay();
		printf("\n");
	}
};