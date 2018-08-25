#pragma once
#include "KYGNode2.h"

class CKYGDblLinkedList {
	CKYGNode2* mHead;		// 헤드 포인터
public :
	CKYGDblLinkedList(void) : mHead(NULL) { }	// 생성자
	~CKYGDblLinkedList(void)	{ clear(); }	// 소멸자
	CKYGNode2* getHead()	{ return mHead; }
	bool isEmpty()			{ return getHead() == NULL; }
	void clear()			{ while(!isEmpty()) delete remove(0); }

	CKYGNode2* getEntry(int pos) {	// pos 번째 노드 반환
		if(pos < 0) return NULL;	// 위치가 0보다 작은 경우 (Head Pointer인 경우) NULL 반환
		CKYGNode2* n = getHead();	// Head Pointer가 아닌 경우
		for(int i = 0; i < pos; i++, n = n->getNext())
			if(n == NULL) break;
		return n;
	}
	void insert(int pos, CKYGNode2* n) {	// pos 위치에 노드 삽입
		CKYGNode2* prevNode = getEntry(pos - 1);	// 삽입할 위치의 이전 노드 포인터객체 생성
		if(prevNode == NULL) {	// 삽입할 위치의 이전 노드가 NULL일 경우(Head Pointer)
			if(mHead != NULL) {	// Head Pointer가 NULL이 아닌 경우
				n->setNext(mHead);	// 삽입 할 노드의 next가 다음 객체를 가리키게 함
				mHead->setPrev(n);	// 다음 객체의 prev가 현재 노드를 가리키게 함
			}
			mHead = n;		// Head Pointer가 NULL일 경우에는 이 연산만 실행
		}
		else
			prevNode->insertNext(n);	// 삽입 할 위치가 0번째가 아닌 경우
	}
	CKYGNode2* remove(int pos) {		// pos 위치의 노드 삭제
		CKYGNode2* n = getEntry(pos);	// 삭제할 위치의 노드 포인터 객체 생성
		if(n->getPrev() == NULL) {		// 삭제할 이전 객체가 없을 경우 (삭제할 노드가 0번째 항목)
			if(n != NULL) {				// 삭제할 객체가 NULL이 아닐 경우
				if(n->getNext() != NULL)// 삭제할 객체의 다음 노드가 존재할 경우
					n->getNext()->setPrev(NULL);	// 삭제할 다음 노드의 prev에 NULL저장
				mHead = n->getNext();	// Head Ponter가 삭제할 다음 노드를 가리키게함
			}
			return n;	// 삭제할 객체가 NULL일 경우는 NULL 반환
		}
		else
			return n->remove();	// 삭제 할 위치가 0번째가 아닌 경우
	}
	CKYGNode2* find(double val) {	// 값이 val인 노드 탐색
		for(CKYGNode2* p = getHead();p != NULL; p = p->getNext())
			if(p->hasData(val)) return p;
		return NULL;
	}
	void replace(int pos, CKYGNode2* n) {	// pos 위치의 노드 교체
		CKYGNode2* prev = getEntry(pos - 1);
		if(prev != NULL) {	// 교환할 위치가 0번째 항목이 아닌 경우
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
		else {				// 교환할 위치가 0번째 항목인 경우
			n->setNext(mHead->getNext());
			delete mHead->remove();
			mHead = n;
		}
	}
	int size() {	// 리스트의 전체 노드 수 반환
		int count = 0;
		for(CKYGNode2* p = getHead(); p != NULL; p = p->getNext())
			count++;
		return count;
	}
	void display() {	// 리스트를 화면에 보기 좋게 출력
		printf(" [이중연결리스트 항목 수 = %d] : ", size());
		for(CKYGNode2* p = getHead(); p != NULL ; p = p->getNext())
			p->display();
		printf("\n");
	}
};