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
			glVertex3f(0.0, y, -0.5);
			glVertex3f(-6.0, y, -0.5);
			glVertex3f(-6.0, y, -1.0);
			glVertex3f(0.0, y, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y, -0.5);
			glVertex3f(0.0, y - 0.5, -0.5);
			glVertex3f(0.0, y - 0.5, -1.0);
			glVertex3f(0.0, y, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y - 0.5, -0.5);
			glVertex3f(-6.0, y - 0.5, -0.5);
			glVertex3f(-6.0, y - 0.5, -1.0);
			glVertex3f(0.0, y - 0.5, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-6.0, y, -0.5);
			glVertex3f(-6.0, y - 0.5, -0.5);
			glVertex3f(-6.0, y - 0.5, -1.0);
			glVertex3f(-6.0, y, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y, -0.5);
			glVertex3f(-6.0, y, -0.5);
			glVertex3f(-6.0, y - 0.5, -0.5);
			glVertex3f(0.0, y - 0.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y, -1.0);
			glVertex3f(-6.0, y, -1.0);
			glVertex3f(-6.0, y - 0.5, -1.0);
			glVertex3f(0.0, y - 0.5, -1.0);
			glEnd();

			glPopMatrix();
		
		

		glutPostRedisplay();
	}

	void draw_button() {
		glPushMatrix();
		glTranslatef(bx1, y, z);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -0.5);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y, -1.0);
		glVertex3f(0.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -0.5);
		glVertex3f(0.0, y - 0.5, -0.5);
		glVertex3f(0.0, y - 0.5, -1.0);
		glVertex3f(0.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(0.0, y - 0.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(-1.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -0.5);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(0.0, y - 0.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -1.0);
		glVertex3f(-1.0, y, -1.0);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(0.0, y - 0.5, -1.0);
		glEnd();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(bx2, y, z);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -0.5);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y, -1.0);
		glVertex3f(0.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -0.5);
		glVertex3f(0.0, y - 0.5, -0.5);
		glVertex3f(0.0, y - 0.5, -1.0);
		glVertex3f(0.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(0.0, y - 0.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(-1.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -0.5);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(0.0, y - 0.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -1.0);
		glVertex3f(-1.0, y, -1.0);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(0.0, y - 0.5, -1.0);
		glEnd();

		glPopMatrix();
	}

	void collision_pepero(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 2 * 0.5;
		float p1middle = p1z - 1.5 * 0.5;
		float p2bottom = p2z - 2 * 0.5;
		float p2middle = p2z - 1.5 * 0.5;
			if (p1x + 0.5 >= (x - 6.0) && p1x - 0.5 <= x) { //빼빼로 x값 사이에 p1이 있을 때
				if (z - 0.5 >= p1bottom && p1middle >= z - 0.5) {
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
		float p1bottom = p1z - 2 * 0.5;
		float p1middle = p1z - 1.5 * 0.5;
		float p2bottom = p2z - 2 * 0.5;
		float p2middle = p2z - 1.5 * 0.5;
		if (p1x + 0.5 >= (bx1 - 1.0) && p1x - 0.5 <= bx1) { //버튼1 x값 사이에 p1이 있을 때
			if (bz1 - 0.5 >= p1bottom) {
				p1z = bz1 + 0.5;
			}
			else if (p1x >= bx1 && p1bottom<=z-0.5) {
				cout << "여긴디" << endl;
				p1x = bx1 + 0.5;
			}

			else if ((p1x <= bx1 - 1.0)&& p1bottom == z - 1.0) {
				p1x = bx1 - 1.0 - 0.5;
			}


		}
		if (p2x + 0.5 >= (bx1 - 1.0) && p2x - 0.5 <= bx1) { //버튼1 x값 사이에 p2이 있을 때
			if (bz1 - 0.5 >= p2bottom) {
				p2z = bz1 + 0.5;
			}
			else if (p2x >= bx1 && p2bottom == z - 1.0) {
				p2x = bx1 + 0.5;
			}

			else if (p2x <= bx1 - 1.0 && p2bottom == z - 1.0) {
				p2x = bx1 - 1.0 - 0.5;
			}

		}

		if (p1x + 0.5 >= (bx2 - 1.0) && p1x - 0.5 <= bx2) { //버튼2 x값 사이에 p1이 있을 때
			if (bz2 - 0.5 >= p1bottom) {
				p1z = bz2 + 0.5;
			}
			else if (p1x >= bx2 && p1bottom == z - 1.0) {
				p1x = bx2 + 0.5;
			}

			else if (p1x <= bx2 - 1.0 && p1bottom == z - 1.0) {
				p1x = bx2 - 1.0 - 0.5;
			}

		}
		if (p2x + 0.5 >= (bx2 - 1.0) && p2x - 0.5 <= bx2) { //버튼2 x값 사이에 p2이 있을 때
			if (bz2 - 0.5 >= p2bottom) {
				p2z = bz2 + 0.5;
			}
			else if (p2x >= bx2 && p2bottom == z - 1.0) {
				p2x = bx2 + 0.5;
			}

			else if (p2x <= bx2 - 1.0 && p2bottom == z - 1.0) {
				p2x = bx2 - 1.0 - 0.5;
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
			glVertex3f(0.0, y, 3.0);
			glVertex3f(-3.0, y, 3.0);
			glVertex3f(-3.0, y, -1.0);
			glVertex3f(0.0, y, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y, 3.0);
			glVertex3f(0.0, y - 0.5, 3.0);
			glVertex3f(0.0, y - 0.5, -1.0);
			glVertex3f(0.0, y, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y - 0.5, 3.0);
			glVertex3f(-3.0, y - 0.5, 3.0);
			glVertex3f(-3.0, y - 0.5, -1.0);
			glVertex3f(0.0, y - 0.5, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-3.0, y, 3.0);
			glVertex3f(-3.0, y - 0.5, 3.0);
			glVertex3f(-3.0, y - 0.5, -1.0);
			glVertex3f(-3.0, y, -1.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y, 3.0);
			glVertex3f(-3.0, y, 3.0);
			glVertex3f(-3.0, y - 0.5, 3.0);
			glVertex3f(0.0, y - 0.5, 3.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y, -1.0);
			glVertex3f(-3.0, y, -1.0);
			glVertex3f(-3.0, y - 0.5, -1.0);
			glVertex3f(0.0, y - 0.5, -1.0);
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
		glVertex3f(0.0, y, -0.5);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y, -1.0);
		glVertex3f(0.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -0.5);
		glVertex3f(0.0, y - 0.5, -0.5);
		glVertex3f(0.0, y - 0.5, -1.0);
		glVertex3f(0.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(0.0, y - 0.5, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(-1.0, y, -1.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -0.5);
		glVertex3f(-1.0, y, -0.5);
		glVertex3f(-1.0, y - 0.5, -0.5);
		glVertex3f(0.0, y - 0.5, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(0.0, y, -1.0);
		glVertex3f(-1.0, y, -1.0);
		glVertex3f(-1.0, y - 0.5, -1.0);
		glVertex3f(0.0, y - 0.5, -1.0);
		glEnd();

		glPopMatrix();
	}

	void collision_pocachip(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.5 * 0.5;
		float p2bottom = p2z - 1.5 * 0.5;
		//cout << p1z << endl;
		if (button == false) {
			if (p1x + 0.5 >= (x - 3.0) && p1x - 0.5 <= x) {
				if (z + 3.0 <= p1bottom) {
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
				if (z + 3.0 <= p2bottom) {
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
		float p1bottom = p1z - 2.0 * 0.5;
		float p1middle = p1z - 1.5 * 0.5;
		float p2bottom = p2z - 2.0 * 0.5;
		float p2middle = p2z - 1.5 * 0.5;
		if (p1x + 0.5 >= (bx - 1.0) && p1x - 0.5 <= bx) { //버튼1 x값 사이에 p1이 있을 때
			if (bz - 0.5 >= p1bottom && p1middle >= bz - 0.5) {
				button = true;
				p1z = bz + 0.5;
			}
			else if (p1x >= bx ) {
				p1x = bx + 0.5;
			}

			else if (p1x <= bx - 1.0) {
				p1x = bx - 1.0 - 0.5;
			}


		}

		if (p2x + 0.5 >= (bx - 1.0) && p2x - 0.5 <= bx) { //버튼1 x값 사이에 p2이 있을 때
			if (bz - 0.5 >= p2bottom && p2middle >= bz - 0.5) {
				button = true;
				p2z = bz + 0.5;
			}
			else if (p2x >= bx) {
				p2x = bx + 0.5;
			}

			else if (p2x <= bx - 1.0) {
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
	float cookieRadius=1.0;
public:
	object_cookie(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->mov = 0.0;
	}

	void draw_cookie() {

		glPushMatrix();
		glTranslatef(x+mov, y, z);
		glutSolidSphere(cookieRadius, 30, 30);
		glPopMatrix();

		glutPostRedisplay();
	}

	void check_players_To_distance(float p1x,float p2x) { //어디까지 굴러가게할지?
		if (((p1x - 0.5) - (x + cookieRadius) < 4.5 && (p1x - 0.5) - (x+ cookieRadius) > 0.0) || ((p2x - 0.5) - (x+ cookieRadius) < 4.5 && (p2x - 0.5) - (x+ cookieRadius) > 0.0)) {
			mov += 0.015;
		}
	
	}

	void collision_cookie(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {

	}
};