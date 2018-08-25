#include <iostream>
#include <cmath>

using namespace std;

void main() {
	int a, b, c; // 2�� ������ a, b, c�� ���� �����ϴ� ����
	int distinction; // 2�� �������� ���� ������ �Ǻ��ϴ� �Ǻ����� ����

	cout << "2�� ������ ax^2+bx+c�� a, b, c�� ��(����)�� �Է��Ͻÿ�." << endl;
	cout << "a : ";
	cin >> a;
	cout << "b : ";
	cin >> b;
	cout << "c : ";
	cin >> c;

	distinction = pow(b, 2.0) - 4 * a * c; // �Ǻ���
	
	if (distinction > 0) { //���� 2�� �����ϴ� ���
		double x1, x2; //���� 2�� �̹Ƿ� ���� ���� ������ ���� 2�� �ʿ�

		x1 = ( - b + sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a);
		x2 = ( - b - sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a);
		
		cout << "2�� ������ ax^2+bx+c�� ���� " << x1 << ", " << x2 << "�Դϴ�." << endl;
	}
	
	else if (distinction == 0) { //���� 1�� �����ϴ� ���
		double x1; //���� 1�� �̹Ƿ� ���� ���� ������ ���� 1��

		x1 = ( - b + sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a);
		
		cout << "2�� ������ ax^2+bx+c�� ���� " << x1 << "�Դϴ�." << endl;
	}

	else { //���� ����� ���
		cout << "2�� ������ ax^2+bx+c�� ���� ����Դϴ�." << endl;
	}
}