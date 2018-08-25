#pragma once
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;
// 입력으로부터 후위 표기 수식을 읽어 계산하는 함수
double calcPostfixExpr(FILE *fp = stdin) {
	char c;
	stack<double> st;

	while((c = getc(fp)) != '\n') {							// '\n' 입력 전까지
		if(c == '+' || c == '-' || c == '*' || c == '/') {	// 연산자이면
			double val2 = st.top();
			st.pop();
			double val1 = st.top();
			st.pop();
			switch(c) {
			case '+' : st.push(val1 + val2); break;
			case '-' : st.push(val1 - val2); break;
			case '*' : st.push(val1 * val2); break;
			case '/' : st.push(val1 / val2); break;
			}
		}
		else if(c >= '0' && c <= '9') {						// 피연산자(숫자)의 시작이면
			ungetc(c, fp);									// 문자를 입력 버퍼에 돌려주고
			double val;
			fscanf(fp, "%lf", &val);						// double로 다시 읽음
			st.push(val);									// 읽은 값을 스택에 저장
		}
	}
	double temp = st.top();
	st.pop();
	return temp;
}

// 객체의 우선순위 계산
inline int precedence(char op) {
	switch (op) {
	case '(' : case ')' : return 0;
	case '+' : case '-' : return 1;	// 우선순위 중간
	case '*' : case '/' : return 2;	// 우선순위 높음
	}
	return -1;
}
// 중위 표기 수식을 후위 표기 수식으로 변환하는 함수
void infix2Postfix(FILE *fp, FILE *fp2) {
	char c, op;
	double val;
	stack<char> st;

	while ((c=getc(fp)) != '\n') {		// 엔터 문자 입력 전까지
		// 피연산자이면 --> 그대로 출력
		if ((c >= '0' && c <= '9')) {	// 연산항(숫자)의 시작이면
			ungetc(c, fp);				// 문자를 돌려놓고
			fscanf(fp, "%lf", &val);	// double로 다시 읽음
			printf("%4.1f ", val);
			fprintf(fp2, "%4.1f ", val);
		}
		// '(' 이면 --> 스택에 삽입
		else if(c == '(') st.push(c);
		// ')' 이면 --> '('가 나올떄까지 연산자 출력
		else if(c == ')') {
			while(!st.empty()) {
				op = st.top();
				st.pop();
				if(op == '(') break;
				else {
					fprintf(fp2, "%c ", op);
					printf("%c ", op);
				}
			}
		}
		// 연산자이면 --> 우선순위 비교 처리
		else if(c == '+' || c == '-' || c == '*' || c == '/') {
			while(!st.empty()) {
				op = st.top();
				if(precedence(c) <= precedence(op)) {
					fprintf(fp2, "%c ", op);
					printf("%c ", op);
					st.pop();
				}
				else break;
			}
			st.push(c);
		}
	}
	while (!st.empty()) {
		fprintf(fp2, "%c ", st.top());
		printf("%c ", st.top());
		st.pop();
	}
	fprintf(fp2, "\n");
	printf("\n");
}