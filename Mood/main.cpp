#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <math.h>
#include <iostream>
#include <string>
#include<MMSystem.h>
#include"Object.cpp"
#include"Road.cpp"
#pragma comment(lib,"Winmm.lib")  

using namespace std;

#define score_height	40
#define	width 			700
#define	height			700
#define GRAVITY

float	camera_distance;
float	camera_theta, camera_phi;

float p1jumpMax, p2jumpMax, bt;
const float timeFactor = 2000;

#define PI 3.141592

float lightPositionR[] = { 55.0 + camera_distance, 0.5f, 10.0f, 1.0f }; //mane
float light_ambient[] = { 254.0/255.0,214.0/255.0, 125.0/255.0, 0.0 };
float light_diffuse[] = { 254.0 / 255.0,214.0 / 255.0, 125.0 / 255.0, 0.0 };
float light_specular[] = { 254.0 / 255.0,214.0 / 255.0, 125.0 / 255.0, 0.0 };

float lightPositionR_2[] = { -117 - camera_distance + 3, 2.0f, 5.0f, 1.0f }; // nox
float light_ambient_2[] = { 79.0 / 255.0, 160.0 / 255.0, 252.0 / 255.0, 0.0 };
float light_diffuse2[] = { 79.0 / 255.0, 160.0 / 255.0, 252.0 / 255.0, 0.0 };
float light_specular2[] = { 79.0 / 255.0, 160.0 / 255.0, 252.0 / 255.0, 0.0 };

float lightPositionR_3[] = { -189 - camera_distance + 3, 2.0f, 5.0f, 1.0f }; // rolar
float light_ambient_3[] = { 208.0 / 255.0,146.0/ 255.0, 231.0 / 255.0, 0.0 };
float light_diffuse3[] = { 208.0 / 255.0,146.0 / 255.0, 231.0 / 255.0, 0.0 };
float light_specular3[] = { 208.0 / 255.0,146.0 / 255.0, 231.0 / 255.0, 0.0 };

float lightPositionR_1[] = { camera_distance, 1.0f, 20.0f, 1.0f }; 
float light_ambient_1[] = { 200.0,200.0, 200.0, 0.0 };
float light_diffuse1[] = { 1.0, 1.0, 1.0, 0.0 };
float light_specular1[] = { 1.0, 1.0, 1.0, 0.0 };


float ambient0[] = { 0.0, 1.0, 1.0, 0.0 };
boolean light_1;
boolean light_2;
boolean light_3;



boolean	camera;
boolean p1Jump;
boolean p2Jump;
float Radius, moveDistance, jumpUp, jumpDown;
int score;
int life;
int level;
int start_flag;
boolean GameClear;
boolean GameOver;
boolean Pause;
boolean p1Left, p1Right, p2Left, p2Right;
float left_, right_, top_, bottom_, zNear_, zFar_;

bool lightOn = true;

unsigned char* LoadBitmapFile(const char* filename, BITMAPINFOHEADER* bitmapInfoHeader) { // ??????????
	FILE* filePtr;
	BITMAPFILEHEADER bitmapFileHeader;
	unsigned char* bitmapImage;
	int imageIdx = 0;
	unsigned char tempRGB;
	errno_t err;
	err = fopen_s(&filePtr, filename, "rb");
	if (filePtr == NULL)
		return NULL;
	// ?????? ???? ?????? ??????.
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
	// ???????? BMP ???????? ????????. 
	if (bitmapFileHeader.bfType != 'MB') {
		fclose(filePtr);
		return (NULL);
	}
	// ?????? ???? ?????? ??????.
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
	// ???? ???????? ?????? ???????? ???? ?????? ??????. 
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
	// ?????? ?????? ???????? ???? ???????? ????????. 
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);
	//???????? ?????? ???????????? ???? 
	if (!bitmapImage) {
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}
	// ???????? ?????? ???????? ???????? 
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
	// ?????? ?????????? ???? 
	if (bitmapImage == NULL) {
		fclose(filePtr);
		return NULL;
	}
	//BMP?? BGR?????????? R?? B?? ???? ???????? ??
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3) {
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}
	// ?????? ???? ?????? ?????? ?????? ???? 
	fclose(filePtr);
	return bitmapImage;
}


