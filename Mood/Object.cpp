/////장애물 클래스 모아놓는 곳
#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <iostream>
#include <string>
using namespace std;

//빼빼로클래스//
class object_pepero {
private:
	///빼빼로 위치///
	float x;
	float y;
	float z;
	///왼쪽버튼위치///
	float bx1;
	float by1;
	float bz1;
	///오른쪽버튼위치///
	float bx2;
	float by2;
	float bz2;
	///각각 버튼 눌렸는지 확인///
	bool button1, button2;

public:
	object_pepero(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->bx1 = x + 5.0;
		this->by1 = y;
		this->bz1 = z;

		this->bx2 = x + 3.0;
		this->by2 = y;
		this->bz2 = z;

		button1 = false;
		button2 = false;

	}
	void draw_pepero() {
		glPushMatrix();
		glColor3f(1.0, 1.0, 0.0);
		glTranslatef(x, y, z);
		glColor3f(0.0, 1.0, 1.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-6.0, y + 1.5, -0.5);
		glVertex3f(-6.0, y + 1.5, -1.0);
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
		glVertex3f(-6.0, y - 1.5, -0.5);
		glVertex3f(-6.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-6.0, y + 1.5, -0.5);
		glVertex3f(-6.0, y - 1.5, -0.5);
		glVertex3f(-6.0, y - 1.5, -1.0);
		glVertex3f(-6.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-6.0, y + 1.5, -0.5);
		glVertex3f(-6.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -1.0);
		glVertex3f(-6.0, y + 1.5, -1.0);
		glVertex3f(-6.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		glPopMatrix();



		glutPostRedisplay();
	}

	void draw_button() {
		glPushMatrix();
		glTranslatef(bx1, y, z);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(bx2, y, z);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();


		glPopMatrix();
	}

	void collision_pepero(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 2 * 0.5;
		float p1middle = p1z - 1.5 * 0.5;
		float p2bottom = p2z - 2 * 0.5;
		float p2middle = p2z - 1.5 * 0.5;
		if (p1x + 0.5 >= (x - 6.0) && p1x - 0.5 <= x) { //빼빼로 x값 사이에 p1이 있을 때
			if (z - 0.5 >= p1bottom) {
				p1z = z + 0.5;
			}
			else if (p1x >= x)
				p1x = x + 0.5;
			else if (p1x <= x - 6.0) {
				p1x = x - 6.0 - 0.5;
			}

		}

		if (p2x + 0.5 >= (x - 6.0) && p2x - 0.5 <= x) { //빼빼로 x값 사이에 p2이 있을 때
			if (z - 0.5 >= p2bottom && p2middle >= z - 0.5) {
				p2z = z + 0.5;
			}
			else if (p2x >= x)
				p2x = x + 0.5;
			else if (p2x <= x - 6.0) {
				p2x = x - 6.0 - 0.5;
			}


		}

	}

	void collision_button(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.1;
		float p2bottom = p2z - 1.1;
		if (p1x + 0.5 >= (bx1 - 1.0) && p1x - 0.5 <= bx1) {
			if (bz1 >= p1bottom) {
				p1z = bz1 + 1.0;
			}
			else if (p1x >= bx1) {
				p1x = bx1 + 0.5;
			}

			else if (p1x <= bx1 - 0.5) {
				p1x = bx1 - 1.0;
			}


		}

		if (p2x + 0.5 >= (bx1 - 1.0) && p2x - 0.5 <= bx1) {
			if (bz1 >= p2bottom) {
				p2z = bz1 + 1.0;
			}
			else if (p2x >= bx1) {
				p2x = bx1 + 0.5;
			}

			else if (p2x <= bx1 - 1.0) {
				p2x = bx1 - 1.0 - 0.5;
			}

		}

		if (p1x + 0.5 >= (bx2 - 1.0) && p1x - 0.5 <= bx2) {
			if (bz2 >= p1bottom) {
				p1z = bz2 + 1.0;
			}
			else if (p1x >= bx2) {
				p1x = bx2 + 0.5;
			}

			else if (p1x <= bx2 - 1.0) {
				p1x = bx2 - 1.0 - 0.5;
			}

		}

		if (p2x + 0.5 >= (bx2 - 1.0) && p2x - 0.5 <= bx2) {
			if (bz2 >= p2bottom) {
				p2z = bz2 + 1.0;
			}
			else if (p2x >= bx2) {
				p2x = bx2 + 1.0;
			}

			else if (p2x <= bx2 - 0.5) {
				p2x = bx2 - 1.0;
			}

		}
	}

};

//포카칩클래스//
class object_pocachip {
private:
	float x;
	float y;
	float z;
	float bx;
	float by;
	float bz;
	bool button;

public:
	object_pocachip(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		bx = x - 4.0;
		by = y;
		bz = z;
		button = false;
	}

