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

//#define score_height	40
#define	width 			700
#define	height			700
#define GRAVITY

float	camera_distance;
float	camera_theta, camera_phi;

float jumpMax = 0.5, bt = -3.0;
const float timeFactor = 2000;

#define PI 3.141592

float	lightPositionR[] = { 0.0f, 0.0f, 5.0f, 1.0f };
boolean	camera = false;
boolean p1Jump = false;
boolean p2Jump = false;
float Radius, moveDistance, jumpUp, jumpDown;

boolean p1Left, p1Right, p2Left, p2Right;
float left_, right_, top_, bottom_, zNear_, zFar_;

object_pepero pepero1(-8.0, 0.0, -3.0);
object_pocachip pocachip(-8.0, 0.0, -3.0);
object_cookie cookie(-8.0, 0.0, -3.0);

struct position {
	float x;
	float y;
	float z;
};
position p1, p2, velocity1, velocity2;

GLuint	texture;

unsigned char* LoadBitmapFile(const char* filename, BITMAPINFOHEADER* bitmapInfoHeader) { // ����̹���
	FILE* filePtr;
	BITMAPFILEHEADER bitmapFileHeader;
	unsigned char* bitmapImage;
	int imageIdx = 0;
	unsigned char tempRGB;
	errno_t err;
	err = fopen_s(&filePtr, filename, "rb");
	if (filePtr == NULL)
		return NULL;
	// ��Ʈ�� ���� ��带 �д´�.
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
	// �������� BMP �������� Ȯ���Ѵ�. 
	if (bitmapFileHeader.bfType != 'MB') {
		fclose(filePtr);
		return (NULL);
	}
	// ��Ʈ�� ���� ��带 �д´�.
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
	// ���� �����͸� ��Ʈ�� �������� ���� ��ġ�� �ű��. 
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
	// ��Ʈ�� �̹��� �����͸� ���� �޸𸮸� �Ҵ��Ѵ�. 
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);
	//�޸𸮰� ����� �Ҵ�Ǿ����� Ȯ�� 
	if (!bitmapImage) {
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}
	// �޸𸮿� ��Ʈ�� ����Ʈ�� �о�帲 
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
	// ����� ������ Ȯ�� 
	if (bitmapImage == NULL) {
		fclose(filePtr);
		return NULL;
	}
	//BMP�� BGR�����̹Ƿ� R�� B�� ���� ��ü�ؾ� ��
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3) {
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}
	// ������ �ݰ� ��Ʈ�� �̹��� ������ ��ȯ 
	fclose(filePtr);
	return bitmapImage;
}

BITMAPINFOHEADER bitmapInfoHeader1;
unsigned char* bitmapImage_1 = LoadBitmapFile("background.bmp", &bitmapInfoHeader1);
// ��ü ���ȭ��
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
	velocity1 = { 0.0,0.0,0.0 };
	velocity2 = { 0.0,0.0,0.0 };
	p1.x = -0.5; p1.y = 0.0; p1.z = bt; //ĳ���� 1 ��ġ
	p2.x = -2.0;p2.y = 0.0;p2.z = bt; //ĳ���� 2 ��ġ

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
}

void MyReshape(int w, int h) { // ���� �� �ʱ�ȭ
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-30.0, 30.0, -30.0, 30.0, 1.0, 150.0);
	gluPerspective(60.0, 1.0, 1.0, 2000.0);
	//gluOrtho2D(left_, left_ + width, bottom, bottom + height);

}

//void Modeling_Score() { // ������ �����
//	glColor3f(0.8, 0.5, 0.5);
//	glRectf(0, 0, width, score_height);
//}

void Drawchar() {
	//////////p1ĳ����//////////
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
	glTranslated(p1.x, p1.y - 0.15, p1.z - 0.6);
	glutSolidCube(0.2);
	glPopMatrix();

	//////////p2ĳ����//////////
	glPushMatrix();
	glTranslated(p2.x, p2.y, p2.z);
	glColor3f(1.0, 0.0, 1.0);
	glutSolidSphere(Radius, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glTranslated(p2.x, p2.y, p2.z - 0.5);
	glutSolidSphere(Radius, 30, 30);
	glPopMatrix();

}

void axis(void) {

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); // x��   ������
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0); // y�� �ʷϻ�
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);

	glColor3f(0.0, 0.0, 1.0); // z�� �Ķ���
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 100.0);
	glEnd();


}


void Collision_Player_To_Player() {
	////////////////�÷��̾ �浹üũ(������)////////////////
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
		//�÷��̾� �Ӹ� �浹(������)
		else if (((p1.z - 2.0 * Radius) <= (p2.z + Radius)) && ((p1.z - 1.5 * Radius) > (p2.z - 1.5 * Radius))) {
			if (p1.x - p2.x < 2 * Radius)
				p1.z = p2.z + 3.0 * Radius;
		}

		else if (((p2.z - 2.0 * Radius) <= (p1.z + Radius)) && ((p2.z - 1.5 * Radius) > (p1.z - 1.5 * Radius))) {
			if (p1.x - p2.x < 2 * Radius)
				p2.z = p1.z + 3.0 * Radius;
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
		else if (((p1.z - 2.0 * Radius) <= (p2.z + Radius)) && ((p1.z - 1.5 * Radius) > (p2.z - 1.5 * Radius))) {
			if ((p2.x - p1.x < 2 * Radius))
				p1.z = p2.z + 3.0 * Radius;
		}

		else if (((p2.z - 2.0 * Radius) <= (p1.z + Radius)) && ((p2.z - 1.5 * Radius) > (p1.z - 1.5 * Radius))) {
			if (p2.x - p1.x < 2 * Radius)
				p2.z = p1.z + 3.0 * Radius;
		}
	}

}

