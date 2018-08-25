#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

void points()		// ��
{
	glBegin(GL_POINTS);
	glVertex3f(50, 70, 0.0);
	glVertex3f(20, 50, 0.0);
	glVertex3f(70, 60, 0.0);
	glVertex3f(50, 30, 0.0);
	glVertex3f(40, 20, 0.0);
	glEnd( );
}

void lines()		// ��
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

void line_strip()	// ����� ��
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

void line_loop()	// ����� ��ȯ ��
{
	glBegin(GL_LINE_LOOP);
	glVertex3f(320, 50, 0.0);
	glVertex3f(380, 60, 0.0);
	glVertex3f(350, 70, 0.0);
	glVertex3f(350, 40, 0.0);
	glVertex3f(340, 30, 0.0);
	glEnd( );
}

void polygon()		// �ٰ���
{
	glBegin(GL_POLYGON);
	glVertex3f(430, 70, 0.0);
	glVertex3f(480, 80, 0.0);
	glVertex3f(480, 50, 0.0);
	glVertex3f(450, 30, 0.0);
	glVertex3f(430, 40, 0.0);
	glEnd( );
}

void quads()		// �簢�� 
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

void quad_strip()	// ����� �簢��
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

void triangles()	// �ﰢ��
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

void triangle_strip()	// ����� �ﰢ�� 
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

void triangle_fan()		// ��ä�� �ﰢ��
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

void myName()			// �̸� �̴ϼ�
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
	glClear(GL_COLOR_BUFFER_BIT);	// �����츦 Ŭ������ ���� ����
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
	myName();			// �̸�
	glFlush( );			// ť�� ����� ��ɾ�� ����
}

int main( ) {
	glutInitWindowSize(1000, 300);		// �������� ���̿� ���� ����
	glutInitWindowPosition(0, 0);		// ȭ���� �»���� �������� �� window�� �»�� ��ǥ ����
	glutCreateWindow("OpenGL Drawing Example");	// ������ â�� ����Ʈ �ɼ����� ����, ������ ���� ����
	glutDisplayFunc(MyDisplay);			// �����츦 �׸� ������ ���ڷ� �־��� �Լ��� ȣ���ϵ��� ����
	glOrtho(0, 1000, 0, 300, 1, -1);	// 0~1�������� ȭ���� ��Ⱦ�� ���ߴ� �Լ�
	glutMainLoop( );					// �ü���� ���õ� ��� ������ ���α׷��� ������ ������ ó���ϵ��� �����ϴ� �Լ�.

	return 0;
}