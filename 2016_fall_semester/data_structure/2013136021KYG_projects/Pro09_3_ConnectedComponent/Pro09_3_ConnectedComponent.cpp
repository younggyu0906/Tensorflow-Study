#include <cstdio>
#define WIDTH 20
#define HEIGHT 9
// 순환 호출 함수 (다중 순환의 예)
void KYGLabelComponent(unsigned char img[HEIGHT][WIDTH], int x, int y, int label) {
	if(x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)	// 영상의 밖이면 return
		return;

	if(img[y][x] == 9) {	// 처리가 안된 전경 화소이면
		img[y][x] = label;	// label로 화소 값을 바꾸고
		KYGLabelComponent(img, x - 1, y, label);	// 순환호출 : 좌측 아웃 화소
		KYGLabelComponent(img, x, y - 1, label);	// 순환호출 : 상측 아웃 화소
		KYGLabelComponent(img, x + 1, y, label);	// 순환호출 : 우측 아웃 화소
		KYGLabelComponent(img, x, y + 1, label);	// 순환호출 : 하측 아웃 화소
	}
}
// 이진 영상의 영역 채색(blob coloring) 함수
void KYGBlobColoring(unsigned char img[HEIGHT][WIDTH]) {
	int label = 1;	// label은 1부터 시작함

	for(int y = 0; y < HEIGHT; y++)			// 영상의 모든 화소에 대해
		for(int x = 0; x < WIDTH; x++) {
			if(img[y][x] == 9)		// 처리가 안 된 전경 화소이면
				KYGLabelComponent(img, x, y, label++);	// 연결화소 채색 시작
		}
}
//영상의 화소 값을 화면에 출력하는 함수
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
//주 함수
void main() {
	// 입력 영상 : 자료!
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