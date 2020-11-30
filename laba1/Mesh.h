#pragma once

#define _USE_MATH_DEFINES
#include "GL/glew.h"

#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "PhongMaterial.h"
#include <math.h>
#include <map>
#include <sstream>


//#include "GL/glew.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"



using namespace glm;
using namespace std;

// Структура, описывающая одну вершину полигональной сетки
// каждая вершина имеет геометрические координаты,
// вектор нормали и текстурные координаты
struct Vertex
{
	// геометрические координаты
	GLfloat coord[3];
	// вектор нормали
	GLfloat normal[3];
	// текстурные координаты нулевого текстурного блока
	GLfloat texCoord[2];
};

// КЛАСС ДЛЯ РАБОТЫ C МЕШЕМ
class Mesh
{
public:
	// конструктор
	Mesh();
	// загрузка меша из файла с указанным именем
	void load(std::string filename);
	// вывод меша (передача всех вершин в OpenGL)
	void draw();
private:
	// массив вершин полигональной сетки
	std::vector<Vertex> vertices;
	// массив индексов
	std::vector<GLuint> indices;
};