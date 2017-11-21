#include "Object.h"


Object::Object()
{
	resolutionX = 800;
	resolutionY = 600;

}

Object::Object(unsigned int x = 800, unsigned int y = 600)
{
	resolutionX = x;
	resolutionY = y;

}

void Object::draw(RenderTarget& target, RenderStates state){

	target.draw(*shapeType, state);

}

float Object::left() {

	return this->shapeType->getPosition().x - sizeOfObjectX;
}

float Object::right() {

	return this->shapeType->getPosition().x + sizeOfObjectX;
}

float Object::up() {

	return this->shapeType->getPosition().y - sizeOfObjectY;
}

float Object::down() {

	return this->shapeType->getPosition().y + sizeOfObjectY;
}

Object::~Object()
{
}
