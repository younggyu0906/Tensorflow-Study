#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

extern int windowX;
extern int windowY;
extern GLfloat WidthFactor;
extern GLfloat HeightFactor;

extern float scale;         // ase 파일을 불러올 때 그 mesh 객체의 크기를 뷰포트 내에 알맞게 조정하기 위한 변수
extern float scaleRate;     // 프로그램에서 z, x 키를 통해 줌인/줌아웃을 하기 위한 변수

extern float rotateX1;   // 1번 뷰포트의 Y축 기준 회전 각도 변수
extern float rotateY1;   // 1번 뷰포트의 X축 기준 회전 각도 변수
extern float rotateX2;
extern float rotateY2;
extern float rotateX3;
extern float rotateY3;
extern float rotateX4;
extern float rotateY4;
extern int viewSelected;   // 마우스로 뷰포트 선택하기 위한 변수
extern int viewClick;
extern float p_near;   // 원근투상의 near 값
extern float p_scale;  // 원근투상의 확대, 축소를 위한 변수
extern float camEyeX;  // 카메라 설정 값 변수
extern float camEyeY;
extern float camEyeZ;
extern float camAtX;
extern float camAtY;
extern float camAtZ;
extern float camUpX;
extern float camUpY;
extern float camUpZ;
extern int systemInt;  // 시스템 값 출력을 위한 변수

extern bool robotRun;            // 로봇의 달리는 애니메이션 유무
extern float robotWeight;        // 로봇의 무게
extern char robotWeightStr[3];   // 로봇의 무게를 출력하기 위한 문자열 
extern double robotSpeed;        // 로봇의 달리는 속도
extern char robotSpeedStr[3];    // 로봇의 속도를 출력하기 위한 문자열 
extern double robotRange;        // 로봇이 달리는 정도를 구하기 위한 각도
extern double dRadian;           // 위 각도의 변수로 sin, cos 값을 구하기 위한 라디안 변수
extern float sinR;               // sin, cos 값으로 로봇의 팔,다리, 몸, 머리의 각 회전 각도를 조절
extern float sinR2;
extern float cosR;
extern float d_cosR;
extern float d_sinR;
extern GLfloat mat_diffuse[6];
extern GLfloat mat_ambient[6];