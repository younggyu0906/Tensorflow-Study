#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>

int		gWindowWidth = 500;
int		gWindowHeight = 500;
int		chooseFigure = 0;		// ������ ������ ���� ����
int		pX, pY;				// ���콺 ��ǥ�� ����ϱ� ���� ����
bool	bPressed = false;	// ���콺�� ���ȴ����� �Ǻ��ϴ� ����
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyMainMenu(int entryID);		// ����1 �޴�
void MyDisplay();
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y);
void MyMouseMove(GLint X, GLint Y);
float calcX(float x);		// ����1 ���� �׸��⸦ ���� ���콺�� x��ǥ�� ����ϴ� �Լ�
float calcY(float y);		// ����1 ���� �׸��⸦ ���� ���콺�� y��ǥ�� ����ϴ� �Լ�
void MyRobot();		// �κ��� �Ӹ��� ����, ��, �ٸ��� �׸��� ���� ������ ������ robotParts() �Լ��� ȣ���ϴ� �Լ� 
void robotParts(float x, float y, float radius, float scaleY, float angle);	// �κ��� �Ӹ��� ����, ��, �ٸ��� �׸��� ���� �Լ�

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(gWindowWidth, gWindowHeight);		// �������� ���̿� ���� ����
	glutInitWindowPosition(0, 0);		// ȭ���� �»���� �������� �� window�� �»�� ��ǥ ����
	glutCreateWindow("OpenGL Drawing Example");	// ������ â�� ����Ʈ �ɼ����� ����, ������ ���� ����
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();						// ��ǥ �ʱ�ȭ

	glutDisplayFunc(MyDisplay);			// �����츦 �׸� ������ ���ڷ� �־��� �Լ��� ȣ���ϵ��� ����
	glutMouseFunc(MyMouseClick);		// mouse �ݹ�
	glutMotionFunc(MyMouseMove);

	
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);		// �޴� ����
	glutAddMenuEntry("Draw Line", 1);
	glutAddMenuEntry("Draw Rectangle", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

	glutMainLoop( );					// �ü���� ���õ� ��� ������ ���α׷��� ������ ������ ó���ϵ��� �����ϴ� �Լ�.
	return 0;
}


// �κ��� �Ӹ��� ����, ��, �ٸ��� �׸��� ���� �Լ�
// �κ��� �Ӹ��� ����, ��, �ٸ��� ����� ���� ũ�⸸ �ٸ��Ƿ�
// �ϳ��� �Լ��� �����Ͽ� ������ ���� ���ڷ� �Ѱ��־� �����Ͽ����ϴ�. 
void robotParts(float x, float y, float radius, float scaleY, float angle = 0) {
	glPushMatrix();
	{
		glTranslatef(x, y, 0);										// ���� �߽� ��ǥ
		glutWireSphere(radius, 20, 20);								// �Ű������� ���� ������ ������ �� �׸���
		glPushMatrix();
		{
			glRotatef(angle, 0, 0, 1);								// �Ű������� ���� ���� �� ��ŭ z���� �߽����� ȸ��
			glPushMatrix();
			{
				glTranslatef(0, - (scaleY * radius + radius), 0);	// ť�긦 �׸��� ���Ͽ� ��ǥ �̵�, glTranslatef�� ������� ��ǥ
				glScalef(1.0, scaleY, 1.0);							// ũ�� ��ȯ
				glutWireCube(2 * radius);							// ť�� �׸���
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}


void MyRobot() {			// �κ��� �Ӹ��� ����, ��, �ٸ��� �׸��� ���� ������ ������ robotParts() �Լ��� ȣ���ϴ� �Լ� 
	glPushMatrix();
	{
		robotParts(		0,	  0.8,	 0.2,	2.0);			// �Ӹ�
		robotParts(	- 0.3,	  0.5,	 0.1,	3.0,	- 45);	// ����
		robotParts(	  0.3,	  0.5,	 0.1,	3.0,	  90);	// ������
		robotParts(	- 0.1,	- 0.3,	 0.1,	3.0,	- 45);	// �޴ٸ�
		robotParts(	  0.1,	- 0.3,	 0.1,	3.0,	  45);	// �����ٸ�
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
	glClear(GL_COLOR_BUFFER_BIT);	// �����츦 Ŭ������ ���� ����
    glColor3f(0.3, 0.3, 0.3);
	// ����1�� 2�� ����Ʈ�� ������ �����Ͽ����� �ּ�ó�� �Ͽ����ϴ�.
	
	// ����Ʈ�� ��ġ, ���� ����Ʈ
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

	// ����Ʈ�� ��ġ, ������ ����Ʈ
	//glViewport(gWindowWidth / 2, 0, gWindowWidth / 2, gWindowHeight);
	

	//MyRobot();
	glFlush();			// ť�� ����� ��ɾ�� ����
}

// ����1�� �����Ͽ����� �ּ�ó���Ͽ����ϴ�.


float calcX(float x) {												// ����1 ���� �׸��⸦ ���� ���콺�� x��ǥ�� ����ϴ� �Լ�
	float calcX = (x / gWindowWidth) * 2 - 1;
	if (calcX > 1)
		return 1;
	else if (calcX < -1)
		return -1;
	else
		return calcX;
}

float calcY(float y) {												// ����1 ���� �׸��⸦ ���� ���콺�� y��ǥ�� ����ϴ� �Լ�
	float calcY = ((gWindowHeight - y) / gWindowHeight) * 2 - 1;
	if (calcY > 1)
		return 1;
	else if (calcY < -1)
		return -1;
	else
		return calcY;
}

void MyMainMenu(int entryID) {										// ����1 �޴�
    chooseFigure = entryID;		// ���� ����
	TopLeftX = 0;				// ��ǥ �ʱ�ȭ
	TopLeftY = 0;				// ��ǥ �ʱ�ȭ
	BottomRightX = 0;			// ��ǥ �ʱ�ȭ
	BottomRightY = 0;			// ��ǥ �ʱ�ȭ
    glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {	// ����1 ���콺 �ݹ�(���� �׸���)
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
		//printf("%d %d\n\n", TopLeftX, TopLeftY);
    }
}

void MyMouseMove(GLint X, GLint Y) {								// ����1 ���콺 �ݹ�(���� �׸���)
    BottomRightX = X;
    BottomRightY = Y;
	//printf("%d %d\n\n", BottomRightX, BottomRightY);
    glutPostRedisplay();
}
