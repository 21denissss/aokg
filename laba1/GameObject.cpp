#include "GameObject.h"


// конструктор
GameObject::GameObject()
{

}
// установка используемого графического объекта
// происходит копирование переданного объекта дл€ последующего использовани€
void GameObject::setGraphicObject(const GraphicObject& graphicObject)
{
	this->graphicObject = graphicObject;
}
// установка логических координат (два перегруженных метода дл€ удобства)
void GameObject::setPosition(int x, int y)
{
	x -= 10;
	y -= 10;
	this->position = ivec2(x, y);
	graphicObject.setPosition(vec3(x,0.5,y));
}
// начать движение в выбранном направлении с указанной скоростью
// скорость передвижени€ определ€етс€ количеством клеток в секунду
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
// проверка на то, что объект в насто€щий момент движетс€
bool  GameObject::isMoving()
{
	if(progress != 0.0)
		return true;
	return false;
}
// симул€ци€ игрового объекта (плавное перемещение объекта)
// метод вызываетс€ непрерывно в функции simulation
void  GameObject::simulate(float sec)
{

}

void GameObject::setPosition(ivec2 position)
{
	int x = position.x - 10;
	int y = position.y - 10;
	setPosition(x, y);
}
// получение текущих логических координат
ivec2 GameObject::getPosition()
{
	return position;
}
// вывод игрового объекта на экран
void GameObject::draw(void)
{
	graphicObject.draw();
}