	void draw_pocachip() {
		if (button == false) {
			glPushMatrix();
			glTranslatef(x, y, z);
			glColor3f(0.0, 1.0, 0.0);

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 3.0);
			glVertex3f(-3.0, y + 1.5, 3.0);
			glVertex3f(-3.0, y + 1.5, -1.0);
			glVertex3f(0.0, y + 1.5, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 3.0);
			glVertex3f(0.0, y - 1.5, 3.0);
			glVertex3f(0.0, y - 1.5, -1.0);
			glVertex3f(0.0, y + 1.5, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y - 1.5, 3.0);
			glVertex3f(-3.0, y - 1.5, 3.0);
			glVertex3f(-3.0, y - 1.5, -1.0);
			glVertex3f(0.0, y - 1.5, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-3.0, y + 1.5, 3.0);
			glVertex3f(-3.0, y - 1.5, 3.0);
			glVertex3f(-3.0, y - 1.5, -1.0);
			glVertex3f(-3.0, y + 1.5, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 3.0);
			glVertex3f(-3.0, y + 1.5, 3.0);
			glVertex3f(-3.0, y - 1.5, 3.0);
			glVertex3f(0.0, y - 1.5, 3.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, -1.0);
			glVertex3f(-3.0, y + 1.5, -1.0);
			glVertex3f(-3.0, y - 1.5, -1.0);
			glVertex3f(0.0, y - 1.5, -1.0);
			glEnd();

			glPopMatrix();
		}


		glutPostRedisplay();
	}

	void draw_button() {
		glPushMatrix();
		glTranslatef(bx, y, z);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -1.0);
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
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -1.0);
		glVertex3f(-1.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -1.0);
		glVertex3f(-1.0, y + 1.5, -1.0);
		glVertex3f(-1.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		glPopMatrix();
	}

	void collision_pocachip(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.0;
		float p2bottom = p2z - 1.0;
		float p1head = p1z + 1.4;
		//cout << p1z << endl;
		if (button == false) {
			if (p1x + 0.5 >= (x - 3.0) && p1x - 0.5 <= x) {
				if (z + 3.0 >= p1bottom) {
					p1z = (z + 3.0) + 2.0 * 0.5;
				}

				else if (p1x >= x) {
					p1x = x + 0.5;
				}

				else if (p1x <= x - 3.0) {
					p1x = (x - 3.0) - 0.5;
				}
			}

			if (p2x + 0.5 >= (x - 3.0) && p2x - 0.5 <= x) {
				if (z + 3.0 >= p2bottom) {
					p2z = (z + 3.0) + 2.0 * 0.5;
				}

				else if (p2x >= x) {
					p2x = x + 0.5;
				}

				else if (p2x <= x - 3.0) {
					p2x = (x - 3.0) - 0.5;
				}
			}
		}


	}

	void collision_button(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.0;
		float p2bottom = p2z - 1.0;
		if (p1x + 0.5 >= (bx - 1.0) && p1x - 0.5 <= bx) { //버튼1 x값 사이에 p1이 있을 때
			if (bz - 0.5 >= p1bottom) {
				button = true;
				p1z = bz + 0.5;
			}
			else if (p1x >= bx && p1bottom <= bz) {
				p1x = bx + 0.5;
			}

			else if (p1x <= bx - 1.0 && p1bottom <= bz) {
				p1x = bx - 1.0 - 0.5;
			}


		}

		if (p2x + 0.5 >= (bx - 1.0) && p2x - 0.5 <= bx) { //버튼1 x값 사이에 p2이 있을 때
			if (bz - 0.5 >= p2bottom) {
				button = true;
				p2z = bz + 0.5;
			}
			else if (p2x >= bx && p2bottom<=bz) {
				p2x = bx + 0.5;
			}

			else if (p2x <= bx - 1.0 && p2bottom <= bz) {
				p2x = bx - 1.0 - 0.5;
			}

		}
	}
};

