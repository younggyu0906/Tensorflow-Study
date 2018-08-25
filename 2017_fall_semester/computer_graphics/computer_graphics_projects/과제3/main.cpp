#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

void points()		// 점
{
	glBegin(GL_POINTS);
	glVertex3f(50, 70, 0.0);
	glVertex3f(20, 50, 0.0);
	glVertex3f(70, 60, 0.0);
	glVertex3f(50, 30, 0.0);
	glVertex3f(40, 20, 0.0);
	glEnd( );
}

void lines()		// 선
{
	glBegin(GL_LINES);
	glVertex3f(130, 50, 0.0);
	glVertex3f(150, 70, 0.0);
	glVertex3f(145, 45, 0.0);
	glVertex3f(170, 20, 0.0);
	glVertex3f(130, 20, 0.0);
	glVertex3f(170, 60, 0.0);
	glEnd( );
}

void line_strip()	// 연결된 선
{
	glBegin(GL_LINE_STRIP);
	glVertex3f(230, 70, 0.0);
	glVertex3f(270, 40, 0.0);
	glVertex3f(270, 70, 0.0);
	glVertex3f(250, 80, 0.0);
	glVertex3f(220, 50, 0.0);
	glVertex3f(235, 30, 0.0);
	glEnd( );
}

void line_loop()	// 연결된 순환 선
{
	glBegin(GL_LINE_LOOP);
	glVertex3f(320, 50, 0.0);
	glVertex3f(380, 60, 0.0);
	glVertex3f(350, 70, 0.0);
	glVertex3f(350, 40, 0.0);
	glVertex3f(340, 30, 0.0);
	glEnd( );
}

void polygon()		// 다각형
{
	glBegin(GL_POLYGON);
	glVertex3f(430, 70, 0.0);
	glVertex3f(480, 80, 0.0);
	glVertex3f(480, 50, 0.0);
	glVertex3f(450, 30, 0.0);
	glVertex3f(430, 40, 0.0);
	glEnd( );
}

void quads()		// 사각형 
{
	glBegin(GL_QUADS);
	glVertex3f(520, 40, 0.0);
	glVertex3f(520, 70, 0.0);
	glVertex3f(530, 80, 0.0);
	glVertex3f(540, 30, 0.0);

	glVertex3f(560, 90, 0.0);
	glVertex3f(580, 80, 0.0);
	glVertex3f(580, 40, 0.0);
	glVertex3f(570, 50, 0.0);
	glEnd( );
}

void quad_strip()	// 연결된 사각형
{
	glBegin(GL_QUAD_STRIP);
	glVertex3f(620, 70, 0.0);
	glVertex3f(620, 40, 0.0);
	glVertex3f(640, 30, 0.0);
	glVertex3f(630, 80, 0.0);

	glVertex3f(660, 90, 0.0);
	glVertex3f(680, 80, 0.0);
	glVertex3f(680, 40, 0.0);
	glVertex3f(670, 50, 0.0);
	glEnd( );
}

void triangles()	// 삼각형
{
	glBegin(GL_TRIANGLES);
	glVertex3f(720, 70, 0.0);
	glVertex3f(720, 40, 0.0);
	glVertex3f(740, 30, 0.0);

	glVertex3f(730, 80, 0.0);
	glVertex3f(760, 90, 0.0);
	glVertex3f(780, 80, 0.0);
	glEnd( );
}

void triangle_strip()	// 연결된 삼각형 
{
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(820, 70, 0.0);
	glVertex3f(820, 40, 0.0);
	glVertex3f(840, 30, 0.0);

	glVertex3f(830, 80, 0.0);
	glVertex3f(860, 90, 0.0);
	glVertex3f(880, 80, 0.0);
	glEnd( );
}

void triangle_fan()		// 부채꼴 삼각형
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(920, 70, 0.0);
	glVertex3f(920, 40, 0.0);
	glVertex3f(940, 30, 0.0);
	glVertex3f(930, 80, 0.0);

	glVertex3f(960, 90, 0.0);
	glVertex3f(980, 80, 0.0);
	glEnd( );
}

void myName()			// 이름 이니셜
{
	glBegin(GL_QUADS);
	// k
	glVertex3f(100, 250, 0.0);
	glVertex3f(120, 250, 0.0);
	glVertex3f(120, 150, 0.0);
	glVertex3f(100, 150, 0.0);

	glVertex3f(120, 200, 0.0);
	glVertex3f(120, 180, 0.0);
	glVertex3f(200, 250, 0.0);
	glVertex3f(180, 250, 0.0);

	glVertex3f(200, 150, 0.0);
	glVertex3f(180, 150, 0.0);
	glVertex3f(128, 187, 0.0);
	glVertex3f(137, 198, 0.0);
	
	//Y
	glVertex3f(250, 250, 0.0);
	glVertex3f(270, 250, 0.0);
	glVertex3f(310, 200, 0.0);
	glVertex3f(290, 200, 0.0);

	glVertex3f(350, 250, 0.0);
	glVertex3f(330, 250, 0.0);
	glVertex3f(290, 200, 0.0);
	glVertex3f(310, 200, 0.0);

	glVertex3f(290, 200, 0.0);
	glVertex3f(310, 200, 0.0);
	glVertex3f(310, 150, 0.0);
	glVertex3f(290, 150, 0.0);

	//G
	glVertex3f(450, 200, 0.0);
	glVertex3f(500, 200, 0.0);
	glVertex3f(500, 180, 0.0);
	glVertex3f(450, 180, 0.0);

	glVertex3f(480, 180, 0.0);
	glVertex3f(480, 150, 0.0);
	glVertex3f(500, 150, 0.0);
	glVertex3f(500, 180, 0.0);
	glEnd( );

	glBegin(GL_QUAD_STRIP);
	glVertex3f(500, 230, 0.0);
	glVertex3f(500, 250, 0.0);
	glVertex3f(450, 230, 0.0);
	glVertex3f(450, 250, 0.0);

	glVertex3f(420, 200, 0.0);
	glVertex3f(400, 205, 0.0);
	glVertex3f(420, 180, 0.0);
	glVertex3f(400, 180, 0.0);

	glVertex3f(430, 170, 0.0);
	glVertex3f(430, 150, 0.0);
	glVertex3f(470, 170, 0.0);
	glVertex3f(470, 150, 0.0);
	glEnd( );
}

void MyDisplay()		
{
	glClear(GL_COLOR_BUFFER_BIT);	// 윈도우를 클리어할 색상 지정
	points();
	lines();
	line_strip();
	line_loop();
	polygon();
	quads();
	quad_strip();
	triangles();
	triangle_strip();
	triangle_fan();
	myName();			// 이름
	glFlush( );			// 큐에 저장된 명령어들 수행
}

int main( ) {
	glutInitWindowSize(1000, 300);		// 윈도우의 넢이와 넓이 설정
	glutInitWindowPosition(0, 0);		// 화면의 좌상단을 기준으로 한 window의 좌상단 좌표 설정
	glutCreateWindow("OpenGL Drawing Example");	// 윈도우 창을 디폴트 옵션으로 생성, 윈도우 제목 설정
	glutDisplayFunc(MyDisplay);			// 윈도우를 그릴 때마다 인자로 주어진 함수를 호출하도록 설정
	glOrtho(0, 1000, 0, 300, 1, -1);	// 0~1까지였던 화면의 종횡비를 맞추는 함수
	glutMainLoop( );					// 운영체제에 관련된 모든 내용을 프로그램이 종료할 때까지 처리하도록 설정하는 함수.

	return 0;
}