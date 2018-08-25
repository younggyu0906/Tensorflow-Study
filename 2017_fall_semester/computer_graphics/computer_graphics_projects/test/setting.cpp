#include "setting.h"
#include "var_dec.h"

void setColor(float r, float g, float b, float a){

	mat_diffuse[0] = r;
	mat_diffuse[1] = g;
	mat_diffuse[2] = b;
	mat_diffuse[3] = a;

	mat_ambient[0] = r;
	mat_ambient[1] = g;
	mat_ambient[2] = b;
	mat_ambient[3] = a;

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
}

void setCamera(float EyeX, float EyeY, float EyeZ, float AtX, float AtY, float AtZ, float UpX, float UpY, float UpZ){
	camEyeX = EyeX;
	camEyeY = EyeY;
	camEyeZ = EyeZ;
	camAtX = AtX;
	camAtY = AtY;
	camAtZ = AtZ;
	camUpX = UpX;
	camUpY = UpY;
	camUpZ = UpZ;
}