class object_cookie {
private:
	float x;
	float y;
	float z;
	float mov;
	float cookieRadius = 1.0;
	bool collision = false;

public:
	object_cookie(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->mov = 0.0;
		collision = false;

	}

	void draw_cookie() {
		if (!collision) {
			glPushMatrix();
			glTranslatef(x + mov, y, z);
			glutSolidSphere(cookieRadius, 30, 30);
			glPopMatrix();

		}

		glutPostRedisplay();
	}

	void check_players_To_distance(float p1x, float p2x) { //어디까지 굴러가게할지?
		if (((p1x - 0.5) - (x + cookieRadius) < 4.5 && (p1x - 0.5) - (x + cookieRadius) > 0.0) || ((p2x - 0.5) - (x + cookieRadius) < 4.5 && (p2x - 0.5) - (x + cookieRadius) > 0.0)) {
			mov += 0.015;
		}
	}

	void collision_cookie(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		if ((p1x - (x + mov) < 0.5 + cookieRadius && p1z - 1.0 < z + cookieRadius) || (p2x - (x + mov) < 0.5 + cookieRadius && p2z - 1.0 < z + cookieRadius)) {
			//라이프감소코드 추가//
			collision = true;
		}
	}
};

class object_icecream {
private:
	float x;
	float y;
	float z;
	float mov;
	///왼쪽쪽버튼위치///
	float bx1;
	float by1;
	float bz1;
	///오른쪽버튼위치///
	float bx2;
	float by2;
	float bz2;
	bool p1b1, p1b2, p2b1, p2b2;

public:
	object_icecream(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z+4.0;
		mov = 0.0;
		this->bx1 = x + 3.0;
		this->by1 = y;
		this->bz1 = z;

		this->bx2 = x - 4.0;
		this->by2 = y;
		this->bz2 = z;
		p1b1 = false;
		p1b2 = false;
		p2b1 = false;
		p2b2 = false;
	}

	void draw_icecream() {
		glPushMatrix();
		glTranslatef(x, y, z - mov);
		glColor3f(0.0, 0.2, 0.7);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 3.0);
		glVertex3f(-2.0, y + 1.5, 3.0);
		glVertex3f(-2.0, y + 1.5, -1.0);
		glVertex3f(0.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 3.0);
		glVertex3f(0.0, y - 1.5, 3.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glVertex3f(0.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, 3.0);
		glVertex3f(-2.0, y - 1.5, 3.0);
		glVertex3f(-2.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-2.0, y + 1.5, 3.0);
		glVertex3f(-2.0, y - 1.5, 3.0);
		glVertex3f(-2.0, y - 1.5, -1.0);
		glVertex3f(-2.0, y + 1.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 3.0);
		glVertex3f(-2.0, y + 1.5, 3.0);
		glVertex3f(-2.0, y - 1.5, 3.0);
		glVertex3f(0.0, y - 1.5, 3.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -1.0);
		glVertex3f(-2.0, y + 1.5, -1.0);
		glVertex3f(-2.0, y - 1.5, -1.0);
		glVertex3f(0.0, y - 1.5, -1.0);
		glEnd();

		///////////////////////////////
		glColor3f(0.6, 0.3, 0.0);
		glBegin(GL_QUADS);
		glVertex3f(-0.7, y + 1.5, 4.5);
		glVertex3f(-1.3, y + 1.5, 4.5);
		glVertex3f(-1.3, y + 1.5, 3.0);
		glVertex3f(-0.7, y + 1.5, 3.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-0.7, y + 1.5, 4.5);
		glVertex3f(-0.7, y - 1.5, 4.5);
		glVertex3f(-0.7, y - 1.5, 3.0);
		glVertex3f(-0.7, y + 1.5, 3.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-0.7, y - 1.5, 4.5);
		glVertex3f(-1.3, y - 1.5, 4.5);
		glVertex3f(-1.3, y - 1.5, 3.0);
		glVertex3f(-0.7, y - 1.5, 3.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.3, y + 1.5, 4.5);
		glVertex3f(-1.3, y - 1.5, 4.5);
		glVertex3f(-1.3, y - 1.5, 3.0);
		glVertex3f(-1.3, y + 1.5, 3.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-0.7, y + 1.5, 4.5);
		glVertex3f(-1.3, y + 1.5, 4.5);
		glVertex3f(-1.3, y - 1.5, 4.5);
		glVertex3f(-0.7, y - 1.5, 4.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-0.7, y + 1.5, 3.0);
		glVertex3f(-1.3, y + 1.5, 3.0);
		glVertex3f(-1.3, y - 1.5, 3.0);
		glVertex3f(-0.7, y - 1.5, 3.0);
		glEnd();

		glPopMatrix();

		

		glutPostRedisplay();
	}

