#include "KYGLocation2D.h"	// ��ġ Ŭ���� ����
#include <deque>			// STL�� deque ���ø� ���� ����

using namespace std;
const int MAZE_SIZE = 8;	// �̷� �� ũ�� ����
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

// (r, c)�� �� �� �ִ� ��ġ������ �˻��ϴ� �Լ�
// (r, c)�� �迭 �ȿ� �ְ�, ���� �� �� �ִ� ��ġ '0'�̰ų� �ⱸ'x' �̾�� ��
bool isValidLoc(int r, int c) {
	if(r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

void main() {
	deque<KYGLocation2D> locDeque;				// ��ġ �� ��ü ����
	KYGLocation2D entry(1, 0);					// �Ա� ��ü
	locDeque.push_front(entry);					// ���� �Ա� ��ġ ����

	while(locDeque.empty() == false) {			// ���� ������� �ʴ� ����
		KYGLocation2D hear = locDeque.front();	// ���� front ��� ��ü ����
		locDeque.pop_front();					// �� ��� ��ü ����

		int r = hear.row;
		int c = hear.col;
		printf("(%d,%d) ", r, c);				// ���� ��ġ�� ȭ�鿡 ���
		if(map[r][c] == 'x') {					// �ⱸ�̸� -> Ž������
			printf("�̷� Ž�� ����\n");
			
			getchar();
			getchar();
			return;
		}
		else {									// �ⱸ�� �ƴϸ� ���� ��ġ��
			map[r][c] = '.';					// ���� ��ġ�� "������" ó��
			/*
			if(isValidLoc(r - 1, c)) locDeque.push_front(KYGLocation2D(r - 1, c));
			if(isValidLoc(r + 1, c)) locDeque.push_front(KYGLocation2D(r + 1, c));
			if(isValidLoc(r, c - 1)) locDeque.push_front(KYGLocation2D(r, c - 1));
			if(isValidLoc(r, c + 1)) locDeque.push_front(KYGLocation2D(r, c + 1));
			*/
			if(isValidLoc(r - 1, c)) locDeque.push_back(KYGLocation2D(r - 1, c));
			if(isValidLoc(r + 1, c)) locDeque.push_back(KYGLocation2D(r + 1, c));
			if(isValidLoc(r, c - 1)) locDeque.push_back(KYGLocation2D(r, c - 1));
			if(isValidLoc(r, c + 1)) locDeque.push_back(KYGLocation2D(r, c + 1));
		}
	}
	printf("�̷�Ž������\n");

	getchar();
	getchar();
}