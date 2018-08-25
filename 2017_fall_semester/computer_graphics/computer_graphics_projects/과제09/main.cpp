#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>

int		gWindowWidth = 800;		// �������� ���� ũ��
int		gWindowHeight = 800;	// �������� ���� ũ��

GLfloat wx_min =	-0.5;	// �簢���� ���� ����
GLfloat wy_min =	-0.5;	// �簢���� ���� ���� 
GLfloat wx_max =	 0.5;	// �簢���� ���� ��
GLfloat wy_max =	 0.5;	// �簢���� ���� ��

GLfloat line1[4] = {0.0, 0.8, -0.8, 0.0};	// ��1�� x y ����, �� ��ǥ
GLfloat line2[4] = {0.1, 0.7, -0.3, 0.1};	// ��2�� x y ����, �� ��ǥ 
GLfloat line3[4] = {0.2, 0.2, -0.2, -0.2};	// ��3�� x y ����, �� ��ǥ
GLfloat line4[4] = {0.7, -0.8, 0.8, 0.0};	// ��4�� x y ����, �� ��ǥ
GLfloat line5[4] = {0.3, 0.8, 0.8, 0.3};	// ��5�� x y ����, �� ��ǥ

typedef int OutCode;
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

void MyDisplay();
void drawLines(GLfloat sx, GLfloat sy, GLfloat ex, GLfloat ey);		// ���� �������� �� ���� �Ű������� �޴� �� �׸��� �Լ�
void drawRec(GLfloat sx = wx_min, GLfloat sy = wy_min, GLfloat ex = wx_max, GLfloat ey = wy_max);	// �簢�� �׸��� �Լ�
void MyKeyboard(unsigned char KeyPressed, int X, int Y);			// Ű���� �ݹ�

OutCode ComputeOutCode(double x, double y);		// �� x, y�� ���� ��Ʈ �ڵ带 ���
void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1);	// ���������˰���

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(gWindowWidth, gWindowHeight);		// �������� ���̿� ���� ����
	glutInitWindowPosition(100, 50);		// ȭ���� �»���� �������� �� window�� �»�� ��ǥ ����
	glutCreateWindow("2013136021_�迵��_Cohen-Sutherland Test");	// ������ â�� ����Ʈ �ɼ����� ����, ������ ���� ����

	glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();						// ��ǥ �ʱ�ȭ
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutKeyboardFunc(MyKeyboard);
	glutDisplayFunc(MyDisplay);			// �����츦 �׸� ������ ���ڷ� �־��� �Լ��� ȣ���ϵ��� ����

	glutMainLoop( );					// ��� ������ ���α׷��� ������ ������ ó���ϵ��� �����ϴ� �Լ�.
	return 0;
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	// �����츦 Ŭ������ ���� ����
    
	glColor3f(0.3, 0.3, 0.3);		// ȸ��
	drawRec();						// �簢�� �׸��� (������)

	glColor3f(0.0, 0.0, 1.0);		// �Ķ���
	drawLines(line1[0], line1[1], line1[2], line1[3]);	// ��1 �׸���
	drawLines(line2[0], line2[1], line2[2], line2[3]);	// ��2 �׸���
	drawLines(line3[0], line3[1], line3[2], line3[3]);	// ��3 �׸���
	drawLines(line4[0], line4[1], line4[2], line4[3]);	// ��4 �׸���
	drawLines(line5[0], line5[1], line5[2], line5[3]);	// ��5 �׸���

	glFlush();			// ť�� ����� ��ɾ�� ����
}

// ���� ��ǥ�� �Ű������� �޾� ���� �׸��� �Լ�
void drawLines(GLfloat sx, GLfloat sy, GLfloat ex, GLfloat ey)
{
	glBegin(GL_LINES);
		glVertex3f(sx, sy, 0.0);
		glVertex3f(ex, ey, 0.0);
	glEnd();
}

