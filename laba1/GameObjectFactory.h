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
	LIGHT_OBJECT, // легкий игровой объект
	HEAVY_OBJECT, // тяжелый игровой объект
	BORDER_OBJECT, // граничный игровой объект
	PLAYER, // игровой объект для представления игрока
	BOMB, // игровой объект для представления бомбы
	MONSTER // игровой объект для представления монстров
};

class GameObjectFactory
{
public:
	// инициализация фабрики (загрузка мешей и установка параметров материала)
	void init();
	// создание нового объекта заданного типа
	std::shared_ptr<GameObject> create(GameObjectType type, int x, int y);
private:
	// меши для каждого типа объекта
	std::vector<std::shared_ptr<Mesh>> meshes;
	// материалы для каждого типа объекта
	std::vector<std::shared_ptr<PhongMaterial>> materials;

	map<GameObjectType, int>thisMap;
	
};