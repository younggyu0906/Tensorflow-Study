#include "draw.h"
#include "var_dec.h"
#include "setting.h"

#define PI   (3.14159265358979323846)

static float tx = 0.0f;
static float ty = 0.0f;

void MyDisplay() {

	if(robotRun == true){
		robotRange += robotSpeed;
		if(robotRange > 360)
			robotRange -= 360;
		dRadian = (PI/180.0) * robotRange;
		sinR = (float)sin(dRadian);
		sinR2 = (float)sin(2*dRadian);
		cosR =  (float)cos(dRadian);

		dRadian = (PI/180.0) * (robotRange - 180);
		d_cosR = (float)cos(dRadian);
		d_sinR = (float)sin(dRadian);
	}

	glClearColor(0.7, 0.8 ,1.0 ,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho (-1 * WidthFactor, 1 * WidthFactor, -1 * HeightFactor, 1 * HeightFactor, -4, 4);

	glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
	

	glViewport(0, windowY/2, windowX/2, windowY/2);        // 1 뷰포트
		if(viewSelected == 1){
			setColor(1.0, 0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			glVertex3f(-0.95, -0.95, 0.0);  // 해당 뷰포트 마우스로 클릭되었음을 나타내는 사각형
			glVertex3f(0.95, -0.95, 0.0);  
			glVertex3f(0.95, -0.95, 0.0);  
			glVertex3f(0.95, 0.95, 0.0);  
			glVertex3f(0.95, 0.95, 0.0);  
			glVertex3f(-0.95, 0.95, 0.0); 
			glVertex3f(-0.95, 0.95, 0.0);  
			glVertex3f(-0.95, -0.95, 0.0);  
			glEnd();
		}
		glPushMatrix();
			gluLookAt(0.0, 0.5, 1.0,  0.0, 0.5, 0.0,  0.0, 1.0, 0.0 );

			glPushMatrix();

				glTranslated (0, 0.4, 0);
				glScalef (0.6f, 0.6f, 0.6f);
				glRotatef (rotateY1, 1, 0, 0);
				glRotatef (rotateX1, 0, 1, 0); 

				drawRobot();                  // 로봇 출력
			glPopMatrix();

			
			drawCoord (1);
			drawGridPlane();

		glPopMatrix();


	glViewport(windowX/2, windowY/2, windowX/2, windowY/2);        // 2 뷰포트
		if(viewSelected == 2){
			setColor(1.0, 0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			glVertex3f(-0.95, -0.95, 0.0);  // 해당 뷰포트 마우스로 클릭되었음을 나타내는 사각형
			glVertex3f(0.95, -0.95, 0.0);  
			glVertex3f(0.95, -0.95, 0.0);  
			glVertex3f(0.95, 0.95, 0.0);  
			glVertex3f(0.95, 0.95, 0.0);  
			glVertex3f(-0.95, 0.95, 0.0); 
			glVertex3f(-0.95, 0.95, 0.0);  
			glVertex3f(-0.95, -0.95, 0.0);  
			glEnd();
		}
		glPushMatrix();
			gluLookAt(1.0, 0.5, 0.0,  0.0, 0.5, 0.0,  0.0, 1.0, 0.0 );

			glPushMatrix();

				glTranslated (0, 0.4, 0);
				glScalef (0.6f, 0.6f, 0.6f);
				glRotatef (rotateY2, 1, 0, 0);
				glRotatef (rotateX2, 0, 1, 0); 

				drawRobot();                  // 로봇 출력
			glPopMatrix();

			
			drawCoord (1);
			drawGridPlane();

		glPopMatrix();


	glViewport(0, 0, windowX/2, windowY/2);        // 3 뷰포트
		if(viewSelected == 3){
			setColor(1.0, 0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			glVertex3f(-0.95, -0.95, 0.0);  // 해당 뷰포트 마우스로 클릭되었음을 나타내는 사각형
			glVertex3f(0.95, -0.95, 0.0);  
			glVertex3f(0.95, -0.95, 0.0);  
			glVertex3f(0.95, 0.95, 0.0);  
			glVertex3f(0.95, 0.95, 0.0);  
			glVertex3f(-0.95, 0.95, 0.0); 
			glVertex3f(-0.95, 0.95, 0.0);  
			glVertex3f(-0.95, -0.95, 0.0);  
			glEnd();
		}
		glPushMatrix();
			gluLookAt(0.0, 1.0, 0.0,  0.0, 0.0, 0.0,  0.0, 0.0, -1.0 );

			glPushMatrix();

				glTranslated (0, 0.8, 0);
				glScalef (0.6f, 0.6f, 0.6f);
				glRotatef (rotateY3, 1, 0, 0);
				glRotatef (rotateX3, 0, 1, 0); 

				drawRobot();                  // 로봇 출력
			glPopMatrix();

			
			drawCoord (1);
			drawGridPlane();

		glPopMatrix();		
	



	glViewport(windowX/2, 0, windowX/2, windowY/2);        // 4 뷰포트
		if(viewSelected == 4){
			setColor(1.0, 0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			glVertex3f(-0.95, -0.95, 0.0);  // 해당 뷰포트 마우스로 클릭되었음을 나타내는 사각형
			glVertex3f(0.95, -0.95, 0.0);  
			glVertex3f(0.95, -0.95, 0.0);  
			glVertex3f(0.95, 0.95, 0.0);  
			glVertex3f(0.95, 0.95, 0.0);  
			glVertex3f(-0.95, 0.95, 0.0); 
			glVertex3f(-0.95, 0.95, 0.0);  
			glVertex3f(-0.95, -0.95, 0.0);  
			glEnd();
		}
		
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			
			glFrustum(-0.1 * WidthFactor, 0.1 * WidthFactor, -0.1 * HeightFactor, 0.1 * HeightFactor, p_near, 20);

			glMatrixMode (GL_MODELVIEW);

			glPushMatrix();

				gluLookAt(camEyeX, camEyeY, camEyeZ, camAtX, camAtY, camAtZ, camUpX, camUpY, camUpZ);

				glScalef (1.0f / scaleRate, 1.0f / scaleRate, 1.0f / scaleRate);
				glPushMatrix();

					glTranslated (0, 0.2, 0);
					glScalef (0.8f / p_scale, 0.8f / p_scale, 0.8f / p_scale);

					drawRobot();                  // 로봇 출력
				glPopMatrix();
			
				drawCoord (1);
				drawGridPlane();

			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
		glPopMatrix();

	glutSwapBuffers();
	glFlush();
}

void drawRobot(){
	
	glPushMatrix();
	{
		setColor(1.0, 1.0, 1.0, 1.0);
		glTranslated(0.0, (sinR2 * 0.08 + -0.6), 0);      // 몸통의 위치 설정
		glRotatef (sinR2*(20-robotWeight) + 10, -1, 0, 0);       // 몸통의 상하회전 설정
		glRotatef (sinR*(40-robotWeight), 0, 1, 0);             // 몸통의 좌우회전 설정
		glRotatef (sinR*(40-robotWeight), 0, 0, 1);

		drawBody2();                            // 몸통2 출력

		glPushMatrix();
		{
			setColor(0, 0, 0, 1.0);
			glTranslated(0, -0.05, 0.5);
			glScalef (1.0f, 1.0f, 3.0f);
			glRotatef (90, 1, 0, 0);
				
			drawButton();                   // 단추 출력
		}
		glPopMatrix();

		glPushMatrix();
		{
			setColor(0, 0, 0, 1.0);
			glTranslated(0, 0.09, 0.5);
			glScalef (1.0f, 1.0f, 3.0f);
			glRotatef (90, 1, 0, 0);
				
			drawButton();                   // 단추 출력
		}
		glPopMatrix();

		glPushMatrix();
		{
			setColor(1.0, 1.0, 1.0, 1.0);
			glTranslated(0.0, 0.45, 0.05);
			glScalef (1.0f, 1.0f, 1.0f);
			glRotatef (cosR*20, 0, 1, 0);

			drawBody1();                       // 몸통1 출력
			{
				glPushMatrix();
				{
					setColor(0.6, 0.45, 0.12, 1.0);
					glTranslated(-0.2, 0, 0.0);
					glScalef (1.0f, 1.0f, 1.0f);
					glRotatef (45, 0, 0, 1);
					glRotatef (cosR*(70-robotWeight), 1, 0, 0);
					glRotatef (sinR*5 + 5, 0, 1, 0);

					drawRightArm();                                   // 오른팔 출력
				}
				glPopMatrix();

				glPushMatrix();
				{
					setColor(0.6, 0.45, 0.12, 1.0);
					glTranslated(0.2, 0, 0.0);
					glScalef (1.0f, 1.0f, 1.0f);
					glRotatef (-45, 0, 0, 1);
					glRotatef (d_cosR*(70-robotWeight), 1, 0, 0);
					glRotatef (d_sinR*5 - 5, 0, 1, 0);

					drawLeftArm();                                // 왼팔 출력
				}
				glPopMatrix();

				glPushMatrix();
				{
					setColor(0, 0, 0, 1.0);
					glTranslated(0, 0.05, 0.29);
					glScalef (1.0f, 1.0f, 3.0f);
					glRotatef (90, 1, 0, 0);
				
					drawButton();                   // 단추 출력
				}
				glPopMatrix();
			
				glPushMatrix();
				{
					setColor(1.0, 1.0, 1.0, 1.0);
					glTranslated(0, 0.6 , 0.0);
					glScalef (1.0f, 1.0f, 1.0f);
					glRotatef (d_cosR*(40-robotWeight), 0, 1, 0);

					drawHead();                        // 머리 출력

					glPushMatrix();
					{
						setColor(0.6, 0.45, 0.12, 1.0);
						glTranslated(0.0, 0.3 , 0.0);
						glScalef (0.8f, 0.8f, 0.8f);

						drawHair();                        // 머리카락 출력
					}
					glPopMatrix();

					glPushMatrix();
					{
						setColor(0.98, 0.625, 0, 1.0);
						glTranslated(0, 0.25 , 0.2);
						glScalef (0.6f, 0.6f, 0.6f);
						glRotatef (90, 1, 0, 0);

						drawNose();                        // 코 출력
					}
					glPopMatrix();

					glPushMatrix();
					{
						setColor(0, 0, 0, 1.0);
						glTranslated(0, 0.0, 0.0);

						drawEyes();                        // 눈 출력
					}
					glPopMatrix();
				}
				glPopMatrix();
			
				glPushMatrix();
				{
					setColor(1.0, 1.0, 1.0, 1.0);
					glTranslated(-0.20, -0.85, cosR*0.2);
					glScalef (1.0f, 1.0f, 1.0f);
					glRotatef (d_cosR*(50-robotWeight), 1, 0, 0);

					drawRightLeg();                            // 오른발 출력
				}
				glPopMatrix();

				glPushMatrix();
				{
					setColor(1.0, 1.0, 1.0, 1.0);
					glTranslated(0.20, -0.85, d_cosR*0.2);
					glScalef (1.0f, 1.0f, 1.0f);
					glRotatef (cosR*(50-robotWeight), 1, 0, 0);

					drawLeftLeg();                        // 왼발 출력
				}
				glPopMatrix();
			}	
			glPopMatrix();
		}	
		glPopMatrix();

	}
	glPopMatrix();
}

void drawBody1(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Body1->faceNum; i++){
				glNormal3f(Body1->normalList[i].faceNormal[0], Body1->normalList[i].faceNormal[1], Body1->normalList[i].faceNormal[2]);

				glVertex3f(Body1->vertexList[Body1->faceList[i].vertexIndex[0]].x / scale, 
					Body1->vertexList[Body1->faceList[i].vertexIndex[0]].y / scale, 
					Body1->vertexList[Body1->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Body1->vertexList[Body1->faceList[i].vertexIndex[1]].x / scale, 
					Body1->vertexList[Body1->faceList[i].vertexIndex[1]].y / scale, 
					Body1->vertexList[Body1->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(Body1->vertexList[Body1->faceList[i].vertexIndex[2]].x / scale, 
					Body1->vertexList[Body1->faceList[i].vertexIndex[2]].y / scale, 
					Body1->vertexList[Body1->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
void drawBody2(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Body2->faceNum; i++){
				float* n = Body2->normalList[i].faceNormal;
				glNormal3f(n[0], n[1], n[2]);
				//glNormal3f(Body->normalList[i].faceNormal[0], Body->normalList[i].faceNormal[1], Body->normalList[i].faceNormal[2]);

				glVertex3f(Body2->vertexList[Body2->faceList[i].vertexIndex[0]].x / scale, 
					Body2->vertexList[Body2->faceList[i].vertexIndex[0]].y / scale, 
					Body2->vertexList[Body2->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Body2->vertexList[Body2->faceList[i].vertexIndex[1]].x / scale, 
					Body2->vertexList[Body2->faceList[i].vertexIndex[1]].y / scale, 
					Body2->vertexList[Body2->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(Body2->vertexList[Body2->faceList[i].vertexIndex[2]].x / scale, 
					Body2->vertexList[Body2->faceList[i].vertexIndex[2]].y / scale, 
					Body2->vertexList[Body2->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
void drawRightArm(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<RightArm->faceNum; i++){
				glColor3f(0.8, 0.8, 0.8);
				glNormal3f(RightArm->normalList[i].faceNormal[0], RightArm->normalList[i].faceNormal[1], RightArm->normalList[i].faceNormal[2]);
				
				glVertex3f(RightArm->vertexList[RightArm->faceList[i].vertexIndex[0]].x / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[0]].y / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(RightArm->vertexList[RightArm->faceList[i].vertexIndex[1]].x / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[1]].y / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(RightArm->vertexList[RightArm->faceList[i].vertexIndex[2]].x / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[2]].y / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawLeftArm(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<LeftArm->faceNum; i++){
				glNormal3f(LeftArm->normalList[i].faceNormal[0], LeftArm->normalList[i].faceNormal[1], LeftArm->normalList[i].faceNormal[2]);

				glVertex3f(LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[0]].x / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[0]].y / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[1]].x / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[1]].y / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[2]].x / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[2]].y / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawRightLeg(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<RightLeg->faceNum; i++){
				glNormal3f(RightLeg->normalList[i].faceNormal[0], RightLeg->normalList[i].faceNormal[1], RightLeg->normalList[i].faceNormal[2]);

				glVertex3f(RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[0]].x / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[0]].y / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[1]].x / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[1]].y / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[2]].x / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[2]].y / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawLeftLeg(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<LeftLeg->faceNum; i++){
				glNormal3f(LeftLeg->normalList[i].faceNormal[0], LeftLeg->normalList[i].faceNormal[1], LeftLeg->normalList[i].faceNormal[2]);

				glVertex3f(LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[0]].x / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[0]].y / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[1]].x / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[1]].y / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[1]].z / scale);
				
				glVertex3f(LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[2]].x / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[2]].y / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawHead(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Head->faceNum; i++){
				glNormal3f(Head->normalList[i].faceNormal[0], Head->normalList[i].faceNormal[1], Head->normalList[i].faceNormal[2]);

				glVertex3f(Head->vertexList[Head->faceList[i].vertexIndex[0]].x / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[0]].y / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Head->vertexList[Head->faceList[i].vertexIndex[1]].x / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[1]].y / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[1]].z / scale);
				
				glVertex3f(Head->vertexList[Head->faceList[i].vertexIndex[2]].x / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[2]].y / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawEyes(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Eyes->faceNum; i++){
				glNormal3f(Eyes->normalList[i].faceNormal[0], Eyes->normalList[i].faceNormal[1], Eyes->normalList[i].faceNormal[2]);

				glVertex3f(Eyes->vertexList[Eyes->faceList[i].vertexIndex[0]].x / scale, 
					Eyes->vertexList[Eyes->faceList[i].vertexIndex[0]].y / scale, 
					Eyes->vertexList[Eyes->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Eyes->vertexList[Eyes->faceList[i].vertexIndex[1]].x / scale, 
					Eyes->vertexList[Eyes->faceList[i].vertexIndex[1]].y / scale, 
					Eyes->vertexList[Eyes->faceList[i].vertexIndex[1]].z / scale);
				
				glVertex3f(Eyes->vertexList[Eyes->faceList[i].vertexIndex[2]].x / scale, 
					Eyes->vertexList[Eyes->faceList[i].vertexIndex[2]].y / scale, 
					Eyes->vertexList[Eyes->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawNose(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Nose->faceNum; i++){
				glNormal3f(Nose->normalList[i].faceNormal[0], Nose->normalList[i].faceNormal[1], Nose->normalList[i].faceNormal[2]);

				glVertex3f(Nose->vertexList[Nose->faceList[i].vertexIndex[0]].x / scale, 
					Nose->vertexList[Nose->faceList[i].vertexIndex[0]].y / scale, 
					Nose->vertexList[Nose->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Nose->vertexList[Nose->faceList[i].vertexIndex[1]].x / scale, 
					Nose->vertexList[Nose->faceList[i].vertexIndex[1]].y / scale, 
					Nose->vertexList[Nose->faceList[i].vertexIndex[1]].z / scale);
				
				glVertex3f(Nose->vertexList[Nose->faceList[i].vertexIndex[2]].x / scale, 
					Nose->vertexList[Nose->faceList[i].vertexIndex[2]].y / scale, 
					Nose->vertexList[Nose->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawHair(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Hair->faceNum; i++){
				glNormal3f(Hair->normalList[i].faceNormal[0], Hair->normalList[i].faceNormal[1], Hair->normalList[i].faceNormal[2]);

				glVertex3f(Hair->vertexList[Hair->faceList[i].vertexIndex[0]].x / scale, 
					Hair->vertexList[Hair->faceList[i].vertexIndex[0]].y / scale, 
					Hair->vertexList[Hair->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Hair->vertexList[Hair->faceList[i].vertexIndex[1]].x / scale, 
					Hair->vertexList[Hair->faceList[i].vertexIndex[1]].y / scale, 
					Hair->vertexList[Hair->faceList[i].vertexIndex[1]].z / scale);
				
				glVertex3f(Hair->vertexList[Hair->faceList[i].vertexIndex[2]].x / scale, 
					Hair->vertexList[Hair->faceList[i].vertexIndex[2]].y / scale, 
					Hair->vertexList[Hair->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawButton(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Button->faceNum; i++){
				glNormal3f(Button->normalList[i].faceNormal[0], Button->normalList[i].faceNormal[1], Button->normalList[i].faceNormal[2]);

				glVertex3f(Button->vertexList[Button->faceList[i].vertexIndex[0]].x / scale, 
					Button->vertexList[Button->faceList[i].vertexIndex[0]].y / scale, 
					Button->vertexList[Button->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Eyes->vertexList[Button->faceList[i].vertexIndex[1]].x / scale, 
					Button->vertexList[Button->faceList[i].vertexIndex[1]].y / scale, 
					Button->vertexList[Button->faceList[i].vertexIndex[1]].z / scale);
				
				glVertex3f(Button->vertexList[Button->faceList[i].vertexIndex[2]].x / scale, 
					Button->vertexList[Button->faceList[i].vertexIndex[2]].y / scale, 
					Button->vertexList[Button->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}

void drawGridPlane()
{
	int		i;
	double	x, z;

	glLineWidth(1);

    glPushMatrix();
		glBegin (GL_LINES);
			x = -1.0;
			z = -1.0;
			for( i=0 ; i<=10 ; i++ ) {
				setColor(i/20.f, 0, 0, 0.2);
				glVertex3f (x, 0, z);
				glVertex3f (x, 0, z+2);

				setColor(0, 0, i/20.f, 0.2);
				glVertex3f (z, 0, x);
				glVertex3f (z+2, 0, x);
				x += 0.2;
			}
		glEnd();
    glPopMatrix();
}
void drawString (const char *s)
{
    unsigned int i;

    for (i= 0; i < strlen (s); i++)
	glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, s[i]);
}

void drawCoord(int lineWidth)
{
	glLineWidth(lineWidth);

    glPushMatrix();
		glScaled (0.9, 0.9, 0.9);
		glBegin (GL_LINES);
			setColor(1.0f, 0, 0, 0);
			glVertex3f (0.0f, 0, 0);
			glVertex3f (1.0f, 0, 0);	// RED   ==> +x axis
			
			setColor(0, 1.0f, 0, 0);
			glVertex3f (0, 0.0f, 0);
			glVertex3f (0, 1.0f, 0);	// GREEN ==> +y axis
			
			setColor(0, 0, 1.0f, 0);
			glVertex3f (0, 0, 0.0f);
			glVertex3f (0, 0, 1.0f);	// BLUE  ==> +z axis
		glEnd();

		glLineWidth(1);

		setColor(1.0f, 0, 0, 0);
		glRasterPos3f (1.0f, 0, 0);
		drawString ("x");

		setColor(0, 1.0f, 0, 0);
		glRasterPos3f (0, 1.0f, 0);
		drawString ("y");

		setColor(0, 1.0f, 0, 0);
		glRasterPos3f (0, 0, 1.0f);
		drawString ("z");

    glPopMatrix();
}