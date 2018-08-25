#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

int		gWindowWidth = 1000;
int		gWindowHeight = 500;
int		pX, pY;
int		chooseFigure = 0;		// 도형 선택, 1 == cube, 2 == Sphere, 3 == Torus, 4 == Corn, 5 == Teapot
bool	bPressed = false;

void myName(int w, int h)			// 이름 이니셜 KYG
{
	glBegin(GL_QUADS);
	// k
	glVertex3f(w + -0.6666, h + 0.50, 0.0);
	glVertex3f(w + -0.60, h + 0.50, 0.0);
	glVertex3f(w + -0.60, h + -0.50, 0.0);
	glVertex3f(w + -0.6666, h + -0.50, 0.0);

	glVertex3f(w + -0.60, h + 0.0, 0.0);
	glVertex3f(w + -0.60, h + -0.20, 0.0);
	glVertex3f(w + -0.3333, h + 0.50, 0.0);
	glVertex3f(w + -0.40, h + 0.50, 0.0);

	glVertex3f(w + -0.3333, h + -0.50, 0.0);
	glVertex3f(w + -0.40, h + -0.50, 0.0);
	glVertex3f(w + -0.5733, h + -0.13, 0.0);
	glVertex3f(w + -0.5433, h + -0.02, 0.0);
	
	//Y
	glVertex3f(w + -0.1666, h + 0.50, 0.0);
	glVertex3f(w + -0.1, h + 0.50, 0.0);
	glVertex3f(w + 0.0333, h + 0.0, 0.0);
	glVertex3f(w + -0.0333, h + 0.0, 0.0);

	glVertex3f(w + 0.1666, h + 0.50, 0.0);
	glVertex3f(w + 0.1, h + 0.50, 0.0);
	glVertex3f(w + -0.0333, h + 0.0, 0.0);
	glVertex3f(w + 0.0333, h + 0.0, 0.0);

	glVertex3f(w + -0.0333, h + 0.0, 0.0);
	glVertex3f(w + 0.0333, h + 0.0, 0.0);
	glVertex3f(w + 0.0333, h + -0.50, 0.0);
	glVertex3f(w + -0.0333, h + -0.50, 0.0);

	//G
	glVertex3f(w + 0.50, h + 0.0, 0.0);
	glVertex3f(w + 0.6666, h + 0.0, 0.0);
	glVertex3f(w + 0.6666, h + -0.20, 0.0);
	glVertex3f(w + 0.50, h + -0.20, 0.0);

	glVertex3f(w + 0.6, h + -0.20, 0.0);
	glVertex3f(w + 0.6, h + -0.50, 0.0);
	glVertex3f(w + 0.6666, h + -0.50, 0.0);
	glVertex3f(w + 0.6666, h + -0.20, 0.0);
	glEnd( );

	glBegin(GL_QUAD_STRIP);
	glVertex3f(w + 0.6666, h + 0.30, 0.0);
	glVertex3f(w + 0.6666, h + 0.50, 0.0);
	glVertex3f(w + 0.5, h + 0.30, 0.0);
	glVertex3f(w + 0.5, h + 0.50, 0.0);

	glVertex3f(w + 0.4, h + 0.0, 0.0);
	glVertex3f(w + 0.3333, h + 0.05, 0.0);
	glVertex3f(w + 0.4, h + -0.20, 0.0);
	glVertex3f(w + 0.3333, h + -0.20, 0.0);

	glVertex3f(w + 0.4333, h + -0.30, 0.0);
	glVertex3f(w + 0.4333, h + -0.50, 0.0);
	glVertex3f(w + 0.5666, h + -0.30, 0.0);
	glVertex3f(w + 0.5666, h + -0.50, 0.0);
	glEnd( );
}