	void draw_button() {
		glPushMatrix();
		glTranslatef(bx1, by1, bz1);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(bx2, by2, bz2);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();


		glPopMatrix();
	}


	void check_players_To_distance(float p1x, float p2x) { 
		if (p1x - x < 2.0 || p2x - x < 2.0) { //오브젝트와 플레이어가 가까워지면 오브젝트 z값 감소
			if (!p1b1 && !p1b2&& !p2b1&& !p2b2) {
				if(mov < 3.5)
					mov += 0.02;
			}
			
			else if (p1b1 || p1b2 || p2b1 || p2b2) {
				if (mov > 0.0)
					mov -= 0.02;
			}

		}
	}

	void collision_icecream(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1Head = p1z + 0.9 + 0.5;
		float p2Head = p2z + 0.9 + 0.5;
		if (p1x + 0.5 >= (x - 2.0) && p1x - 0.5 <= x) {
			if (p1Head > (z-mov) - 1.0) {
				if (p1x >= x) {
					p1x = x + 0.5;
				}

				else if (p1x <= x - 2.0) {
					p1x = (x - 2.0) - 0.5;
				}
			}

		}

		if (p2x + 0.5 >= (x - 2.0) && p2x - 0.5 <= x) {
			if (p2Head > (z - mov) - 1.0) {
				if (p2x >= x) {
					p2x = x + 0.5;
				}

				else if (p2x <= x - 2.0) {
					p2x = (x - 2.0) - 0.5;
				}
			}

		}
	}

	void collision_button(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.1;
		float p2bottom = p2z - 1.1;
		if (p1x + 0.5 >= (bx1 - 1.0) && p1x - 0.5 <= bx1) {
			if (bz1 >= p1bottom) {
				p1b1 = true;
				p1z = bz1 + 1.0;
			}
			else if (p1x >= bx1 && p1bottom<=bz1) {
				p1x = bx1 + 0.5;
			}

			else if (p1x <= bx1 - 0.5 && p1bottom <= bz1) {
				p1x = bx1 - 1.0;
			}
			


		}
		else p1b1 = false;


		if (p2x + 0.5 >= (bx1 - 1.0) && p2x - 0.5 <= bx1) {
			if (bz1 >= p2bottom) {
				p2b1 = true;
				p2z = bz1 + 1.0;
			}
			else if (p2x >= bx1 && p2bottom <= bz1) {
				p2x = bx1 + 0.5;
			}

			else if (p2x <= bx1 - 1.0 && p2bottom <= bz1) {
				p2x = bx1 - 1.0 - 0.5;
			}
			

		}
		else p2b1 = false;

		if (p1x + 0.5 >= (bx2 - 1.0) && p1x - 0.5 <= bx2) {
			if (bz2 >= p1bottom) {
				p1b2 = true;
				p1z = bz2 + 1.0;
			}
			else if (p1x >= bx2 && p1bottom <= bz2) {
				p1x = bx2 + 0.5;
			}

			else if (p1x <= bx2 - 1.0 && p1bottom <= bz2) {
				p1x = bx2 - 1.0 - 0.5;
			}
		
		}
		else p1b2 = false;


		if (p2x + 0.5 >= (bx2 - 1.0) && p2x - 0.5 <= bx2) {
			if (bz2 >= p2bottom) {
				p2b2 = true;
				p2z = bz2 + 1.0;
			}
			else if (p2x >= bx2 && p2bottom <= bz2) {
				p2x = bx2 + 1.0;
			}

			else if (p2x <= bx2 - 0.5 && p2bottom <= bz2) {
				p2x = bx2 - 1.0;
			}

		}
		else p2b2 = false;
	}
};

