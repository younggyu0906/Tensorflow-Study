#pragma once
#include "KYGLinkedList.h"

class CKYGLineEditor : public CKYGLinkedList {
public:
   void Display(FILE* fp = stdout) {
      int i=0;
      for(CKYGNode* p = getHead(); p != NULL; p = p->getLink(), i++) {
         if(fp == stdout)
			 fprintf(stderr, "%3d: ", i);
         p->print(fp);
      }
	  fprintf(stderr, "\n");
   }
   void InsertLine() {
      int position;
      char line[MAX_CHAR_PER_LINE];
      printf("�Է��� ��ȣ : ");
      scanf("%d",&position);
      printf("�Է��� ���� : ");
      fflush(stdin);
      fgets(line,MAX_CHAR_PER_LINE,stdin);
      insert(position, new CKYGNode(line));
   }

   void DeletetLine() {
      printf("������ ��ȣ : ");
      int position;
      scanf("%d",&position);
      delete remove(position);
   }

   void ReplaceLine() {
      int position;
      char line[MAX_CHAR_PER_LINE];
      printf("������ ��ȣ : ");
      scanf("%d",&position);
      printf("������ ���� : ");
      fflush(stdin);
      fgets(line,MAX_CHAR_PER_LINE,stdin);
      replace(position, new CKYGNode(line));
   }
   void LoadFile(char* fname) {
      FILE* fp = fopen(fname,"r");
      if(fp != NULL) {
         char line[MAX_CHAR_PER_LINE];
         while(fgets(line,MAX_CHAR_PER_LINE,fp))
            insert(size(), new CKYGNode(line));
         fclose(fp);
      }
   }

   void StoreFile(char* fname) {
      FILE* fp = fopen(fname,"w");
      if(fp != NULL) {
         Display(fp);
         fclose(fp);
      }
   }
};