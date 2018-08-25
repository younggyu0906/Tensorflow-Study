#include <iostream>

using namespace std;

void main() {
	char calculation; //무슨 연산을 할 지 선택한 값을 저장할 변수
	double num1, num2, answer; //연산할 숫자1, 2, 계산 값을 저장할 변수

	while(1) {
		cout << "*************\n";
		cout << "+---Add\n";
		cout << "----Subtract\n";
		cout << "*---Multiply\n";
		cout << "/---Divide\n";
		cout << "Q---Quit\n";
		cout << "*************\n";
		cout << "연산을 선택하시오 : ";
		cin >> calculation;
		
		if(calculation == 'q' || calculation == 'Q') { //q, Q가 입력되면 무한루프 종료
			break;
		}

		cout << "두 수를 공백으로 분리하여 입력하시오 : ";
		cin >> num1 >> num2;

		switch(calculation) {
			case '+': // +연산
				answer = num1 + num2;
				cout << answer << endl;
				break;
			case '-': // -연산
				answer = num1 - num2;
				cout << answer << endl;
				break;
			case '*': // *연산
				answer = num1 * num2;
				cout << answer << endl;
				break;
			case '/': // /연산
				if(num2 == 0) { // 0으로 나눌 경우
					cout << "0으로 나눌 수 없습니다. 다시 입력하시오.\n";
				}
				else { // 0으로 나누는 경우가 아닐 경우
					answer = num1 / num2;
					cout << answer << endl;
				}
				break;
			default: //입력된 연산자가 +, -, *, /가 아닌경우
				cout << "잘못된 입력입니다. 다시 입력하시오.\n";
				break;
		}
	}
}