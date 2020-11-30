#include "display.h"


// ���������� ��� �������� ���
LARGE_INTEGER prevTime, currTime, incFrequncy;

// �������, ���������� ��� ��������� �������� ����
void reshape(int w, int h)
{
	// ���������� ����� ������� ���������, ������ ���� ������� ����
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// ���������� ������� �������� � ���������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};

int getFPS()
{
	static int counter;
	static int oldFps;
	QueryPerformanceCounter(&currTime);
	QueryPerformanceFrequency(&incFrequncy);
	counter++;
	float time = (currTime.QuadPart - prevTime.QuadPart) / incFrequncy.QuadPart;
	//int fps = incFrequncy.QuadPart / (currTime.QuadPart - prevTime.QuadPart);
	//cout << ((float)currTime.QuadPart - (float)prevTime.QuadPart) / (float)incFrequncy.QuadPart << endl;
	if (time >= 1.0) {
		prevTime = currTime;
		oldFps = counter;
		counter = 0;
	}
	return oldFps;
}

// ������� ���������� ��� ����������� ����
// � ��� ����� � �������������, �� �������� glutPostRedisplay
void display(void)
{
	// ����� ���
	glutSetWindowTitle(("6 ���� [" + to_string(getFPS()) + ']').c_str());

	// �������� ����� ����� � ����� �������
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// �������� ���� �������
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	
	



	//test.draw();

	light.apply();
	//material2.apply();
	// ������������� ������
	camera.apply();

	//graphicObjects[0].changeAngle(-10);

	planeGraphicObject.draw();
	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if(mapObjects[i][j] != nullptr)
				mapObjects[i][j]->draw();
		}
	}
	player->draw();

	//glutWireTeapot(1.0);
	glDisable(GL_LIGHTING);

	// ����� ��������� � ������� �������
	glutSwapBuffers();
};