#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>

int		gWindowWidth = 800;		// 윈도우의 가로 크기
int		gWindowHeight = 800;	// 윈도우의 세로 크기

GLfloat wx_min =	-0.5;	// 사각형의 가로 시작
GLfloat wy_min =	-0.5;	// 사각형의 세로 시작 
GLfloat wx_max =	 0.5;	// 사각형의 가로 끝
GLfloat wy_max =	 0.5;	// 사각형의 세로 끝

GLfloat line1[4] = {0.0, 0.8, -0.8, 0.0};	// 선1의 x y 시작, 끝 좌표
GLfloat line2[4] = {0.1, 0.7, -0.3, 0.1};	// 선2의 x y 시작, 끝 좌표 
GLfloat line3[4] = {0.2, 0.2, -0.2, -0.2};	// 선3의 x y 시작, 끝 좌표
GLfloat line4[4] = {0.7, -0.8, 0.8, 0.0};	// 선4의 x y 시작, 끝 좌표
GLfloat line5[4] = {0.3, 0.8, 0.8, 0.3};	// 선5의 x y 시작, 끝 좌표

typedef int OutCode;
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

void MyDisplay();
void drawLines(GLfloat sx, GLfloat sy, GLfloat ex, GLfloat ey);		// 선의 시작점과 끝 점을 매개변수로 받는 선 그리기 함수
void drawRec(GLfloat sx = wx_min, GLfloat sy = wy_min, GLfloat ex = wx_max, GLfloat ey = wy_max);	// 사각형 그리기 함수
void MyKeyboard(unsigned char KeyPressed, int X, int Y);			// 키보드 콜백

OutCode ComputeOutCode(double x, double y);		// 점 x, y에 대한 비트 코드를 계산
void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1);	// 코헨서덜랜드알고리즘

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(gWindowWidth, gWindowHeight);		// 윈도우의 높이와 넓이 설정
	glutInitWindowPosition(100, 50);		// 화면의 좌상단을 기준으로 한 window의 좌상단 좌표 설정
	glutCreateWindow("2013136021_김영규_Cohen-Sutherland Test");	// 윈도우 창을 디폴트 옵션으로 생성, 윈도우 제목 설정

	glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();						// 좌표 초기화
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutKeyboardFunc(MyKeyboard);
	glutDisplayFunc(MyDisplay);			// 윈도우를 그릴 때마다 인자로 주어진 함수를 호출하도록 설정

	glutMainLoop( );					// 모든 내용을 프로그램이 종료할 때까지 처리하도록 설정하는 함수.
	return 0;
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	// 윈도우를 클리어할 색상 지정
    
	glColor3f(0.3, 0.3, 0.3);		// 회색
	drawRec();						// 사각형 그리기 (윈도우)

	glColor3f(0.0, 0.0, 1.0);		// 파란색
	drawLines(line1[0], line1[1], line1[2], line1[3]);	// 선1 그리기
	drawLines(line2[0], line2[1], line2[2], line2[3]);	// 선2 그리기
	drawLines(line3[0], line3[1], line3[2], line3[3]);	// 선3 그리기
	drawLines(line4[0], line4[1], line4[2], line4[3]);	// 선4 그리기
	drawLines(line5[0], line5[1], line5[2], line5[3]);	// 선5 그리기

	glFlush();			// 큐에 저장된 명령어들 수행
}

// 선의 좌표를 매개변수로 받아 선을 그리는 함수
void drawLines(GLfloat sx, GLfloat sy, GLfloat ex, GLfloat ey)
{
	glBegin(GL_LINES);
		glVertex3f(sx, sy, 0.0);
		glVertex3f(ex, ey, 0.0);
	glEnd();
}

// 사각형의 좌표를 매개변수로 받아 사각형을 그리는 함수
void drawRec(GLfloat sx, GLfloat sy, GLfloat ex, GLfloat ey)
{
	glBegin(GL_LINE_LOOP);
		glVertex3f(sx, sy, 0.0);
		glVertex3f(sx, ey, 0.0);
		glVertex3f(ex, ey, 0.0);
		glVertex3f(ex, sy, 0.0);
	glEnd();
}

