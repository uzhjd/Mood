// 길 //
// 1. 일반 길 2. 낭떠러지 //
#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <iostream>
#include <string>
using namespace std;

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
		
	}

	void draw_generalRoad() {
		glPushMatrix();
		glTranslatef(x, y, z);
		glColor3f(0.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-10.0, y + 1.5, -0.5);
		glVertex3f(-10.0, y + 1.5, -1.0);
		glVertex3f(0.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -1.0);
		glVertex3f(0.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(-10.0, y - 1.5, -0.5);
		glVertex3f(-10.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-10.0, y + 1.5, -0.5);
		glVertex3f(-10.0, y - 1.5, -0.5);
		glVertex3f(-10.0, y - 1.5, -1.0);
		glVertex3f(-10.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-10.0, y + 1.5, -0.5);
		glVertex3f(-10.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -1.0);
		glVertex3f(-10.0, y + 1.5, -1.0);
		glVertex3f(-10.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		glPopMatrix();

		glutPostRedisplay();
	}
};


// 2. 낭떠러지 //
class cliff {
private:
	/// 길 위치///
	float x;
	float y;
	float z;

public:
	cliff(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;

	}

	void draw_cliff() {
		glPushMatrix();
		glTranslatef(x, y, z);
		glColor3f(1.0, 1.0, 1.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-4.0, y + 1.5, -0.5);
		glVertex3f(-4.0, y + 1.5, -1.0);
		glVertex3f(0.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -1.0);
		glVertex3f(0.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(-4.0, y - 1.5, -0.5);
		glVertex3f(-4.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-4.0, y + 1.5, -0.5);
		glVertex3f(-4.0, y - 1.5, -0.5);
		glVertex3f(-4.0, y - 1.5, -1.0);
		glVertex3f(-4.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-4.0, y + 1.5, -0.5);
		glVertex3f(-4.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -1.0);
		glVertex3f(-4.0, y + 1.5, -1.0);
		glVertex3f(-4.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();


		//////////////////////////////////////
		glBegin(GL_QUADS);
		glVertex3f(-8.0, y + 1.5, -0.5);
		glVertex3f(-12.0, y + 1.5, -0.5);
		glVertex3f(-12.0, y + 1.5, -1.0);
		glVertex3f(-8.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-8.0, y + 1.5, -0.5);
		glVertex3f(-8.0, y - 1.5, -0.5);
		glVertex3f(-8.0, y - 1.5, -1.0);
		glVertex3f(-8.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-8.0, y - 1.5, -0.5);
		glVertex3f(-12.0, y - 1.5, -0.5);
		glVertex3f(-12.0, y - 1.5, -1.0);
		glVertex3f(-8.0, y - 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-12.0, y + 1.5, -0.5);
		glVertex3f(-12.0, y - 1.5, -0.5);
		glVertex3f(-12.0, y - 1.5, -1.0);
		glVertex3f(-12.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-8.0, y + 1.5, -0.5);
		glVertex3f(-12.0, y + 1.5, -0.5);
		glVertex3f(-12.0, y - 1.5, -0.5);
		glVertex3f(-8.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-8.0, y + 1.5, -1.0);
		glVertex3f(-12.0, y + 1.5, -1.0);
		glVertex3f(-12.0, y - 1.5, -1.0);
		glVertex3f(-8.0, y - 1.5, -1.0);
		glEnd();

		glPopMatrix();

		glutPostRedisplay();
	}
};