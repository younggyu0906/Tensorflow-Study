#include "timer.h"
#include "var_dec.h"

void MyTimer(int Value){
	if(robotRun){                       // 달리는 모션이면 타이머 함수 적용
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);
	}
}