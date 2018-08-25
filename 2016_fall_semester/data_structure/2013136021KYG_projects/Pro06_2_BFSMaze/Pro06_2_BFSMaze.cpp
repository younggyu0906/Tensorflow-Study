#include "KYGLocation2D.h"	// 위치 클래스 포함
#include <deque>			// STL의 deque 템플릿 파일 포함
#include <Windows.h>

using namespace std;
//const int MAZE_SIZE = 8;	// 미로 맵 크기 고정

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
// (r, c)가 갈 수 있는 위치인지를 검사하는 함수
// (r, c)가 배열 안에 있고, 값이 갈 수 있는 위치 '0'이거나 출구'x' 이어야 함
extern int** KYGalloc2DInt(int rows, int cols);
extern void KYGfree2DInt(int **mat, int rows, int cols);

int** map = NULL;		// 미로 맵의 주소
int rows, cols;

void KYGloadMazeFile(char* filename) {
	FILE* fp = fopen(filename, "r");
	if(fp == NULL) {
		printf(" 파일 %s을 열 수 없습니다.!!!\n", filename);
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
	printf( " 전체 미로의 크기 = ");
	printf( "%d %d\n", cols, rows);
	printf( "=============================================\n");
	for(int i = 0 ; i < rows ; i++) {
		for(int j = 0 ; j < cols ; j++) {
			switch (map[i][j]) {
			case 0 : printf( "■" ); break;
			case 5 : printf( "○" ); break;
			case 9 : printf( "◎" ); break;
			case 1 : printf( "  " ); break;
			case 2 : printf( "□" ); break;
			}
		} printf( "\n");
	}
}

KYGLocation2D KYGfindStartLocation() {
	for(int i = 0 ; i < rows ; i++)
		for(int j = 0 ; j < cols ; j++)
			if( map[i][j] == 5 )
				return KYGLocation2D(i, j);
	printf(" 미로 파일에서 입구 위치를 찾을 수 없습니다.!!!\n");
	return KYGLocation2D(0, 0);
}

bool KYGisValidLoc(int r, int c) {
	if(r < 0 || c < 0 || r >= rows || c >= cols) return false;
	else return map[r][c] == 1 || map[r][c] == 9;
}

void main() {
	KYGloadMazeFile("maze.txt");
	KYGprintMaze();

	deque<KYGLocation2D> locDeque;				// 위치 덱 객체 생성
	locDeque.push_front(KYGfindStartLocation());	// 덱에 입구 위치 삽입

	getchar();

	while(locDeque.empty() == false) {			// 덱이 비어있지 않는 동안
		KYGLocation2D hear = locDeque.front();	// 덱의 front 상단 객체 복사
		locDeque.pop_front();					// 덱 상단 객체 삭제

		int r = hear.row;
		int c = hear.col;
		//printf("(%d,%d) ", r, c);				// 현재 위치를 화면에 출력
		if(map[r][c] == 9) {					// 출구이면 -> 탐색성공
			printf("미로 탐색 성공\n");
			KYGfree2DInt (map, rows, cols);

			getchar();
			getchar();
			return;
		}
		else {								// 출구가 아니면 현재 위치를
			map[r][c] = 2;					// 현재 위치를 "지나옴" 처리
			if(KYGisValidLoc(r - 1, c)) locDeque.push_back(KYGLocation2D(r - 1, c));
			if(KYGisValidLoc(r + 1, c)) locDeque.push_back(KYGLocation2D(r + 1, c));
			if(KYGisValidLoc(r, c - 1)) locDeque.push_back(KYGLocation2D(r, c - 1));
			if(KYGisValidLoc(r, c + 1)) locDeque.push_back(KYGLocation2D(r, c + 1));
		}
		KYGprintMaze();
		Sleep(30);
	}
	printf("미로탐색실패\n");
	KYGfree2DInt (map, rows, cols);

	getchar();
	getchar();
}