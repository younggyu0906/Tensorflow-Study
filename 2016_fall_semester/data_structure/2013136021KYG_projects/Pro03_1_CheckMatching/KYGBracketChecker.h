#pragma once
#include "ArrayStack.h"

class KYGBracketChecker {
	int nLine;		// 읽은 라인의 개수
	int nChar;		// 읽은 문자의 개수
	bool bSingle;
	bool bDouble;
	bool bLCmt;
	bool bMCmt;
	char ch;
	ArrayStack mBraketStack;	// 괄호 스택 객체
public:
	KYGBracketChecker() : nLine(1), nChar(0), bSingle(false), bDouble(false), bLCmt(false), bMCmt(false) {}
	~KYGBracketChecker() {}

	//주어진 파일을 읽어 괄호 매칭을 검사를 하고 결과를 출력하는 함수
	bool checkMatching(char* filename) {
		reset();
		FILE *fp = fopen(filename, "r");
		if(fp == NULL)
			error("Error : 파일이 존재하지 않습니다.\n");

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
		printf("[%s] 파일 검사 결과 : \n", filename);
		if(!mBraketStack.isEmpty())
			printf("Error : 문제발견!(라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
		else
			printf("Ok : 괄호닫기정상(라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
		return mBraketStack.isEmpty();
	}

	void reset() {		// 객체 초기화 함수
		nLine = 1;
		nChar = 0;
		bSingle = false;
		bDouble = false;
		bLCmt = false;
		bMCmt = false;
		mBraketStack.setArray();
	}

	bool checkMatching2(char* filename) {
		reset();		// 초기화

		FILE *fp = fopen(filename, "r");
		if(fp == NULL)
			error("Error : 파일이 존재하지 않습니다.\n");

		while((ch = getc(fp)) != EOF) {
			if(ch == '\n') nLine++;		// 줄 수 계산
			nChar++;					// 글자 수 계산

			if(ch == '\\') {			// 이스케이프 시퀀스 처리, \가 들어오면 한 글자 무시
				ch = getc(fp);
				nChar++;
				continue;
			}

			if(bSingle) {				// '가 시작되고 '가 닫히면 bSingle의 값 = false 
				if(ch == 39) {
					bSingle = false;
					continue;
				}
				continue;
			}
			if(bDouble) {				// "가 시작되고 "가 닫히면 bDouble의 값 = false 
				if(ch == 34) {
					bDouble = false;
					continue;
				}
				continue;
			}
			if(bLCmt) {					// //가 시작되고 \n 면 bLCmt의 값 = false
				if(ch == '\n') {
					bLCmt = false;
					continue;
				}
				continue;
			}
			if(bMCmt) {
				if(ch == '*') {			// /*가 시작되고 */이면 bMCmt의 값 = false
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

			if(ch == 39) {				// ' 일 경우 bSingle = true
				bSingle = true;
				continue;
			}
			if(ch == 34) {				// " 일 경우 bDouble = true
				bDouble = true;
				continue;
			}
			if(ch == '/') {				// /일 경우 다음 문자가 /일경우, *일 경우, 파일의 끝일 경우, 줄바꿈일 경우 판별
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

			if(ch == '[' || ch == '(' || ch == '{')		// 괄호검사
				mBraketStack.push(ch);
			else if(ch == ']' || ch == ')' || ch == '}') {
				int prev = mBraketStack.pop();
				if(	   (ch == ']' && prev != '[')
					|| (ch == ')' && prev != '(')
					|| (ch == '}' && prev != '{') ) break;	
			}
		}
		fclose(fp);
		printf("[%s] 파일 검사 결과 : \n", filename);
		if(!mBraketStack.isEmpty())
			printf("Error : 문제발견!(라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
		else
			printf("Ok : 괄호닫기정상(라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
		return mBraketStack.isEmpty();
	}
};