// �簢���� ��ǥ�� �Ű������� �޾� �簢���� �׸��� �Լ�
void drawRec(GLfloat sx, GLfloat sy, GLfloat ex, GLfloat ey)
{
	glBegin(GL_LINE_LOOP);
		glVertex3f(sx, sy, 0.0);
		glVertex3f(sx, ey, 0.0);
		glVertex3f(ex, ey, 0.0);
		glVertex3f(ex, sy, 0.0);
	glEnd();
}

// Ű���� �ݹ� 'q' || 'Q' || 'ESC' �Է½� ����, 'c', 'C' �Է½� ��������� �˰��� ����
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case 27:                //'esc' Ű�� �ƽ�Ű �ڵ� ��
        exit(0); break;
	case 'c':
	case 'C':
		glClear(GL_COLOR_BUFFER_BIT);	// �����츦 Ŭ����
		CohenSutherlandLineClipAndDraw(line1[0], line1[1], line1[2], line1[3]);	// ��1 ���������
		CohenSutherlandLineClipAndDraw(line2[0], line2[1], line2[2], line2[3]);	// ��2 ���������
		CohenSutherlandLineClipAndDraw(line3[0], line3[1], line3[2], line3[3]);	// ��3 ���������
		CohenSutherlandLineClipAndDraw(line4[0], line4[1], line4[2], line4[3]);	// ��4 ���������
		CohenSutherlandLineClipAndDraw(line5[0], line5[1], line5[2], line5[3]);	// ��5 ���������
		break;
	default:
		break;
    }
}

OutCode ComputeOutCode(double x, double y)
{
    OutCode code;
    
    code = INSIDE;			// Ŭ�� ������ �ȿ� �ִ� ������ �ʱ�ȭ
    
    if (x < wx_min)           
        code |= LEFT;		// Ŭ�� �������� ��������
    else if (x > wx_max)      
        code |= RIGHT;		// Ŭ�� �������� ����������
    if (y < wy_min)          
        code |= BOTTOM;		// Ŭ�� �������� �Ʒ�������
    else if (y > wy_max)     
        code |= TOP;		// Ŭ�� �������� ��������
    
    return code;
}


void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1)
{
	// Ŭ�� ������ �ܺο� �ִ� �� ���
    OutCode outcode0 = ComputeOutCode(x0, y0);
    OutCode outcode1 = ComputeOutCode(x1, y1);
    bool accept = false;
    double x, y;

    while (true) {
        if (!(outcode0 | outcode1)) {	// ��Ʈ���� OR�� 0�̸� ���� ����
            accept = true;
            break;
        } else if (outcode0 & outcode1) {	// ��Ʈ���� AND�� 0�� �ƴϸ� ������ ����
            break;
        } else {	// �� ���� �׽�Ʈ�� �ش����� �ʴ� ��� ���� Ŭ�� ���
            OutCode outcodeOut = outcode0? outcode0 : outcode1;
            
            if (outcodeOut & TOP) {   
                x = x0 + (x1 - x0) * (wy_max - y0) / (y1 - y0);
                y = wy_max;
            } else if (outcodeOut & BOTTOM) { 
                x = x0 + (x1 - x0) * (wy_min - y0) / (y1 - y0);
                y = wy_min;
            } else if (outcodeOut & RIGHT) { 
                y = y0 + (y1 - y0) * (wx_max - x0) / (x1 - x0);
                x = wx_max;
            } else if (outcodeOut & LEFT) { 
                y = y0 + (y1 - y0) * (wx_min - x0) / (x1 - x0);
                x = wx_min;
            }

            if (outcodeOut == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = ComputeOutCode(x0, y0);
            } else {
                x1 = x;
                y1 = y;
                outcode1 = ComputeOutCode(x1, y1);
            }
        }
    }
    if (accept) {
		// �� �׸���
		glColor3f(0.3, 0.3, 0.3);
		drawRec();

        glColor3f(1.0, 0.0, 0.0);
		drawLines(x0, y0, x1, y1);

        glFlush();
    }
} 

// ���� �������� �˰��� ���� http://msparkms.tistory.com/entry/Cohen%E2%80%93Sutherland-algorithmWiki