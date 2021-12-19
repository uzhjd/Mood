/////장애물 클래스 모아놓는 곳
#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <iostream>
#include <string>
#include<vector>
#include<math.h>
using namespace std;
extern struct position {
	float x;
	float y;
	float z;
};

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
	bool p1b1, p1b2, p2b1, p2b2;
	bool draw;
	float vertex[24][3] = {
		{0.0,1.5,-0.5},{-6.0, 1.5, -0.5},{-6.0, 1.5, -1.0},{0.0, 1.5, -1.0},
		{0.0,1.5,-0.5},{0.0, -1.5, -0.5},{0.0, -1.5, -1.0},{0.0, 1.5, -1.0},
		{0.0,-1.5,-0.5},{-6.0, -1.5, -0.5},{0.0, 1.5, -1.0},{0.0, -1.5, -1.0},
		{-6.0,1.5,-0.5},{-6.0,  -1.5, -0.5},{-6.0, -1.5, -1.0},{-6.0, 1.5, -1.0},
		{0.0,1.5,-0.5},{-6.0, 1.5, -0.5},{-6.0, -1.5, -0.5},{0.0, -1.5, -0.5},
		{0.0, 1.5,-1.0},{-6.0, 1.5, -1.0},{-6.0, -1.5, -1.0},{0.0, -1.5, -1.0}
	};

