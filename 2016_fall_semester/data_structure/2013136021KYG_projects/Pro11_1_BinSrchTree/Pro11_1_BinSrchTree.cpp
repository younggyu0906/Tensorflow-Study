#include "KYGBinSrchTree.h"

void main(){
	printf("\n*************** [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 11 ] ***************\n\n");
	printf("         1. ���� Ž�� Ʈ�� �׽�Ʈ ���α׷�(���Ŭ���� ����)\n\n");
	CKYGBinSrchTree tree;

	tree.insert( new CKYGBinaryNode(35) );
	tree.insert( new CKYGBinaryNode(18) );
	tree.insert( new CKYGBinaryNode(7 ) );
	tree.insert( new CKYGBinaryNode(26) );
	tree.insert( new CKYGBinaryNode(12) );
	tree.insert( new CKYGBinaryNode(3 ) );
	tree.insert( new CKYGBinaryNode(68) );
	tree.insert( new CKYGBinaryNode(22) );
	tree.insert( new CKYGBinaryNode(30) );
	tree.insert( new CKYGBinaryNode(99) );

	printf(" ����� ���� = %d\n", tree.getCount());
	printf(" �ܸ��� ���� = %d\n", tree.getLeafCount());
	printf(" Ʈ���� ���� = %d\n", tree.getHeight());
	
	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	tree.search(26);
	tree.search(25);

	printf("case 1 ==> ���  3 ����");
	tree.remove( 3 );
	tree.levelorder();
	printf("\ncase 2 ==> ��� 68 ����");
	tree.remove( 68 );
	tree.levelorder();
	printf("\ncase 3 ==> ��� 18 ����");
	tree.remove( 18 );
	tree.levelorder();
	printf("\ncase 4 ==> ��� 35 ���� (��Ʈ ��� ����)");
	tree.remove( 35 );
	tree.levelorder();

	printf("\n ����� ���� = %d\n", tree.getCount());
	printf(" �ܸ��� ���� = %d\n", tree.getLeafCount());
	printf(" Ʈ���� ���� = %d\n", tree.getHeight());

	getchar();
	getchar();
}