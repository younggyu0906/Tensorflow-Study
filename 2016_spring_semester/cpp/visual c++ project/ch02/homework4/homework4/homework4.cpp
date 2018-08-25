#include <iostream>
#include <cmath>

using namespace std;

void main() {
	int a, b, c; // 2차 방정식 a, b, c의 값을 저장하는 변수
	int distinction; // 2차 방정식의 근의 갯수를 판별하는 판별식의 변수

	cout << "2차 방정식 ax^2+bx+c의 a, b, c의 값(정수)을 입력하시오." << endl;
	cout << "a : ";
	cin >> a;
	cout << "b : ";
	cin >> b;
	cout << "c : ";
	cin >> c;

	distinction = pow(b, 2.0) - 4 * a * c; // 판별식
	
	if (distinction > 0) { //근이 2개 존재하는 경우
		double x1, x2; //근이 2개 이므로 근의 값을 저장할 변수 2개 필요

		x1 = ( - b + sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a);
		x2 = ( - b - sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a);
		
		cout << "2차 방정식 ax^2+bx+c의 근은 " << x1 << ", " << x2 << "입니다." << endl;
	}
	
	else if (distinction == 0) { //근이 1개 존재하는 경우
		double x1; //근이 1개 이므로 근의 값을 저장할 변수 1개

		x1 = ( - b + sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a);
		
		cout << "2차 방정식 ax^2+bx+c의 근은 " << x1 << "입니다." << endl;
	}

	else { //근이 허근인 경우
		cout << "2차 방정식 ax^2+bx+c의 근은 허근입니다." << endl;
	}
}