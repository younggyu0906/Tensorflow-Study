#pragma once
#include <cstdio>
#include <cstring>
#define MAX_CHAR_PER_LINE 1000

class CKYGLine {
	char data[MAX_CHAR_PER_LINE];
public:
	// ������ : ������ ���ڿ� �ʱ�ȭ
	CKYGLine(char *line="")			{ strcpy(data,line); }
	// ����Լ� : ȭ���̳� ���Ͽ� ����� �� ����
	void print(FILE* fp = stdout)	{ fprintf(fp,"%s",data); }
	// ���Լ� : �� ������ str ���ڿ��� ���������� �˻�
	bool hasData(char* str)			{ return strcmp(str,data) == 0; }
};