#include "draw.h"
#include "event.h"
#include "mesh.h"
#include "var_dec.h"
#include "timer.h"
#include "setting.h"

static float sx, sy;

int windowX;
int windowY;

GLfloat WidthFactor;
GLfloat HeightFactor;

float scale;         // ase ������ �ҷ��� �� �� mesh ��ü�� ũ�⸦ ����Ʈ ���� �˸°� �����ϱ� ���� ����
float scaleRate;     // ���α׷����� z, x Ű�� ���� ����/�ܾƿ��� �ϱ� ���� ����

float rotateX1;   // 1�� ����Ʈ�� Y�� ���� ȸ�� ���� ����
float rotateY1;   // 1�� ����Ʈ�� X�� ���� ȸ�� ���� ����
float rotateX2;
float rotateY2;
float rotateX3;
float rotateY3;
float rotateX4;
float rotateY4;

int viewSelected;   // ���콺�� ����Ʈ �����ϱ� ���� ����
int viewClick;

float p_near;   // ���������� near ��
float p_scale;  // ���������� Ȯ��, ��Ҹ� ���� ����

float camEyeX;  // ī�޶� ���� �� ����
float camEyeY;
float camEyeZ;
float camAtX;
float camAtY;
float camAtZ;
float camUpX;
float camUpY;
float camUpZ;
int systemInt;  // �ý��� �� ����� ���� ����

Mesh *Body1;        // �κ��� �� ���� ��ü
Mesh *Body2;
Mesh *RightArm;
Mesh *LeftArm;
Mesh *RightLeg;
Mesh *LeftLeg;
Mesh *Head;
Mesh *Eyes;
Mesh *Nose;
Mesh *Button;
Mesh *Hair;

bool robotRun;            // �κ��� �޸��� �ִϸ��̼� ����
float robotWeight;        // �κ��� ����
char robotWeightStr[3];   // �κ��� ���Ը� ����ϱ� ���� ���ڿ� 
double robotSpeed;        // �κ��� �޸��� �ӵ�
char robotSpeedStr[3];    // �κ��� �ӵ��� ����ϱ� ���� ���ڿ� 
double robotRange;        // �κ��� �޸��� ������ ���ϱ� ���� ����

double dRadian;           // �� ������ ������ sin, cos ���� ���ϱ� ���� ���� ����
float sinR;               // sin, cos ������ �κ��� ��,�ٸ�, ��, �Ӹ��� �� ȸ�� ������ ����
float sinR2;
float cosR;
float d_cosR;
float d_sinR;

GLfloat mat_diffuse[6];
GLfloat mat_ambient[6];

void MyReshape(int, int);
void MyKeyboard(unsigned char, int, int);

void MySubMenu(int);   // ����,�ܾƿ�, �޸���,���� ���
void MySubMenu2(int);  // 4��° ����Ʈ�� ī�޶� ����
void MySubMenu3(int);  // Backface culling on, off
void MySubMenu4(int);  // �ո�, �޸� ��� ��� (Fill, Line, Point ����)
void MyMainMenu(int);

void mouse(int button, int state, int x, int y);
void motion(int x, int y);

