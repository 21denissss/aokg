#include "Camera.h"

Camera::Camera()
{

}

Camera::Camera(vec3 position)
{
	setPosition(position);
	recalculatePosition();

}

Camera::Camera(float x,float y,float z)
{
	vec3 position = vec3(x, y, z);
	setPosition(position);
}

void Camera::setPosition(vec3 position)
{
	// определяем радиус - расстояние от начала системы координат до заданной позиции
	r = length(position);
	// определяем вертикальный угол:
	// это угол между вектором из начала координат к наблюдателю (v1)
	// и проекцией этого вектора на горизонтальную плоскость (v2)
	// для определения угла используется скалярное произведение нормализованных векторов
	vec3 v1 = position;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	// аналогичным образом определяем горизонтальный угол:
	// это угол между проекцией (v2) и единичным вектором вдоль оси Ox
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	// пересчитываем позицию (для корректировок ошибок округления)
	recalculatePosition();
}

vec3 Camera::getPosition()
{
	return this->position;
}

void Camera::rotateLeftRight(float degree)
{
	angleX += degree;
	if (angleX > 360) {
		angleX -= 360;
	}
	if (angleX < -360) {
		angleX += 360;
	}
	recalculatePosition();
}

void Camera::rotateUpDown(float degree)
{
	angleY += degree;
	if (angleY > 89) {
		angleY -= degree;
	}
	if (angleY < 0) {
		angleY -= degree;
	}
	recalculatePosition();
}

void Camera::zoomInOut(float distance)
{
	r -= distance;
	r < 10 ? r = 10 : r = r;
	r > 50 ? r = 50 : r = r;

	recalculatePosition();
}

void Camera::apply()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(position.x,position.y,position.z,0,0,0,0,1,0);
}

void Camera::recalculatePosition()
{
	position.y = r * sin(radians(angleY));
	float radius = r * cos(radians(angleY));
	position.x = radius * sin(radians(angleX));
	position.z = radius * cos(radians(angleX));
}