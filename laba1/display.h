#pragma once
#include "GL/glew.h"

#include "Mesh.h"

#include <windows.h>

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include "GraphicObject.h"
#include "Camera.h"
#include <conio.h>
#include <string>
#include "data.h"
#include "Light.h"
#include "PhongMaterial.h"


#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

void reshape(int w, int h);

int getFPS();

void display(void);