class object_cloud {
private:
	float x;
	float y;
	float z;
	///왼쪽쪽버튼위치///
	float bx1;
	float by1;
	float bz1;
	///오른쪽버튼위치///
	float bx2;
	float by2;
	float bz2;
	bool p1b1, p1b2, p2b1, p2b2;
	
public:
	object_cloud(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->bx1 = x + 1.5;
		this->by1 = y;
		this->bz1 = z;

		this->bx2 = x - 7.5;
		this->by2 = y;
		this->bz2 = z;
		p1b1 = false;
		p1b2 = false;
		p2b1 = false;
		p2b2 = false;
	}

	void draw_cloud() {
		if (p1b1 || p1b2 || p2b1 || p2b2) {
			glPushMatrix();
			glTranslatef(x, y, z + 1.0);
			glColor3f(0.0, 0.4, 0.5);

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glVertex3f(0.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, -0.5);
			glVertex3f(0.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, -0.5);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(x - 2.5, y, z + 2.0);
			glColor3f(0.0, 0.4, 0.5);

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glVertex3f(0.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, -0.5);
			glVertex3f(0.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, -0.5);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(x - 5.0, y, z + 1.0);
			glColor3f(0.0, 0.4, 0.5);

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glVertex3f(0.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, -0.5);
			glVertex3f(0.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y + 1.5, 0.0);
			glVertex3f(-2.0, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, -0.5);
			glVertex3f(-2.0, y + 1.5, -0.5);
			glVertex3f(-2.0, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();
			glPopMatrix();
		}
		glutPostRedisplay();
	}

	void draw_button() {
		glPushMatrix();
		glTranslatef(bx1, by1, bz1);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(bx2, by2, bz2);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, -0.5);
		glVertex3f(0.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y + 1.5, 0.0);
		glVertex3f(-1.0, y - 1.5, 0.0);
		glVertex3f(0.0, y - 1.5, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y + 1.5, -0.5);
		glVertex3f(-1.0, y - 1.5, -0.5);
		glVertex3f(0.0, y - 1.5, -0.5);
		glEnd();


		glPopMatrix();
	}

	void collision_button(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.1;
		float p2bottom = p2z - 1.1;
		if (p1x + 0.5 >= (bx1 - 1.0) && p1x - 0.5 <= bx1) {
			if (bz1 >= p1bottom) {
				p1b1 = true;
				p1z = bz1 + 1.0;
			}
			else if (p1x >= bx1 && p1bottom <= bz1) {
				p1x = bx1 + 0.5;
			}

			else if (p1x <= bx1 - 0.5 && p1bottom <= bz1) {
				p1x = bx1 - 1.0;
			}



		}
		else p1b1 = false;


		if (p2x + 0.5 >= (bx1 - 1.0) && p2x - 0.5 <= bx1) {
			if (bz1 >= p2bottom) {
				p2b1 = true;
				p2z = bz1 + 1.0;
			}
			else if (p2x >= bx1 && p2bottom <= bz1) {
				p2x = bx1 + 0.5;
			}

			else if (p2x <= bx1 - 1.0 && p2bottom <= bz1) {
				p2x = bx1 - 1.0 - 0.5;
			}


		}
		else p2b1 = false;

		if (p1x + 0.5 >= (bx2 - 1.0) && p1x - 0.5 <= bx2) {
			if (bz2 >= p1bottom) {
				p1b2 = true;
				p1z = bz2 + 1.0;
			}
			else if (p1x >= bx2 && p1bottom <= bz2) {
				p1x = bx2 + 0.5;
			}

			else if (p1x <= bx2 - 1.0 && p1bottom <= bz2) {
				p1x = bx2 - 1.0 - 0.5;
			}

		}
		else p1b2 = false;


		if (p2x + 0.5 >= (bx2 - 1.0) && p2x - 0.5 <= bx2) {
			if (bz2 >= p2bottom) {
				p2b2 = true;
				p2z = bz2 + 1.0;
			}
			else if (p2x >= bx2 && p2bottom <= bz2) {
				p2x = bx2 + 1.0;
			}

			else if (p2x <= bx2 - 0.5 && p2bottom <= bz2) {
				p2x = bx2 - 1.0;
			}

		}
		else p2b2 = false;
	}

