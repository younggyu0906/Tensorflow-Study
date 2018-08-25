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

float scale;         // ase 파일을 불러올 때 그 mesh 객체의 크기를 뷰포트 내에 알맞게 조정하기 위한 변수
float scaleRate;     // 프로그램에서 z, x 키를 통해 줌인/줌아웃을 하기 위한 변수

float rotateX1;   // 1번 뷰포트의 Y축 기준 회전 각도 변수
float rotateY1;   // 1번 뷰포트의 X축 기준 회전 각도 변수
float rotateX2;
float rotateY2;
float rotateX3;
float rotateY3;
float rotateX4;
float rotateY4;

int viewSelected;   // 마우스로 뷰포트 선택하기 위한 변수
int viewClick;

float p_near;   // 원근투상의 near 값
float p_scale;  // 원근투상의 확대, 축소를 위한 변수

float camEyeX;  // 카메라 설정 값 변수
float camEyeY;
float camEyeZ;
float camAtX;
float camAtY;
float camAtZ;
float camUpX;
float camUpY;
float camUpZ;
int systemInt;  // 시스템 값 출력을 위한 변수

Mesh *Body1;        // 로봇의 몸 부위 객체
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

bool robotRun;            // 로봇의 달리는 애니메이션 유무
float robotWeight;        // 로봇의 무게
char robotWeightStr[3];   // 로봇의 무게를 출력하기 위한 문자열 
double robotSpeed;        // 로봇의 달리는 속도
char robotSpeedStr[3];    // 로봇의 속도를 출력하기 위한 문자열 
double robotRange;        // 로봇이 달리는 정도를 구하기 위한 각도

double dRadian;           // 위 각도의 변수로 sin, cos 값을 구하기 위한 라디안 변수
float sinR;               // sin, cos 값으로 로봇의 팔,다리, 몸, 머리의 각 회전 각도를 조절
float sinR2;
float cosR;
float d_cosR;
float d_sinR;

GLfloat mat_diffuse[6];
GLfloat mat_ambient[6];

void MyReshape(int, int);
void MyKeyboard(unsigned char, int, int);

void MySubMenu(int);   // 줌인,줌아웃, 달리기,정지 모션
void MySubMenu2(int);  // 4번째 뷰포트의 카메라 설정
void MySubMenu3(int);  // Backface culling on, off
void MySubMenu4(int);  // 앞면, 뒷면 출력 방식 (Fill, Line, Point 설정)
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
	InitLight();       // 조명값 설정
	glEnable(GL_CULL_FACE);
  	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);  // 숨겨진 면을 제거, 시점으로부터 mesh 의 각 픽셀의 깊이 값을 계산하여 출력
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
			glutTimerFunc(40, MyTimer, 1);  // 타이머 시작
		} 
		break;
	case 'e':
		if(robotRun == true){
			robotRun = false;
		}
		else {
			robotRun = true;
			glutPostRedisplay();
			glutTimerFunc(40, MyTimer, 1);  // 타이머 시작
		}
		break;
	case 'R':
		meshInit();      // 기본 위치로 
		glutPostRedisplay();
		break;
	case 'r':
		meshInit();      // 기본 위치로 
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
	case 1:                               // 줌인
		if(scaleRate > 0.5)
			scaleRate -= 0.25;
		glutPostRedisplay();
		break;
	case 2:                               // 줌아웃
		if(scaleRate < 2)
			scaleRate += 0.25;
		glutPostRedisplay();
		break;
	case 3:
		if(robotRun == false){
			robotRun = true;
			glutPostRedisplay();
			glutTimerFunc(40, MyTimer, 1);  // 타이머 시작
		}
		break;
	case 4:
		if(robotRun == true)
			robotRun = false;
		break;
	}
}
void MySubMenu2(int entryID){              // 카메라 선택
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
void MySubMenu3(int entryID){              // Backface culling 선택
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
void MySubMenu4(int entryID){              // 폴리곤 모드
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
		meshInit();      // 기본 위치로 
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
	if(state == GLUT_DOWN){                 // 뷰포트를 클릭 시
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
	switch(viewSelected){                 // 선택된 뷰포트
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
		p_scale += (x-sx)/200;      // 마우스 좌우이동 시 로봇의 사이즈 조정
		p_near += (y-sy)/200;       // 마우스 상하이동 시 원근투상의 near 값 조정
		//rotateX4 += (x-sx)/2;
		//rotateY4 += (y-sy)/2;
		break;
	}
    sx = x;
    sy = y;
	if(robotRun == false)
		glutPostRedisplay(); // display();
}