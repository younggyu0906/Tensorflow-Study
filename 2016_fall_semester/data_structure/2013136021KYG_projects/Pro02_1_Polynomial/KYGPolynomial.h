#include <cstdio>

#define MAX_DEGREE 80								//다항식의 처리 가능한 최대 차수 +1

class KYGPolynomial {
	int degree;
	float coef[MAX_DEGREE];
public:
	KYGPolynomial() {
		degree = 0;
	}

	void read(char *str = " Poly = ") {				//다항식의 내용을 입력받는 멤버함수
		printf("\t다항식의 '%s'최고 차수를 입력하시오 : ", str);
		scanf("%d", &degree);
		printf("\t\t각 항의 계수를 입력하시오 (총 %d개) : ", degree + 1);
		for(int i = 0; i <= degree; i++)
			scanf("%f", coef + i);
	}

	void display(char *str = " Poly ") {			//다항식의 내용을 화면에 출력하는 함수 //디폴트 매개변수 사용
		printf("\t%s", str);
		for(int i = 0; i < degree; i++) {
			printf("(%.1f x^%d) + ", coef[i], degree - i);
		}
		printf("(%.1f)\n", coef[degree] );
	}

	void display2(char *str = " Poly = ") {			//다항식의 내용을 화면에 출력하는 함수 //디폴트 매개변수 사용
		printf("\t%s", str);

		if(isZero()) {								//다항식이 상수항일 때
			if(coef[0] < 0)							//음수일 때
				printf(" -%4.1f\n", -coef[0]);
			else									//양수일 때
				printf("%4.1f\n", coef[0]);
			return;
		}
		//첫항 출력
		if(coef[0] < 0)								//첫항이 음수일 때 
			if(coef[0] == -1)
				printf("  -  x^%d", degree);
			else
				printf("  -%4.1f x^%d", -coef[0], degree);
		else {										//첫 항이 0보다 클떄
			if(coef[0] == 1)
				printf("  x^%d", degree);
			else
				printf("%4.1f x^%d", coef[0], degree);
		}
		//첫 항과 상수항을 제외한 나머지를 출력
		for(int i = 1; i < degree; i++) {
			if(coef[i] == 0)						//계수가 0일 경우
				continue;
			else if(coef[i] < 0) {					//계수가 음수일 경우
				if(coef[i] == -1)					//계수가 -1일경우 -x^%d출력
					printf("  -   x^%d", degree - i);
				else
					printf("  -%5.1f x^%d", -coef[i], degree - i);
			}
			else {									//계수가 양수일 경우
				if(coef[i] == 1)					//계수가 1일 경우 x^%d출력
					printf("  +   x^%d", degree - i);
				else
					printf("  +%5.1f x^%d", coef[i], degree - i);
			}
		}
		//상수항
		if(coef[degree] == 0)						//상수항이 0일경우
			printf("\n");
		else if(coef[degree] > 0)					//상수항이 양수일 경우
			printf("  +%5.1f\n", coef[degree]);
		else
			printf("  -%5.1f\n", -coef[degree]);	//상수항이 음수일 경우
	}


	void add(KYGPolynomial a, KYGPolynomial b) {	//다항식 a와 b를 더하는 함수, a와 b를 더해 자신의 다항식 설정.
		if(a.degree > b.degree) {					//a항 > b항
			*this = a;
			for(int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {										//a항 <= b항
			*this = b;
			for(int i = 0; i <= a.degree; i++)		//b다항식을 자신에 복사
				coef[i+(degree - a.degree)] += a.coef[i];
		}
	}

	void sub(KYGPolynomial a, KYGPolynomial b) {	//다항식 a에서 b를 빼는 함수
		if(a.degree >= b.degree) {					//a항 > b항
			*this = a;
			for(int i = 0; i <= b.degree; i++)
	 			coef[i + (degree - b.degree)] -= b.coef[i];
		}
		else {										//a항 <= b항
			*this = b;
			for(int i = 0; i <= a.degree; i++)		
				coef[i+(degree - a.degree)] -= a.coef[i];
			negate();
		}
	}

	void mult(KYGPolynomial a, KYGPolynomial b) {	//다항식 a와 b를 곱하는 함수
		degree = a.degree + b.degree;
		for(int i = 0; i <= degree; i++) {			//초기화
			coef[i] = 0;
		}
		for(int i = 0; i <= a.degree; i++) {		//곱셈 연산
			for(int j = 0; j <= b.degree; j++) {
				coef[i + j] += a.coef[i] * b.coef[j];
			}
		}
	}

	bool isZero() {	return degree == 0; }			//최고차수가 0인가?

	void negate() {									//모든 계수의 부호를 바꿈
		for(int i = 0; i < degree; i++)
			coef[i] = -coef[i];						//계수의 부호를 바꿈
	}
													//다항식의 최고차항의 계수가 0일 때 
	void trim() {									//최고차항의 계수가 0이 아닌 값이 나오도록 변경하는 멤버함수
		for(int i = 0; i <= degree; i++) {
			if(coef[0] == 0) {						//최고차항이 0이면
				for(int j = 0; j < degree; j++) {
					coef[j] = coef[j + 1];			//계수 배열을 1씩 앞으로 이동
				}
				degree -= 1;						//최고차항의 차수 -1
				if(degree == -1)					//상수항이 0일 경우 차수가 -1이 되기 때문에 차수를 0으로 초기화
					degree = 0;
			}
			else
				break;
		}
	}
};