#include <cstdio>

#define MAX_DEGREE 80								//���׽��� ó�� ������ �ִ� ���� +1

class KYGPolynomial {
	int degree;
	float coef[MAX_DEGREE];
public:
	KYGPolynomial() {
		degree = 0;
	}

	void read(char *str = " Poly = ") {				//���׽��� ������ �Է¹޴� ����Լ�
		printf("\t���׽��� '%s'�ְ� ������ �Է��Ͻÿ� : ", str);
		scanf("%d", &degree);
		printf("\t\t�� ���� ����� �Է��Ͻÿ� (�� %d��) : ", degree + 1);
		for(int i = 0; i <= degree; i++)
			scanf("%f", coef + i);
	}

	void display(char *str = " Poly ") {			//���׽��� ������ ȭ�鿡 ����ϴ� �Լ� //����Ʈ �Ű����� ���
		printf("\t%s", str);
		for(int i = 0; i < degree; i++) {
			printf("(%.1f x^%d) + ", coef[i], degree - i);
		}
		printf("(%.1f)\n", coef[degree] );
	}

	void display2(char *str = " Poly = ") {			//���׽��� ������ ȭ�鿡 ����ϴ� �Լ� //����Ʈ �Ű����� ���
		printf("\t%s", str);

		if(isZero()) {								//���׽��� ������� ��
			if(coef[0] < 0)							//������ ��
				printf(" -%4.1f\n", -coef[0]);
			else									//����� ��
				printf("%4.1f\n", coef[0]);
			return;
		}
		//ù�� ���
		if(coef[0] < 0)								//ù���� ������ �� 
			if(coef[0] == -1)
				printf("  -  x^%d", degree);
			else
				printf("  -%4.1f x^%d", -coef[0], degree);
		else {										//ù ���� 0���� Ŭ��
			if(coef[0] == 1)
				printf("  x^%d", degree);
			else
				printf("%4.1f x^%d", coef[0], degree);
		}
		//ù �װ� ������� ������ �������� ���
		for(int i = 1; i < degree; i++) {
			if(coef[i] == 0)						//����� 0�� ���
				continue;
			else if(coef[i] < 0) {					//����� ������ ���
				if(coef[i] == -1)					//����� -1�ϰ�� -x^%d���
					printf("  -   x^%d", degree - i);
				else
					printf("  -%5.1f x^%d", -coef[i], degree - i);
			}
			else {									//����� ����� ���
				if(coef[i] == 1)					//����� 1�� ��� x^%d���
					printf("  +   x^%d", degree - i);
				else
					printf("  +%5.1f x^%d", coef[i], degree - i);
			}
		}
		//�����
		if(coef[degree] == 0)						//������� 0�ϰ��
			printf("\n");
		else if(coef[degree] > 0)					//������� ����� ���
			printf("  +%5.1f\n", coef[degree]);
		else
			printf("  -%5.1f\n", -coef[degree]);	//������� ������ ���
	}


	void add(KYGPolynomial a, KYGPolynomial b) {	//���׽� a�� b�� ���ϴ� �Լ�, a�� b�� ���� �ڽ��� ���׽� ����.
		if(a.degree > b.degree) {					//a�� > b��
			*this = a;
			for(int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {										//a�� <= b��
			*this = b;
			for(int i = 0; i <= a.degree; i++)		//b���׽��� �ڽſ� ����
				coef[i+(degree - a.degree)] += a.coef[i];
		}
	}

	void sub(KYGPolynomial a, KYGPolynomial b) {	//���׽� a���� b�� ���� �Լ�
		if(a.degree >= b.degree) {					//a�� > b��
			*this = a;
			for(int i = 0; i <= b.degree; i++)
	 			coef[i + (degree - b.degree)] -= b.coef[i];
		}
		else {										//a�� <= b��
			*this = b;
			for(int i = 0; i <= a.degree; i++)		
				coef[i+(degree - a.degree)] -= a.coef[i];
			negate();
		}
	}

	void mult(KYGPolynomial a, KYGPolynomial b) {	//���׽� a�� b�� ���ϴ� �Լ�
		degree = a.degree + b.degree;
		for(int i = 0; i <= degree; i++) {			//�ʱ�ȭ
			coef[i] = 0;
		}
		for(int i = 0; i <= a.degree; i++) {		//���� ����
			for(int j = 0; j <= b.degree; j++) {
				coef[i + j] += a.coef[i] * b.coef[j];
			}
		}
	}

	bool isZero() {	return degree == 0; }			//�ְ������� 0�ΰ�?

	void negate() {									//��� ����� ��ȣ�� �ٲ�
		for(int i = 0; i < degree; i++)
			coef[i] = -coef[i];						//����� ��ȣ�� �ٲ�
	}
													//���׽��� �ְ������� ����� 0�� �� 
	void trim() {									//�ְ������� ����� 0�� �ƴ� ���� �������� �����ϴ� ����Լ�
		for(int i = 0; i <= degree; i++) {
			if(coef[0] == 0) {						//�ְ������� 0�̸�
				for(int j = 0; j < degree; j++) {
					coef[j] = coef[j + 1];			//��� �迭�� 1�� ������ �̵�
				}
				degree -= 1;						//�ְ������� ���� -1
				if(degree == -1)					//������� 0�� ��� ������ -1�� �Ǳ� ������ ������ 0���� �ʱ�ȭ
					degree = 0;
			}
			else
				break;
		}
	}
};