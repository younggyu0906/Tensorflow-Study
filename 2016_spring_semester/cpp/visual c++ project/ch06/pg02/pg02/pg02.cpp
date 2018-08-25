#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
//void fill(int [], int);
void fill (int *, int);
using namespace std;

void main() {
	int num[5];
	fill(num, 5);
	cout << "main() 함수 : ";
	for (int i = 0; i < 5; i++)
		cout << setw(3) << num[i];
	cout << endl;
}
/*void fill(int n[], int size) {
 srand(time(NULL));
 cout << "fill() 함수 : ";
 for (int i = 0; i < size; i++) {
  n[i] = rand() % 100;
  cout << setw(3) << n[i];
 }
 cout << endl;
}*/
void fill(int *n, int size) {
	srand(time(NULL));
	cout << "fill() 함수 : ";
	for (int i = 0; i < size; i++) {
		*n = rand() % 100;
		cout << setw(3) << *n;
		n++;
	}
	cout << endl;
}
