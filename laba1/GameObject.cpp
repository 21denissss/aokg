#include "GameObject.h"


// �����������
GameObject::GameObject()
{

}
// ��������� ������������� ������������ �������
// ���������� ����������� ����������� ������� ��� ������������ �������������
void GameObject::setGraphicObject(const GraphicObject& graphicObject)
{
	this->graphicObject = graphicObject;
}
// ��������� ���������� ��������� (��� ������������� ������ ��� ��������)
void GameObject::setPosition(int x, int y)
{
	x -= 10;
	y -= 10;
	this->position = ivec2(x, y);
	graphicObject.setPosition(vec3(x,0.5,y));
}
// ������ �������� � ��������� ����������� � ��������� ���������
// �������� ������������ ������������ ����������� ������ � �������
void  GameObject::move(MoveDirection direction, float speed)
{
	vec3 newPos;
	switch (direction)
	{
	case MoveDirection::STOP:
		break;
	case MoveDirection::LEFT:
		newPos = vec3(position.x - speed, 0.5, position.y);
		break;
	case MoveDirection::RIGHT:
		break;
	case MoveDirection::UP:
		break;
	case MoveDirection::DOWN:
		break;
	default:
		break;
	}
	while (progress < 1.0) {
		graphicObject.setPosition(newPos);
		progress += speed;
	}
	progress = 0.0;
}
// �������� �� ��, ��� ������ � ��������� ������ ��������
bool  GameObject::isMoving()
{
	if(progress != 0.0)
		return true;
	return false;
}
// ��������� �������� ������� (������� ����������� �������)
// ����� ���������� ���������� � ������� simulation
void  GameObject::simulate(float sec)
{

}

void GameObject::setPosition(ivec2 position)
{
	int x = position.x - 10;
	int y = position.y - 10;
	setPosition(x, y);
}
// ��������� ������� ���������� ���������
ivec2 GameObject::getPosition()
{
	return position;
}
// ����� �������� ������� �� �����
void GameObject::draw(void)
{
	graphicObject.draw();
}