#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char upper_case(char ch) { //�ҹ��ڸ� �빮�ڷ� �ٲ��ִ� �Լ�
	char upper;
	if(ch >= 'a' && ch <='z') 
		upper = ch - 'a' + 'A';
	else
		upper = ch;
	return upper;
}

int transnum(char ch) { //�Է��� ���ڸ� ������ ���� ���ڷ� �ٲ��ִ� �Լ�
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

char transchar(int num) { //��ǻ�Ͱ� ���� ���� ���ڸ� ����� ���� ���ڷ� �ٲ��ִ� �Լ�
	char ch;

	if(num == 2)
		ch = 'R';
	else if(num == 1)
		ch = 'S';
	else
		ch = 'P';
	return ch;
}

void main() { //�����Լ�
	char choice, comchoice; //������� ���������� ���ð��� ������ ����, ��ǻ���� ���ð��� ���ڷ� ��ȯ�Ͽ� ������ ����
	int chnum, comnum, distinct; //����ڰ� ������ ���� ���� ������ ���� ���ڷ� ��ȯ�� ���� ������ ����, �������� ������ ����, ���и� �Ǻ��� ���� ������ ����

	while(1) {
		srand(time(NULL));
		comnum = rand() % 3; //���� �� ����
		cout << "������������ �����մϴ�!\n";
		cout << "���� : R, ���� : S, �� : P, ���� : Q\n";
		cout << "���� : ";
		cin >> choice;

		choice = upper_case(choice); //�Է��� ���� �ҹ����� ��� �빮�ڷ� ��ȯ
		chnum = transnum(choice); //�Է��� ���� ������ ���� ���ڷ� ��ȯ
		
		if(chnum == 4) { //Q�Է�. ���ѷ��� ����
			cout << "������������ �����մϴ�.\n";
			break;
		}
		else if(chnum == 5) {//R,P,S,Q���ƴ� �ٸ� ���� �Է��Ͽ��� ��
			cout << "�߸��� �Է��Դϴ�. �ٽ� �����Ͻÿ�.\n";
			continue;
		}
		else { //������������ �� ��
			distinct = chnum - comnum; //���� �̰���� �Ǻ��� ��. 1or-2�����win, -1or2��win, 0draw
			comchoice = transchar(comnum); //����ڰ� �˾ƺ� �� �ֵ��� ��ǻ�Ͱ� ���� �������� �� ���� �´� ���ڷ� ��ȯ

			if(distinct == 1 || distinct == -2)//��� ��� ����ڼ���, ��ǻ�ͼ���, ����
				cout << "�� : " << choice << ", ��ǻ�� : " << comchoice << "\nYou win!!\n";
			else if(distinct == -1 || distinct == 2)
				cout << "�� : " << choice << ", ��ǻ�� : " << comchoice << "\nYou lose!!\n";
			else
				cout << "�� : " << choice << ", ��ǻ�� : " << comchoice << "\ndraw!!\n";
		}
	}
}