int main(int argc, char **argv)
{
	windowX = 800;
	windowY = 800;
	WidthFactor = 1;
	HeightFactor = 1;
	camEyeX = 2.0;
	camEyeY = 1.0;
	camEyeZ = 2.0;
	camAtX = 0.5;
	camAtY = 0.5;
	camAtZ = 0.5;
	camUpX = 0;
	camUpY = 1;
	camUpZ = 0;
	viewSelected = 4;
	viewClick = 0;

	meshLoad();
	meshInit();

	cout << "--- Control Key ---\nRun / Stop : E \nRun Faster : W\nRun Slower : S\nIncrease Weight : A\n";
	cout << "Loose Weight : D\nZoom in : Z\nZoom out : X\nReload : R\nQuit : Q\n" ; 

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(windowX, windowY);
	glutInitWindowPosition(300, 100); 
	glutCreateWindow("2003136021 KYG #07-08");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	InitLight();       // ���� ����
	glEnable(GL_CULL_FACE);
  	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);  // ������ ���� ����, �������κ��� mesh �� �� �ȼ��� ���� ���� ����Ͽ� ���
	glShadeModel(GL_SMOOTH); 

	GLint MySubMenuID = glutCreateMenu(MySubMenu);
	
	glutAddMenuEntry("Zoom in", 1);
	glutAddMenuEntry("Zoom out", 2);
	glutAddMenuEntry("Run", 3);
	glutAddMenuEntry("Stop", 4);

	GLint MySubMenuID2 = glutCreateMenu(MySubMenu2);
	
	glutAddMenuEntry("Camera 1", 1);
	glutAddMenuEntry("Camera 2", 2);
	glutAddMenuEntry("Camera 3", 3);
	glutAddMenuEntry("Camera 4", 4);
	glutAddMenuEntry("default Camera", 5);
	
	GLint MySubMenuID3 = glutCreateMenu(MySubMenu3);
	
	glutAddMenuEntry("Backface Culling On", 1);
	glutAddMenuEntry("Backface Culling Off", 2);

	GLint MySubMenuID4 = glutCreateMenu(MySubMenu4);
	
	glutAddMenuEntry("Frontface Fill", 1);
	glutAddMenuEntry("Frontface Line", 2);
	glutAddMenuEntry("Frontface Point", 3);
	glutAddMenuEntry("Backface Fill", 4);
	glutAddMenuEntry("Backface Line", 5);
	glutAddMenuEntry("Backface Point", 6);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Motion", MySubMenuID);
	glutAddSubMenu("Camera", MySubMenuID2);
	glutAddSubMenu("BackfaceCulling", MySubMenuID3);
	glutAddSubMenu("PolygonMode", MySubMenuID4);
	glutAddMenuEntry("Reset", 1);
	glutAddMenuEntry("System Info", 2);
	glutAddMenuEntry("Exit", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutKeyboardFunc(MyKeyboard);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glOrtho (-1, 1, -1, 1, -4, 4);
	glutMainLoop();
  
	delete Body1;
	delete Body2;
	delete RightArm;
	delete LeftArm;
	delete RightLeg;
	delete LeftLeg;
	delete Head;
	delete Eyes;
	delete Nose;
	delete Hair;
	delete Button;

	return 0;
}

void MyReshape(int NewWidth, int NewHeight) {
	WidthFactor = (GLfloat)NewWidth / (GLfloat)800;
	HeightFactor = (GLfloat)NewHeight / (GLfloat)800;
	
	windowX = NewWidth;
	windowY = NewHeight;
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y){
	switch(KeyPressed){
	case 'Q':
		exit(0);
		break;
	case 'q':
		exit(0);
		break;
	case 'W':
		if(robotSpeed < 35)
			robotSpeed++;
		break;
	case 'w':
		if(robotSpeed < 35)
			robotSpeed++;
		break;
	case 'S':
		if(robotSpeed > 16)
			robotSpeed--;
		break;
	case 's':
		if(robotSpeed > 16)
			robotSpeed--;
		break;
	case 'A':
		if(robotWeight < 20)
			robotWeight++;
		break;
	case 'a':
		if(robotWeight < 20)
			robotWeight++;
		break;
	case 'D':
		if(robotWeight > 6)
			robotWeight--;
		break;
	case 'd':
		if(robotWeight > 6)
			robotWeight--;
		break;
	case 'E':
		if(robotRun == true){
			robotRun = false;
		}
		else {
			robotRun = true;
			glutPostRedisplay();
			glutTimerFunc(40, MyTimer, 1);  // Ÿ�̸� ����
		} 
		break;
	case 'e':
		if(robotRun == true){
			robotRun = false;
		}
		else {
			robotRun = true;
			glutPostRedisplay();
			glutTimerFunc(40, MyTimer, 1);  // Ÿ�̸� ����
		}
		break;
	case 'R':
		meshInit();      // �⺻ ��ġ�� 
		glutPostRedisplay();
		break;
	case 'r':
		meshInit();      // �⺻ ��ġ�� 
		glutPostRedisplay();
		break;
	case 'Z':
		if(scaleRate > 0.5)
			scaleRate -= 0.25;
		glutPostRedisplay();
		break;
	case 'z':
		if(scaleRate > 0.5)
			scaleRate -= 0.25;
		glutPostRedisplay();
		break;
	case 'X':
		if(scaleRate < 3)
			scaleRate += 0.25;
		glutPostRedisplay();
		break;
	case 'x':
		if(scaleRate < 3)
			scaleRate += 0.25;
		glutPostRedisplay();
		break;
	}
}


