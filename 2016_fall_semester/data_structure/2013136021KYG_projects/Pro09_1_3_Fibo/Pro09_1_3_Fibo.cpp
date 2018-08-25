#include <cstdio>

int KYGFiboRecur(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	return (KYGFiboRecur(n - 1) + KYGFiboRecur(n - 2));
}

int KYGFiboIter(int n) {
	if(n < 2) return n;
	else {
		int tmp, current = 1, last = 0;
		for(int i = 2; i <= n; i++) {
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

void main() {
	int n = 10;

	printf("반복: %d, 순환: %d\n", KYGFiboIter(n), KYGFiboRecur(n));
}