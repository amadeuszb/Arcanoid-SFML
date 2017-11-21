#include "Block.h"




Block::Block(float x, float y, float w, float h){
	rectangle.setPosition(x, y);
	rectangle.setSize({ this->w,this->h });
	rectangle.setFillColor(Color::Green);
	rectangle.setOrigin(w / 2.f, h / 2.f);
}

bool Block::isDestroyed() {
	return this->destroyed;
}

Vector2f Block::getPosition() {
	return rectangle.getPosition();
}
void Block::destroy() {
	this->destroyed = true;
}
Vector2f Block::getSize() {

	return rectangle.getSize();
}
void Block::draw(RenderTarget& target, RenderStates state) const {

	target.draw(this->rectangle, state);

}
float Block::left() {

	return this->rectangle.getPosition().x - rectangle.getSize().x / 2.f;
}

float Block::right() {

	return this->rectangle.getPosition().x + rectangle.getSize().x / 2.f;
}

float Block::up() {

	return this->rectangle.getPosition().y - rectangle.getSize().y / 2.f;
}

float Block::down() {

	return this->rectangle.getPosition().y + rectangle.getSize().y / 2.f;
}
void Block::update() {

}