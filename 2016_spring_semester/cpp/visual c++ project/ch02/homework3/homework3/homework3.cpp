#include <iostream>

using namespace std;

void zero(double x, double y){ //x �Ǵ� y�� 0�� ����� �Լ� ����
	(x == 0 && y == 0) ? cout << "�����Դϴ�." << endl : (x == 0) ? cout << "y�� �Դϴ�." << endl : cout << "x�� �Դϴ�." << endl;//(0,0)(0,y)(x,0)�ϰ��
}

void check_quadrant(double x, double y){ //x�� y�� 0�� �ƴҰ�� ��и��� �Ǵ��ϴ� �Լ� ����
	int quadrant; //��и��� ���� ������ ����
	quadrant = (x > 0) ? ((y > 0) ? 1 : 4) : ((y < 0) ? 3 : 2);

	cout << "��" << quadrant << "��и� �Դϴ�." << endl;
}

void main() { //�����Լ�
	double x, y; //x, y�� ��

	cout << "x�� ���� y�� ���� �Է��Ͻÿ�." << endl;
	cout << "x : ";
	cin >> x;
	cout << "y : ";
	cin >> y;
	
	(x == 0 || y == 0) ? zero(x, y) : check_quadrant(x, y); // �Է¹��� x, y���� ���� �Լ� ȣ��
}