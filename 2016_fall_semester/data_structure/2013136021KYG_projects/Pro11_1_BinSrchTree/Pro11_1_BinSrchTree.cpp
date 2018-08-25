#include "KYGBinSrchTree.h"

void main(){
	printf("\n*************** [ 2016년도 2학기 자료구조 실습과제 11 ] ***************\n\n");
	printf("         1. 이진 탐색 트리 테스트 프로그램(노드클래스 구현)\n\n");
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

	printf(" 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());
	
	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	tree.search(26);
	tree.search(25);

	printf("case 1 ==> 노드  3 삭제");
	tree.remove( 3 );
	tree.levelorder();
	printf("\ncase 2 ==> 노드 68 삭제");
	tree.remove( 68 );
	tree.levelorder();
	printf("\ncase 3 ==> 노드 18 삭제");
	tree.remove( 18 );
	tree.levelorder();
	printf("\ncase 4 ==> 노드 35 삭제 (루트 노드 삭제)");
	tree.remove( 35 );
	tree.levelorder();

	printf("\n 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());

	getchar();
	getchar();
}