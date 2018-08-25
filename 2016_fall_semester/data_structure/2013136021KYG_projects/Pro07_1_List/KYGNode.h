// KYGNude.h : 연결리스트로 구현된 릿스트를 위한 노드 클래스
#pragma once
#include <cstdio>

class KYGNode {
	KYGNode* mLink;	// 다음 노드를 가리키는 포인터 변수
	double mData;		// 노드의 데이터 필드
public:
	KYGNode(double val = 0) : mData(val), mLink(NULL) {}
	KYGNode* mKYGGetLink()			{ return mLink; }
	void mKYGSetLink(KYGNode* next)	{ mLink = next; }
	void mKYGDisplay()				{ printf(" (%3.1lf)", mData); }
	bool mKYGHasData(int val)		{ return mData == val; }

	// 자신의 다음에 새로운 노드 n을 삽입하는 함수
	void mKYGInsertNext(KYGNode *n) {
		if(n != NULL) {
			n->mLink = mLink;
			mLink = n;
		}
	}

	// 자신의 다음 노드를 리스트에서 삭제하는 함수
	KYGNode* mKYGRemoveNext() {
		KYGNode* removed = mLink;
		if(removed != NULL)
			mLink = removed->mLink;
		return removed;
	}
};

// 일반함수로 구현한 insertNext()
// 삽입할 이전의 노드와 삽입 할 노드를 매개변수로 받음
inline void KYGInsertNext2(KYGNode* before, KYGNode* n) {
	if(n != NULL) {	// 삽입할 노드가 NULL이 아닐 경우
		n->mKYGSetLink(before->mKYGGetLink());	// 삽입할 노드의 link에 이전 노드의 link값 저장
		before->mKYGSetLink(n);	// 이전 노드의 link값을 삽입할 노드의 주로 값 저장
	}
}

// 일반함수로 구현한 removeNext()
// 삽입할 이전의 노드를 매개변수로 받음
inline KYGNode* KYGRemoveNext2(KYGNode* before) {
	KYGNode* removed = before->mKYGGetLink();
		if(removed != NULL) // 삭제할 노드가 NULL이 아닐 경우
			before->mKYGSetLink(removed->mKYGGetLink());// 이전 노드의 link에 삭제할 노드의 링크 값 저장
		return removed;
}