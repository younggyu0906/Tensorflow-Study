#pragma once
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;
// �Է����κ��� ���� ǥ�� ������ �о� ����ϴ� �Լ�
double calcPostfixExpr(FILE *fp = stdin) {
	char c;
	stack<double> st;

	while((c = getc(fp)) != '\n') {							// '\n' �Է� ������
		if(c == '+' || c == '-' || c == '*' || c == '/') {	// �������̸�
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
		else if(c >= '0' && c <= '9') {						// �ǿ�����(����)�� �����̸�
			ungetc(c, fp);									// ���ڸ� �Է� ���ۿ� �����ְ�
			double val;
			fscanf(fp, "%lf", &val);						// double�� �ٽ� ����
			st.push(val);									// ���� ���� ���ÿ� ����
		}
	}
	double temp = st.top();
	st.pop();
	return temp;
}

// ��ü�� �켱���� ���
inline int precedence(char op) {
	switch (op) {
	case '(' : case ')' : return 0;
	case '+' : case '-' : return 1;	// �켱���� �߰�
	case '*' : case '/' : return 2;	// �켱���� ����
	}
	return -1;
}
// ���� ǥ�� ������ ���� ǥ�� �������� ��ȯ�ϴ� �Լ�
void infix2Postfix(FILE *fp, FILE *fp2) {
	char c, op;
	double val;
	stack<char> st;

	while ((c=getc(fp)) != '\n') {		// ���� ���� �Է� ������
		// �ǿ������̸� --> �״�� ���
		if ((c >= '0' && c <= '9')) {	// ������(����)�� �����̸�
			ungetc(c, fp);				// ���ڸ� ��������
			fscanf(fp, "%lf", &val);	// double�� �ٽ� ����
			printf("%4.1f ", val);
			fprintf(fp2, "%4.1f ", val);
		}
		// '(' �̸� --> ���ÿ� ����
		else if(c == '(') st.push(c);
		// ')' �̸� --> '('�� ���Ë����� ������ ���
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
		// �������̸� --> �켱���� �� ó��
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