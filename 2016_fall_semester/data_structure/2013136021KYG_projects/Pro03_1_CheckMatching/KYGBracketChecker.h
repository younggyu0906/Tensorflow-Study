#pragma once
#include "ArrayStack.h"

class KYGBracketChecker {
	int nLine;		// ���� ������ ����
	int nChar;		// ���� ������ ����
	bool bSingle;
	bool bDouble;
	bool bLCmt;
	bool bMCmt;
	char ch;
	ArrayStack mBraketStack;	// ��ȣ ���� ��ü
public:
	KYGBracketChecker() : nLine(1), nChar(0), bSingle(false), bDouble(false), bLCmt(false), bMCmt(false) {}
	~KYGBracketChecker() {}

	//�־��� ������ �о� ��ȣ ��Ī�� �˻縦 �ϰ� ����� ����ϴ� �Լ�
	bool checkMatching(char* filename) {
		reset();
		FILE *fp = fopen(filename, "r");
		if(fp == NULL)
			error("Error : ������ �������� �ʽ��ϴ�.\n");

		while((ch = getc(fp)) != EOF) {
			if(ch == '\n') nLine++;
			nChar++;
			if(ch == '[' || ch == '(' || ch == '{')
				mBraketStack.push(ch);
			else if(ch == ']' || ch == ')' || ch == '}') {
				int prev = mBraketStack.pop();
				if(	   (ch == ']' && prev != '[')
					|| (ch == ')' && prev != '(')
					|| (ch == '}' && prev != '{') ) break;
			}
		}
		fclose(fp);
		printf("[%s] ���� �˻� ��� : \n", filename);
		if(!mBraketStack.isEmpty())
			printf("Error : �����߰�!(���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
		else
			printf("Ok : ��ȣ�ݱ�����(���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
		return mBraketStack.isEmpty();
	}

	void reset() {		// ��ü �ʱ�ȭ �Լ�
		nLine = 1;
		nChar = 0;
		bSingle = false;
		bDouble = false;
		bLCmt = false;
		bMCmt = false;
		mBraketStack.setArray();
	}

	bool checkMatching2(char* filename) {
		reset();		// �ʱ�ȭ

		FILE *fp = fopen(filename, "r");
		if(fp == NULL)
			error("Error : ������ �������� �ʽ��ϴ�.\n");

		while((ch = getc(fp)) != EOF) {
			if(ch == '\n') nLine++;		// �� �� ���
			nChar++;					// ���� �� ���

			if(ch == '\\') {			// �̽������� ������ ó��, \�� ������ �� ���� ����
				ch = getc(fp);
				nChar++;
				continue;
			}

			if(bSingle) {				// '�� ���۵ǰ� '�� ������ bSingle�� �� = false 
				if(ch == 39) {
					bSingle = false;
					continue;
				}
				continue;
			}
			if(bDouble) {				// "�� ���۵ǰ� "�� ������ bDouble�� �� = false 
				if(ch == 34) {
					bDouble = false;
					continue;
				}
				continue;
			}
			if(bLCmt) {					// //�� ���۵ǰ� \n �� bLCmt�� �� = false
				if(ch == '\n') {
					bLCmt = false;
					continue;
				}
				continue;
			}
			if(bMCmt) {
				if(ch == '*') {			// /*�� ���۵ǰ� */�̸� bMCmt�� �� = false
					ch = getc(fp);
					if(ch == EOF)	break;
					if(ch == '\n') 
						nLine++;
					if(ch == '/') {
						bMCmt = false;
						continue;
					}
					else
						continue;
				}
				else
					continue;
			}

			if(ch == 39) {				// ' �� ��� bSingle = true
				bSingle = true;
				continue;
			}
			if(ch == 34) {				// " �� ��� bDouble = true
				bDouble = true;
				continue;
			}
			if(ch == '/') {				// /�� ��� ���� ���ڰ� /�ϰ��, *�� ���, ������ ���� ���, �ٹٲ��� ��� �Ǻ�
				ch = getc(fp);
				if(ch == EOF) break;
				if(ch == '\n') nLine++;
				nChar++; 
				if(ch == '/') {
					bLCmt = true;
					continue;
				}
				else if(ch == '*') {
					bMCmt = true;
					continue;
				}
			}

			if(ch == '[' || ch == '(' || ch == '{')		// ��ȣ�˻�
				mBraketStack.push(ch);
			else if(ch == ']' || ch == ')' || ch == '}') {
				int prev = mBraketStack.pop();
				if(	   (ch == ']' && prev != '[')
					|| (ch == ')' && prev != '(')
					|| (ch == '}' && prev != '{') ) break;	
			}
		}
		fclose(fp);
		printf("[%s] ���� �˻� ��� : \n", filename);
		if(!mBraketStack.isEmpty())
			printf("Error : �����߰�!(���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
		else
			printf("Ok : ��ȣ�ݱ�����(���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
		return mBraketStack.isEmpty();
	}
};