// 키보드 콜백 'q' || 'Q' || 'ESC' 입력시 종료, 'c', 'C' 입력시 코헨서덜랜드 알고리즘 적용
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case 27:                //'esc' 키의 아스키 코드 값
        exit(0); break;
	case 'c':
	case 'C':
		glClear(GL_COLOR_BUFFER_BIT);	// 윈도우를 클리어
		CohenSutherlandLineClipAndDraw(line1[0], line1[1], line1[2], line1[3]);	// 선1 코헨서덜랜드
		CohenSutherlandLineClipAndDraw(line2[0], line2[1], line2[2], line2[3]);	// 선2 코헨서덜랜드
		CohenSutherlandLineClipAndDraw(line3[0], line3[1], line3[2], line3[3]);	// 선3 코헨서덜랜드
		CohenSutherlandLineClipAndDraw(line4[0], line4[1], line4[2], line4[3]);	// 선4 코헨서덜랜드
		CohenSutherlandLineClipAndDraw(line5[0], line5[1], line5[2], line5[3]);	// 선5 코헨서덜랜드
		break;
	default:
		break;
    }
}

OutCode ComputeOutCode(double x, double y)
{
    OutCode code;
    
    code = INSIDE;			// 클립 윈도우 안에 있는 것으로 초기화
    
    if (x < wx_min)           
        code |= LEFT;		// 클립 윈도우의 왼쪽으로
    else if (x > wx_max)      
        code |= RIGHT;		// 클립 윈도우의 오른쪽으로
    if (y < wy_min)          
        code |= BOTTOM;		// 클립 윈도우의 아래쪽으로
    else if (y > wy_max)     
        code |= TOP;		// 클립 윈도우의 위쪽으로
    
    return code;
}


void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1)
{
	// 클립 윈도우 외부에 있는 점 계산
    OutCode outcode0 = ComputeOutCode(x0, y0);
    OutCode outcode1 = ComputeOutCode(x1, y1);
    bool accept = false;
    double x, y;

    while (true) {
        if (!(outcode0 | outcode1)) {	// 비트단위 OR이 0이면 루프 종료
            accept = true;
            break;
        } else if (outcode0 & outcode1) {	// 비트단위 AND가 0이 아니면 루프를 종료
            break;
        } else {	// 두 개의 테스트에 해당하지 않는 경우 선분 클립 계산
            OutCode outcodeOut = outcode0? outcode0 : outcode1;
            
            if (outcodeOut & TOP) {   
                x = x0 + (x1 - x0) * (wy_max - y0) / (y1 - y0);
                y = wy_max;
            } else if (outcodeOut & BOTTOM) { 
                x = x0 + (x1 - x0) * (wy_min - y0) / (y1 - y0);
                y = wy_min;
            } else if (outcodeOut & RIGHT) { 
                y = y0 + (y1 - y0) * (wx_max - x0) / (x1 - x0);
                x = wx_max;
            } else if (outcodeOut & LEFT) { 
                y = y0 + (y1 - y0) * (wx_min - x0) / (x1 - x0);
                x = wx_min;
            }

            if (outcodeOut == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = ComputeOutCode(x0, y0);
            } else {
                x1 = x;
                y1 = y;
                outcode1 = ComputeOutCode(x1, y1);
            }
        }
    }
    if (accept) {
		// 선 그리기
		glColor3f(0.3, 0.3, 0.3);
		drawRec();

        glColor3f(1.0, 0.0, 0.0);
		drawLines(x0, y0, x1, y1);

        glFlush();
    }
} 

// 코헨 서덜랜드 알고리즘 참고 http://msparkms.tistory.com/entry/Cohen%E2%80%93Sutherland-algorithmWiki