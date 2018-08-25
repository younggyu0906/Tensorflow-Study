// 파일명 : KYGLinkedList.h : 단순 연결 리스트 클래스
#pragma once
#include "KYGNode.h"

class KYGLinkedList {
	KYGNode* mHead;	// 헤드 포인터
public:
	KYGLinkedList() : mHead(NULL) {}	// 생성자, 헤드포인터를 NULL로 초기화
	~KYGLinkedList() { mKYGClear(); }	// 소멸자
	void mKYGClear()		{ while(!mKYGIsEmpty()) delete mKYGRemove(0); }
	KYGNode* mKYGGetHead()	{ return mHead; }	// 헤드포인터반환
	bool mKYGIsEmpty()		{ return mKYGGetHead() == NULL; }

	// pos번째 항목을 반환함
	KYGNode* mKYGGetEntry(int pos) {
		if(pos < 0) return NULL;	// (pos < 0) <- 헤드 포인터인 경우
		KYGNode* n = mKYGGetHead();	// 헤드포인터가 아닌 경우
		for(int i = 0; i < pos; i++, n = n->mKYGGetLink())
			if(n == NULL) break;
		return n;
	}

	// 리스트에 pos 위치에 항목 삽입
	void mKYGInsert(int pos, KYGNode *n) {
		KYGNode* prev = mKYGGetEntry(pos - 1);	// 삽입할 이전위치의 항목을 prev에 저장
		if(prev == NULL) {						// prev의 위치가 헤드포인터일 경우
			n->mKYGSetLink(mKYGGetHead());		// 삽입할 항목의 link를 헤드포인터가 가리키는 주소 저장 
			mHead = n;							// 헤드포인터가 n을 가리키도록 저장
		}
		else
			prev->mKYGInsertNext(n);
	}

	// 리스트의 pos 위치의 항목 삭제
	KYGNode* mKYGRemove(int pos) {
		KYGNode* prev = mKYGGetEntry(pos - 1);	// prev객체에 삭제할 이전의 항목 저장
		if(prev == NULL) {						// prev의 위치가 헤드포인터일 경우
			KYGNode* temp = mKYGGetEntry(pos);	// 삭제할 항목을 저장 할 임시 객체 생성
			if(temp != NULL)					// 삭제할 항목이 NULL이 아닌 경우(NULL인 경우 == 삭제할객체가없음)
				mHead = temp->mKYGGetLink();	// 헤드 포인터에 삭제할 항목의 링크가 가리키는 주소 저장
			return temp;						// 삭제할 항목이 없는 경우(temp == NULL)
		}
		else
			return prev->mKYGRemoveNext();
	}
/*	
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
*/
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