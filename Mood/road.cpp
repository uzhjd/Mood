// 길 //
// 1. 일반 길 2. 충돌체크 //
#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <iostream>
using namespace std;

//static GLuint	grasstexture;



// 전체 배경화면
//static BITMAPINFOHEADER bitmapInfoHeader10;
//static unsigned char* bitmapImage_10 = LoadBitmapFile("grass.bmp", &bitmapInfoHeader10);

// 1. 일반 길 //
class generalRoad {
private:
	/// 길 위치///
	float x;
	float y;
	float z;

public:
	generalRoad(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;

		//glEnable(GL_DEPTH_TEST);
		//glEnable(GL_TEXTURE_2D);

		//glGenTextures(1, &grasstexture);
		//glBindTexture(GL_TEXTURE_2D, grasstexture);


		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		////   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		////glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader10.biWidth,
		//	bitmapInfoHeader10.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapImage_10);
	}

	void draw_generalRoad() {
		/*glShadeModel(GL_FLAT);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);*/

		glColor3f(0.56, 0.47, 0.29);
		/*glBindTexture(GL_TEXTURE_2D, grasstexture);*/

		glPushMatrix();
		glTranslatef(x, y, z);


		glBegin(GL_QUADS);

		/*glTexCoord2f(0.0, 0.0);*/
		glVertex3f(0.0, y + 10.0, -0.5);

		//glTexCoord2f(1.0, 0.0);
		glVertex3f(-10.0, y + 10.0, -0.5);

		//glTexCoord2f(1.0, 1.0);
		glVertex3f(-10.0, y + 10.0, -1.0);

		//glTexCoord2f(0.0, 1.0);
		glVertex3f(0.0, y + 10.0, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 10.0, -0.5);
		glVertex3f(0.0, y - 1, -0.5);
		glVertex3f(0.0, y - 1, -1.0);
		glVertex3f(0.0, y + 10.0, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1, -0.5);
		glVertex3f(-10.0, y - 1, -0.5);
		glVertex3f(-10.0, y - 1, -1.0);
		glVertex3f(0.0, y - 1, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-10.0, y + 10.0, -0.5);
		glVertex3f(-10.0, y - 1, -0.5);
		glVertex3f(-10.0, y - 1, -1.0);
		glVertex3f(-10.0, y + 10.0, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 10.0, -0.5);
		glVertex3f(-10.0, y + 10.0, -0.5);
		glVertex3f(-10.0, y - 1, -0.5);
		glVertex3f(0.0, y - 1, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 10.0, -1.0);
		glVertex3f(-10.0, y + 10.0, -1.0);
		glVertex3f(-10.0, y - 1, -1.0);
		glVertex3f(0.0, y - 1, -1.0);
		glEnd();/*
		glBindTexture(GL_TEXTURE_2D, 0);*/

		glPopMatrix();

		glutPostRedisplay();
	}


	// 3. 충돌 체크
	bool collisionRoad(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 2 * 0.5;
		float p1middle = p1z - 1.5 * 0.5;
		float p2bottom = p2z - 2 * 0.5;
		float p2middle = p2z - 1.5 * 0.5;
		if (p1x + 0.5 >= (x - 10.0) && p1x - 0.5 <= x) { //빼빼로 x값 사이에 p1이 있을 때
			if (z - 0.5 >= p1bottom && p1middle >= z - 0.5) {
				p1z = z + 0.5;
			}
			/*else if (p1x >= x)
				p1x = x + 0.5;
			else if (p1x <= x - 6.0) {
				p1x = x - 6.0 - 0.5;
			}*/


		}

		if (p2x + 0.5 >= (x - 10.0) && p2x - 0.5 <= x) { //빼빼로 x값 사이에 p2이 있을 때
			if (z - 0.5 >= p2bottom && p2middle >= z - 0.5) {
				p2z = z + 0.5;
			}
			/*else if (p2x >= x)
				p2x = x + 0.5;
			else if (p2x <= x - 6.0) {
				p2x = x - 6.0 - 0.5;
			}*/


		}

		if (p1bottom <= z - 1.0) {
			// life깍기게 하기
			p1x = p1x + 0.9;
			p1z = z + 0.5;
			return true;
		}

		if (p2bottom <= z - 1.0) {
			// life깍기게 하기
			p2x = p2x + 0.9;
			p2z = z + 0.5;
			return true;
		}
		return false;
	}
};