public:
	object_pepero(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->bx1 = x + 3.0;
		this->by1 = y;
		this->bz1 = z;

		this->bx2 = x + 1.0;
		this->by2 = y;
		this->bz2 = z;

		p1b1 = false; p1b2 = false; p2b1 = false; p2b2 = false;
		draw = false;

	}

	position Normal(float v1[3], float v2[3], float v3[3])
	{	
		float v11[3], v22[3];
		position out;
		static const int x = 0;
		static const int y = 1;
		static const int z = 2;

		// Calculate two vectors from the three points
		v11[x] = v1[x] - v2[x];
		v11[y] = v1[y] - v2[y];
		v11[z] = v1[z] - v2[z];

		v22[x] = v3[x] - v1[x];
		v22[y] = v3[y] - v1[y];
		v22[z] = v3[z] - v1[z];

		float len1 = sqrt(v11[x] * v11[x] + v11[y] * v11[y] + v11[z] * v11[z]);
		float len2 = sqrt(v22[x] * v22[x] + v22[y] * v22[y] + v22[z] * v22[z]);

		v11[x] = v11[x] / len1; v11[y] = v11[y] / len1; v11[z] = v11[z] / len1;
		v22[x] = v22[x] / len2; v22[y] = v22[y] / len2; v22[z] = v22[z] / len2;

		out.x = v11[y] * v22[z] - v11[z] * v22[y];
		out.y = v11[z] * v22[x] - v11[x] * v22[z];
		out.z = v11[x] * v22[y] - v11[y] * v22[x];
		// Normalize the vector (shorten length to one)
		return out;
	}

	void draw_pepero() {
		if (draw) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslatef(x, y, z);
			glColor3f(0.0, 1.0, 1.0);
			//glColorMaterial(GL_FRONT, GL_AMBIENT);

			position v1= Normal(vertex[0],vertex[1],vertex[2]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[0]);
			glVertex3fv(vertex[1]);
			glVertex3fv(vertex[2]);
			glVertex3fv(vertex[3]);
			glEnd();

			v1 = Normal(vertex[4], vertex[5], vertex[6]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[4]);
			glVertex3fv(vertex[5]);
			glVertex3fv(vertex[6]);
			glVertex3fv(vertex[7]);
			glEnd();

			v1 = Normal(vertex[8], vertex[9], vertex[10]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[8]);
			glVertex3fv(vertex[9]);
			glVertex3fv(vertex[10]);
			glVertex3fv(vertex[11]);
			glEnd();

			v1 = Normal(vertex[12], vertex[13], vertex[14]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[12]);
			glVertex3fv(vertex[13]);
			glVertex3fv(vertex[14]);
			glVertex3fv(vertex[15]);
			glEnd();

			v1 = Normal(vertex[16], vertex[17], vertex[18]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[16]);
			glVertex3fv(vertex[17]);
			glVertex3fv(vertex[18]);
			glVertex3fv(vertex[19]);
			glEnd();

			v1 = Normal(vertex[20], vertex[21], vertex[22]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[20]);
			glVertex3fv(vertex[21]);
			glVertex3fv(vertex[22]);
			glVertex3fv(vertex[23]);
			glEnd();

			glPopMatrix();
		}


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
		if (draw) {
			if (p1x + 0.5 >= (x - 6.0) && p1x - 0.5 <= x) { //빼빼로 x값 사이에 p1이 있을 때
				if (z - 0.5 >= p1bottom) {
					p1z = z + 0.5;
				}


			}

			if (p2x + 0.5 >= (x - 6.0) && p2x - 0.5 <= x) { //빼빼로 x값 사이에 p2이 있을 때
				if (z - 0.5 >= p2bottom && p2middle >= z - 0.5) {
					p2z = z + 0.5;
				}



			}
		}

	}

	void collision_button(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.1;
		float p2bottom = p2z - 1.1;
		if (p1x + 0.5 >= (bx1 - 1.0) && p1x - 0.5 <= bx1) {
			if (bz1 - 0.1 >= p1bottom) {
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
			if (bz1 - 0.1 >= p2bottom) {
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
			if (bz2 - 0.1 >= p1bottom) {
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
			if (bz2 - 0.1 >= p2bottom) {
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

		if ((p1b1 && p2b2) || (p1b2 && p2b1))
			draw = true;
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
	float vertex[24][3] = {
		{0.0, 1.5, 3.0},{-3.0, 1.5, 3.0},{-3.0, 1.5, -1.0},{0.0, 1.5, -1.0},
		{0.0, 1.5, 3.0},{0.0, -1.5, 3.0},{0.0, -1.5, -1.0},{0.0, 1.5, -1.0},
		{0.0, -1.5, 3.0},{-3.0, -1.5, 3.0},{-3.0, -1.5, -1.0},{0.0,-1.5, -1.0},
		{-3.0, 1.5, 3.0},{-3.0, -1.5, 3.0},{-3.0, -1.5, -1.0},{-3.0,1.5, -1.0},
		{0.0, 1.5, 3.0},{-3.0, 1.5, 3.0},{-3.0, -1.5, 3.0},{0.0, -1.5, 3.0},
		{0.0,1.5, -1.0},{-3.0, 1.5, -1.0},{-3.0, -1.5, -1.0},{0.0, -1.5, -1.0}
	};

	float bvertex[24][3] = {
		{0.0, 1.5, -0.5},{-1.0, 1.5, -0.5},{-1.0, 1.5, -1.0},{0.0, 1.5, -1.0},
		{0.0, 1.5, -0.5},{0.0, -1.5, -0.5},{0.0, -1.5, -1.0},{0.0, 1.5, -1.0},
		{0.0,-1.5, -0.5},{-1.0,-1.5, -0.5},{-1.0,-1.5, -1.0},{-1.0,1.5, -1.0},
		{-1.0,1.5, -0.5},{-1.0,-1.5, -0.5},{-1.0,-1.5, -1.0},{-1.0,1.5, -1.0},
		{0.0, 1.5, -0.5},{-1.0, 1.5, -0.5},{-1.0,-1.5, -0.5},{0.0,-1.5, -0.5},
		{0.0, 1.5, -1.0},{-1.0, 1.5, -1.0},{-1.0,-1.5, -1.0},{0.0,-1.5, -1.0}
	};
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

	position Normal(float v1[3], float v2[3], float v3[3])
	{	
		float v11[3], v22[3];
		position out;
		static const int x = 0;
		static const int y = 1;
		static const int z = 2;

		// Calculate two vectors from the three points
		v11[x] = v1[x] - v2[x];
		v11[y] = v1[y] - v2[y];
		v11[z] = v1[z] - v2[z];

		v22[x] = v3[x] - v1[x];
		v22[y] = v3[y] - v1[y];
		v22[z] = v3[z] - v1[z];

		float len1 = sqrt(v11[x] * v11[x] + v11[y] * v11[y] + v11[z] * v11[z]);
		float len2 = sqrt(v22[x] * v22[x] + v22[y] * v22[y] + v22[z] * v22[z]);

		v11[x] = v11[x] / len1; v11[y] = v11[y] / len1; v11[z] = v11[z] / len1;
		v22[x] = v22[x] / len2; v22[y] = v22[y] / len2; v22[z] = v22[z] / len2;

		out.x = v11[y] * v22[z] - v11[z] * v22[y];
		out.y = v11[z] * v22[x] - v11[x] * v22[z];
		out.z = v11[x] * v22[y] - v11[y] * v22[x];
		// Normalize the vector (shorten length to one)
		return out;
	}

	void draw_pocachip() {
		if (button == false) {
			glPushMatrix();
			glTranslatef(x, y, z);
			glColor3f(1.0, 1.0, 0.0);

			position v1 = Normal(vertex[0], vertex[1], vertex[2]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[0]);
			glVertex3fv(vertex[1]);
			glVertex3fv(vertex[2]);
			glVertex3fv(vertex[3]);
			glEnd();

			v1 = Normal(vertex[4], vertex[5], vertex[6]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[4]);
			glVertex3fv(vertex[5]);
			glVertex3fv(vertex[6]);
			glVertex3fv(vertex[7]);
			glEnd();

			v1 = Normal(vertex[8], vertex[9], vertex[10]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[8]);
			glVertex3fv(vertex[9]);
			glVertex3fv(vertex[10]);
			glVertex3fv(vertex[11]);
			glEnd();

			v1 = Normal(vertex[12], vertex[13], vertex[14]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[12]);
			glVertex3fv(vertex[13]);
			glVertex3fv(vertex[14]);
			glVertex3fv(vertex[15]);
			glEnd();

			v1 = Normal(vertex[16], vertex[17], vertex[18]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[16]);
			glVertex3fv(vertex[17]);
			glVertex3fv(vertex[18]);
			glVertex3fv(vertex[19]);
			glEnd();

			v1 = Normal(vertex[20], vertex[21], vertex[22]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(vertex[20]);
			glVertex3fv(vertex[21]);
			glVertex3fv(vertex[22]);
			glVertex3fv(vertex[23]);
			glEnd();
			glPopMatrix();
		}


		glutPostRedisplay();
	}

	void draw_button() {
		glPushMatrix();
		glTranslatef(bx, y, z);
		glColor3f(1.0, 0.0, 0.0);

		position v1 = Normal(bvertex[0], bvertex[1], bvertex[2]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(bvertex[0]);
			glVertex3fv(bvertex[1]);
			glVertex3fv(bvertex[2]);
			glVertex3fv(bvertex[3]);
			glEnd();

			v1 = Normal(bvertex[4], bvertex[5], bvertex[6]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(bvertex[4]);
			glVertex3fv(bvertex[5]);
			glVertex3fv(bvertex[6]);
			glVertex3fv(bvertex[7]);
			glEnd();

			v1 = Normal(bvertex[8], bvertex[9], bvertex[10]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(bvertex[8]);
			glVertex3fv(bvertex[9]);
			glVertex3fv(bvertex[10]);
			glVertex3fv(bvertex[11]);
			glEnd();

			v1 = Normal(bvertex[12], bvertex[13], bvertex[14]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(bvertex[12]);
			glVertex3fv(bvertex[13]);
			glVertex3fv(bvertex[14]);
			glVertex3fv(bvertex[15]);
			glEnd();

			v1 = Normal(bvertex[16], bvertex[17], bvertex[18]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(bvertex[16]);
			glVertex3fv(bvertex[17]);
			glVertex3fv(bvertex[18]);
			glVertex3fv(bvertex[19]);
			glEnd();

			v1 = Normal(bvertex[20], bvertex[21], bvertex[22]);
			glBegin(GL_QUADS);
			glNormal3f(v1.x, v1.y, v1.z);
			glVertex3fv(bvertex[20]);
			glVertex3fv(bvertex[21]);
			glVertex3fv(bvertex[22]);
			glVertex3fv(bvertex[23]);
			glEnd();

		glPopMatrix();
	}

	void collision_pocachip(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.0;
		float p2bottom = p2z - 1.0;
		float p1head = p1z + 1.4;
		float p2head = p2z + 1.4;
		//cout << p1z << endl;
		if (button == false) {
			if (p1x + 0.5 >= (x - 3.0) && p1x - 0.5 <= x) {
				if (z + 3.0 >= p1bottom && p1head >= z + 5.0) {
					p1z = (z + 3.0) + 2.0 * 0.5;
				}
				else if (p1bottom >= z - 1.0 && p1bottom <= z + 3.0) {
					if (p1x >= x) {
						p1x = x + 0.5;
					}

					if (p1x <= x - 3.0) {
						p1x = (x - 3.0) - 0.5;
					}
				}

			}

			if (p2x + 0.5 >= (x - 3.0) && p2x - 0.5 <= x) {
				if (z + 3.0 >= p2bottom && p2head >= z + 5.0) {
					p2z = (z + 3.0) + 2.0 * 0.5;
				}
				else if (p2bottom >= z - 1.0 && p2bottom <= z + 3.0) {
					if (p2x >= x) {
						p2x = x + 0.5;
					}

					else if (p2x <= x - 3.0) {
						p2x = (x - 3.0) - 0.5;
					}
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
			else if (p2x >= bx && p2bottom <= bz) {
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
	float cookieRadius = 0.6;
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
		if (((p1x - 0.5) - (x + cookieRadius) < 5.5 && (p1x - 0.5) - (x + cookieRadius) > 0.0) || ((p2x - 0.5) - (x + cookieRadius) < 5.5 && (p2x - 0.5) - (x + cookieRadius) > 0.0)) {
			mov += 0.005;
		}
	}

	void collision_cookie(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z, int& life) {
		if (!collision) {
			if ((p1x - (x + mov) < 0.5 + cookieRadius && p1x - (x + mov) > 0.0 && p1z - 1.0 < z + cookieRadius) || (p2x - (x + mov) < 0.5 + cookieRadius && p2z - 1.0 < z + cookieRadius && p2x - (x + mov) > 0.0)) {
				//라이프감소코드 추가//
				life -= 1;
				cout << "life:" << life << endl;
				collision = true;
			}
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
	float vertex[24][3] = {
		{0.0, 1.5, 3.0},{-2.0, 1.5, 3.0},{-2.0, 1.5, -1.0},{0.0, 1.5, -1.0},
		{0.0,1.5, 3.0},{0.0, -1.5, 3.0},{0.0, -1.5, -1.0},{0.0, 1.5, -1.0},
		{0.0, -1.5, 3.0},{-2.0, -1.5, 3.0},{-2.0, -1.5, -1.0},{0.0, -1.5, -1.0},
		{-2.0, 1.5, 3.0},{-2.0, -1.5, 3.0},{-2.0, -1.5, -1.0},{-2.0, 1.5, -1.0},
		{0.0, 1.5, 3.0},{-2.0,  1.5, 3.0},{-2.0, -1.5, 3.0},{0.0, -1.5, 3.0},
		{0.0, 1.5, -1.0},{-2.0, 1.5, -1.0},{-2.0, -1.5, -1.0},{0.0, -1.5, -1.0}
	};
	float mvertex[24][3] = {
		{-0.7, 1.5, 4.5},{-1.3, 1.5, 4.5},{-1.3, 1.5, 3.0},{-0.7, 1.5, 3.0},
		{-0.7, 1.5, 4.5},{-0.7, -1.5, 4.5},{-0.7, -1.5, 3.0},{-0.7, 1.5, 3.0},
		{-0.7, -1.5, 4.5},{-1.3, -1.5, 4.5},{-1.3, -1.5, 3.0},{-0.7, -1.5, 3.0},
		{-1.3, 1.5, 4.5},{-1.3, -1.5, 4.5},{-1.3, -1.5, 3.0},{-1.3, 1.5, 3.0},
		{-0.7, 1.5, 4.5},{-1.3, 1.5, 4.5},{-1.3, -1.5, 4.5},{-0.7, -1.5, 4.5},
		{-0.7, 1.5, 3.0},{-1.3, 1.5, 3.0},{-1.3, -1.5, 3.0},{-0.7, -1.5, 3.0}
	};

	float bvertex[24][3] = {
	{0.0, 1.5, 0.0},{-1.0, 1.5, 0.0},{-1.0, 1.5, -0.5},{0.0,  1.5, -0.5},
	{0.0, 1.5, 0.0},{0.0, -1.5, 0.0},{0.0, -1.5, -0.5},{0.0,  1.5, -0.5},
	{0.0, -1.5, 0.0},{-1.0, -1.5, 0.0},{-1.0, -1.5, -0.5},{0.0, -1.5, -0.5},
	{-1.0, 1.5, 0.0},{-1.0, -1.5, 0.0},{-1.0, -1.5, -0.5},{-1.0, 1.5, -0.5},
	{0.0, 1.5, 0.0},{-1.0, 1.5, 0.0},{-1.0, -1.5, 0.0},{0.0, -1.5, 0.0},
	{0.0, 1.5, -0.5},{-1.0, 1.5, -0.5},{-1.0, -1.5, -0.5},{0.0, -1.5, -0.5}
	};

public:
	object_icecream(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z + 4.0;
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

	position Normal(float v1[3], float v2[3], float v3[3])
	{
		float v11[3], v22[3];
		position out;
		static const int x = 0;
		static const int y = 1;
		static const int z = 2;

		// Calculate two vectors from the three points
		v11[x] = v1[x] - v2[x];
		v11[y] = v1[y] - v2[y];
		v11[z] = v1[z] - v2[z];

		v22[x] = v3[x] - v1[x];
		v22[y] = v3[y] - v1[y];
		v22[z] = v3[z] - v1[z];

		float len1 = sqrt(v11[x] * v11[x] + v11[y] * v11[y] + v11[z] * v11[z]);
		float len2 = sqrt(v22[x] * v22[x] + v22[y] * v22[y] + v22[z] * v22[z]);

		v11[x] = v11[x] / len1; v11[y] = v11[y] / len1; v11[z] = v11[z] / len1;
		v22[x] = v22[x] / len2; v22[y] = v22[y] / len2; v22[z] = v22[z] / len2;

		out.x = v11[y] * v22[z] - v11[z] * v22[y];
		out.y = v11[z] * v22[x] - v11[x] * v22[z];
		out.z = v11[x] * v22[y] - v11[y] * v22[x];
		// Normalize the vector (shorten length to one)
		return out;
	}

	void draw_icecream() {
		glPushMatrix();
		glTranslatef(x, y, z - mov);
		glColor3f(0.0, 0.2, 0.7);

		position v1 = Normal(vertex[0], vertex[1], vertex[2]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(vertex[0]);
		glVertex3fv(vertex[1]);
		glVertex3fv(vertex[2]);
		glVertex3fv(vertex[3]);
		glEnd();

		v1 = Normal(vertex[4], vertex[5], vertex[6]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(vertex[4]);
		glVertex3fv(vertex[5]);
		glVertex3fv(vertex[6]);
		glVertex3fv(vertex[7]);
		glEnd();

		v1 = Normal(vertex[8], vertex[9], vertex[10]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(vertex[8]);
		glVertex3fv(vertex[9]);
		glVertex3fv(vertex[10]);
		glVertex3fv(vertex[11]);
		glEnd();

		v1 = Normal(vertex[12], vertex[13], vertex[14]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(vertex[12]);
		glVertex3fv(vertex[13]);
		glVertex3fv(vertex[14]);
		glVertex3fv(vertex[15]);
		glEnd();

		v1 = Normal(vertex[16], vertex[17], vertex[18]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(vertex[16]);
		glVertex3fv(vertex[17]);
		glVertex3fv(vertex[18]);
		glVertex3fv(vertex[19]);
		glEnd();

		v1 = Normal(vertex[20], vertex[21], vertex[22]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(vertex[20]);
		glVertex3fv(vertex[21]);
		glVertex3fv(vertex[22]);
		glVertex3fv(vertex[23]);
		glEnd();

		///////////////////////////////
		v1 = Normal(mvertex[0], mvertex[1], mvertex[2]);
		glColor3f(0.6, 0.3, 0.0);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(mvertex[0]);
		glVertex3fv(mvertex[1]);
		glVertex3fv(mvertex[2]);
		glVertex3fv(mvertex[3]);
		glEnd();

		v1 = Normal(mvertex[4], mvertex[5], mvertex[6]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(mvertex[4]);
		glVertex3fv(mvertex[5]);
		glVertex3fv(mvertex[6]);
		glVertex3fv(mvertex[7]);
		glEnd();

		v1 = Normal(mvertex[8], mvertex[9], mvertex[10]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(mvertex[8]);
		glVertex3fv(mvertex[9]);
		glVertex3fv(mvertex[10]);
		glVertex3fv(mvertex[11]);
		glEnd();

		v1 = Normal(mvertex[12], mvertex[13], mvertex[14]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(mvertex[12]);
		glVertex3fv(mvertex[13]);
		glVertex3fv(mvertex[14]);
		glVertex3fv(mvertex[15]);
		glEnd();

		v1 = Normal(mvertex[16], mvertex[17], mvertex[18]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(mvertex[16]);
		glVertex3fv(mvertex[17]);
		glVertex3fv(mvertex[18]);
		glVertex3fv(mvertex[19]);
		glEnd();

		v1 = Normal(mvertex[20], mvertex[21], mvertex[22]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(mvertex[20]);
		glVertex3fv(mvertex[21]);
		glVertex3fv(mvertex[22]);
		glVertex3fv(mvertex[23]);
		glEnd();

		glPopMatrix();



		glutPostRedisplay();
	}

	void draw_button() {
		glPushMatrix();
		glTranslatef(bx1, by1, bz1);
		glColor3f(1.0, 0.0, 0.0);

		position v1 = Normal(bvertex[0], bvertex[1], bvertex[2]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[0]);
		glVertex3fv(bvertex[1]);
		glVertex3fv(bvertex[2]);
		glVertex3fv(bvertex[3]);
		glEnd();

		v1 = Normal(bvertex[4], bvertex[5], bvertex[6]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[4]);
		glVertex3fv(bvertex[5]);
		glVertex3fv(bvertex[6]);
		glVertex3fv(bvertex[7]);
		glEnd();

		v1 = Normal(bvertex[8], bvertex[9], bvertex[10]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[8]);
		glVertex3fv(bvertex[9]);
		glVertex3fv(bvertex[10]);
		glVertex3fv(bvertex[11]);
		glEnd();

		v1 = Normal(bvertex[12], bvertex[13], bvertex[14]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[12]);
		glVertex3fv(bvertex[13]);
		glVertex3fv(bvertex[14]);
		glVertex3fv(bvertex[15]);
		glEnd();

		v1 = Normal(bvertex[16], bvertex[17], bvertex[18]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[16]);
		glVertex3fv(bvertex[17]);
		glVertex3fv(bvertex[18]);
		glVertex3fv(bvertex[19]);
		glEnd();

		v1 = Normal(bvertex[20], bvertex[21], bvertex[22]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[20]);
		glVertex3fv(bvertex[21]);
		glVertex3fv(bvertex[22]);
		glVertex3fv(bvertex[23]);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(bx2, by2, bz2);
		glColor3f(1.0, 0.0, 0.0);

		v1 = Normal(bvertex[0], bvertex[1], bvertex[2]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[0]);
		glVertex3fv(bvertex[1]);
		glVertex3fv(bvertex[2]);
		glVertex3fv(bvertex[3]);
		glEnd();

		v1 = Normal(bvertex[4], bvertex[5], bvertex[6]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[4]);
		glVertex3fv(bvertex[5]);
		glVertex3fv(bvertex[6]);
		glVertex3fv(bvertex[7]);
		glEnd();

		v1 = Normal(bvertex[8], bvertex[9], bvertex[10]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[8]);
		glVertex3fv(bvertex[9]);
		glVertex3fv(bvertex[10]);
		glVertex3fv(bvertex[11]);
		glEnd();

		v1 = Normal(bvertex[12], bvertex[13], bvertex[14]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[12]);
		glVertex3fv(bvertex[13]);
		glVertex3fv(bvertex[14]);
		glVertex3fv(bvertex[15]);
		glEnd();

		v1 = Normal(bvertex[16], bvertex[17], bvertex[18]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[16]);
		glVertex3fv(bvertex[17]);
		glVertex3fv(bvertex[18]);
		glVertex3fv(bvertex[19]);
		glEnd();

		v1 = Normal(bvertex[20], bvertex[21], bvertex[22]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[20]);
		glVertex3fv(bvertex[21]);
		glVertex3fv(bvertex[22]);
		glVertex3fv(bvertex[23]);
		glEnd();

		glPopMatrix();
	}


	void check_players_To_distance(float p1x, float p2x) {
		if (p1x - x < 2.0 || p2x - x < 2.0) { //오브젝트와 플레이어가 가까워지면 오브젝트 z값 감소
			if (!p1b1 && !p1b2 && !p2b1 && !p2b2) {
				if (mov < 3.5)
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
			if (p1Head > (z - mov) - 1.0) {
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
			if (bz1 - 0.1 >= p1bottom) {
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
			if (bz1 - 0.1 >= p2bottom) {
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
			if (bz2 - 0.1 >= p1bottom) {
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
			if (bz2 - 0.1 >= p2bottom) {
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
	float bvertex[24][3] = {
	{0.0, 1.5, 0.0},{-1.0, 1.5, 0.0},{-1.0, 1.5, -0.5},{0.0,  1.5, -0.5},
	{0.0, 1.5, 0.0},{0.0, -1.5, 0.0},{0.0, -1.5, -0.5},{0.0,  1.5, -0.5},
	{0.0, -1.5, 0.0},{-1.0, -1.5, 0.0},{-1.0, -1.5, -0.5},{0.0, -1.5, -0.5},
	{-1.0, 1.5, 0.0},{-1.0, -1.5, 0.0},{-1.0, -1.5, -0.5},{-1.0, 1.5, -0.5},
	{0.0, 1.5, 0.0},{-1.0, 1.5, 0.0},{-1.0, -1.5, 0.0},{0.0, -1.5, 0.0},
	{0.0, 1.5, -0.5},{-1.0, 1.5, -0.5},{-1.0, -1.5, -0.5},{0.0, -1.5, -0.5}
	};
public:
	object_cloud(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->bx1 = x + 2.5;
		this->by1 = y;
		this->bz1 = z;

		this->bx2 = x - 7.0;
		this->by2 = y;
		this->bz2 = z;
		p1b1 = false;
		p1b2 = false;
		p2b1 = false;
		p2b2 = false;
	}

	position Normal(float v1[3], float v2[3], float v3[3])
	{
		float v11[3], v22[3];
		position out;
		static const int x = 0;
		static const int y = 1;
		static const int z = 2;

		// Calculate two vectors from the three points
		v11[x] = v1[x] - v2[x];
		v11[y] = v1[y] - v2[y];
		v11[z] = v1[z] - v2[z];

		v22[x] = v3[x] - v1[x];
		v22[y] = v3[y] - v1[y];
		v22[z] = v3[z] - v1[z];

		float len1 = sqrt(v11[x] * v11[x] + v11[y] * v11[y] + v11[z] * v11[z]);
		float len2 = sqrt(v22[x] * v22[x] + v22[y] * v22[y] + v22[z] * v22[z]);

		v11[x] = v11[x] / len1; v11[y] = v11[y] / len1; v11[z] = v11[z] / len1;
		v22[x] = v22[x] / len2; v22[y] = v22[y] / len2; v22[z] = v22[z] / len2;

		out.x = v11[y] * v22[z] - v11[z] * v22[y];
		out.y = v11[z] * v22[x] - v11[x] * v22[z];
		out.z = v11[x] * v22[y] - v11[y] * v22[x];
		// Normalize the vector (shorten length to one)
		return out;
	}

	void draw_cloud() {
		if (p1b1 || p1b2 || p2b1 || p2b2) {
			glPushMatrix();
			glTranslatef(x, y, z + 1.0);
			glColor3f(0.0, 0.4, 0.5);

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, -0.5);
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
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, -0.5);
			glVertex3f(-1.5, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, -0.5);
			glVertex3f(-1.5, y + 1.5, -0.5);
			glVertex3f(-1.5, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(x - 2.0, y, z + 1.5);
			glColor3f(0.0, 0.4, 0.5);
			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, -0.5);
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
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, -0.5);
			glVertex3f(-1.5, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, -0.5);
			glVertex3f(-1.5, y + 1.5, -0.5);
			glVertex3f(-1.5, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(x - 4.0, y, z + 1.0);
			glColor3f(0.0, 0.4, 0.5);
			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, -0.5);
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
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, -0.5);
			glVertex3f(0.0, y - 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, -0.5);
			glVertex3f(-1.5, y + 1.5, -0.5);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, 0.0);
			glVertex3f(-1.5, y + 1.5, 0.0);
			glVertex3f(-1.5, y - 1.5, 0.0);
			glVertex3f(0.0, y - 1.5, 0.0);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(0.0, y + 1.5, -0.5);
			glVertex3f(-1.5, y + 1.5, -0.5);
			glVertex3f(-1.5, y - 1.5, -0.5);
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

		position v1 = Normal(bvertex[0], bvertex[1], bvertex[2]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[0]);
		glVertex3fv(bvertex[1]);
		glVertex3fv(bvertex[2]);
		glVertex3fv(bvertex[3]);
		glEnd();

		v1 = Normal(bvertex[4], bvertex[5], bvertex[6]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[4]);
		glVertex3fv(bvertex[5]);
		glVertex3fv(bvertex[6]);
		glVertex3fv(bvertex[7]);
		glEnd();

		v1 = Normal(bvertex[8], bvertex[9], bvertex[10]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[8]);
		glVertex3fv(bvertex[9]);
		glVertex3fv(bvertex[10]);
		glVertex3fv(bvertex[11]);
		glEnd();

		v1 = Normal(bvertex[12], bvertex[13], bvertex[14]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[12]);
		glVertex3fv(bvertex[13]);
		glVertex3fv(bvertex[14]);
		glVertex3fv(bvertex[15]);
		glEnd();

		v1 = Normal(bvertex[16], bvertex[17], bvertex[18]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[16]);
		glVertex3fv(bvertex[17]);
		glVertex3fv(bvertex[18]);
		glVertex3fv(bvertex[19]);
		glEnd();

		v1 = Normal(bvertex[20], bvertex[21], bvertex[22]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[20]);
		glVertex3fv(bvertex[21]);
		glVertex3fv(bvertex[22]);
		glVertex3fv(bvertex[23]);
		glEnd();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(bx2, by2, bz2);
		glColor3f(1.0, 0.0, 0.0);

		v1 = Normal(bvertex[0], bvertex[1], bvertex[2]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[0]);
		glVertex3fv(bvertex[1]);
		glVertex3fv(bvertex[2]);
		glVertex3fv(bvertex[3]);
		glEnd();

		v1 = Normal(bvertex[4], bvertex[5], bvertex[6]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[4]);
		glVertex3fv(bvertex[5]);
		glVertex3fv(bvertex[6]);
		glVertex3fv(bvertex[7]);
		glEnd();

		v1 = Normal(bvertex[8], bvertex[9], bvertex[10]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[8]);
		glVertex3fv(bvertex[9]);
		glVertex3fv(bvertex[10]);
		glVertex3fv(bvertex[11]);
		glEnd();

		v1 = Normal(bvertex[12], bvertex[13], bvertex[14]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[12]);
		glVertex3fv(bvertex[13]);
		glVertex3fv(bvertex[14]);
		glVertex3fv(bvertex[15]);
		glEnd();

		v1 = Normal(bvertex[16], bvertex[17], bvertex[18]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[16]);
		glVertex3fv(bvertex[17]);
		glVertex3fv(bvertex[18]);
		glVertex3fv(bvertex[19]);
		glEnd();

		v1 = Normal(bvertex[20], bvertex[21], bvertex[22]);
		glBegin(GL_QUADS);
		glNormal3f(v1.x, v1.y, v1.z);
		glVertex3fv(bvertex[20]);
		glVertex3fv(bvertex[21]);
		glVertex3fv(bvertex[22]);
		glVertex3fv(bvertex[23]);
		glEnd();


		glPopMatrix();
	}

	void collision_button(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.1;
		float p2bottom = p2z - 1.1;
		if (p1x + 0.5 >= (bx1 - 1.0) && p1x - 0.5 <= bx1) {
			if (bz1 - 0.1 >= p1bottom) {
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
			if (bz1 - 0.1 >= p2bottom) {
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
			if (bz2 - 0.1 >= p1bottom) {
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
			if (bz2 - 0.1 >= p2bottom) {
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

	void collision_cloud(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
		float p1bottom = p1z - 1.0;
		float p2bottom = p2z - 1.0;
		float p1head = p1z + 1.4;
		//cout << p1z << endl;
		if (p1b1 || p1b2 || p2b1 || p2b2) {
			//1번째구름충돌//
			if (p1x + 0.5 >= (x - 1.5) && p1x - 0.5 <= x) {
				if (z + 1.0 >= p1bottom) {
					p1z = (z + 1.0) + 2.0 * 0.5;
				}

				else if (p1x >= x && p1bottom <= z) {
					p1x = x + 0.5;
				}

				else if (p1x <= x - 1.5 && p1bottom <= z) {
					p1x = (x - 1.5) - 0.5;
				}
			}

			if (p2x + 0.5 >= (x - 1.5) && p2x - 0.5 <= x) {
				if (z + 1.0 >= p2bottom) {
					p2z = (z + 1.0) + 2.0 * 0.5;
				}

				else if (p2x >= x && p2bottom <= z) {
					p2x = x + 0.5;
				}

				else if (p2x <= x - 1.5 && p2bottom <= z) {
					p2x = (x - 1.5) - 0.5;
				}
			}
			//2번째구름충돌//
			if (p1x + 0.5 >= (x - 3.5) && p1x - 0.5 <= (x - 2.0)) {
				if (z + 1.5 >= p1bottom) {
					p1z = (z + 1.5) + 2.0 * 0.5;
				}

				else if (p1x >= x - 2.0 && p1bottom <= z + 1.0) {
					p1x = x - 2.0 + 0.5;
				}

				else if (p1x <= x - 3.5 && p1bottom <= z + 1.0) {
					p1x = (x - 4.5) - 0.5;
				}
			}

			if (p2x + 0.5 >= (x - 3.5) && p2x - 0.5 <= (x - 2.0)) {
				if (z + 1.5 >= p2bottom) {
					p2z = (z + 1.5) + 2.0 * 0.5;
				}

				else if (p2x >= x - 2.0 && p2bottom <= z + 1.0) {
					p2x = x - 2.0 + 0.5;
				}

				else if (p2x <= x - 3.5 && p2bottom <= z + 1.0) {
					p2x = (x - 3.5) - 0.5;
				}
			}
			//3번째구름충돌//
			if (p1x + 0.5 >= (x - 5.5) && p1x - 0.5 <= (x - 4.0)) {
				if (z + 1.0 >= p1bottom) {
					p1z = (z + 1.0) + 2.0 * 0.5;
				}

				else if (p1x >= x - 4.0 && p1bottom <= z + 1.0) {
					p1x = x - 4.0 + 0.5;
				}

				else if (p1x <= x - 5.5 && p1bottom <= z + 1.0) {
					p1x = (x - 5.5) - 0.5;
				}
			}

			if (p2x + 0.5 >= (x - 5.5) && p2x - 0.5 <= (x - 4.0)) {
				if (z + 1.0 >= p2bottom) {
					p2z = (z + 1.0) + 2.0 * 0.5;
				}

				else if (p2x >= x - 4.0 && p2bottom <= z + 1.0) {
					p2x = x - 4.0 + 0.5;
				}

				else if (p2x <= x - 5.5 && p2bottom <= z + 1.0) {
					p2x = (x - 5.5) - 0.5;
				}
			}
		}
	}

};

class object_candy {
private:
	float x;
	float y;
	float z;
	float mov = 0.0;
	bool collision = false;
public:
	object_candy(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z + 0.5;
		mov = 0.0;
		collision = false;
	}

	void draw_candy() {
		if (!collision) {
			glPushMatrix();
			glTranslated(x + mov, y, z);
			glColor3f(1.0, 1.0, 1.0);
			glutSolidSphere(0.3, 30, 30);
			glPopMatrix();

			glPushMatrix();
			glTranslated(x + mov, y, z);
			glBegin(GL_POLYGON);
			glVertex3f(0.2, y, 0.0);
			glVertex3f(0.5, y, 0.3);
			glVertex3f(0.5, y, -0.3);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(-0.2, y, 0.0);
			glVertex3f(-0.5, y, 0.3);
			glVertex3f(-0.5, y, -0.3);
			glEnd();
			glPopMatrix();
		}


		glutPostRedisplay();
	}

	void check_players_To_distance(float p1x, float p2x) {
		if (p1x - x < 4.0 || p2x - x < 4.0) { //오브젝트와 플레이어가 가까워지면 오브젝트 z값 감소
			mov += 0.005;

		}
	}

	void collision_candy(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z, int& life) {
		if (!collision) {
			if ((p1x - (x + mov) < 0.7 && p1z - 1.0 < z + 0.3 && p1x - (x + mov) > 0.0) || (p2x - (x + mov) < 0.7 && p2z - 1.0 < z + 0.3 && p2x - (x + mov) > 0.0)) {
				collision = true;
				life -= 1;
				cout << "life: " << life << endl;
			}
		}
	}
};