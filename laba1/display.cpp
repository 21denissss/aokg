#include "display.h"


// Переменные для подсчета фпс
LARGE_INTEGER prevTime, currTime, incFrequncy;

// функция, вызываемая при изменении размеров окна
void reshape(int w, int h)
{
	// установить новую область просмотра, равную всей области окна
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// установить матрицу проекции с правильным аспектом
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

// функция вызывается при перерисовке окна
// в том числе и принудительно, по командам glutPostRedisplay
void display(void)
{
	// Вывод фпс
	glutSetWindowTitle(("6 лаба [" + to_string(getFPS()) + ']').c_str());

	// отчищаем буфер цвета и буфер глубины
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// включаем тест глубины
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	
	



	//test.draw();

	light.apply();
	//material2.apply();
	// устанавливаем камеру
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

	// смена переднего и заднего буферов
	glutSwapBuffers();
};