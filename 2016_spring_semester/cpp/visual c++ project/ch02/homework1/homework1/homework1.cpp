#include <iostream>

using namespace std;

const double INCH_TO_CM = 2.54;
const int FEET_TO_INCH = 12;

void main() {
	int choice; // ����ڰ� ������ ��ȯ �� �� �����ϴ� ���ڸ� �Է¹޴� ����

	cout << "��ȯ �� ������ �����Ͻÿ�. (1 / 2)" << endl;
	
	cout << "(1. cm -> feet, inch / 2. feet, inch -> cm) : ";
	cin >> choice;
		
	if (choice == 1) { //1. cm�� inch, feet������ ��ȯ�ϴ� ���
		double cm, inch; //�Է¹��� Űcm�� ��ȯ�� inch���� ������ ����
		
		cout << "Ű�� �Է��Ͻÿ� : ";
		cin >> cm;

		inch = cm / INCH_TO_CM; // cm�� inch ������ ��ȯ
		
		if (inch >= 12) { // ��ȯ�� ���� 12(1feet=12inch)���� ���ų� ū ��� ���� feet�� ǥ��
			int feet;//feet���� �ʿ�
			
			feet = inch / FEET_TO_INCH;
			inch = inch - feet * FEET_TO_INCH; // inch�� �ڷ����� double�̱� ������ % ���� ��� �Ұ�
			
			cout << cm << "cm�� " << feet << "��Ʈ " << inch << "��ġ �Դϴ�." << endl;
		}
		
		else { // 12���� �۾Ƽ� feet�� ǥ������ �ʾƵ� �Ǵ� ���
			cout << cm << "cm�� " << inch << "��ġ �Դϴ�." << endl;
		}
	}

	else if (choice == 2) { //2. inch, feet�� cm������ ǥ���ϴ� ���
		double inch, cm; //�Է¹��� inch���� ��ȯ�� cm���� ����
		int feet;//�Է¹��� feet���� ����

		cout << "Ű�� �Է��Ͻÿ�." << endl;
		cout << "��Ʈ : ";
		cin >> feet;
		cout << "��ġ : ";
		cin >> inch;

		cm = (inch + (feet * FEET_TO_INCH)) * INCH_TO_CM;

		cout << feet << "��Ʈ " << inch << "��ġ�� " << cm << "cm �Դϴ�." << endl;
	}

	else { // 1�Ǵ� 2�� �ƴѰ��
		cout << "�߸��� �����Դϴ�." << endl;
	}
}