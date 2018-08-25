#include <cstdio>

int** KYGalloc2DInt(int rows, int cols) {
	if(rows <= 0 || cols <= 0) return NULL;

	int** mat = new int* [rows];	// ������ ������ ������ �迭
	for(int i = 0; i < rows; i++)
		mat[i] = new int [cols];	// ���� �� ���� �����͸� ������ �迭
	return mat;
}

void KYGfree2DInt (int **mat, int rows, int cols) {
	if(mat != NULL) {
		for(int i = 0; i < rows; i++)
			delete [] mat[i];
		delete [] mat;
	}
}