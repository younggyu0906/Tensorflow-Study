#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>
#include <math.h>

int	gWindowWidth = 800;		// 윈도우의 가로 크기
int	gWindowHeight = 800;	// 윈도우의 세로 크기

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;	// 선의 시작점과 끝점

void MyDisplay();
void bresenham_line(int x1, int y1, int x2, int y2);	// 브레스넘 알고리즘
void bDisplay(int x, int y, float gradient);			// 브레스넘 알고리즘의 점 (x, y) 출력, 후처리 단계 포함
void drawAxis();										// 좌표축을 그리는 함수
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y);	// 마우스 클릭 이벤트 처리
void MyMouseMove(GLint X, GLint Y);								// 마우스 드래그 이벤트 처리

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(gWindowWidth, gWindowHeight);		// 윈도우의 높이와 넓이 설정
	glutInitWindowPosition(100, 50);		// 화면의 좌상단을 기준으로 한 window의 좌상단 좌표 설정
	glutCreateWindow("2013136021_김영규_Bresenham_Algorithm_Test");	// 윈도우 창을 디폴트 옵션으로 생성, 윈도우 제목 설정

	printf("2013136021_김영규_Bresenham_Algorithm_Test\n");

	glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();						// 좌표 초기화
	glOrtho(0.0, gWindowWidth, 0.0, gWindowHeight, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);			// 윈도우를 그릴 때마다 인자로 주어진 함수를 호출하도록 설정
	glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);

	glutMainLoop( );					// 모든 내용을 프로그램이 종료할 때까지 처리하도록 설정하는 함수.
	return 0;
}

void MyDisplay()
{
	glViewport(0, 0, gWindowWidth, gWindowHeight);
	glClear(GL_COLOR_BUFFER_BIT);		// 윈도우를 클리어할 색상 지정
    
	glColor3f(0.7, 0.7, 0.7);			// 회색
	drawAxis();							// 좌표축 그리기

	glColor3f(1.0, 0.0, 0.0);			// 빨간색
	// 브레스넘 알고리즘
	bresenham_line(TopLeftX, TopLeftY, BottomRightX, BottomRightY);

	glFlush();			// 큐에 저장된 명령어들 수행
}

void bresenham_line(int x1, int y1, int x2, int y2)
{
	int dx, dy, x, y, x_end, p, const1, const2;

	// 전처리 단계 ******************************************************
	// 전처리 단계에서는 기울기가 0이상 1이하가 아닌 선들에 대한 기울기를 0이상 1이하로 변환한다.
	// 알고리즘 적용 후 전처리 단계의 반대의 일을 하는 후처리 단계가 필요하다.
	float gradient = (float) (y2 - y1) / (x2 - x1);	// 기울기
	//printf("gradient = %f\n", gradient);		// 기울기 출력

	if(0 <= gradient && gradient <= 1) {		// 아무것도 하지 않는다.
		//printf("0 <= gradient <= 1\n");
	}

	else if(gradient > 1) {						// y = x 대칭 변환
		int tmp1 = x1;
		int tmp2 = x2;

		x1 = y1;
		x2 = y2;

		y1 = tmp1;
		y2 = tmp2;
		//printf("1 < gradient < infinity\n");
	}
	else if(-1 <= gradient && gradient < 0) {	// y축 대칭 변환
		x1 = - x1;
		x2 = - x2;
		//printf("-1 <= gradient < 0\n");
	}
	else {										// y = x 대칭 변환 후 x축 대칭 변환
		int tmp1 = x1;
		int tmp2 = x2;

		x1 = y1;
		x2 = y2;

		y1 = -tmp1;
		y2 = -tmp2;
		//printf("-infinity < gradient < -1\n");
	}
	// 전처리 단계 끝 ************************************************
	
	// 브레스넘 알고리즘 시작
	dx = abs(x1 - x2);
	dy = abs(y1 - y2);

	p = 2 * dy - dx;

	const1 = 2 * dy;
	const2 = 2 * (dy - dx);

	// 시작점으로 사용할 점을 결정
	if(x1 > x2) {
		x = x2;
		y = y2;
		x_end = x1;
	}
	else {
		x = x1;
		y = y1;
		x_end = x2;
	}
	bDisplay(x, y, gradient);	// 점 (x, y) 출력, 후처리 단계 포함

	while (x < x_end) {
		x = x + 1;
		if(p < 0)
			p = p + const1;
		else {
			y = y + 1;
			p = p + const2;
		}
		bDisplay(x, y, gradient);	// 점 (x, y) 출력, 후처리 단계 포함
	}
}

void bDisplay(int x, int y, float gradient)
{
	// 후처리 단계
	if(0 <= gradient && gradient <= 1) {		// 아무것도 하지 않는다.
		//
	}
	else if(gradient > 1) {						// y = x 대칭 변환
		int tmp = x;
		x = y;
		y = tmp;
	}
	else if(-1 <= gradient && gradient < 0) {	// y축 대칭 변환
		x = - x;
	}
	else {										// y = x 대칭 변환 후 y축 대칭 변환
		int tmp = x;
		x = -y;
		y = tmp;
	}
	// 후처리 끝
	//drawPoint(x, y);				// 선 그리기
	glBegin(GL_POINTS);
		glVertex3f(x, y, 0.0);
	glEnd();
	
	//printf("(%4d, %4d)  ", x, y);	// 콘솔창에 xy값 출력
}

void drawAxis() {
	glBegin(GL_LINES);
		glVertex3f(0.0, gWindowHeight/2, 0.0);
		glVertex3f(gWindowWidth, gWindowHeight/2, 0.0);
		glVertex3f(gWindowWidth/2, 0.0, 0.0);
		glVertex3f(gWindowWidth/2, gWindowHeight, 0.0);
	glEnd();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = gWindowHeight - Y - 50;
		printf("(%4d, %4d)\n", X, Y);
    }
}

void MyMouseMove(GLint X, GLint Y) {
    BottomRightX = X;
    BottomRightY = gWindowHeight - Y - 50;
	printf("(%4d, %4d)\n", X, Y);
    glutPostRedisplay();
}