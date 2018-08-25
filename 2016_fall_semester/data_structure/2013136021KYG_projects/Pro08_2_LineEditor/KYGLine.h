#pragma once
#include <cstdio>
#include <cstring>
#define MAX_CHAR_PER_LINE 1000

class CKYGLine {
	char data[MAX_CHAR_PER_LINE];
public:
	// 생성자 : 라인의 문자열 초기화
	CKYGLine(char *line="")			{ strcpy(data,line); }
	// 출력함수 : 화면이나 파일에 출력할 수 있음
	void print(FILE* fp = stdout)	{ fprintf(fp,"%s",data); }
	// 비교함수 : 이 라인이 str 문자열과 동일한지를 검사
	bool hasData(char* str)			{ return strcmp(str,data) == 0; }
};