object_pepero pepero1(-20.0, 0.0, -3.0);

object_pocachip pocachip1(-8.0, 0.0, -2.5);
object_pocachip pocachip2(-25.0, 0.0, -2.5);
object_pocachip pocachip3(-50.0, 0.0, -2.5);

object_cookie cookie1(-90.0, 0.0, -3.0);
object_cookie cookie2(-137.0, 0.0, -3.0);
object_cookie cookie3(-139.0, 0.0, -3.0);
object_cookie cookie4(-141.0, 0.0, -3.0);

object_icecream icecream1(-43.0, 0.0, -3.0);
object_icecream icecream2(-100.0, 0.0, -3.0);
object_icecream icecream3(-145.0, 0.0, -3.0);

object_cloud cloud1(-65.0, 0.0, -3.0);
object_cloud cloud2(-120.0, 0.0, -3.0);

object_candy candy1(-40.0, 0.0, -3.0);
object_candy candy2(-80.0, 0.0, -3.0);
object_candy candy3(-115.0, 0.0, -3.0);
object_candy candy4(-138.0, 0.0, -3.0);
object_candy candy5(-150.0, 0.0, -2.0);

cloud_road cr1(-145.0, 0.0, -3.0);

object_mini_cookie minicookie1(-12.0, 0.0, 2.0);
object_mini_cookie minicookie2(-30.0, 0.0, 2.0);

position p1, p2, velocity1, velocity2;
static int a = 0;
static int b = 0;
static int c = 0;
static int d = 0;
GLuint	texture;



// ???? ????????
BITMAPINFOHEADER bitmapInfoHeader1;
unsigned char* bitmapImage_1 = LoadBitmapFile("background.bmp", &bitmapInfoHeader1);
BITMAPINFOHEADER bitmapInfoHeader2;
unsigned char* bitmapImage_2 = LoadBitmapFile("GameOver.bmp", &bitmapInfoHeader2);
BITMAPINFOHEADER bitmapInfoHeader3;
unsigned char* bitmapImage_3 = LoadBitmapFile("Pause.bmp", &bitmapInfoHeader3);
BITMAPINFOHEADER bitmapInfoHeader4;
unsigned char* bitmapImage_4 = LoadBitmapFile("Start_1.bmp", &bitmapInfoHeader4);
BITMAPINFOHEADER bitmapInfoHeader5;
unsigned char* bitmapImage_5 = LoadBitmapFile("Start_2.bmp", &bitmapInfoHeader5);
BITMAPINFOHEADER bitmapInfoHeader6;
unsigned char* bitmapImage_6 = LoadBitmapFile("Clear.bmp", &bitmapInfoHeader6);

void init(void) {
	p1jumpMax = 0.5;
	p2jumpMax = 0.5;
	bt = -3.0;


	camera = false;
	p1Jump = false;
	p2Jump = false;
	
	score = 0;
	life = 4;
	level = 1;
	GameOver = false;
	Pause = false;
	GameClear = false;
	
	static int a = 0;
	static int b = 0;
	static int c = 0;


	start_flag = 0;

	Radius = 0.5;
	camera_phi = PI / 6.0;
	camera_theta = 0.0;
	camera_distance = 4.0 * Radius;
	velocity1 = { 0.0,0.0,0.0 };
	velocity2 = { 0.0,0.0,0.0 };
	p1.x = -0.0; p1.y = 0.0; p1.z = bt; //?????? 1 ????
	p2.x = -2.0; p2.y = 0.0; p2.z = bt; //?????? 2 ????

	p1Left = false; p1Right = false; p2Left = false; p2Right = false;
	moveDistance = 0.1; jumpUp = 0.02; jumpDown = -0.003;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader1.biWidth,
		bitmapInfoHeader1.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapImage_1);

	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_SMOOTH);   //glShadeModel(GL_FLAT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); // mane
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPositionR);

	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient_3); // rolar
	glLightfv(GL_LIGHT3, GL_POSITION, lightPositionR);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular3);

	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient_2); // nox
	glLightfv(GL_LIGHT2, GL_POSITION, lightPositionR);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);

	glLightfv(GL_LIGHT1, GL_POSITION, lightPositionR_1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
}

