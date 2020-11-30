#include "GL/glew.h"
#include <windows.h>
#include "GraphicObject.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <math.h>
#include "display.h"
#include "Camera.h"
#include <conio.h>
#include <string>
#include "simulation.h"
#include "data.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

#define _USE_MATH_DEFINES

// используем пространство имен стандартной библиотеки
using namespace std;
using namespace glm;


void main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");

	init();
	srand(time(0));
	// инициализация библиотеки GLUT
	glutInit(&argc, argv);
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// СОЗДАНИЕ ОКНА:
	// 1. устанавливаем верхний левый угол окна
	glutInitWindowPosition(200, 200);
	// 2. устанавливаем размер окна
	glutInitWindowSize(800, 600);
	// 3. создаем окно
	glutCreateWindow("Laba_01");

	// УСТАНОВКА ФУНКЦИЙ ОБРАТНОГО ВЫЗОВА
	// устанавливаем функцию, которая будет вызываться для перерисовки окна
	glutDisplayFunc(display);
	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(reshape);
	// устанавливаем функцию, которая будет вызвана
	glutIdleFunc(simulation);
	// основной цикл обработки сообщений ОС
	glutMainLoop();
};