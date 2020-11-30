#pragma once
#include "GL/glew.h"
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <map>
#include <sstream>
#include "GameObject.h"
#include <iomanip>


#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"
#include "../rapidjson-master/include/rapidjson/document.h"

using namespace glm;
using namespace rapidjson;
using namespace std;

enum class GameObjectType {
	LIGHT_OBJECT, // ������ ������� ������
	HEAVY_OBJECT, // ������� ������� ������
	BORDER_OBJECT, // ��������� ������� ������
	PLAYER, // ������� ������ ��� ������������� ������
	BOMB, // ������� ������ ��� ������������� �����
	MONSTER // ������� ������ ��� ������������� ��������
};

class GameObjectFactory
{
public:
	// ������������� ������� (�������� ����� � ��������� ���������� ���������)
	void init();
	// �������� ������ ������� ��������� ����
	std::shared_ptr<GameObject> create(GameObjectType type, int x, int y);
private:
	// ���� ��� ������� ���� �������
	std::vector<std::shared_ptr<Mesh>> meshes;
	// ��������� ��� ������� ���� �������
	std::vector<std::shared_ptr<PhongMaterial>> materials;

	map<GameObjectType, int>thisMap;
	
};