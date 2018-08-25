#include "KYGLocation2D.h"	// ��ġ Ŭ���� ����
#include <deque>			// STL�� deque ���ø� ���� ����
#include <Windows.h>

using namespace std;
//const int MAZE_SIZE = 8;	// �̷� �� ũ�� ����

/*
char map[MAZE_SIZE][MAZE_SIZE] = {
{'1', '1', '1', '1', '1', '1', '1', '1'},
{'e', '0', '0', '0', '0', '0', '0', '1'},
{'1', '0', '1', '0', '1', '1', '0', '1'},
{'1', '0', '1', '0', '0', '1', '0', '1'},
{'1', '0', '1', '1', '1', '0', '0', '1'},
{'1', '0', '1', '0', '1', '0', '1', '1'},
{'1', '0', '0', '0', '1', '0', '0', 'x'},
{'1', '1', '1', '1', '1', '1', '1', '1'},
};
*/
// (r, c)�� �� �� �ִ� ��ġ������ �˻��ϴ� �Լ�
// (r, c)�� �迭 �ȿ� �ְ�, ���� �� �� �ִ� ��ġ '0'�̰ų� �ⱸ'x' �̾�� ��
extern int** KYGalloc2DInt(int rows, int cols);
extern void KYGfree2DInt(int **mat, int rows, int cols);

int** map = NULL;		// �̷� ���� �ּ�
int rows, cols;

void KYGloadMazeFile(char* filename) {
	FILE* fp = fopen(filename, "r");
	if(fp == NULL) {
		printf(" ���� %s�� �� �� �����ϴ�.!!!\n", filename);
		return;
	}

	fscanf(fp, "%d%d", &cols, &rows);
	map = KYGalloc2DInt(rows, cols);
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			fscanf(fp, "%d", &map[i][j]);

	fclose(fp);
}

void KYGprintMaze() {
	system("cls");
	printf( "=============================================\n");
	printf( " ��ü �̷��� ũ�� = ");
	printf( "%d %d\n", cols, rows);
	printf( "=============================================\n");
	for(int i = 0 ; i < rows ; i++) {
		for(int j = 0 ; j < cols ; j++) {
			switch (map[i][j]) {
			case 0 : printf( "��" ); break;
			case 5 : printf( "��" ); break;
			case 9 : printf( "��" ); break;
			case 1 : printf( "  " ); break;
			case 2 : printf( "��" ); break;
			}
		} printf( "\n");
	}
}

KYGLocation2D KYGfindStartLocation() {
	for(int i = 0 ; i < rows ; i++)
		for(int j = 0 ; j < cols ; j++)
			if( map[i][j] == 5 )
				return KYGLocation2D(i, j);
	printf(" �̷� ���Ͽ��� �Ա� ��ġ�� ã�� �� �����ϴ�.!!!\n");
	return KYGLocation2D(0, 0);
}

bool KYGisValidLoc(int r, int c) {
	if(r < 0 || c < 0 || r >= rows || c >= cols) return false;
	else return map[r][c] == 1 || map[r][c] == 9;
}

void main() {
	KYGloadMazeFile("maze.txt");
	KYGprintMaze();

	deque<KYGLocation2D> locDeque;				// ��ġ �� ��ü ����
	locDeque.push_front(KYGfindStartLocation());	// ���� �Ա� ��ġ ����

	getchar();

	while(locDeque.empty() == false) {			// ���� ������� �ʴ� ����
		KYGLocation2D hear = locDeque.front();	// ���� front ��� ��ü ����
		locDeque.pop_front();					// �� ��� ��ü ����

		int r = hear.row;
		int c = hear.col;
		//printf("(%d,%d) ", r, c);				// ���� ��ġ�� ȭ�鿡 ���
		if(map[r][c] == 9) {					// �ⱸ�̸� -> Ž������
			printf("�̷� Ž�� ����\n");
			KYGfree2DInt (map, rows, cols);

			getchar();
			getchar();
			return;
		}
		else {								// �ⱸ�� �ƴϸ� ���� ��ġ��
			map[r][c] = 2;					// ���� ��ġ�� "������" ó��
			if(KYGisValidLoc(r - 1, c)) locDeque.push_back(KYGLocation2D(r - 1, c));
			if(KYGisValidLoc(r + 1, c)) locDeque.push_back(KYGLocation2D(r + 1, c));
			if(KYGisValidLoc(r, c - 1)) locDeque.push_back(KYGLocation2D(r, c - 1));
			if(KYGisValidLoc(r, c + 1)) locDeque.push_back(KYGLocation2D(r, c + 1));
		}
		KYGprintMaze();
		Sleep(30);
	}
	printf("�̷�Ž������\n");
	KYGfree2DInt (map, rows, cols);

	getchar();
	getchar();
}