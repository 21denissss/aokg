#pragma once
#include "GL/glew.h"

#include <windows.h>

#include <vector>
#include <iostream>
#include <math.h>
#include "GraphicObject.h"
#include "Camera.h"
#include <conio.h>
#include <string>
//#include "../rapidjson-master/include/rapidjson/document.h"


#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

class Light
{
public:
	// ������������
	Light();
	Light(vec3 position);
	Light(float x, float y, float z);
	// ������� ��������� ���������� ��������� �����
	void setPosition(vec3 position);
	void setAmbient(vec4 color);
	void setDiffuse(vec4 color);
	void setSpecular(vec4 color);
	// ��������� ���� ���������� ��������� ����� � �������� �������
	// ������ ������� ������ ���������� ����� ��������� ������,
	// �.�. ����� ��������������� ������� ��������� �����
	void apply(GLenum LightNumber = GL_LIGHT0);
private:
	// ������� ��������� �����
	vec4 position;
	// ������� ������������ ��������� �����
	vec4 ambient;
	// ��������� ������������
	vec4 diffuse;
	// ���������� ������������
	vec4 specular;
};