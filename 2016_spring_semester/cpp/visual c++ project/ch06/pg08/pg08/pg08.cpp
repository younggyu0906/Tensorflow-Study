#include <iostream>

using namespace std;

void get_sum_diff(int [], int *, int *);

void main() {
	int arr[2];
	int sum;
	int diff;
	
	cout << "�� ������ �Է��Ͻÿ� : ";
	cin >> arr[0] >> arr[1];

	get_sum_diff(arr, &sum, &diff);

	cout << "�� ������ �� : " << sum << "\n�� ������ �� : " << diff;
}

void get_sum_diff(int a[], int *p_sum, int *p_diff) {
	*p_sum = a[0] + a[1];
	*p_diff = a[0] - a[1];
}