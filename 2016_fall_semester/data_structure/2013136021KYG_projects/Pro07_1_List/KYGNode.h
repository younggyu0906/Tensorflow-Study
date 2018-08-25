// KYGNude.h : ���Ḯ��Ʈ�� ������ ����Ʈ�� ���� ��� Ŭ����
#pragma once
#include <cstdio>

class KYGNode {
	KYGNode* mLink;	// ���� ��带 ����Ű�� ������ ����
	double mData;		// ����� ������ �ʵ�
public:
	KYGNode(double val = 0) : mData(val), mLink(NULL) {}
	KYGNode* mKYGGetLink()			{ return mLink; }
	void mKYGSetLink(KYGNode* next)	{ mLink = next; }
	void mKYGDisplay()				{ printf(" (%3.1lf)", mData); }
	bool mKYGHasData(int val)		{ return mData == val; }

	// �ڽ��� ������ ���ο� ��� n�� �����ϴ� �Լ�
	void mKYGInsertNext(KYGNode *n) {
		if(n != NULL) {
			n->mLink = mLink;
			mLink = n;
		}
	}

	// �ڽ��� ���� ��带 ����Ʈ���� �����ϴ� �Լ�
	KYGNode* mKYGRemoveNext() {
		KYGNode* removed = mLink;
		if(removed != NULL)
			mLink = removed->mLink;
		return removed;
	}
};

// �Ϲ��Լ��� ������ insertNext()
// ������ ������ ���� ���� �� ��带 �Ű������� ����
inline void KYGInsertNext2(KYGNode* before, KYGNode* n) {
	if(n != NULL) {	// ������ ��尡 NULL�� �ƴ� ���
		n->mKYGSetLink(before->mKYGGetLink());	// ������ ����� link�� ���� ����� link�� ����
		before->mKYGSetLink(n);	// ���� ����� link���� ������ ����� �ַ� �� ����
	}
}

// �Ϲ��Լ��� ������ removeNext()
// ������ ������ ��带 �Ű������� ����
inline KYGNode* KYGRemoveNext2(KYGNode* before) {
	KYGNode* removed = before->mKYGGetLink();
		if(removed != NULL) // ������ ��尡 NULL�� �ƴ� ���
			before->mKYGSetLink(removed->mKYGGetLink());// ���� ����� link�� ������ ����� ��ũ �� ����
		return removed;
}