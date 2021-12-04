#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <math.h>
#include <iostream>
#include <string>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")

using namespace std;

//#define score_height	40
#define	width 			700
#define	height			700
#define GRAVITY
int	left_ = 0;
int	bottom = 0;
float	camera_distance;
float	camera_theta, camera_phi;
float Radius;
#define PI 3.141592

float	lightPositionR[] = { 0.0f, 0.0f, 5.0f, 1.0f };
boolean	camera = false;

struct position {
	float x;
	float y;
	float z;
}; 
position p1, p2;

unsigned char* LoadBitmapFile(const char* filename, BITMAPINFOHEADER* bitmapInfoHeader) { // 배경이미지
	FILE* filePtr;
	BITMAPFILEHEADER bitmapFileHeader;
	unsigned char* bitmapImage;
	int imageIdx = 0;
	unsigned char tempRGB;
	errno_t err;
	err = fopen_s(&filePtr, filename, "rb");
	if (filePtr == NULL)
		return NULL;
	// 비트맵 파일 헤드를 읽는다.
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
	// 윈도우즈 BMP 파일인지 확인한다. 
	if (bitmapFileHeader.bfType != 'MB') {
		fclose(filePtr);
		return (NULL);
	}
	// 비트맵 정보 헤드를 읽는다.
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
	// 파일 포인터를 비트맵 데이터의 시작 위치로 옮긴다. 
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
	// 비트맵 이미지 데이터를 넣을 메모리를 할당한다. 
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);
	//메모리가 제대로 할당되었는지 확인 
	if (!bitmapImage) {
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}
	// 메모리에 비트맵 데이트를 읽어드림 
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
	// 제대로 들어갔는지 확인 
	if (bitmapImage == NULL) {
		fclose(filePtr);
		return NULL;
	}
	//BMP는 BGR형식이므로 R과 B를 서로 교체해야 함
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3) {
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}
	// 파일을 닫고 비트맵 이미지 데이터 반환 
	fclose(filePtr);
	return bitmapImage;
}

BITMAPINFOHEADER bitmapInfoHeader1;
unsigned char* bitmapImage_1 = LoadBitmapFile("Rapunzel.bmp", &bitmapInfoHeader1);
// 전체 배경화면
BITMAPINFOHEADER bitmapInfoHeader2;
unsigned char* bitmapImage_2 = LoadBitmapFile("GameOver.bmp", &bitmapInfoHeader2);
BITMAPINFOHEADER bitmapInfoHeader3;
unsigned char* bitmapImage_3 = LoadBitmapFile("Pause.bmp", &bitmapInfoHeader3);
BITMAPINFOHEADER bitmapInfoHeader4;
unsigned char* bitmapImage_4 = LoadBitmapFile("Start.bmp", &bitmapInfoHeader4);
BITMAPINFOHEADER bitmapInfoHeader5;
unsigned char* bitmapImage_5 = LoadBitmapFile("Clear.bmp", &bitmapInfoHeader5);

void init(void) {
	Radius = 0.5;
	camera_phi = PI / 6.0;
	camera_theta = 0.0;
	camera_distance = 4.0 * Radius;

	p1.x = 0.0; p1.y = 0.0; p1.z = 0.0; //캐릭터 1 위치
	p2.x = 1.0;p2.y = 0;p2.z = 0; //캐릭터 2 위치
	glEnable(GL_DEPTH_TEST);
}

void MyReshape(int w, int h) { // 시점 및 초기화
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -50.0, 50.0, -10.0, 15.0);
	//gluPerspective(60.0, 1.0, 1.0, 20.0);
	//gluOrtho2D(left_, left_ + width, bottom, bottom + height);

}

//void Modeling_Score() { // 점수판 만들기
//	glColor3f(0.8, 0.5, 0.5);
//	glRectf(0, 0, width, score_height);
//}

void Drawchar() {
	//////////p1캐릭터//////////
	glPushMatrix();
	glTranslated(p1.x, p1.y, p1.z);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(Radius, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(p1.x, p1.y, p1.z-0.5);
	glutSolidSphere((Radius), 30, 30);
	glPopMatrix();
	

	//////////p2캐릭터//////////
	glPushMatrix();
	glTranslated(p2.x, p2.y, p2.z);
	glColor3f(1.0, 0.0, 1.0);
	glutSolidSphere(Radius, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glTranslated(p2.x, p2.y, p2.z - 0.5);
	glutSolidSphere((Radius), 30, 30);
	glPopMatrix();

}

void axis(void) {

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); // x축   빨간색
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0); // y축 초록색
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);

	glColor3f(0.0, 0.0, 1.0); // z축 파란색
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 100.0);
	glEnd();

}

void cameraSet() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera_distance = (p1.x + p2.x) / 2;
	gluLookAt(0.0+camera_distance, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}

void RenderScene(void) { // 변경 화면
	float	x, y, z;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	////////////////화면 분할 코드(수정중)////////////////
	if (camera) {
		glViewport(0, 0, width / 2, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-50.0, 0.0, -50.0, 50.0, -10.0, 15.0);// 클리핑 볼륨 설정.
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glViewport((width / 2) + 30, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 50.0, -50.0, 50.0, -10.0, 15.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();


	}
	else {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-50.0, 50.0, -50.0, 50.0, -10.0, 15.0);
		//glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 15.0);
	}
	////////////////////////////////////////////////////////
	// Camera Position 
	x = camera_distance * cos(camera_phi) * cos(camera_theta);
	y = camera_distance * cos(camera_phi) * sin(camera_theta);
	z = camera_distance * sin(camera_phi);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glShadeModel(GL_FLAT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glRasterPos2i((4.0 - x) * 20, 0); // 배경화면 위치
	glDrawPixels(bitmapInfoHeader1.biWidth, bitmapInfoHeader1.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapImage_1);

	glLightfv(GL_LIGHT1, GL_POSITION, lightPositionR); // (lightPositionR[0], lightPositionR[1], lightPositionR[2]) in Camera Coordinates
	//Modeling_Score();
	
	cameraSet();
	axis();
	Drawchar();

	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void p1Jump() {

}

void p2Jump() {

}

void SpecialKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT:
		p1.x += 0.1;
		//camera_distance += 0.1;
		break;
	case GLUT_KEY_RIGHT:
		p1.x -= 0.1;
		//camera_distance -= 0.1;
		break;

	//p1Jump()
	case GLUT_KEY_UP: break;

	//viewport 분할
	case GLUT_KEY_INSERT: camera = !(camera); break;

	default:break;
	}
	glutPostRedisplay();

}

void Keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'a': p2.x += 0.1; break;
	case 'd': p2.x -= 0.1; break;

	default:
		break;
	}
	glutPostRedisplay();
}
void main(int argc, char** argv) {
	glutInitWindowPosition(200, 50);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // 애니메이션처럼 보이기 위해 DOUBLE로 씀
	glutInitWindowSize(width, height);
	glutCreateWindow("To the dawn");
	init();
	glutReshapeFunc(MyReshape); // 범위 설정
	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene); // 아무일을 수행 안해도 그것을 이벤트로 삼아라!!!(마우스, 키보드 입력이 없을때 발생)

	glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(Keyboard);
	//	
	//	//if (you) {
	//	//	sndPlaySoundA("music.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	////
	//	//}
	glutMainLoop();
}