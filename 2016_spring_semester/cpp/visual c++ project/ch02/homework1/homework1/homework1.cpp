#include <iostream>

using namespace std;

const double INCH_TO_CM = 2.54;
const int FEET_TO_INCH = 12;

void main() {
	int choice; // 사용자가 무엇을 변환 할 지 선택하는 숫자를 입력받는 변수

	cout << "변환 할 단위를 선택하시오. (1 / 2)" << endl;
	
	cout << "(1. cm -> feet, inch / 2. feet, inch -> cm) : ";
	cin >> choice;
		
	if (choice == 1) { //1. cm를 inch, feet단위로 변환하는 경우
		double cm, inch; //입력받을 키cm와 변환할 inch값을 저장할 변수
		
		cout << "키를 입력하시오 : ";
		cin >> cm;

		inch = cm / INCH_TO_CM; // cm를 inch 단위로 변환
		
		if (inch >= 12) { // 변환한 값이 12(1feet=12inch)보다 같거나 큰 경우 단위 feet로 표현
			int feet;//feet단위 필요
			
			feet = inch / FEET_TO_INCH;
			inch = inch - feet * FEET_TO_INCH; // inch의 자료형이 double이기 때문에 % 연산 사용 불가
			
			cout << cm << "cm는 " << feet << "피트 " << inch << "인치 입니다." << endl;
		}
		
		else { // 12보다 작아서 feet로 표현하지 않아도 되는 경우
			cout << cm << "cm는 " << inch << "인치 입니다." << endl;
		}
	}

	else if (choice == 2) { //2. inch, feet를 cm단위로 표현하는 경우
		double inch, cm; //입력받을 inch값과 변환할 cm값의 변수
		int feet;//입력받을 feet값의 변수

		cout << "키를 입력하시오." << endl;
		cout << "피트 : ";
		cin >> feet;
		cout << "인치 : ";
		cin >> inch;

		cm = (inch + (feet * FEET_TO_INCH)) * INCH_TO_CM;

		cout << feet << "피트 " << inch << "인치는 " << cm << "cm 입니다." << endl;
	}

	else { // 1또는 2가 아닌경우
		cout << "잘못된 선택입니다." << endl;
	}
}