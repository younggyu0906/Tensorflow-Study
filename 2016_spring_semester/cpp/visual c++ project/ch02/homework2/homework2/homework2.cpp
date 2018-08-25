#include <iostream>

using namespace std;

const int HOUR_TO_MIN = 60;
const int HOUR_TO_SEC = 3600;

void main() {
	double distance, min, sec, avrg;

	cout << "달린 거리를 입력하시오(km) : ";
	cin >> distance;
	cout << "달린 시간 중에서 분을 입력하시오 : ";
	cin >> min;
	cout << "달린 시간 중에서 초를 입력하시오 : ";
	cin >> sec;

	avrg = distance / (min / HOUR_TO_MIN + sec / HOUR_TO_SEC); // 속도 = 거리 / 시간 (분,초를 시로 바꾸어 연산)
	cout << "평균 속도는 " << avrg << " km/h입니다." << endl;
}