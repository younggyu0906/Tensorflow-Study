#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 5;//Ÿ���� ���� ũ��
const int M = 5;//Ÿ���� ���� ũ��
const int LIMIT = 100000;//�̵� Ƚ�� ����

void print_tile(const int [N][M]);//Ÿ���� ���¸� ����ϴ� �Լ�
int random_walk(int);//������ũ������ �ǽ��ϰ� ����Ƚ���� �����ϴ� �Լ�
bool check(const int [N][M]);//Ÿ���� ��� 1�� �Ǵ� ��츦 ã�� �Լ�

void main() { //�����Լ�
	int move_count = 0;//����Ƚ���� ������ ����
	
	while(true) {
		char chioce;
		
		cout << "���� ��ũ ���α׷��� �����ұ��? (�� : Y, �ƴϿ� : N) : ";
		cin >> chioce;
		
		if (chioce == 'Y' || chioce == 'y') {//Y�� �Է¹޾� ������ũ�� ������ ���
			int start_time = clock();//������ũ ���� �ð�
			move_count = random_walk(move_count);//random_walk�Լ� ȣ��, ������ũ�� �����ϰ� ���� Ƚ�� ����
			int end_time = clock();//������ũ ���� �ð�
			cout << "�� �̵��� : " << move_count << "\n���� �ð� : " << (end_time - start_time) / 1000.0 << endl << endl;//������ũ�� ����Ƚ�� �� ����ð��� ���
		}
		else if (chioce == 'N' || chioce == 'n') {//N�� �Է¹޾� ������ ���
			cout << "������ũ�� �����մϴ�!\n";
			break;
		}
		else {//�׿��� �Է��� ���� ���
			cout << "�߸��� �Է��Դϴ�.\n";
		}
	}
}

void print_tile(const int arrange[N][M]) {//Ÿ���� ���¸� ����ϴ� �Լ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arrange[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check(const int arrange[N][M]) {//Ÿ���� ��� 1�̵Ǵ� ��츦 ã�� �Լ�
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arrange [i][j] == 1) { //�迭�� ���� 1�� ��� ī��Ʈ�� �� 1 ����, ��� 1�� ��� cnt�� = Ÿ���� ��
				cnt++;
			}
		}
	}
	if (cnt == N * M) //��� 1�� ��� true ��ȯ
		return true;
	else
		return false; //��� 1�� �ƴ� ��� false ��ȯ
}

int random_walk (int cnt) {//������ũ�� �����ϰ� ���� Ƚ���� ��ȯ �� �Լ�
	int move;//���������� ������ ������ ���� �� ����
	int x = N / 2, y = M / 2;//���������� ��ġ�� ���� �� ����, �ʱ� ��ġ�� ��(Ÿ���� �߾�)
	int tile[N][M] = {0};//Ÿ���� ���� ������ �迭
	
	srand(time(NULL));
	
	tile [x][y] = 1;//���������� ��ġ�� 1�� ��ȯ
	print_tile(tile);//Ÿ���� ���� ���

	for (cnt = 0; cnt < LIMIT; cnt++) {
		move = rand() % 8;//���������� ��ġ�� �����Լ��� ����Ͽ� ����

		if (move == 0 || move == 1 || move == 7) //���� �������� �����̴� ����
			y--;
		else if (move == 3 || move == 4 || move == 5)//�Ʒ��� �������� �����̴� ����
			y++;
		if (move == 5 || move == 6 || move == 7)//���� �������� �����̴� ����
			x--;
		else if (move == 1 || move == 2 || move == 3)//������ �������� �����̴� ����
			x++;

		if (x < 0)//���������� Ÿ�� ������ ����� ��� ���� ��ġ�� �״�� ��ġ�ϵ��� �� ����
			x = 0;
		if (y < 0)
			y = 0;
		if (x > N - 1)
			x = N - 1;
		if (y > M - 1)
			y = M - 1;

		tile [x][y] = 1;//���������� ��ġ�� Ÿ���� 1�� ��ȯ
		print_tile(tile);//Ÿ�� ���� ���
		
		if (check(tile) == true)
			break;//Ÿ���� ��� 1�� ��� �ݺ��� ����
	}
	return cnt;
}