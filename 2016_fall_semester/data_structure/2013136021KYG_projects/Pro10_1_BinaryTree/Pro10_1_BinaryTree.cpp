#include "KYGBinaryTree.h"

void main()
{
	printf("\n*************** [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 10 ] ***************\n\n");
	printf("                     1. ���� Ʈ�� �׽�Ʈ ���α׷�\n\n");
	printf(" 10.1) ����Ʈ�� �׽�Ʈ \n\n");
	CKYGBinaryTree tree;

	CKYGBinaryNode *d = new CKYGBinaryNode('D', NULL, NULL );
	CKYGBinaryNode *e = new CKYGBinaryNode('E', NULL, NULL );
	CKYGBinaryNode *b = new CKYGBinaryNode('B', d, e );
	CKYGBinaryNode *f = new CKYGBinaryNode('F', NULL, NULL );
	CKYGBinaryNode *c = new CKYGBinaryNode('C', f, NULL );
	CKYGBinaryNode *a = new CKYGBinaryNode('A', b, c );

	tree.setRoot(a);
	printf("	 ����� ���� = %d\n", tree.getCount());
	printf("	 �ܸ��� ���� = %d\n", tree.getLeafCount());
	printf("	 Ʈ���� ���� = %d\n", tree.getHeight());
	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	printf("\n\n 10.2) ���� Ʈ�� \n\n");
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
	printf("	 ��� ��� = %d\n\n\n",tree2.evaluate());

	printf(" 10.3) ���丮 �뷮 ��� \n\n");
	CKYGBinaryTree tree3;
	CKYGBinaryNode *m4 = new CKYGBinaryNode ( 200, NULL, NULL );
	CKYGBinaryNode *m5 = new CKYGBinaryNode ( 500, NULL, NULL );
	CKYGBinaryNode *m3 = new CKYGBinaryNode ( 100, m4, m5 );
	CKYGBinaryNode *m2 = new CKYGBinaryNode (  50, NULL, NULL );
	CKYGBinaryNode *m1 = new CKYGBinaryNode (   0, m2, m3 );
	tree3.setRoot(m1);
	printf("	 ���丮 �뷮 ��� ��� = %d KB\n\n",tree3.calcSize());
	

	getchar();
	getchar();
}