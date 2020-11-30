#pragma once
#include "GL/glew.h"

#include <windows.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <fstream>
#include <string>


#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

using namespace std;
using namespace glm;

class PhongMaterial
{
public:
	// ����������� �� ���������
	PhongMaterial();
	// ������� ���������� ���������
	void setAmbient(vec4 color);
	void setDiffuse(vec4 color);
	void setSpecular(vec4 color);
	void setEmission(vec4 color);
	void setShininess(float p);
	// �������� ���������� ��������� �� �������� ���������� �����
	void load(std::string filename);
	// ��������� ���� ���������� ���������
	void apply();
private:
	// ������� ������������
	vec4 ambient;
	// ��������� ������������
	vec4 diffuse;
	// ���������� ������������
	vec4 specular;
	// ������������
	vec4 emission;
	// ������� ����������������
	float shininess;
};