void MyReshape(int NewWidth, int NewHeight) {
     // glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat) NewWidth / (GLfloat) gWindowWidth;
    GLfloat HeightFactor = (GLfloat) NewHeight / (GLfloat) gWindowHeight;

	gWindowWidth = NewWidth;		// 윈도우의 가로 크기를 새로운 가로 크기로 설정 
	gWindowHeight = NewHeight;		// 윈도우의 세로 크기를 새로운 세로 크기로 설정

    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();  // 단위행렬로 바꾸어주는 것
    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
        -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed){
    case 'Q': case 'q': case 27:	// 27 == 'esc' 키의 아스키 코드 값
        exit(0);					// 종료
		break;
	case 'c' : case 'C' :			// 'c' || 'C' 입력시
		chooseFigure = 1;			// chooseFigure = 1로 초기화 (cube 선택)
		break;
	case 's' : case 'S' :			// 's' || 'S' 입력시
		chooseFigure = 2;			// chooseFigure = 2로 초기화 (sphere 선택)
		break;
	case 't' : case 'T' :			// 't' || 'T' 입력시
		chooseFigure = 3;			// chooseFigure = 3로 초기화 (torus 선택)
		break;
	case 'n' : case 'N' :			// 'n' || 'N' 입력시
		chooseFigure = 4;			// chooseFigure = 4로 초기화 (cone 선택)
		break;
	case 'p' : case 'P' :			// 'p' || 'P' 입력시
		chooseFigure = 5;			// chooseFigure = 5로 초기화 (teapot 선택)
		break;
    }
	glutPostRedisplay();
}

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
}

void MyMainMenu(int entryID) {
    chooseFigure = entryID;
    glutPostRedisplay();
}

void MyDisplay()		
{
	glClear(GL_COLOR_BUFFER_BIT);	// 윈도우를 클리어할 색상 지정
	glViewport(0, 0, gWindowWidth / 2, gWindowHeight);	// 뷰포트의 위치
	myName(0, 0);			// 이름
	glViewport(gWindowWidth / 2, 0, gWindowWidth / 2, gWindowHeight);	// 뷰포트의 위치
	if(chooseFigure == 1)
		glutWireCube(0.5);					// 큐브(변의 크기가 0.5)
	else if(chooseFigure == 2)
		glutWireSphere(0.5, 30, 30);		// 구(반지름 = 0.5, z축을 중심으로 세분화의 수(위도) = 30, z축을 따르는 구획 수(경도) = 30)
	else if(chooseFigure == 3)
		glutWireTorus(0.2, 0.5, 30, 30);	// 원환면
	else if(chooseFigure == 4)
		glutWireCone(0.5, 0.5, 30, 30);		// 원뿔
	else if(chooseFigure == 5)
		glutWireTeapot(0.5);				// 주전자
	glFlush( );			// 큐에 저장된 명령어들 수행
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(gWindowWidth, gWindowHeight);		// 윈도우의 넢이와 넓이 설정
	glutInitWindowPosition(0, 0);		// 화면의 좌상단을 기준으로 한 window의 좌상단 좌표 설정
	glutCreateWindow("OpenGL Drawing Example");	// 윈도우 창을 디폴트 옵션으로 생성, 윈도우 제목 설정
	//glOrtho(0, gWindowWidth, 0, gWindowHeight, 1, -1);	// 0~1까지였던 화면의 종횡비를 맞추는 함수
	
	glutDisplayFunc(MyDisplay);			// 윈도우를 그릴 때마다 인자로 주어진 함수를 호출하도록 설정
	glutReshapeFunc(MyReshape);			// reshape 콜백
	glutKeyboardFunc(MyKeyboard);		// keyboard 콜백
	glutMouseFunc(MyMouseClick);		// mouse 콜백
    glutMotionFunc(MyMouseMove);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);		// 메뉴 생성
    glutAddMenuEntry("Draw Cube", 1);
	glutAddMenuEntry("Draw Sphere", 2);
	glutAddMenuEntry("Draw Torus", 3);
    glutAddMenuEntry("Draw Cone", 4);
	glutAddMenuEntry("Draw Teapot", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop( );					// 운영체제에 관련된 모든 내용을 프로그램이 종료할 때까지 처리하도록 설정하는 함수.
	return 0;
}