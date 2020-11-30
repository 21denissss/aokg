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

// ���������, ����������� ���� ������� ������������� �����
// ������ ������� ����� �������������� ����������,
// ������ ������� � ���������� ����������
struct Vertex
{
	// �������������� ����������
	GLfloat coord[3];
	// ������ �������
	GLfloat normal[3];
	// ���������� ���������� �������� ����������� �����
	GLfloat texCoord[2];
};

// ����� ��� ������ C �����
class Mesh
{
public:
	// �����������
	Mesh();
	// �������� ���� �� ����� � ��������� ������
	void load(std::string filename);
	// ����� ���� (�������� ���� ������ � OpenGL)
	void draw();
private:
	// ������ ������ ������������� �����
	std::vector<Vertex> vertices;
	// ������ ��������
	std::vector<GLuint> indices;
};