void MyReshape(int w, int h) { // ???? ?? ??????
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-30.0, 30.0, -30.0, 30.0, 1.0, 150.0);
	//gluPerspective(60.0, 1.0, 1.0, 2000.0);
	//gluOrtho2D(left_, left_ + width, bottom, bottom + height);

}

void Modeling_Score() { // ?????? ??????
	glColor3f(189.0 / 255.0, 236.0 / 255.0, 182.0 / 255.0);
	//if ((p1.x + p2.x) / 2 <= 5 - 4.95)
	//	camera_distance = (p1.x + p2.x) / 2;
	//gluLookAt(camera_distance + 2, 4, 1.5, camera_distance, 0, 0, 0, 0, 1.0); // ????
	
	glDisable(GL_LIGHT1);
	if (camera) {
		glBegin(GL_QUADS);
		glVertex3f(camera_distance - 5, 7, -7);
		glVertex3f(camera_distance - 5, 7, -3);
		glVertex3f(camera_distance + 7, 1, -3);
		glVertex3f(camera_distance + 7, 1, -7);
		glEnd();
	}
	else {
		glBegin(GL_QUADS);
		glVertex3f(camera_distance - 5, 0, -5);
		glVertex3f(camera_distance - 5, 0, -4.3);
		glVertex3f(camera_distance + 5, 0, -4.3);
		glVertex3f(camera_distance + 5, 0, -5);
		glEnd();

	}
	if (lightOn)
		glEnable(GL_LIGHT1);
}

