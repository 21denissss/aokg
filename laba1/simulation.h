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
#include "data.h"
#include "display.h"


#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

void simulationCamera(float simulationTime);

// функция вызывается каждые 20 мс
void simulation();

double getSimulationTime();