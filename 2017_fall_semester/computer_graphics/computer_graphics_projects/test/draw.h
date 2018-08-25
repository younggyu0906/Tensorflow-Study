#include <iostream>
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <string.h>
#include <math.h>

#include "ase.h"

using namespace std;

extern void MyDisplay(void);

extern void drawRobot();        // 로봇 전체 출력

extern void drawBody1();         // 로봇 머리 출력
extern void drawBody2();         // 로봇 몸통 출력
extern void drawRightArm();
extern void drawLeftArm();
extern void drawRightLeg();
extern void drawLeftLeg();
extern void drawHead();
extern void drawEyes();
extern void drawNose();
extern void drawHair();
extern void drawButton();

extern void drawGridPlane();   // 바닥출력
extern void drawString (const char *);  // 문자열 출력
extern void drawCoord(int);    // x,y,z 축 출력