void Drawchar() {
	glDisable(GL_LIGHT1);
	//////////p1??????//////////
	glPushMatrix();
	glTranslated(p1.x, p1.y, p1.z + 0.9);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(Radius, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(p1.x, p1.y, p1.z - 0.6);
	glutSolidCone(0.5, 1.2, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(p1.x, p1.y + 0.15, p1.z - 0.7);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(p1.x, p1.y + 0.15, p1.z - 0.9);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(p1.x, p1.y - 0.15, p1.z - 0.7);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(p1.x, p1.y - 0.15, p1.z - 0.9);
	glutSolidCube(0.2);
	glPopMatrix();

	//////////p2??????//////////
	glPushMatrix();
	glTranslated(p2.x, p2.y, p2.z + 0.9);
	glColor3f(0.0, 1.0, 1.0);
	glutSolidSphere(Radius, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(p2.x, p2.y, p2.z - 0.6);
	glutSolidCone(0.5, 1.2, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(p2.x, p2.y + 0.15, p2.z - 0.7);
	glutSolidCube(0.2);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(p2.x, p2.y + 0.15, p2.z - 0.9);
	glutSolidCube(0.2);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(p2.x, p2.y - 0.15, p2.z - 0.7);
	glutSolidCube(0.2);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(p2.x, p2.y - 0.15, p2.z - 0.9);
	glutSolidCube(0.2);
	glPopMatrix();

	////????/////
	glPushMatrix();
	glTranslated(-155, 0.0, -0.5);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(Radius, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f(139.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
	glTranslated(-155, 0.0, -2.8);
	glutSolidCone(0.7, 2.0, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f(139.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
	glTranslated(-155, 0.15, -2.8);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-155, 0.15, -3.0);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-155, 0.15, -3.2);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-155, 0.15, -3.4);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(139.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
	glTranslated(-155, -0.15, -2.8);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-155, -0.15, -3.0);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-155, -0.15, -3.2);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-155, -0.15, -3.4);
	glutSolidCube(0.2);
	glPopMatrix();
	if (lightOn)
		glEnable(GL_LIGHT1);
}





void Collision_Player_To_Player() {
	////////////////?????????? ????????(??????)////////////////
	if (p1.x > p2.x) { // p1 - left
		if ((p1.z == p2.z) || ((p1.z + Radius >= p2.z - 1.5 * Radius) && (p1.z - 1.5 * Radius <= p2.z + Radius))) {
			if ((p1.x - p2.x) < 2 * Radius) {
				if (p1Right) {
					if ((p1.x - Radius) < (p2.x + Radius))
						p1.x = p2.x + 2 * Radius;
				}

				else if (p2Left) {
					if ((p1.x - Radius) < (p2.x + Radius))
						p2.x = p1.x - 2 * Radius;
				}
			}
		}
		//???????? ???? ????(??????)
		else if (((p1.z - 1.0) < (p2.z + 0.9 + Radius)) && ((p1.z - 1.0) > (p2.z - 1.0))) {
			if (p1.x - p2.x < 2 * Radius) {
				p1jumpMax = 1.5;
				p1.z = p2.z + 0.9 + 3 * Radius;
			}
			else p1jumpMax = 0.5;

		}

		else if (((p2.z - 1.0) < (p1.z + 0.9 + Radius)) && ((p2.z - 1.0) > (p1.z - 1.0))) {
			if (p1.x - p2.x < 2 * Radius) {
				p2jumpMax = 1.5;
				p2.z = p1.z + 0.9 + 3 * Radius;
			}
			else p2jumpMax = 0.5;

		}

	}

	else {
		if ((p1.z == p2.z) || ((p2.z + Radius >= p1.z - 1.5 * Radius) && (p2.z - 1.5 * Radius <= p1.z + Radius))) {

			if ((p2.x - p1.x) < 2 * Radius) {
				if (p1Left) {
					if ((p1.x + Radius) > (p2.x - Radius))
						p1.x = p2.x - 2 * Radius;
				}
				if (p2Right) {
					if ((p1.x - Radius) < (p2.x + Radius))
						p2.x = p1.x + 2 * Radius;
				}
			}

		}
		else if (((p1.z - 1.0) < (p2.z + +0.9 + Radius)) && ((p1.z - 1.0) > (p2.z - 1.0))) {
			if ((p2.x - p1.x < 2 * Radius)) {
				p1jumpMax = 1.5;
				p1.z = p2.z + 0.9 + 3 * Radius;
			}
			else
				p1jumpMax = 0.5;

		}

		else if (((p2.z - 1.0) < (p1.z + 0.9 + Radius)) && ((p2.z - 1.1) > (p1.z - 1.0))) {
			if (p2.x - p1.x < 2 * Radius) {
				p2jumpMax = 1.5;
				p2.z = p1.z + 0.9 + 3 * Radius;
			}
			else
				p2jumpMax = 0.5;

		}
	}

}



void jump() {
	float z1 = p1.z;
	float z2 = p2.z;

	//////////p1?????? ????//////////
	if (p1Jump == true && z1 <= p1jumpMax) {
		velocity1.z = jumpUp;

		if (z1 > p1jumpMax) {
			p1Jump = false;
		}
	}
	if (z1 > p1jumpMax || (p1Jump == false && z1 > bt)) {
		p1Jump = false;
		velocity1.z = jumpDown;
	}
	if (p1Jump == false && z1 <= bt) {
		p1.z = bt;
		velocity1.z = 0.0;
	}
	//////////p2?????? ????//////////
	if (p2Jump == true && z2 <= p2jumpMax) {
		velocity2.z = jumpUp;

		if (z2 > p2jumpMax) {
			p2Jump = false;
		}
	}

	if (z2 > p2jumpMax || (p2Jump == false && z2 > bt)) {
		p2Jump = false;
		velocity2.z = jumpDown;
	}

	if (p2Jump == false && z2 <= bt) {
		p2.z = bt;
		velocity2.z = 0.0;
	}

	glutPostRedisplay();
}

void roadModeling(void) {
	generalRoad road0(10.0, 0.0, -3.0);
	generalRoad road1(0.0, 0.0, -3.0);
	generalRoad road2(-10.0, 0.0, -3.0);
	generalRoad road3(-25.0, 0.0, -3.0);
	generalRoad road4(-35.0, 0.0, -3.0);
	generalRoad road5(-45.0, 0.0, -3.0);
	generalRoad road6(-55.0, 0.0, -3.0);
	generalRoad road7(-71.0, 0.0, -3.0);
	generalRoad road8(-81.0, 0.0, -3.0);
	generalRoad road9(-93.0, 0.0, -3.0);
	generalRoad road10(-100.0, 0.0, -3.0);
	generalRoad road11(-110.0, 0.0, -3.0);
	generalRoad road12(-125.5, 0.0, -3.0);
	generalRoad road13(-134.5, 0.0, -3.0);
	generalRoad road14(-150.5, 0.0, -3.0);
	generalRoad road15(-160.5, 0.0, -3.0);
	road0.draw_generalRoad();
	road1.draw_generalRoad();
	road2.draw_generalRoad();
	road3.draw_generalRoad();
	road4.draw_generalRoad();
	road5.draw_generalRoad();
	road6.draw_generalRoad();
	road7.draw_generalRoad();
	road8.draw_generalRoad();
	road9.draw_generalRoad();
	road10.draw_generalRoad();
	road11.draw_generalRoad();
	road12.draw_generalRoad();
	road13.draw_generalRoad();
	road14.draw_generalRoad();
	road15.draw_generalRoad();
	bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;

	a = road0.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	b = road1.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	c = road2.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	d = road3.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	e = road4.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	f = road5.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	g = road6.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	h = road7.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	i = road8.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	j = road9.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	k = road10.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	l = road11.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	m = road12.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	n = road13.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	o = road14.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	p = road15.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	for (int i = 'a'; i <= 'p'; i++) {
		if (a) {
			life--;
			return;
		}


	}

	glutPostRedisplay();
}

void objectModeling(void) {
	if(lightOn)
		glDisable(GL_LIGHT1);

	if (level == 1) {
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
	}
	else if (level == 2) {
		glEnable(GL_LIGHT2);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT3);
	}
	else if (level == 3) {
		glEnable(GL_LIGHT3);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT0);
	}


	pocachip1.draw_pocachip();
	pocachip1.collision_pocachip(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	pocachip1.draw_button();
	pocachip1.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	pepero1.draw_pepero();
	pepero1.collision_pepero(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	pepero1.draw_button();
	pepero1.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	pocachip2.draw_pocachip();
	pocachip2.collision_pocachip(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	pocachip2.draw_button();
	pocachip2.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	candy1.draw_candy();
	candy1.check_players_To_distance(p1.x, p2.x);
	candy1.collision_candy(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	icecream1.draw_icecream();
	icecream1.check_players_To_distance(p1.x, p2.x);
	icecream1.collision_icecream(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	icecream1.draw_button();
	icecream1.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	pocachip3.draw_pocachip();
	pocachip3.collision_pocachip(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	pocachip3.draw_button();
	pocachip3.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	cloud1.draw_cloud();
	cloud1.draw_button();
	cloud1.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	cloud1.collision_cloud(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	candy2.draw_candy();
	candy2.check_players_To_distance(p1.x, p2.x);
	candy2.collision_candy(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	cookie1.draw_cookie();
	cookie1.check_players_To_distance(p1.x, p2.x);
	cookie1.collision_cookie(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	icecream2.draw_icecream();
	icecream2.check_players_To_distance(p1.x, p2.x);
	icecream2.collision_icecream(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	icecream2.draw_button();
	icecream2.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	candy3.draw_candy();
	candy3.check_players_To_distance(p1.x, p2.x);
	candy3.collision_candy(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	cloud2.draw_cloud();
	cloud2.draw_button();
	cloud2.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	cloud2.collision_cloud(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);


	cookie2.draw_cookie();
	cookie2.check_players_To_distance(p1.x, p2.x);
	cookie2.collision_cookie(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	candy3.draw_candy();
	candy3.check_players_To_distance(p1.x, p2.x);
	candy3.collision_candy(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	cookie3.draw_cookie();
	cookie3.check_players_To_distance(p1.x, p2.x);
	cookie3.collision_cookie(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	candy4.draw_candy();
	candy4.check_players_To_distance(p1.x, p2.x);
	candy4.collision_candy(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	cookie4.draw_cookie();
	cookie4.check_players_To_distance(p1.x, p2.x);
	cookie4.collision_cookie(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	cr1.draw_cloud();
	cr1.collision_cloud(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	candy5.draw_candy();
	candy5.check_players_To_distance(p1.x, p2.x);
	candy5.collision_candy(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	minicookie1.draw_mini_cookie();
	minicookie1.collision_mini_cookie(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);

	//minicookie2.draw_mini_cookie();
	//minicookie2.collision_mini_cookie(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, life);
	
}

void cameraSet() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (camera) {
		if ((p1.x + p2.x) / 2 <= 5 - 4.95)
			camera_distance = (p1.x + p2.x) / 2;
		gluLookAt(camera_distance + 2, 4, 1.5, camera_distance, 0, 0, 0, 0, 1.0); // ????
	}

	else {
		if ((p1.x + p2.x) / 2 <= 5 - 4.95)
			camera_distance = (p1.x + p2.x) / 2;
		gluLookAt(camera_distance, p1.y + 4.0, 0.0, camera_distance, p1.y, 0.0, 0.0, 0.0, 1.0); // ????, ????
	}

}
void Level_up() {
	if (p1.x <= p2.x) { // p1?? ?? ??
		if (p1.x <= -55.8 && level != 2)
			level = 2;
		if (p1.x <= -117.0 && level != 3)
			level = 3;
	}
	else { // p2?? ?? ??
		if (p2.x <= -55.8 && level != 2)
			level = 2;
		if (p2.x <= -117.0 && level != 3)
			level = 3;
	}
}

void RenderScene(void) { // ???? ????
	float	x, y, z;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.7, 0.9, 1.0, 1.0);
	p1.z += velocity1.z;
	p2.z += velocity2.z;
	jump();


	if (life <= 0) {
		GameOver = true;
	}
	if (a == 0 && level == 1) {
		PlaySound(TEXT("lv.1.wav"), 0, SND_ASYNC | SND_LOOP);
		a++;

	}
	else if (b == 0 && level == 2) {
		//sndPlaySound(vbStringNull, SND_ASYNC);
		PlaySound(TEXT("lv.2.wav"), 0, SND_ASYNC | SND_ALIAS);
		b++;

	}
	else if (c == 0 && level == 3 && !(GameClear)) {
		sndPlaySoundA("lv.3.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
		c++;

	}
	if (d ==0 && level == 3 && GameClear) {
		sndPlaySoundA("????.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
		d++;

	}
	if (level == 1) {
		light_1 = true;

		//light_pos = -55.8 + camera_distance;
	}
	if (level == 2) {

		light_2 = true;
	}
	if (level == 3) {
		light_2 = true;

	}


	if (start_flag == 0) { // 
		glShadeModel(GL_FLAT);						// ???? ?????? ????_1
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		glRasterPos3i(4, 2, -4.5);
		glDrawPixels(bitmapInfoHeader4.biWidth, bitmapInfoHeader4.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapImage_4);
	}
	if (start_flag == 1) { // 
		glShadeModel(GL_FLAT);						// ???? ?????? ????_2
		glPixelStorei(GL_UNPACK_ALIGNMENT, 5);
		glRasterPos3i(4, 2, -4.5);
		glDrawPixels(bitmapInfoHeader5.biWidth, bitmapInfoHeader5.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapImage_5);
	}
	if (GameOver == true) {
		glShadeModel(GL_FLAT);						// ???????? ?????? ????
		glPixelStorei(GL_UNPACK_ALIGNMENT, 2);
		glRasterPos3i(camera_distance + 3.5, 2, -4.5);
		glDrawPixels(bitmapInfoHeader2.biWidth, bitmapInfoHeader2.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapImage_2);

		string text1 = to_string(level); // ???? ?? ?????? ????
		string text2 = to_string(life);
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(camera_distance - 3, 3, 0);
		for (int i = 0; i < text1.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);
		}
		glRasterPos3f(camera_distance - 2.7, 3, -0.8);
		for (int i = 0; i < text2.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
		}
	}
	if (start_flag % 2 && start_flag >= 2 && GameClear == false) { // 
		glShadeModel(GL_FLAT);						// ???????? ?????? ????
		glPixelStorei(GL_UNPACK_ALIGNMENT, 3);
		glRasterPos3i(camera_distance + 4.5, 2, -4.5);
		glDrawPixels(bitmapInfoHeader3.biWidth, bitmapInfoHeader3.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapImage_3);

		string text1 = to_string(level); // ???? ?? ?????? ????
		string text2 = to_string(life);
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(camera_distance - 0.5, 3, -2.8);
		for (int i = 0; i < text1.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);
		}
		glRasterPos3f(camera_distance - 0.5, 3, -3.3);
		for (int i = 0; i < text2.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
		}
	}

	if (p1.x <= -153.0 || p2.x <= -153.0) {
		GameClear = true;
		glShadeModel(GL_FLAT);						// ?????? ?????? ????
		glPixelStorei(GL_UNPACK_ALIGNMENT, 6);
		glRasterPos3i(-148, 2, -4.5);
		glDrawPixels(bitmapInfoHeader6.biWidth, bitmapInfoHeader6.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapImage_6);


		string text1 = to_string(level); // ???? ?? ?????? ????
		string text2 = to_string(life);
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-152.5, 3, 0);
		for (int i = 0; i < text1.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);
		}
		glRasterPos3f(-152.5, 3, -0.8);
		for (int i = 0; i < text2.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
		}
	}
	////////////////???? ???? ????(??????)////////////////
	if (camera) {
		//left_ = -5.0; right_ = 5.0;bottom_ = -5.0;top_ = 5.0;zNear_ = -5.0;zFar_ = 15.0;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // ?????? ???? ????.
		glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 15.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//if ((p1.x + p2.x) / 2 <= 5 - 4.95)
		//	camera_distance = (p1.x + p2.x) / 2;
		//gluLookAt(camera_distance, p1.y + 4.0, 0.0, camera_distance, p1.y, 0.0, 0.0, 0.0, 1.0); // ????, ????
		cameraSet();
		//gluLookAt(p1.x, p1.y, p1.z, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
		//gluLookAt(p1.x, p1.y, p1.z, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0); // ????, ????

	}
	else {
		//left_ = -50.0; right_ = 50.0;bottom_ = -50.0;top_ = 50.0;zNear_ = -10.0;zFar_ = 15.0;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glOrtho(-50.0, 50.0, -50.0, 50.0, -10.0, 15.0);
		glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 15.0);
		cameraSet();
	}
	////////////////////////////////////////////////////////
	// Camera Position 
	x = camera_distance * cos(camera_phi) * cos(camera_theta);
	y = camera_distance * cos(camera_phi) * sin(camera_theta);
	z = camera_distance * sin(camera_phi);

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glShadeModel(GL_FLAT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	if (lightOn) { // ??????
		glEnable(GL_LIGHT1);
	}
	else
		glDisable(GL_LIGHT1);

	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(5.0, -1.7, -5.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-155.0, -1.7, -5.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-155.0, -1.7, 5.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(5.0, -1.7, 5.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	Level_up();

	

	if (level == 1) {
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
	}
	else if (level == 2) {
		glEnable(GL_LIGHT2);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT3);
	}
	else if (level == 3) {
		glEnable(GL_LIGHT3);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT0);
	}

	Modeling_Score();




	Drawchar();
	objectModeling();
	Collision_Player_To_Player();
	roadModeling();

	string text1;

	if (level == 1)
		text1 = "Level : " + to_string(level) + "  (mane's road)      " + "life : " + to_string(life); // ???? ?????? ?????? ????

	else if (level == 2) {
		glColor3f(49.0 / 255.0, 22.0 / 255.0, 125.0 / 255.0);
		text1 = "Level : " + to_string(level) + "  (nox's road)      " + "life : " + to_string(life); // ???? ?????? ?????? ????
	}
	else if (level == 3) {
		glColor3f(121.0 / 255.0, 21.0 / 255.0, 11.0 / 255.0);
		text1 = "Level : " + to_string(level) + "  (Rolar's road)      " + "life : " + to_string(life); // ???? ?????? ?????? ????
	}
	//glColor3f(0.2, 0.2, 0.2);

	if (camera) {
		glRasterPos3f(camera_distance + 6.3, 2, -3.1);

	}
	else {
		glRasterPos3f(camera_distance + 4.8, 3, -4.6);
	}
	for (int i = 0; i < text1.size(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);
	}

	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void SpecialKey(int key, int x, int y) {
	if (start_flag >= 2 && GameOver == false && !(start_flag % 2) && GameClear == false) {
		switch (key) {
		case GLUT_KEY_LEFT:
			if (camera_distance + 4.95 >= p1.x + 0.5) {
				p1.x += moveDistance;
				//cout << p1.x << endl;
				//cout << center << endl << endl;
			}

			p1Left = true;
			p1Right = false;
			//camera_distance += 0.1;
			break;
		case GLUT_KEY_RIGHT:
			if (camera_distance - 4.95 <= p1.x - 0.5) {
				p1.x -= moveDistance;

				//cout << p1.x << endl;
			}
			p1Left = false;
			p1Right = true;
			//camera_distance -= 0.1;
			break;

			//p1Jump()
		case GLUT_KEY_UP:
			if (!p1Jump) { p1Jump = true; }
			//   else p1Jump = false;
			break;

			//viewport ????
		case GLUT_KEY_INSERT: camera = !(camera); break;

		case GLUT_KEY_PAGE_UP: lightOn = !(lightOn); break;
		default:
			p1Left = false;
			p1Right = false;
			break;
		}
	}

	glutPostRedisplay();

}

void Keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'a':
		if (start_flag >= 2 && GameOver == false && !(start_flag % 2) && GameClear == false) {
			if (camera_distance + 4.95 >= p2.x + 0.5)
				p2.x += moveDistance;
			p2Left = true;
			p2Right = false;
		}

		break;
	case 'd':
		if (start_flag >= 2 && GameOver == false && !(start_flag % 2) && GameClear == false) {
			if (camera_distance - 4.95 <= p2.x - 0.5)
				p2.x -= moveDistance;
			p2Left = false;
			p2Right = true;
		}

		break;
	case 'w':if (start_flag >= 2 && GameOver == false && !(start_flag % 2) && GameClear == false) {
		if (!p2Jump) p2Jump = true;
	}

			break;
			//else p2Jump = false; break;
	case 13: // enter (???? ????)
		start_flag++;
		break;
	case 27: // ???? ESC
		exit(0);
		break;
	case 32: // ???????? SpaceBar
		if (GameOver == false) {
			if (start_flag >= 2) {
				start_flag++;
				break;
			}
		}
		

	default:
		p2Left = false;
		p2Right = false;
		break;
	}
	glutPostRedisplay();
}

void SpecialKeyUp(int key, int x, int y) {
	
		switch (key)
		{
			
		case GLUT_KEY_LEFT:
			if (start_flag >= 2 && GameOver == false && !(start_flag % 2) && GameClear == false) {
				p1Left = false;
				p1Right = false;
			}
			break;
		case GLUT_KEY_RIGHT:
			if (start_flag >= 2 && GameOver == false && !(start_flag % 2) && GameClear == false) {
				p1Left = false;
				p1Right = false;
			}
			break;
		case GLUT_KEY_END:		// ??????
			init();
		default:
			break;
		}
	}


void KeyboardUp(unsigned char key, int x, int y) {
	if (start_flag >= 2 && GameOver == false && !(start_flag % 2) && GameClear == false) {
		switch (key)
		{
		case 'a':
			p2Left = false;
			p2Right = false;
			break;
		case 'd':
			p2Left = false;
			p2Right = false;
			break;

		default:
			break;
		}
	}

	glutPostRedisplay();
}

void main(int argc, char** argv) {
	glutInitWindowPosition(200, 50);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // ?????????????? ?????? ???? DOUBLE?? ??
	glutInitWindowSize(width, height);
	glutCreateWindow("To the dawn");
	init();
	glutReshapeFunc(MyReshape); // ???? ????
	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene); // ???????? ???? ?????? ?????? ???????? ??????!!!(??????, ?????? ?????? ?????? ????)

	glutSpecialFunc(SpecialKey);
	glutSpecialUpFunc(SpecialKeyUp);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyboardUp);
	glutMainLoop();
}