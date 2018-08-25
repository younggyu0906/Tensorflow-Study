/*
#include "event.h"
#include "var_dec.h"
#include "timer.h"
#include "mesh.h"
#include "setting.h"

static float sx, sy;

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
}*/