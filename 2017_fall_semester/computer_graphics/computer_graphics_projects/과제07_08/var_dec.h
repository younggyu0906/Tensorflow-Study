#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

extern int windowX;
extern int windowY;
extern GLfloat WidthFactor;
extern GLfloat HeightFactor;

extern float scale;         // ase ������ �ҷ��� �� �� mesh ��ü�� ũ�⸦ ����Ʈ ���� �˸°� �����ϱ� ���� ����
extern float scaleRate;     // ���α׷����� z, x Ű�� ���� ����/�ܾƿ��� �ϱ� ���� ����

extern float rotateX1;   // 1�� ����Ʈ�� Y�� ���� ȸ�� ���� ����
extern float rotateY1;   // 1�� ����Ʈ�� X�� ���� ȸ�� ���� ����
extern float rotateX2;
extern float rotateY2;
extern float rotateX3;
extern float rotateY3;
extern float rotateX4;
extern float rotateY4;
extern int viewSelected;   // ���콺�� ����Ʈ �����ϱ� ���� ����
extern int viewClick;
extern float p_near;   // ���������� near ��
extern float p_scale;  // ���������� Ȯ��, ��Ҹ� ���� ����
extern float camEyeX;  // ī�޶� ���� �� ����
extern float camEyeY;
extern float camEyeZ;
extern float camAtX;
extern float camAtY;
extern float camAtZ;
extern float camUpX;
extern float camUpY;
extern float camUpZ;
extern int systemInt;  // �ý��� �� ����� ���� ����

extern bool robotRun;            // �κ��� �޸��� �ִϸ��̼� ����
extern float robotWeight;        // �κ��� ����
extern char robotWeightStr[3];   // �κ��� ���Ը� ����ϱ� ���� ���ڿ� 
extern double robotSpeed;        // �κ��� �޸��� �ӵ�
extern char robotSpeedStr[3];    // �κ��� �ӵ��� ����ϱ� ���� ���ڿ� 
extern double robotRange;        // �κ��� �޸��� ������ ���ϱ� ���� ����
extern double dRadian;           // �� ������ ������ sin, cos ���� ���ϱ� ���� ���� ����
extern float sinR;               // sin, cos ������ �κ��� ��,�ٸ�, ��, �Ӹ��� �� ȸ�� ������ ����
extern float sinR2;
extern float cosR;
extern float d_cosR;
extern float d_sinR;
extern GLfloat mat_diffuse[6];
extern GLfloat mat_ambient[6];