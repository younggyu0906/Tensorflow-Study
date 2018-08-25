#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int n = 5;//타일의 가로 크기
const int m = 5;//타일의 세로 크기
const int limit = 100000;//이동 횟수 제한

void movetime();
void print_tile(const int [n][m]);//타일의 상태를 출력하는 함수
int random_walk(int);//랜덤워크문제를 실시하고 수행횟수를 리턴하는 함수
bool check(const int [n][m]);//타일이 모두 1이 되는 경우를 찾는 함수

void main() { //메인함수
	while(true) {
		char ch;
		
		cout << "랜덤 워크 프로그램을 시작할까요? (네 : Y, 아니오 : N) : ";
		cin >> ch;
		
		if (ch == 'Y' || ch == 'y') {
			movetime();
		}
		else if (ch == 'N' || ch == 'n') {
			cout << "랜덤워크를 종료합니다!\n";
			break;
		}
		else {
			cout << "잘못된 입력입니다.\n";
		}
	}
}

void movetime() {//메인함수
	int move_count = 0;//수행횟수를 저장할 변수
	int start_time = clock();//랜덤워크 시작 시간

	move_count = random_walk(move_count);//random_walk함수 호출, 랜덤워크를 실행하고 실행 횟수 리턴

	int end_time = clock();//랜덤워크 종료 시간
	cout << "총 이동수 : " << move_count << "\n수행 시간 : " << (end_time - start_time) / 1000.0 << endl << endl;//랜덤워크의 수행횟수 및 수행시간을 출력
}

void print_tile(const int arrange[n][m]) {//타일의 상태를 출력하는 함수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arrange[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check(const int arrange[n][m]) {//타일이 모두 1이되는 경우를 찾는 함수
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arrange [i][j] == 1) { //배열의 값이 1일 경우 카운트의 값 1 증가, 모두 1일 경우 cnt값 = 타일의 수
				cnt++;
			}
		}
	}
	if (cnt == n * m) //모두 1일 경우 true 반환
		return true;
	else
		return false; //모두 1이 아닐 경우 false 반환
}

int random_walk (int cnt) {//랜덤워크를 실행하고 실행 횟수를 반환 할 함수
	int move;//딱정벌레가 움직일 방향을 저장 할 변수
	int x = n / 2, y = m / 2;//딱정벌레의 위치를 저장 할 변수, 초기 위치의 값(타일의 중앙)
	//int chk;//타일의 상태를 저장 할 변수, 모두 1일경우 true, 모두 1이 아닐 경우 false
	int tile[n][m] = {0};//타일의 값을 저장할 배열
	
	srand(time(NULL));
	
	tile [x][y] = 1;//딱정벌레의 위치를 1로 변환
	print_tile(tile);//타일의 상태 출력

	for (cnt = 0; cnt < limit; cnt++) {
		move = rand() % 8;//딱정벌레의 위치를 랜덤함수를 사용하여 선택
/*		if (move == 0) {//12시 방향으로 움직일 경우
			x--;
		}
		else if (move == 1) {//1시 방향으로 움직일 경우
			x++;
			y--;
		}
		else if (move == 2) {//3시 방향으로 움직일 경우
			x++;
		}
		else if (move == 3) {//5시 방향으로 움직일 경우
			x++;
			y++;
		}
		else if (move == 4) {//6시 방향으로 움직일 경우
			y++;
		}
		else if (move == 5) {//7시 방향으로 움직일 경우
			x--;
			y++;
		}
		else if (move == 6) {//9시 방향으로 움직일 경우
			x--;
		}
		else {//11시 방향으로 움직일 경우
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

		if (x < 0)//딱정벌레가 타일 밖으로 벗어나는 경우 현재 위치에 그대로 위치하도록 할 조건
			x = 0;
		if (y < 0)
			y = 0;
		if (x > n - 1)
			x = n - 1;
		if (y > m - 1)
			y = m - 1;

		tile [x][y] = 1;//딱정벌레의 위치의 타일을 1로 변환
		print_tile(tile);//타일 상태 출력
		
		if (check(tile) == true)
			break;//타일이 모두 1일 경우 반복문 종료
	}
	return cnt;
}