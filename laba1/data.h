#pragma once
#include "GL/glew.h"
#include "Mesh.h"
#include <windows.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <conio.h>
#include "GraphicObject.h"
#include "Camera.h"
#include <string>
#include "PhongMaterial.h"
#include "Light.h"
#include "GameObject.h"
#include <map>
#include "GameObjectFactory.h"


#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

using namespace std;
using namespace glm;

extern shared_ptr<GameObject> player;

// массив чайников
extern vector<GraphicObject> graphicObjects;

extern GraphicObject planeGraphicObject;

extern shared_ptr<GameObject> mapObjects[21][21];

extern Light light;

// Камера
extern Camera camera;

extern int passabilityMap[21][21];

extern vector<shared_ptr<PhongMaterial>> materials;

extern vector<shared_ptr<Mesh>> meshes;

// скорость поворота камеры(градус в секунду)
extern const float CAMERA_ROTATION_SPEED;

extern const float CAMERA_ZOOM_SPEED;

extern vector<ivec2>emptyPlaces;

void init();