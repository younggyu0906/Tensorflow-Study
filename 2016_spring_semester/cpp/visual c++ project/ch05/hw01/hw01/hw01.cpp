#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int n = 5;//Ÿ���� ���� ũ��
const int m = 5;//Ÿ���� ���� ũ��
const int limit = 100000;//�̵� Ƚ�� ����

void movetime();
void print_tile(const int [n][m]);//Ÿ���� ���¸� ����ϴ� �Լ�
int random_walk(int);//������ũ������ �ǽ��ϰ� ����Ƚ���� �����ϴ� �Լ�
bool check(const int [n][m]);//Ÿ���� ��� 1�� �Ǵ� ��츦 ã�� �Լ�

void main() { //�����Լ�
	while(true) {
		char ch;
		
		cout << "���� ��ũ ���α׷��� �����ұ��? (�� : Y, �ƴϿ� : N) : ";
		cin >> ch;
		
		if (ch == 'Y' || ch == 'y') {
			movetime();
		}
		else if (ch == 'N' || ch == 'n') {
			cout << "������ũ�� �����մϴ�!\n";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�.\n";
		}
	}
}

void movetime() {//�����Լ�
	int move_count = 0;//����Ƚ���� ������ ����
	int start_time = clock();//������ũ ���� �ð�

	move_count = random_walk(move_count);//random_walk�Լ� ȣ��, ������ũ�� �����ϰ� ���� Ƚ�� ����

	int end_time = clock();//������ũ ���� �ð�
	cout << "�� �̵��� : " << move_count << "\n���� �ð� : " << (end_time - start_time) / 1000.0 << endl << endl;//������ũ�� ����Ƚ�� �� ����ð��� ���
}

void print_tile(const int arrange[n][m]) {//Ÿ���� ���¸� ����ϴ� �Լ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arrange[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check(const int arrange[n][m]) {//Ÿ���� ��� 1�̵Ǵ� ��츦 ã�� �Լ�
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arrange [i][j] == 1) { //�迭�� ���� 1�� ��� ī��Ʈ�� �� 1 ����, ��� 1�� ��� cnt�� = Ÿ���� ��
				cnt++;
			}
		}
	}
	if (cnt == n * m) //��� 1�� ��� true ��ȯ
		return true;
	else
		return false; //��� 1�� �ƴ� ��� false ��ȯ
}

int random_walk (int cnt) {//������ũ�� �����ϰ� ���� Ƚ���� ��ȯ �� �Լ�
	int move;//���������� ������ ������ ���� �� ����
	int x = n / 2, y = m / 2;//���������� ��ġ�� ���� �� ����, �ʱ� ��ġ�� ��(Ÿ���� �߾�)
	//int chk;//Ÿ���� ���¸� ���� �� ����, ��� 1�ϰ�� true, ��� 1�� �ƴ� ��� false
	int tile[n][m] = {0};//Ÿ���� ���� ������ �迭
	
	srand(time(NULL));
	
	tile [x][y] = 1;//���������� ��ġ�� 1�� ��ȯ
	print_tile(tile);//Ÿ���� ���� ���

	for (cnt = 0; cnt < limit; cnt++) {
		move = rand() % 8;//���������� ��ġ�� �����Լ��� ����Ͽ� ����
/*		if (move == 0) {//12�� �������� ������ ���
			x--;
		}
		else if (move == 1) {//1�� �������� ������ ���
			x++;
			y--;
		}
		else if (move == 2) {//3�� �������� ������ ���
			x++;
		}
		else if (move == 3) {//5�� �������� ������ ���
			x++;
			y++;
		}
		else if (move == 4) {//6�� �������� ������ ���
			y++;
		}
		else if (move == 5) {//7�� �������� ������ ���
			x--;
			y++;
		}
		else if (move == 6) {//9�� �������� ������ ���
			x--;
		}
		else {//11�� �������� ������ ���
			x--;
			y--;
		}*/
		if (move == 0 || move == 1 || move == 7)
			y--;
		else if (move == 3 || move == 4 || move == 5)
			y++;

		if (move == 5 || move == 6 || move == 7)
			x--;
		else if (move == 1 || move == 2 || move == 3)
			x++;

		if (x < 0)//���������� Ÿ�� ������ ����� ��� ���� ��ġ�� �״�� ��ġ�ϵ��� �� ����
			x = 0;
		if (y < 0)
			y = 0;
		if (x > n - 1)
			x = n - 1;
		if (y > m - 1)
			y = m - 1;

		tile [x][y] = 1;//���������� ��ġ�� Ÿ���� 1�� ��ȯ
		print_tile(tile);//Ÿ�� ���� ���
		
		if (check(tile) == true)
			break;//Ÿ���� ��� 1�� ��� �ݺ��� ����
	}
	return cnt;
}