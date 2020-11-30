#include "GraphicObject.h"


GraphicObject::GraphicObject()
{
	this->position = vec3(0, 0, 0);
	this->angle = 0;
	this->color = vec3(1, 0, 0);
	material = nullptr;
	mesh = nullptr;
	recalculateModelMatrix();
}

GraphicObject::GraphicObject(vec3 position,float grad, vec3 color)
{
	this->position = position;
	this->angle = grad;
	this->color = color;
	material = nullptr;
	mesh = nullptr;
	recalculateModelMatrix();
}

void GraphicObject::setPosition(vec3 position)
{
	this->position = position;
	recalculateModelMatrix();
}

vec3 GraphicObject::getPosition()
{
	return this->position;
}

void GraphicObject::setAngle(float grad)
{
	this->angle = grad;
	recalculateModelMatrix();
}

float GraphicObject::getAngle()
{
	return this->angle;
}

void GraphicObject::setСolor(vec3 color)
{
	this->color = color;
}

vec3 GraphicObject::getColor()
{
	return this->color;
}

// расчет матрицы modelMatrix на основе position и angle
void GraphicObject::recalculateModelMatrix()
{
	modelMatrix[0] = cosf(radians(angle));
	modelMatrix[1] = 0;
	modelMatrix[2] = sinf(radians(angle));
	modelMatrix[3] = 0;
	modelMatrix[4] = 0;
	modelMatrix[5] = 1;
	modelMatrix[6] = 0;
	modelMatrix[7] = 0;
	modelMatrix[8] = -sinf(radians(angle));
	modelMatrix[9] = 0;
	modelMatrix[10] = cosf(angle * M_PI / 180);
	modelMatrix[11] = 0;
	modelMatrix[12] = position.x;
	modelMatrix[13] = position.y;
	modelMatrix[14] = position.z;
	modelMatrix[15] = 1;
}

// вывести объект
void GraphicObject::draw()
{
	//glColor3f(color.r,color.g,color.b);
	
	glPushMatrix();
	glMultMatrixf(modelMatrix);
	if (material != nullptr)
		material->apply();
	if (mesh != nullptr)
		mesh->draw();
	//glutSolidTeapot(1.0);
	glPopMatrix();
}

void GraphicObject::changeAngle(float grad)
{
	angle += grad;
	angle = angle > 360 ? angle - 360 : angle;
	angle = angle < -360 ? angle + 360 : angle;
	recalculateModelMatrix();
}

void GraphicObject::moveForward(float dist)
{
	float tempAngle = radians(this->angle);
	this->position += vec3(dist*cos(tempAngle), 0, dist*sin(tempAngle));
	recalculateModelMatrix();
}

// Установка используемого материала
void GraphicObject::setMaterial(shared_ptr<PhongMaterial> material)
{
	this->material = material;
}

void GraphicObject::setMesh(std::shared_ptr<Mesh> mesh)
{
	this->mesh = mesh;
}