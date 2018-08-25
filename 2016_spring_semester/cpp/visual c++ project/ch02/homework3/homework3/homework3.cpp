#include <iostream>

using namespace std;

void zero(double x, double y){ //x 또는 y가 0일 경우의 함수 선언
	(x == 0 && y == 0) ? cout << "원점입니다." << endl : (x == 0) ? cout << "y축 입니다." << endl : cout << "x축 입니다." << endl;//(0,0)(0,y)(x,0)일경우
}

void check_quadrant(double x, double y){ //x와 y가 0이 아닐경우 사분면을 판단하는 함수 선언
	int quadrant; //사분면의 값을 저장할 변수
	quadrant = (x > 0) ? ((y > 0) ? 1 : 4) : ((y < 0) ? 3 : 2);

	cout << "제" << quadrant << "사분면 입니다." << endl;
}

void main() { //메인함수
	double x, y; //x, y의 값

	cout << "x의 값과 y의 값을 입력하시오." << endl;
	cout << "x : ";
	cin >> x;
	cout << "y : ";
	cin >> y;
	
	(x == 0 || y == 0) ? zero(x, y) : check_quadrant(x, y); // 입력받은 x, y값에 따라 함수 호출
}