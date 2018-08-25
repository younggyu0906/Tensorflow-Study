#include <iostream>
#include <cmath>

using namespace std;

const double error_range = 0.00000000001; //허용 오차(아주 작은 수)를 const문으로 선언

double newton_raphson(double); //뉴턴 랩슨 기법을 이용하여 제곱근을 구하는 함수

void main() {//메인함수
	double num;//제곱근을 구할 숫자를 입력받을 변수

	while(1) { //0보다 큰 수가 아닐 경우 입력을 다시 받도록 하는 반복문
		cout << "0보다 큰 실수를 입력하시오 : ";
		cin >> num;

		if(num <= 0) {//입력 받은 수가 0보다 크지 않은 경우 
			cout << "잘못된 입력입니다.\n";
		}
		else {//0보다 큰 경우 함수를 호출하여 구한 제곱근의 값 출력
			cout << num << "의 제곱근은 " << newton_raphson(num) << " 입니다.\n";
			break;//0보다 큰 경우 제곱근 값을 구한 후 반복문 종료
		}
	}
}

double newton_raphson(double n) { //뉴튼랩슨기법으로 제곱근을 구하는 함수 (rn+1=(rn+n/rn)/2)
	double sqrt = 1;//제곱근의 근사값

	while(1) {//(제곱근의 근사값 제곱 - 입력받은 수)의 절댓값이 허용 오차보다 작을 경우까지 근삿값을 찾는 반복문
		if(abs(pow(sqrt, 2.0) - n) < error_range) { //(제곱근의 근사값 제곱 - 입력받은 수)의 절댓값이 허용 오차보다 작을 경우 반복문 종료  
			break;
		}
		else {//(제곱근의 근사값 제곱 - 입력받은 수)의 절댓값이 허용 오차보다 클 경우 다음 근삿값 연산
			sqrt = (n / sqrt + sqrt) / 2;
		}
	}
	return sqrt;//구한 제곱근의 근사값을 리턴
}