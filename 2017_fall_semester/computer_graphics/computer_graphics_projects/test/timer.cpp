#include "timer.h"
#include "var_dec.h"

void MyTimer(int Value){
	if(robotRun){                       // �޸��� ����̸� Ÿ�̸� �Լ� ����
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);
	}
}