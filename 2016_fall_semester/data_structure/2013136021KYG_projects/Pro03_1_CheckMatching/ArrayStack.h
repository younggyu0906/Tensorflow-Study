#pragma once
#include <cstdio>
#include <cstdlib>

//오류 처리 함수
inline void error(char *message) {
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20;	// 스택 최대 크기 설정

class ArrayStack {
	int top;					// 요소의 개수
	int data[MAX_STACK_SIZE];	// 요소의 배열
public:
	ArrayStack() : top(-1) {}	// 스택 생성자 (ADT의 create()역할)
	~ArrayStack() {}			// 스택 소멸자
	bool isEmpty() { return top == -1; }
	bool isFull()  { return top == MAX_STACK_SIZE - 1; }

	void push(int e) {
		if(isFull())
			error("스택 포화 에러");
		data[++top] = e;
	}

	int pop() {
		if(isEmpty())
			error("스택 공백 에러");
		return data[top--];
	}

	int peek() {
		if(isEmpty())
			error("스택 공백 에러");
		return data[top];
	}

	void display() {
		printf("[스텍 항목의 수 = %2d] ==> ", top + 1);
		for(int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}

	void setArray() { // 스택 초기화 함수
		top = -1;
	}
};