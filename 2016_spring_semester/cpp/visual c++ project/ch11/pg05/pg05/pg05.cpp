#include <iostream>
#include <ctime>

using namespace std;

class Time {//시간을 나타내는 클래스
	int hour, minute, second;//시간, 분, 초를 저장 할 멤버변수
public :
	Time() {//디폴트 생성자
		hour = 0;
		minute = 0;
		second = 0;
	}
	Time (int h, int m, int s) {//매개변수를 갖는 생성자
		hour = h;
		minute = m;
		second = s;
	}
	~Time() {//소멸자
	}
	void setHour(int h) {//멤버변수 hour setter
		hour = h;
	}
	int getHour() {//멤버변수hour getter
		return hour;
	}
	void setMinute(int m) {//멤버변수minute setter
		minute = m;
	}
	int getMinute() {//멤버변수minute getter
		return minute;
	}
	void setSecond(int s) {//멤버변수second setter
		second = s;
	}
	int getSecond() {//멤버변수second getter
		return second;
	}
	void print() {//출력 멤버 함수
		cout << hour << "시 " << minute << "분 " << second << "초\n";
	}
};

//bool isEqual(Time, Time);//래퍼런스를 매개변수로 받는 함수를 호출할 경우와 인자의 형태가 같기 때문에 오류
bool isEqual(Time &, Time &);//래퍼런스를 매개변수로 받는 비교 함수
bool isEqual(Time *, Time *);//포인터를 매개변수로 받는 비교 함수

void main() {//메인 함수
	int hour, min, sec;

	cout << "현재의 시간, 분, 초를 입력하세요.\n";
	cin >> hour >> min >> sec;

	//시간을 나타내는 객체를 생성하고 입력받은 시간, 분, 초 값을 인자로 넘겨 줌
	Time t1(hour, min, sec);
	t1.print();//결과 출력
	
	time_t timer;
	struct tm *t;
	
	timer = time(NULL);//현재 시각을 초 단위로 얻기

	t = localtime(&timer);//초 단위의 시간을 분리하여 구조체에 저장

	//시간을 나타내는 객체를 생성하고 현재 시간을 인자로 넘겨 줌
	Time t2(t->tm_hour, t->tm_min, t->tm_sec);
	
	t2.print();//결과 출력

	isEqual(t1, t2);
	isEqual(&t1, &t2);
}

/*bool isEqual(Time t1, Time t2) {//오류로 인한 주석 처리
	int hour = t1.getHour();
	int min = t1.getMinute();
	int sec = t1.getSecond();

	if(hour == t2.getHour() && min == t2.getMinute() && sec == t2.getSecond()) {
		cout << "입력한 시간과 현재 시간이 같습니다.\n";
		return true;
	}
	else {
		cout << "입력한 시간과 현재 시간이 같지 않습니다.\n";
		return false;
	}
}*/
bool isEqual(Time &t1, Time &t2){//래퍼런스를 매개변수로 받는 비교 함수
	int hour = t1.getHour();
	int min = t1.getMinute();
	int sec = t1.getSecond();

	if(hour == t2.getHour() && min == t2.getMinute() && sec == t2.getSecond()) {
		cout << "입력한 시간과 현재 시간이 같습니다.\n";
		return true;
	}
	else {
		cout << "입력한 시간과 현재 시간이 같지 않습니다.\n";
		return false;
	}
}
bool isEqual(Time *t1, Time *t2) {//포인터를 매개변수로 받는 비교 함수
	int hour = t1->getHour();
	int min = t1->getMinute();
	int sec = t1->getSecond();

	if(hour == t2->getHour() && min == t2->getMinute() && sec == t2->getSecond()) {
		cout << "입력한 시간과 현재 시간이 같습니다.\n";
		return true;
	}
	else {
		cout << "입력한 시간과 현재 시간이 같지 않습니다.\n";
		return false;
	}
}