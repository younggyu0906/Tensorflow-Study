#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

int		gWindowWidth = 1000;
int		gWindowHeight = 500;
int		pX, pY;
int		chooseFigure = 0;		// ���� ����, 1 == cube, 2 == Sphere, 3 == Torus, 4 == Corn, 5 == Teapot
bool	bPressed = false;

void myName(int w, int h)			// �̸� �̴ϼ� KYG
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

	gWindowWidth = NewWidth;		// �������� ���� ũ�⸦ ���ο� ���� ũ��� ���� 
	gWindowHeight = NewHeight;		// �������� ���� ũ�⸦ ���ο� ���� ũ��� ����

    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();  // ������ķ� �ٲپ��ִ� ��
    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
        -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed){
    case 'Q': case 'q': case 27:	// 27 == 'esc' Ű�� �ƽ�Ű �ڵ� ��
        exit(0);					// ����
		break;
	case 'c' : case 'C' :			// 'c' || 'C' �Է½�
		chooseFigure = 1;			// chooseFigure = 1�� �ʱ�ȭ (cube ����)
		break;
	case 's' : case 'S' :			// 's' || 'S' �Է½�
		chooseFigure = 2;			// chooseFigure = 2�� �ʱ�ȭ (sphere ����)
		break;
	case 't' : case 'T' :			// 't' || 'T' �Է½�
		chooseFigure = 3;			// chooseFigure = 3�� �ʱ�ȭ (torus ����)
		break;
	case 'n' : case 'N' :			// 'n' || 'N' �Է½�
		chooseFigure = 4;			// chooseFigure = 4�� �ʱ�ȭ (cone ����)
		break;
	case 'p' : case 'P' :			// 'p' || 'P' �Է½�
		chooseFigure = 5;			// chooseFigure = 5�� �ʱ�ȭ (teapot ����)
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
	glClear(GL_COLOR_BUFFER_BIT);	// �����츦 Ŭ������ ���� ����
	glViewport(0, 0, gWindowWidth / 2, gWindowHeight);	// ����Ʈ�� ��ġ
	myName(0, 0);			// �̸�
	glViewport(gWindowWidth / 2, 0, gWindowWidth / 2, gWindowHeight);	// ����Ʈ�� ��ġ
	if(chooseFigure == 1)
		glutWireCube(0.5);					// ť��(���� ũ�Ⱑ 0.5)
	else if(chooseFigure == 2)
		glutWireSphere(0.5, 30, 30);		// ��(������ = 0.5, z���� �߽����� ����ȭ�� ��(����) = 30, z���� ������ ��ȹ ��(�浵) = 30)
	else if(chooseFigure == 3)
		glutWireTorus(0.2, 0.5, 30, 30);	// ��ȯ��
	else if(chooseFigure == 4)
		glutWireCone(0.5, 0.5, 30, 30);		// ����
	else if(chooseFigure == 5)
		glutWireTeapot(0.5);				// ������
	glFlush( );			// ť�� ����� ��ɾ�� ����
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(gWindowWidth, gWindowHeight);		// �������� ���̿� ���� ����
	glutInitWindowPosition(0, 0);		// ȭ���� �»���� �������� �� window�� �»�� ��ǥ ����
	glutCreateWindow("OpenGL Drawing Example");	// ������ â�� ����Ʈ �ɼ����� ����, ������ ���� ����
	//glOrtho(0, gWindowWidth, 0, gWindowHeight, 1, -1);	// 0~1�������� ȭ���� ��Ⱦ�� ���ߴ� �Լ�
	
	glutDisplayFunc(MyDisplay);			// �����츦 �׸� ������ ���ڷ� �־��� �Լ��� ȣ���ϵ��� ����
	glutReshapeFunc(MyReshape);			// reshape �ݹ�
	glutKeyboardFunc(MyKeyboard);		// keyboard �ݹ�
	glutMouseFunc(MyMouseClick);		// mouse �ݹ�
    glutMotionFunc(MyMouseMove);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);		// �޴� ����
    glutAddMenuEntry("Draw Cube", 1);
	glutAddMenuEntry("Draw Sphere", 2);
	glutAddMenuEntry("Draw Torus", 3);
    glutAddMenuEntry("Draw Cone", 4);
	glutAddMenuEntry("Draw Teapot", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop( );					// �ü���� ���õ� ��� ������ ���α׷��� ������ ������ ó���ϵ��� �����ϴ� �Լ�.
	return 0;
}