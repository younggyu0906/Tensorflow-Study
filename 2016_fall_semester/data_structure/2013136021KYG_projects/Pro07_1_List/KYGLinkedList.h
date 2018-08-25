// 파일명 : KYGLinkedList.h : 단순 연결 리스트 클래스
#pragma once
#include "KYGNode.h"

class KYGLinkedList {
	KYGNode mOrg;	// 헤드 노드 (헤드포인터 x)
public:
	KYGLinkedList() : mOrg(0) {}		// 생성자
	~KYGLinkedList() { mKYGClear(); }	// 소멸자
	void mKYGClear()		{ while(!mKYGIsEmpty()) delete mKYGRemove(0); }
	KYGNode* mKYGGetHead()	{ return mOrg.mKYGGetLink(); }
	bool mKYGIsEmpty()		{ return mKYGGetHead() == NULL; }

	// pos번째 항목을 반환함
	KYGNode* mKYGGetEntry(int pos) {
		KYGNode* n = &mOrg;
		for(int i = -1; i < pos; i++, n = n->mKYGGetLink())
			if(n == NULL) break;
		return n;
	}

	// 리스트에 pos 위치에 항목 삽입
	void mKYGInsert(int pos, KYGNode *n) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		if(prev != NULL)
			prev->mKYGInsertNext(n);
	}

	// 리스트의 pos 위치의 항목 삭제
	KYGNode* mKYGRemove(int pos) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		return prev->mKYGRemoveNext();
	}

	// 일반함수로 구현된 insertNest2()를 호출하여 구현한 insert()
	void mKYGInsert2(int pos, KYGNode* n) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		if(prev != NULL)
			KYGInsertNext2(prev, n);
	}

	// 일반 함수로 구현된 removeNext2()를 호출하여 구현한 remove()
	KYGNode* mKYGRemove2(int pos) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		return KYGRemoveNext2(prev);
	}

	// 탐색 함수
	KYGNode* mKYGFind(int val) {
		for(KYGNode *p = mKYGGetHead(); p != NULL; p=p->mKYGGetLink())
			if(p->mKYGHasData(val)) return p;
		return NULL;
	}

	// 리스트의 pos 위치에 항목 교체
	void mKYGReplace(int pos, KYGNode *n) {
		KYGNode* prev = mKYGGetEntry(pos - 1);
		if(prev != NULL) {
			delete prev->mKYGRemoveNext();
			prev->mKYGInsertNext(n);
		}
	}

	// 리스트 항목 개수를 반환
	int mKYGSize() {
		int count = 0;
		for(KYGNode *p = mKYGGetHead(); p != NULL; p = p->mKYGGetLink())
			count++;
		return count;
	}

	// 화면에 보기 좋게 출력
	void mKYGDisplay() {
		printf("[전체 항목 수 = %2d] : ", mKYGSize());
		for(KYGNode *p = mKYGGetHead() ; p != NULL; p = p->mKYGGetLink())
			p->mKYGDisplay();
		printf("\n");
	}
};