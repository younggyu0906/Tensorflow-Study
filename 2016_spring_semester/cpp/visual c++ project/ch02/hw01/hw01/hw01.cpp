#include <iostream>

using namespace std;

void main() {
	char calculation; //���� ������ �� �� ������ ���� ������ ����
	double num1, num2, answer; //������ ����1, 2, ��� ���� ������ ����

	while(1) {
		cout << "*************\n";
		cout << "+---Add\n";
		cout << "----Subtract\n";
		cout << "*---Multiply\n";
		cout << "/---Divide\n";
		cout << "Q---Quit\n";
		cout << "*************\n";
		cout << "������ �����Ͻÿ� : ";
		cin >> calculation;
		
		if(calculation == 'q' || calculation == 'Q') { //q, Q�� �ԷµǸ� ���ѷ��� ����
			break;
		}

		cout << "�� ���� �������� �и��Ͽ� �Է��Ͻÿ� : ";
		cin >> num1 >> num2;

		switch(calculation) {
			case '+': // +����
				answer = num1 + num2;
				cout << answer << endl;
				break;
			case '-': // -����
				answer = num1 - num2;
				cout << answer << endl;
				break;
			case '*': // *����
				answer = num1 * num2;
				cout << answer << endl;
				break;
			case '/': // /����
				if(num2 == 0) { // 0���� ���� ���
					cout << "0���� ���� �� �����ϴ�. �ٽ� �Է��Ͻÿ�.\n";
				}
				else { // 0���� ������ ��찡 �ƴ� ���
					answer = num1 / num2;
					cout << answer << endl;
				}
				break;
			default: //�Էµ� �����ڰ� +, -, *, /�� �ƴѰ��
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻÿ�.\n";
				break;
		}
	}
}