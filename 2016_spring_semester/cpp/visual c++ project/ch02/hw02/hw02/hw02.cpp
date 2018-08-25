#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char upper_case(char ch) { //소문자를 대문자로 바꿔주는 함수
	char upper;
	if(ch >= 'a' && ch <='z') 
		upper = ch - 'a' + 'A';
	else
		upper = ch;
	return upper;
}

int transnum(char ch) { //입력한 문자를 연산을 위해 숫자로 바꿔주는 함수
	int num;
	if(ch == 'R')
		num = 2;
	else if(ch == 'S')
		num = 1;
	else if(ch == 'P')
		num = 0;
	else if(ch == 'Q')
		num = 4;
	else
		num = 5;
	return num;
}

char transchar(int num) { //컴퓨터가 뽑은 랜덤 숫자를 출력을 위해 문자로 바꿔주는 함수
	char ch;

	if(num == 2)
		ch = 'R';
	else if(num == 1)
		ch = 'S';
	else
		ch = 'P';
	return ch;
}

void main() { //메인함수
	char choice, comchoice; //사용자의 가위바위보 선택값을 저장할 변수, 컴퓨터의 선택값을 문자로 변환하여 저장할 변수
	int chnum, comnum, distinct; //사용자가 선택한 문자 값을 연산을 위해 숫자로 변환한 값을 저장할 변수, 랜덤값을 저장할 변수, 승패를 판별할 값을 저장할 변수

	while(1) {
		srand(time(NULL));
		comnum = rand() % 3; //랜덤 값 저장
		cout << "가위바위보를 시작합니다!\n";
		cout << "바위 : R, 가위 : S, 보 : P, 종료 : Q\n";
		cout << "선택 : ";
		cin >> choice;

		choice = upper_case(choice); //입력한 값이 소문자일 경우 대문자로 변환
		chnum = transnum(choice); //입력한 값을 연산을 위해 숫자로 변환
		
		if(chnum == 4) { //Q입력. 무한루프 종료
			cout << "가위바위보를 종료합니다.\n";
			break;
		}
		else if(chnum == 5) {//R,P,S,Q가아닌 다른 값을 입력하였을 때
			cout << "잘못된 입력입니다. 다시 선택하시오.\n";
			continue;
		}
		else { //가위바위보를 할 때
			distinct = chnum - comnum; //누가 이겼는지 판별할 값. 1or-2사용자win, -1or2컴win, 0draw
			comchoice = transchar(comnum); //사용자가 알아볼 수 있도록 컴퓨터가 뽑은 랜덤값을 각 값에 맞는 문자로 변환

			if(distinct == 1 || distinct == -2)//결과 출력 사용자선택, 컴퓨터선택, 승패
				cout << "나 : " << choice << ", 컴퓨터 : " << comchoice << "\nYou win!!\n";
			else if(distinct == -1 || distinct == 2)
				cout << "나 : " << choice << ", 컴퓨터 : " << comchoice << "\nYou lose!!\n";
			else
				cout << "나 : " << choice << ", 컴퓨터 : " << comchoice << "\ndraw!!\n";
		}
	}
}