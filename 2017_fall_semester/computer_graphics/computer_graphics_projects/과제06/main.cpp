#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>

int		gWindowWidth = 500;
int		gWindowHeight = 500;
int		chooseFigure = 0;		// 도형의 선택을 위한 변수
int		pX, pY;				// 마우스 좌표를 계산하기 위한 변수
bool	bPressed = false;	// 마우스가 눌렸는지를 판별하는 변수
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyMainMenu(int entryID);		// 과제1 메뉴
void MyDisplay();
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y);
void MyMouseMove(GLint X, GLint Y);
float calcX(float x);		// 과제1 도형 그리기를 위한 마우스의 x좌표를 계산하는 함수
float calcY(float y);		// 과제1 도형 그리기를 위한 마우스의 y좌표를 계산하는 함수
void MyRobot();		// 로봇의 머리와 몸통, 팔, 다리를 그리기 위해 적절한 값으로 robotParts() 함수를 호출하는 함수 
void robotParts(float x, float y, float radius, float scaleY, float angle);	// 로봇의 머리와 몸통, 팔, 다리를 그리기 위한 함수

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(gWindowWidth, gWindowHeight);		// 윈도우의 넢이와 넓이 설정
	glutInitWindowPosition(0, 0);		// 화면의 좌상단을 기준으로 한 window의 좌상단 좌표 설정
	glutCreateWindow("OpenGL Drawing Example");	// 윈도우 창을 디폴트 옵션으로 생성, 윈도우 제목 설정
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();						// 좌표 초기화

	glutDisplayFunc(MyDisplay);			// 윈도우를 그릴 때마다 인자로 주어진 함수를 호출하도록 설정
	glutMouseFunc(MyMouseClick);		// mouse 콜백
	glutMotionFunc(MyMouseMove);

	
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);		// 메뉴 생성
	glutAddMenuEntry("Draw Line", 1);
	glutAddMenuEntry("Draw Rectangle", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

	glutMainLoop( );					// 운영체제에 관련된 모든 내용을 프로그램이 종료할 때까지 처리하도록 설정하는 함수.
	return 0;
}


// 로봇의 머리와 몸통, 팔, 다리를 그리기 위한 함수
// 로봇의 머리와 몸통, 팔, 다리는 모양이 같고 크기만 다르므로
// 하나의 함수로 구현하여 적절한 값을 인자로 넘겨주어 구현하였습니다. 
void robotParts(float x, float y, float radius, float scaleY, float angle = 0) {
	glPushMatrix();
	{
		glTranslatef(x, y, 0);										// 원의 중심 좌표
		glutWireSphere(radius, 20, 20);								// 매개변수로 받은 반지름 값으로 구 그리기
		glPushMatrix();
		{
			glRotatef(angle, 0, 0, 1);								// 매개변수로 받은 각의 값 만큼 z축을 중심으로 회전
			glPushMatrix();
			{
				glTranslatef(0, - (scaleY * radius + radius), 0);	// 큐브를 그리기 위하여 좌표 이동, glTranslatef는 상대적이 좌표
				glScalef(1.0, scaleY, 1.0);							// 크기 변환
				glutWireCube(2 * radius);							// 큐브 그리기
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}


void MyRobot() {			// 로봇의 머리와 몸통, 팔, 다리를 그리기 위해 적절한 값으로 robotParts() 함수를 호출하는 함수 
	glPushMatrix();
	{
		robotParts(		0,	  0.8,	 0.2,	2.0);			// 머리
		robotParts(	- 0.3,	  0.5,	 0.1,	3.0,	- 45);	// 왼팔
		robotParts(	  0.3,	  0.5,	 0.1,	3.0,	  90);	// 오른팔
		robotParts(	- 0.1,	- 0.3,	 0.1,	3.0,	- 45);	// 왼다리
		robotParts(	  0.1,	- 0.3,	 0.1,	3.0,	  45);	// 오른다리
	}
	glPopMatrix();
}
/*
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		bPressed = true;
		pX = X;
		pY = Y;
	}
	else bPressed = false;
}

void MyMouseMove(GLint X, GLint Y) {
	if( bPressed ) {
		int dx = X - pX;
		int dy = Y - pY;
		pX = X;
		pY = Y;
		glRotatef( dx, 0.0, 1.0, 0.0 );
		glRotatef( dy, 1.0, 0.0, 0.0 );
		glutPostRedisplay();
	}
}*/

void MyDisplay()		
{
	glClear(GL_COLOR_BUFFER_BIT);	// 윈도우를 클리어할 색상 지정
    glColor3f(0.3, 0.3, 0.3);
	// 과제1과 2를 뷰포트를 나누어 구현하였으나 주석처리 하였습니다.
	
	// 뷰포트의 위치, 왼쪽 뷰포트
	//glViewport(0, 0, gWindowWidth / 2, gWindowHeight);
	if(chooseFigure == 1) {
		glBegin(GL_LINES);
			glVertex3f(calcX((float)TopLeftX), calcY((float)TopLeftY), 0.0);
			glVertex3f(calcX((float)BottomRightX), calcY((float)BottomRightY), 0.0);
		glEnd();
	}
	else if(chooseFigure == 2) {
		glBegin(GL_LINE_LOOP);
			glVertex3f(calcX((float)TopLeftX), calcY((float)TopLeftY), 0.0);
			glVertex3f(calcX((float)BottomRightX), calcY((float)TopLeftY), 0.0);
			glVertex3f(calcX((float)BottomRightX), calcY((float)BottomRightY), 0.0);
			glVertex3f(calcX((float)TopLeftX), calcY((float)BottomRightY), 0.0);
		glEnd();
	}

	// 뷰포트의 위치, 오른쪽 뷰포트
	//glViewport(gWindowWidth / 2, 0, gWindowWidth / 2, gWindowHeight);
	

	//MyRobot();
	glFlush();			// 큐에 저장된 명령어들 수행
}

// 과제1은 구현하였으나 주석처리하였습니다.


float calcX(float x) {												// 과제1 도형 그리기를 위한 마우스의 x좌표를 계산하는 함수
	float calcX = (x / gWindowWidth) * 2 - 1;
	if (calcX > 1)
		return 1;
	else if (calcX < -1)
		return -1;
	else
		return calcX;
}

float calcY(float y) {												// 과제1 도형 그리기를 위한 마우스의 y좌표를 계산하는 함수
	float calcY = ((gWindowHeight - y) / gWindowHeight) * 2 - 1;
	if (calcY > 1)
		return 1;
	else if (calcY < -1)
		return -1;
	else
		return calcY;
}

void MyMainMenu(int entryID) {										// 과제1 메뉴
    chooseFigure = entryID;		// 도형 선택
	TopLeftX = 0;				// 좌표 초기화
	TopLeftY = 0;				// 좌표 초기화
	BottomRightX = 0;			// 좌표 초기화
	BottomRightY = 0;			// 좌표 초기화
    glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {	// 과제1 마우스 콜백(도형 그리기)
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
		//printf("%d %d\n\n", TopLeftX, TopLeftY);
    }
}

void MyMouseMove(GLint X, GLint Y) {								// 과제1 마우스 콜백(도형 그리기)
    BottomRightX = X;
    BottomRightY = Y;
	//printf("%d %d\n\n", BottomRightX, BottomRightY);
    glutPostRedisplay();
}
