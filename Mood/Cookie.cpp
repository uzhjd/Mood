//// �� //
//// 1. �Ϲ� �� 2. �浹üũ //
//#include <windows.h>
//#include <gl/gl.h>
//#include <glut.h>
//#include <iostream>
//#include <string>
//using namespace std;
//
//// 1. �Ϲ� �� //
//class generalRoad {
//private:
//	/// �� ��ġ///
//	float x;
//	float y;
//	float z;
//
//public:
//	generalRoad(float x, float y, float z) {
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//
//	void draw_generalRoad() {
//		glPushMatrix();
//		glTranslatef(x, y, z);
//
//		glColor3f(0.56, 0.47, 0.29);
//		gluSphere(3)
//
//		glPopMatrix();
//
//		glutPostRedisplay();
//	}
//
//
//	// 3. �浹 üũ
//	bool collisionRoad(float& p1x, float& p1y, float& p1z, float& p2x, float& p2y, float& p2z) {
//		float p1bottom = p1z - 2 * 0.5;
//		float p1middle = p1z - 1.5 * 0.5;
//		float p2bottom = p2z - 2 * 0.5;
//		float p2middle = p2z - 1.5 * 0.5;
//		if (p1x + 0.5 >= (x - 10.0) && p1x - 0.5 <= x) { //������ x�� ���̿� p1�� ���� ��
//			if (z - 0.5 >= p1bottom && p1middle >= z - 0.5) {
//				p1z = z + 0.5;
//			}
//			/*else if (p1x >= x)
//				p1x = x + 0.5;
//			else if (p1x <= x - 6.0) {
//				p1x = x - 6.0 - 0.5;
//			}*/
//
//
//		}
//
//		if (p2x + 0.5 >= (x - 10.0) && p2x - 0.5 <= x) { //������ x�� ���̿� p2�� ���� ��
//			if (z - 0.5 >= p2bottom && p2middle >= z - 0.5) {
//				p2z = z + 0.5;
//			}
//			/*else if (p2x >= x)
//				p2x = x + 0.5;
//			else if (p2x <= x - 6.0) {
//				p2x = x - 6.0 - 0.5;
//			}*/
//
//
//		}
//
//		if (p1bottom <= z - 1.0) {
//			// life���� �ϱ�
//			p1x = p1x + 0.9;
//			p1z = z + 0.5;
//			return true;
//		}
//
//		if (p2bottom <= z - 1.0) {
//			// life���� �ϱ�
//			p2x = p2x + 0.9;
//			p2z = z + 0.5;
//			return true;
//		}
//		return false;
//	}
//};