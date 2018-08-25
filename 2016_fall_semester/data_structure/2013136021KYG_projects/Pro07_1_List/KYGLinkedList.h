// ���ϸ� : KYGLinkedList.h : �ܼ� ���� ����Ʈ Ŭ����
#pragma once
#include "KYGNode.h"

class KYGLinkedList {
	KYGNode mOrg;	// ��� ��� (��������� x)
public:
	KYGLinkedList() : mOrg(0) {}		// ������
	~KYGLinkedList() { mKYGClear(); }	// �Ҹ���
	void mKYGClear()		{ while(!mKYGIsEmpty()) delete mKYGRemove(0); }
	KYGNode* mKYGGetHead()	{ return mOrg.mKYGGetLink(); }
	bool mKYGIsEmpty()		{ return mKYGGetHead() == NULL; }

	// pos��° �׸��� ��ȯ��
	KYGNode* mKYGGetEntry(int pos) {
		KYGNode* n = &mOrg;
		for(int i = -1; i < pos; i++, n = n->mKYGGetLink())
			if(n == NULL) break;
		return n;
	}

	// ����Ʈ�� pos ��ġ�� �׸� ����
	void mKYGInsert(int pos, KYGNode *n) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		if(prev != NULL)
			prev->mKYGInsertNext(n);
	}

	// ����Ʈ�� pos ��ġ�� �׸� ����
	KYGNode* mKYGRemove(int pos) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		return prev->mKYGRemoveNext();
	}

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