	void collision_cloud(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z ) {
		float p1bottom = p1z - 1.0;
		float p2bottom = p2z - 1.0;
		float p1head = p1z + 1.4;
		//cout << p1z << endl;
		if (p1b1||p1b2||p2b1||p2b2) {
			//1번째구름충돌//
			if (p1x + 0.5 >= (x - 2.0) && p1x - 0.5 <= x) {
				if (z + 1.0 >= p1bottom) {
					p1z = (z + 1.0) + 2.0 * 0.5;
				}

				else if (p1x >= x && p1bottom<=z) {
					p1x = x + 0.5;
				}

				else if (p1x <= x - 2.0 && p1bottom <= z) {
					p1x = (x - 2.0) - 0.5;
				}
			}

			if (p2x + 0.5 >= (x - 2.0) && p2x - 0.5 <= x) {
				if (z + 1.0 >= p2bottom) {
					p2z = (z + 1.0) + 2.0 * 0.5;
				}

				else if (p2x >= x && p2bottom <= z) {
					p2x = x + 0.5;
				}

				else if (p2x <= x - 2.0 && p2bottom <= z) {
					p2x = (x - 2.0) - 0.5;
				}
			}
			//2번째구름충돌//
			if (p1x + 0.5 >= (x - 4.5) && p1x - 0.5 <= (x-2.5)) {
				if (z + 2.0 >= p1bottom) {
					p1z = (z + 2.0) + 2.0 * 0.5;
				}

				else if (p1x >= x-2.0 && p1bottom <= z+1.0) {
					p1x = x-2.0 + 0.5;
				}

				else if (p1x <= x - 4.5 && p1bottom <= z + 1.0) {
					p1x = (x - 4.5) - 0.5;
				}
			}

			if (p2x + 0.5 >= (x - 4.5) && p2x - 0.5 <= (x - 2.5)) {
				if (z + 2.0 >= p2bottom) {
					p2z = (z + 2.0) + 2.0 * 0.5;
				}

				else if (p2x >= x - 2.5 && p2bottom <= z + 1.0) {
					p2x = x - 2.5 + 0.5;
				}

				else if (p2x <= x - 4.5 && p2bottom <= z + 1.0) {
					p2x = (x - 4.5) - 0.5;
				}
			}
			//3번째구름충돌//
			if (p1x + 0.5 >= (x - 7.0) && p1x - 0.5 <= (x-5.0)) {
				if (z + 1.0 >= p1bottom) {
					p1z = (z + 1.0) + 2.0 * 0.5;
				}

				else if (p1x >= x-5.0 && p1bottom <= z + 1.0) {
					p1x = x-5.0 + 0.5;
				}

				else if (p1x <= x - 7.0 && p1bottom <= z + 1.0 ) {
					p1x = (x - 7.0) - 0.5;
				}
			}

			if (p2x + 0.5 >= (x - 7.0) && p2x - 0.5 <= (x-5.0)) {
				if (z + 1.0 >= p2bottom) {
					p2z = (z + 1.0) + 2.0 * 0.5;
				}

				else if (p2x >= x-5.0 && p2bottom <= z + 1.0) {
					p2x = x-5.0 + 0.5;
				}

				else if (p2x <= x - 7.0 && p2bottom <= z + 1.0) {
					p2x = (x - 7.0) - 0.5;
				}
			}
		}
	}

};