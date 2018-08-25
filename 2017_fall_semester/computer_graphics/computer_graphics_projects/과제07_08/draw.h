#include <iostream>
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <string.h>
#include <math.h>

#include "ase.h"

using namespace std;

extern void MyDisplay(void);

extern void drawRobot();        // �κ� ��ü ���

extern void drawBody1();         // �κ� �Ӹ� ���
extern void drawBody2();         // �κ� ���� ���
extern void drawRightArm();
extern void drawLeftArm();
extern void drawRightLeg();
extern void drawLeftLeg();
extern void drawHead();
extern void drawEyes();
extern void drawNose();
extern void drawHair();
extern void drawButton();

extern void drawGridPlane();   // �ٴ����
extern void drawString (const char *);  // ���ڿ� ���
extern void drawCoord(int);    // x,y,z �� ���