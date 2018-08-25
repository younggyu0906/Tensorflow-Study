#include "mesh.h"
#include "ase.h"
#include "var_dec.h"
#include "setting.h"

void meshLoad(){      // ase 파일을 불러옴

	Body1 = new Mesh();
	Body1->readAse("KYG_body1.ASE");

	Body2 = new Mesh();
	Body2->readAse("KYG_body2.ASE");

	RightArm = new Mesh();
	RightArm->readAse("KYG_arms.ASE");

	LeftArm = new Mesh();
	LeftArm->readAse("KYG_arms.ASE");

	RightLeg = new Mesh();
	RightLeg->readAse("KYG_foot.ASE");

	LeftLeg = new Mesh();
	LeftLeg->readAse("KYG_foot.ASE");

	Head = new Mesh();
	Head->readAse("KYG_head.ASE");

	Eyes = new Mesh();
	Eyes->readAse("KYG_eyes.ASE");

	Nose = new Mesh();
	Nose->readAse("KYG_nose.ASE");

	Hair = new Mesh();
	Hair->readAse("KYG_hair.ASE");

	Button = new Mesh();
	Button->readAse("KYG_button.ASE");
}

void meshInit() {      // mesh 의 회전방향, 이동 위치 좌표를 초기화
	robotWeight = 10;
	robotSpeed = 20;
	robotRun = false;
	robotRange = 0;
	dRadian = 0;
	sinR = 0;
	cosR = 0;
	sinR2 = 0;
	d_cosR = 0;
	d_sinR = 0;

	sprintf(robotWeightStr, "%.f", robotWeight - 5);
	sprintf(robotWeightStr, "%.f", (float)robotSpeed - 15);

	scaleRate = 1;
	rotateX1 = 0.0f;
	rotateY1 = 0.0f;
	rotateX2 = 0.0f;
	rotateY2 = 0.0f;
	rotateX3 = 0.0f;
	rotateY3 = 0.0f;
	rotateX4 = 0.0f;
	rotateY4 = 0.0f;
	p_near = 0.2;
	p_scale = 1;

	if( Body2->max > 1 )
		scale = (float)floor((double)(Body2->max+0.5)) * 2;
	else
		scale = 1;
}

void InitLight(){
	    // mesh 의 재질 색, 광원 값
	GLfloat mat_specular[ ] = {0.4, 0.4, 0.4, 1.0};		// 객체의 반사
	GLfloat mat_shininess[ ] = {70.0};
	    // 조명의 색, 광원 값
	GLfloat light_specular[ ] = {0.5, 1.0, 0.5, 1.0};	// 빛의 반사
	GLfloat light_diffuse[ ] = {0.8, 0.8, 0.8, 1.0};	// 빛의 분산
	GLfloat light_ambient[ ] = {0.8, 0.8, 0.8, 1.0};	// 빛의 잔잔한 정도
	GLfloat light_position[ ] = {-1.5 / scaleRate, -0.5 / scaleRate, 0.5, 0.0};
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);  // 조명 사용 설정
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE); // 정규화
        // mesh 의 재질 색, 광원  및  조명의 색, 광원 설정
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	setColor(0.5, 0.5, 0.5, 1.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}