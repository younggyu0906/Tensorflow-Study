#include "KYGBinaryTree.h"

void main()
{
	printf("\n*************** [ 2016년도 2학기 자료구조 실습과제 10 ] ***************\n\n");
	printf("                     1. 이진 트리 테스트 프로그램\n\n");
	printf(" 10.1) 이진트리 테스트 \n\n");
	CKYGBinaryTree tree;

	CKYGBinaryNode *d = new CKYGBinaryNode('D', NULL, NULL );
	CKYGBinaryNode *e = new CKYGBinaryNode('E', NULL, NULL );
	CKYGBinaryNode *b = new CKYGBinaryNode('B', d, e );
	CKYGBinaryNode *f = new CKYGBinaryNode('F', NULL, NULL );
	CKYGBinaryNode *c = new CKYGBinaryNode('C', f, NULL );
	CKYGBinaryNode *a = new CKYGBinaryNode('A', b, c );

	tree.setRoot(a);
	printf("	 노드의 개수 = %d\n", tree.getCount());
	printf("	 단말의 개수 = %d\n", tree.getLeafCount());
	printf("	 트리의 높이 = %d\n", tree.getHeight());
	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	printf("\n\n 10.2) 수식 트리 \n\n");
	CKYGBinaryTree tree2;
	//           +
	//       *       -
	//     3	   2   5   6
	CKYGBinaryNode *n1 = new CKYGBinaryNode ( 3 , NULL, NULL );
	CKYGBinaryNode *n2 = new CKYGBinaryNode ( 2 , NULL, NULL );
	CKYGBinaryNode *n3 = new CKYGBinaryNode ('*', n1, n2 );
	CKYGBinaryNode *n4 = new CKYGBinaryNode ( 5 , NULL, NULL );
	CKYGBinaryNode *n5 = new CKYGBinaryNode ( 6 , NULL, NULL );
	CKYGBinaryNode *n6 = new CKYGBinaryNode ('-', n4, n5 );
	CKYGBinaryNode *n7 = new CKYGBinaryNode ('+', n3, n6 );
	tree2.setRoot(n7);
	printf("	 계산 결과 = %d\n\n\n",tree2.evaluate());

	printf(" 10.3) 디렉토리 용량 계산 \n\n");
	CKYGBinaryTree tree3;
	CKYGBinaryNode *m4 = new CKYGBinaryNode ( 200, NULL, NULL );
	CKYGBinaryNode *m5 = new CKYGBinaryNode ( 500, NULL, NULL );
	CKYGBinaryNode *m3 = new CKYGBinaryNode ( 100, m4, m5 );
	CKYGBinaryNode *m2 = new CKYGBinaryNode (  50, NULL, NULL );
	CKYGBinaryNode *m1 = new CKYGBinaryNode (   0, m2, m3 );
	tree3.setRoot(m1);
	printf("	 디렉토리 용량 계산 결과 = %d KB\n\n",tree3.calcSize());
	

	getchar();
	getchar();
}