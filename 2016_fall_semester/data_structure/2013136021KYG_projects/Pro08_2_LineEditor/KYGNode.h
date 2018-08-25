#pragma once
#include "KYGLine.h"

class CKYGNode : public CKYGLine {
	CKYGNode* link;
public:
	CKYGNode(char* str="") : CKYGLine(str), link(NULL) { }
	void setLink(CKYGNode* p)  { link = p; }
	CKYGNode* getLink()        { return link; }
	void insertNext( CKYGNode* p ) {
		if(p!=NULL) {
			p->link = link;
			link = p;
		}
	}
	CKYGNode* removeNext() {
		CKYGNode* removed = link;
		if(removed != NULL) {
			link = removed->link;
			return removed;
		}
	}
};