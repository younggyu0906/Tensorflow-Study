#include <cstdio>
#define WIDTH 20
#define HEIGHT 9
// ��ȯ ȣ�� �Լ� (���� ��ȯ�� ��)
void KYGLabelComponent(unsigned char img[HEIGHT][WIDTH], int x, int y, int label) {
	if(x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)	// ������ ���̸� return
		return;

	if(img[y][x] == 9) {	// ó���� �ȵ� ���� ȭ���̸�
		img[y][x] = label;	// label�� ȭ�� ���� �ٲٰ�
		KYGLabelComponent(img, x - 1, y, label);	// ��ȯȣ�� : ���� �ƿ� ȭ��
		KYGLabelComponent(img, x, y - 1, label);	// ��ȯȣ�� : ���� �ƿ� ȭ��
		KYGLabelComponent(img, x + 1, y, label);	// ��ȯȣ�� : ���� �ƿ� ȭ��
		KYGLabelComponent(img, x, y + 1, label);	// ��ȯȣ�� : ���� �ƿ� ȭ��
	}
}
// ���� ������ ���� ä��(blob coloring) �Լ�
void KYGBlobColoring(unsigned char img[HEIGHT][WIDTH]) {
	int label = 1;	// label�� 1���� ������

	for(int y = 0; y < HEIGHT; y++)			// ������ ��� ȭ�ҿ� ����
		for(int x = 0; x < WIDTH; x++) {
			if(img[y][x] == 9)		// ó���� �� �� ���� ȭ���̸�
				KYGLabelComponent(img, x, y, label++);	// ����ȭ�� ä�� ����
		}
}
//������ ȭ�� ���� ȭ�鿡 ����ϴ� �Լ�
void KYGPrintImage(unsigned char img[HEIGHT][WIDTH], char* msg) {
	printf("%s\n\n", msg);
	for(int y = 0; y < HEIGHT; y++) {
		printf("\t\t\t");
		for(int x = 0; x < WIDTH; x++) {
			if(img[y][x] == 0)
				printf(".");
			else
				printf("%-1d", img[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}
//�� �Լ�
void main() {
	// �Է� ���� : �ڷ�!
	unsigned char image[HEIGHT][WIDTH] = {
		0,0,0,0,0, 0,9,0,0,0, 0,9,9,9,9, 9,0,0,9,9,
		9,9,9,9,9, 0,9,0,0,0, 0,0,0,0,0, 9,0,0,9,9,
		0,0,9,0,0, 0,9,0,0,0, 0,9,9,9,9, 9,0,0,9,9,
		0,9,9,9,0, 0,9,9,9,0, 0,9,0,0,0, 0,0,0,9,9,
		0,9,0,9,0, 0,9,0,0,0, 0,9,9,9,9, 9,0,0,9,9,
		9,9,0,9,9, 0,9,0,0,0, 0,0,0,0,0, 0,0,0,9,9,
		9,0,0,0,9, 0,0,0,0,0, 0,0,9,0,9, 0,0,0,0,0,
		9,0,0,0,9, 0,9,0,0,0, 0,0,9,0,9, 0,0,0,9,9,
		0,0,0,0,0, 0,9,0,0,0, 0,9,9,9,9, 9,0,0,9,9
	};

	KYGPrintImage	(image, "\t\t\t\t<Original image>");
	KYGBlobColoring	(image);
	KYGPrintImage	(image, "\t\t\t\t<Labelled image>");

	getchar();
	getchar();
}