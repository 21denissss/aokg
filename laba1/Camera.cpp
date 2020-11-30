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
	// ���������� ������ - ���������� �� ������ ������� ��������� �� �������� �������
	r = length(position);
	// ���������� ������������ ����:
	// ��� ���� ����� �������� �� ������ ��������� � ����������� (v1)
	// � ��������� ����� ������� �� �������������� ��������� (v2)
	// ��� ����������� ���� ������������ ��������� ������������ ��������������� ��������
	vec3 v1 = position;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	// ����������� ������� ���������� �������������� ����:
	// ��� ���� ����� ��������� (v2) � ��������� �������� ����� ��� Ox
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	// ������������� ������� (��� ������������� ������ ����������)
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