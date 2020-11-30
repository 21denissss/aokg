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
	// �����������
	GraphicObject();

	// �������, ����, ����
	GraphicObject(vec3 position, float grad, vec3 color);

	// ��������� � ��������� ������� �������
	void setPosition(vec3 position);
	vec3 getPosition();

	// ��������� � ��������� ���� �������� � ��������
	// ������� �������������� � �������������� ���������
	// ������ ��� Oy �� ������� �������
	void setAngle(float grad);
	float getAngle();

	// ��������� �������� ����� �������
	void set�olor(vec3 color);
	vec3 getColor();

	// ��������� ������������� ���������
	void setMaterial(shared_ptr<PhongMaterial> material);

	// ��������� ������������� ����
	void setMesh(std::shared_ptr<Mesh> mesh);

	// ������� ������
	void draw();

	void changeAngle(float grad);

	void moveForward(float dist);
private:
	// ������� ������� � ���������� ������� ���������
	vec3 position;

	// ���� �������� � �������������� ��������� (� ��������)
	float angle;

	// ���� ������
	vec3 color;

	// ������� ������ - ���� �� ��������� ������ ���
	GLfloat modelMatrix[16];

	// ������������ ��������
	shared_ptr<PhongMaterial> material;

	// ������������ ���
	shared_ptr<Mesh> mesh;
private:
	// ������ ������� modelMatrix �� ������ position � angle
	void recalculateModelMatrix();
};