#include <iostream>

using namespace std;

void get_sum_diff(int [], int *, int *);

void main() {
	int arr[2];
	int sum;
	int diff;
	
	cout << "두 정수를 입력하시오 : ";
	cin >> arr[0] >> arr[1];

	get_sum_diff(arr, &sum, &diff);

	cout << "두 정수의 합 : " << sum << "\n두 정수의 차 : " << diff;
}

void get_sum_diff(int a[], int *p_sum, int *p_diff) {
	*p_sum = a[0] + a[1];
	*p_diff = a[0] - a[1];
}