void cameraSet() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera_distance = (p1.x + p2.x) / 2;
	gluLookAt(p1.x, p1.y + 4.0, 0.0, p1.x, p1.y, 0.0, 0.0, 0.0, 1.0); // ����, ��ġ
}

void jump() {
	float z1 = p1.z;
	float z2 = p2.z;
	//////////p1ĳ���� ����//////////
	if (p1Jump == true && z1 <= jumpMax) {
		velocity1.z = jumpUp;

		if (z1 > jumpMax) {
			p1Jump = false;
		}
	}
	if (z1 > jumpMax || (p1Jump == false && z1 > bt)) {
		p1Jump = false;
		velocity1.z = jumpDown;
	}
	if (p1Jump == false && z1 <= bt) {
		p1.z = bt;
		velocity1.z = 0.0;
	}
	//////////p2ĳ���� ����//////////
	if (p2Jump == true && z2 <= jumpMax) {
		velocity2.z = jumpUp;

		if (z2 > jumpMax) {
			p2Jump = false;
		}
	}

	if (z2 > jumpMax||(p2Jump == false && z2 > bt)) {
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
	generalRoad road3(-22.0, 0.0, -3.0);
	generalRoad road4(-34.0, 0.0, -3.0);
	generalRoad road5(-44.0, 0.0, -3.0);
	generalRoad road6(-54.0, 0.0, -3.0);
	generalRoad road7(-66.0, 0.0, -3.0);
	generalRoad road8(-78.0, 0.0, -3.0);
	generalRoad road9(-88.0, 0.0, -3.0);
	generalRoad road10(-100.0, 0.0, -3.0);
	generalRoad road11(-110.0, 0.0, -3.0);
	generalRoad road12(-122.0, 0.0, -3.0);
	generalRoad road13(-124.0, 0.0, -3.0);
	generalRoad road14(-134.0, 0.0, -3.0);
	generalRoad road15(-146.0, 0.0, -3.0);

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
		

	road0.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road1.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road2.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road3.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road4.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road5.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road6.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road7.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road8.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road9.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road10.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road11.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road12.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road13.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road14.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	road15.collisionRoad(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	glutPostRedisplay();
}

void RenderScene(void) { // ���� ȭ��
	float	x, y, z;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 0.0, 0.0);
	p1.z += velocity1.z;
	p2.z += velocity2.z;
	jump();

	////////////////ȭ�� ���� �ڵ�(������)////////////////
	if (camera) {
		left_ = -5.0; right_ = 5.0;bottom_ = -5.0;top_ = 5.0;zNear_ = -5.0;zFar_ = 15.0;
		glViewport(0, 0, width / 2, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Ŭ���� ���� ����.
		glOrtho(left_, right_, bottom_, top_, zNear_, zFar_);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(p1.x, p1.y, p1.z, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0); // ����, ��ġ

		glViewport(width / 2, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(left_, right_, bottom_, top_, zNear_, zFar_);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(p2.x, p2.y, p2.z, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);

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

	glShadeModel(GL_FLAT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

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




	glLightfv(GL_LIGHT1, GL_POSITION, lightPositionR); // (lightPositionR[0], lightPositionR[1], lightPositionR[2]) in Camera Coordinates
	//Modeling_Score();

	axis();
	Drawchar();
	Collision_Player_To_Player();

	pepero1.draw_pepero();
	pepero1.collision_pepero(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	pepero1.draw_button();
	pepero1.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	roadModeling();

	/*pocachip.draw_pocachip();
	pocachip.collision_pocachip(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	pocachip.draw_button();
	pocachip.collision_button(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);*/

	//cookie.draw_cookie();
	//cookie.check_players_To_distance(p1.x, p2.x);

	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}
void SpecialKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT:
		p1.x += moveDistance;
		p1Left = true;
		p1Right = false;
		//camera_distance += 0.1;
		break;
	case GLUT_KEY_RIGHT:
		p1.x -= moveDistance;
		p1Left = false;
		p1Right = true;
		//camera_distance -= 0.1;
		break;

		//p1Jump()
	case GLUT_KEY_UP:
		if (!p1Jump) { p1Jump = true; }
		//   else p1Jump = false;
		break;

		//viewport ����
	case GLUT_KEY_INSERT: camera = !(camera); break;

	default:
		p1Left = false;
		p1Right = false;
		break;
	}
	glutPostRedisplay();

}

void Keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'a':
		p2.x += moveDistance;
		p2Left = true;
		p2Right = false;
		break;
	case 'd':
		p2.x -= moveDistance;
		p2Left = false;
		p2Right = true;
		break;
	case 'w':
		if (!p2Jump) p2Jump = true;
		break;
		//else p2Jump = false; break;
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
		p1Left = false;
		p1Right = false;
		break;
	case GLUT_KEY_RIGHT:
		p1Left = false;
		p1Right = false;
		break;
	default:
		break;
	}
}

void KeyboardUp(unsigned char key, int x, int y) {
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
	glutPostRedisplay();
}

void main(int argc, char** argv) {
	glutInitWindowPosition(200, 50);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // �ִϸ��̼�ó�� ���̱� ���� DOUBLE�� ��
	glutInitWindowSize(width, height);
	glutCreateWindow("To the dawn");
	init();
	glutReshapeFunc(MyReshape); // ���� ����
	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene); // �ƹ����� ���� ���ص� �װ��� �̺�Ʈ�� ��ƶ�!!!(���콺, Ű���� �Է��� ������ �߻�)

	glutSpecialFunc(SpecialKey);
	glutSpecialUpFunc(SpecialKeyUp);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyboardUp);
	//   
	//   //if (you) {
	//   //   sndPlaySoundA("music.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	////
	//   //}
	glutMainLoop();
}