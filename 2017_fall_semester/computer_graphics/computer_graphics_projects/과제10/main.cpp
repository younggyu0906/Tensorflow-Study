#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>
#include <math.h>

int	gWindowWidth = 800;		// �������� ���� ũ��
int	gWindowHeight = 800;	// �������� ���� ũ��

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;	// ���� �������� ����

void MyDisplay();
void bresenham_line(int x1, int y1, int x2, int y2);	// �극���� �˰���
void bDisplay(int x, int y, float gradient);			// �극���� �˰����� �� (x, y) ���, ��ó�� �ܰ� ����
void drawAxis();										// ��ǥ���� �׸��� �Լ�
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y);	// ���콺 Ŭ�� �̺�Ʈ ó��
void MyMouseMove(GLint X, GLint Y);								// ���콺 �巡�� �̺�Ʈ ó��

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(gWindowWidth, gWindowHeight);		// �������� ���̿� ���� ����
	glutInitWindowPosition(100, 50);		// ȭ���� �»���� �������� �� window�� �»�� ��ǥ ����
	glutCreateWindow("2013136021_�迵��_Bresenham_Algorithm_Test");	// ������ â�� ����Ʈ �ɼ����� ����, ������ ���� ����

	printf("2013136021_�迵��_Bresenham_Algorithm_Test\n");

	glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();						// ��ǥ �ʱ�ȭ
	glOrtho(0.0, gWindowWidth, 0.0, gWindowHeight, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);			// �����츦 �׸� ������ ���ڷ� �־��� �Լ��� ȣ���ϵ��� ����
	glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);

	glutMainLoop( );					// ��� ������ ���α׷��� ������ ������ ó���ϵ��� �����ϴ� �Լ�.
	return 0;
}

void MyDisplay()
{
	glViewport(0, 0, gWindowWidth, gWindowHeight);
	glClear(GL_COLOR_BUFFER_BIT);		// �����츦 Ŭ������ ���� ����
    
	glColor3f(0.7, 0.7, 0.7);			// ȸ��
	drawAxis();							// ��ǥ�� �׸���

	glColor3f(1.0, 0.0, 0.0);			// ������
	// �극���� �˰���
	bresenham_line(TopLeftX, TopLeftY, BottomRightX, BottomRightY);

	glFlush();			// ť�� ����� ��ɾ�� ����
}

void bresenham_line(int x1, int y1, int x2, int y2)
{
	int dx, dy, x, y, x_end, p, const1, const2;

	// ��ó�� �ܰ� ******************************************************
	// ��ó�� �ܰ迡���� ���Ⱑ 0�̻� 1���ϰ� �ƴ� ���鿡 ���� ���⸦ 0�̻� 1���Ϸ� ��ȯ�Ѵ�.
	// �˰��� ���� �� ��ó�� �ܰ��� �ݴ��� ���� �ϴ� ��ó�� �ܰ谡 �ʿ��ϴ�.
	float gradient = (float) (y2 - y1) / (x2 - x1);	// ����
	//printf("gradient = %f\n", gradient);		// ���� ���

	if(0 <= gradient && gradient <= 1) {		// �ƹ��͵� ���� �ʴ´�.
		//printf("0 <= gradient <= 1\n");
	}

	else if(gradient > 1) {						// y = x ��Ī ��ȯ
		int tmp1 = x1;
		int tmp2 = x2;

		x1 = y1;
		x2 = y2;

		y1 = tmp1;
		y2 = tmp2;
		//printf("1 < gradient < infinity\n");
	}
	else if(-1 <= gradient && gradient < 0) {	// y�� ��Ī ��ȯ
		x1 = - x1;
		x2 = - x2;
		//printf("-1 <= gradient < 0\n");
	}
	else {										// y = x ��Ī ��ȯ �� x�� ��Ī ��ȯ
		int tmp1 = x1;
		int tmp2 = x2;

		x1 = y1;
		x2 = y2;

		y1 = -tmp1;
		y2 = -tmp2;
		//printf("-infinity < gradient < -1\n");
	}
	// ��ó�� �ܰ� �� ************************************************
	
	// �극���� �˰��� ����
	dx = abs(x1 - x2);
	dy = abs(y1 - y2);

	p = 2 * dy - dx;

	const1 = 2 * dy;
	const2 = 2 * (dy - dx);

	// ���������� ����� ���� ����
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
	bDisplay(x, y, gradient);	// �� (x, y) ���, ��ó�� �ܰ� ����

	while (x < x_end) {
		x = x + 1;
		if(p < 0)
			p = p + const1;
		else {
			y = y + 1;
			p = p + const2;
		}
		bDisplay(x, y, gradient);	// �� (x, y) ���, ��ó�� �ܰ� ����
	}
}

void bDisplay(int x, int y, float gradient)
{
	// ��ó�� �ܰ�
	if(0 <= gradient && gradient <= 1) {		// �ƹ��͵� ���� �ʴ´�.
		//
	}
	else if(gradient > 1) {						// y = x ��Ī ��ȯ
		int tmp = x;
		x = y;
		y = tmp;
	}
	else if(-1 <= gradient && gradient < 0) {	// y�� ��Ī ��ȯ
		x = - x;
	}
	else {										// y = x ��Ī ��ȯ �� y�� ��Ī ��ȯ
		int tmp = x;
		x = -y;
		y = tmp;
	}
	// ��ó�� ��
	//drawPoint(x, y);				// �� �׸���
	glBegin(GL_POINTS);
		glVertex3f(x, y, 0.0);
	glEnd();
	
	//printf("(%4d, %4d)  ", x, y);	// �ܼ�â�� xy�� ���
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