void MySubMenu(int entryID){
	switch(entryID){
	case 1:                               // ����
		if(scaleRate > 0.5)
			scaleRate -= 0.25;
		glutPostRedisplay();
		break;
	case 2:                               // �ܾƿ�
		if(scaleRate < 2)
			scaleRate += 0.25;
		glutPostRedisplay();
		break;
	case 3:
		if(robotRun == false){
			robotRun = true;
			glutPostRedisplay();
			glutTimerFunc(40, MyTimer, 1);  // Ÿ�̸� ����
		}
		break;
	case 4:
		if(robotRun == true)
			robotRun = false;
		break;
	}
}
void MySubMenu2(int entryID){              // ī�޶� ����
	switch(entryID){
	case 1:
		setCamera(0.0, 1.5, 2.0,  0.0, 0.0, -0.5, 0.0, 1.0, 0.0);
		glutPostRedisplay();
		break;
	case 2:
		setCamera(2.0, -0.5, 2.0,  0.5, 0.2, 0.5, 0.0, 1.0, 0.0);
		glutPostRedisplay();
		break;
	case 3:
		setCamera(-2.0, 0.5, -2.0,  -0.5, 0.2, -0.5, 0.0, 1.0, 0.0);
		glutPostRedisplay();
		break;
	case 4:
		setCamera(2.0, 2.0, 2.0,  0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glutPostRedisplay();
		break;
	case 5:
		setCamera(2.0, 1.0, 2.0,  0.5, 0.5, 0.5, 0.0, 1.0, 0.0);
		glutPostRedisplay();
		break;
	}
}
void MySubMenu3(int entryID){              // Backface culling ����
	switch(entryID){
	case 1:
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glutPostRedisplay();
		break;
	case 2:
		glDisable(GL_CULL_FACE);
		glutPostRedisplay();
		break;
	}
}
void MySubMenu4(int entryID){              // ������ ���
		switch(entryID){
	case 1:
		glPolygonMode(GL_FRONT, GL_FILL);
		glutPostRedisplay();
		break;
	case 2:
		glPolygonMode(GL_FRONT, GL_LINE);
		glutPostRedisplay();
		break;
	case 3:
		glPolygonMode(GL_FRONT, GL_POINT);
		glutPostRedisplay();
		break;
	case 4:
		glPolygonMode(GL_BACK, GL_FILL);
		glutPostRedisplay();
		break;
	case 5:
		glPolygonMode(GL_BACK, GL_LINE);
		glutPostRedisplay();
		break;
	case 6:
		glPolygonMode(GL_BACK, GL_POINT);
		glutPostRedisplay();
		break;
	}
}
void MyMainMenu(int entryID){
	switch(entryID){
	case 0:
		exit(0);
		break;
	case 1:
		meshInit();      // �⺻ ��ġ�� 
		glutPostRedisplay();
		break;
	case 2:
		glGetIntegerv(GL_MAX_CLIP_PLANES, &systemInt);
		cout << "--- System Info ---\nGL_MAX_CLIP_PLANES : " << systemInt << endl;
		glGetIntegerv(GL_DEPTH_BITS, &systemInt);
		cout << "GL_DEPTH_BITS : " << systemInt << endl;
		glGetIntegerv(GL_RED_BITS, &systemInt);
		cout << "GL_RED_BITS : " << systemInt << endl;
		glGetIntegerv(GL_GREEN_BITS, &systemInt);
		cout << "GL_GREEN_BITS : " << systemInt << endl;
		glGetIntegerv(GL_BLUE_BITS, &systemInt);
		cout << "GL_BLUE_BITS : " << systemInt << endl;
	}
}

void mouse(int button, int state, int x, int y)
{
    sx = x;
    sy = y;
	if(state == GLUT_DOWN){                 // ����Ʈ�� Ŭ�� ��
		if( x < windowX/2 ){
			if( y > (windowY/2))
				viewSelected = 3;
			else
				viewSelected = 1;
		}
		else {
			if( y > (windowY/2))
				viewSelected = 4;
			else
				viewSelected = 2;
		}
	}
	glutPostRedisplay();

}

void motion(int x, int y)
{
	switch(viewSelected){                 // ���õ� ����Ʈ
	case 1:
		rotateX1 += (x-sx)/2;
		rotateY1 += (y-sy)/2;
		break;
	case 2:
		rotateX2 += (x-sx)/2;
		rotateY2 += (y-sy)/2;
		break;
	case 3:
		rotateX3 += (x-sx)/2;
		rotateY3 += (y-sy)/2;
		break;
	case 4:
		p_scale += (x-sx)/200;      // ���콺 �¿��̵� �� �κ��� ������ ����
		p_near += (y-sy)/200;       // ���콺 �����̵� �� ���������� near �� ����
		//rotateX4 += (x-sx)/2;
		//rotateY4 += (y-sy)/2;
		break;
	}
    sx = x;
    sy = y;
	if(robotRun == false)
		glutPostRedisplay(); // display();
}