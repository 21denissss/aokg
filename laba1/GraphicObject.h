#pragma once
#include "GL/glew.h"
#include "Mesh.h"

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "PhongMaterial.h"
#define _USE_MATH_DEFINES
#include <math.h>


#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;

class GraphicObject
{
public:
	// Конструктор
	GraphicObject();

	// позиция, угол, цвет
	GraphicObject(vec3 position, float grad, vec3 color);

	// Установка и получение позиции объекта
	void setPosition(vec3 position);
	vec3 getPosition();

	// Установка и получения угла поворота в градусах
	// поворот осуществляется в горизонтальной плоскости
	// вокруг оси Oy по часовой стрелке
	void setAngle(float grad);
	float getAngle();

	// Установка текущего цвета объекта
	void setСolor(vec3 color);
	vec3 getColor();

	// Установка используемого материала
	void setMaterial(shared_ptr<PhongMaterial> material);

	// Установка используемого меша
	void setMesh(std::shared_ptr<Mesh> mesh);

	// Вывести объект
	void draw();

	void changeAngle(float grad);

	void moveForward(float dist);
private:
	// Позиция объекта в глобальной системе координат
	vec3 position;

	// Угол поворота в горизонтальной плоскости (в градусах)
	float angle;

	// Цвет модели
	vec3 color;

	// Матрица модели - чтоб не вычислять каждый раз
	GLfloat modelMatrix[16];

	// Используемый материал
	shared_ptr<PhongMaterial> material;

	// Используемый меш
	shared_ptr<Mesh> mesh;
private:
	// расчет матрицы modelMatrix на основе position и angle
	void recalculateModelMatrix();
};