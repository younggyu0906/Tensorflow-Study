#include <iostream>

using namespace std;

const int HOUR_TO_MIN = 60;
const int HOUR_TO_SEC = 3600;

void main() {
	double distance, min, sec, avrg;

	cout << "�޸� �Ÿ��� �Է��Ͻÿ�(km) : ";
	cin >> distance;
	cout << "�޸� �ð� �߿��� ���� �Է��Ͻÿ� : ";
	cin >> min;
	cout << "�޸� �ð� �߿��� �ʸ� �Է��Ͻÿ� : ";
	cin >> sec;

	avrg = distance / (min / HOUR_TO_MIN + sec / HOUR_TO_SEC); // �ӵ� = �Ÿ� / �ð� (��,�ʸ� �÷� �ٲپ� ����)
	cout << "��� �ӵ��� " << avrg << " km/h�Դϴ�." << endl;
}