//// 2. 낭떠러지 //
//class cliff {
//private:
//	/// 길 위치///
//	float x;
//	float y;
//	float z;
//
//public:
//	cliff(float x, float y, float z) {
//		this->x = x;
//		this->y = y;
//		this->z = z;
//
//	}
//
//	void draw_cliff() {
//		glPushMatrix();
//		glTranslatef(x, y, z);
//		glColor3f(1.0, 1.0, 1.0);
//
//		glBegin(GL_QUADS);
//		glVertex3f(0.0, y + 1.5, -0.5);
//		glVertex3f(-4.0, y + 1.5, -0.5);
//		glVertex3f(-4.0, y + 1.5, -1.0);
//		glVertex3f(0.0, y + 1.5, -1.0);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(0.0, y + 1.5, -0.5);
//		glVertex3f(0.0, y - 1.5, -0.5);
//		glVertex3f(0.0, y - 1.5, -1.0);
//		glVertex3f(0.0, y + 1.5, -1.0);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(0.0, y - 1.5, -0.5);
//		glVertex3f(-4.0, y - 1.5, -0.5);
//		glVertex3f(-4.0, y - 1.5, -1.0);
//		glVertex3f(0.0, y - 1.5, -1.0);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(-4.0, y + 1.5, -0.5);
//		glVertex3f(-4.0, y - 1.5, -0.5);
//		glVertex3f(-4.0, y - 1.5, -1.0);
//		glVertex3f(-4.0, y + 1.5, -1.0);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(0.0, y + 1.5, -0.5);
//		glVertex3f(-4.0, y + 1.5, -0.5);
//		glVertex3f(-4.0, y - 1.5, -0.5);
//		glVertex3f(0.0, y - 1.5, -0.5);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(0.0, y + 1.5, -1.0);
//		glVertex3f(-4.0, y + 1.5, -1.0);
//		glVertex3f(-4.0, y - 1.5, -1.0);
//		glVertex3f(0.0, y - 1.5, -1.0);
//		glEnd();
//
//
//		//////////////////////////////////////
//		glBegin(GL_QUADS);
//		glVertex3f(-8.0, y + 1.5, -0.5);
//		glVertex3f(-12.0, y + 1.5, -0.5);
//		glVertex3f(-12.0, y + 1.5, -1.0);
//		glVertex3f(-8.0, y + 1.5, -1.0);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(-8.0, y + 1.5, -0.5);
//		glVertex3f(-8.0, y - 1.5, -0.5);
//		glVertex3f(-8.0, y - 1.5, -1.0);
//		glVertex3f(-8.0, y + 1.5, -1.0);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(-8.0, y - 1.5, -0.5);
//		glVertex3f(-12.0, y - 1.5, -0.5);
//		glVertex3f(-12.0, y - 1.5, -1.0);
//		glVertex3f(-8.0, y - 1.5, -1.0);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(-12.0, y + 1.5, -0.5);
//		glVertex3f(-12.0, y - 1.5, -0.5);
//		glVertex3f(-12.0, y - 1.5, -1.0);
//		glVertex3f(-12.0, y + 1.5, -1.0);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(-8.0, y + 1.5, -0.5);
//		glVertex3f(-12.0, y + 1.5, -0.5);
//		glVertex3f(-12.0, y - 1.5, -0.5);
//		glVertex3f(-8.0, y - 1.5, -0.5);
//		glEnd();
//
//		glBegin(GL_QUADS);
//		glVertex3f(-8.0, y + 1.5, -1.0);
//		glVertex3f(-12.0, y + 1.5, -1.0);
//		glVertex3f(-12.0, y - 1.5, -1.0);
//		glVertex3f(-8.0, y - 1.5, -1.0);
//		glEnd();
//
//		glPopMatrix();
//
//		glutPostRedisplay();
//	}
//
//	//// 3. 충돌 체크
//	//void collisionRoad(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
//	//	/*float p1_bottom = p1z - 3 * 0.5;
//	//	float p2_bottom = p2z - 3 * 0.5;*/
//
//	//	if (p1x + 0.5 >= (x - 10.0) && p1x - 0.5 <= x) { //p1이 길의 범위 안에 있을 때
//	//		p1z += 0.5;
//	//	}
//
//	//	if (p2x + 0.5 >= (x - 10.0) && p2x - 0.5 <= x) { //빼빼로 x값 사이에 p2이 있을 때
//	//		p2z += 0.5;
//
//
//	//	}
//
//	//}
//
//};