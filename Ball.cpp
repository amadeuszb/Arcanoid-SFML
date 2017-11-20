#include "Ball.h"



Ball::Ball(float x, float y){

	this->radius = 30.0f;
	this->x = 2 * x;
	this->y = 2 * y;
	circle.setPosition(x, y);
	circle.setRadius(this->radius);
	food.loadFromFile("jedzonko.png");
	circle.setTexture(&food);
	circle.setOrigin(this->radius, this->radius);
}
void Ball::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->circle, state);
}

void Ball::changePosition(){
	circle.move(this->velocity);

	if (this->left() < 0) velocity.x = ballVelocity;
	else if (this->right() > this->x) velocity.x = -ballVelocity;

	if (this->up() < 0) velocity.y = ballVelocity;
	else if (this->down() > this->y) velocity.y = -ballVelocity;
}

float Ball::left() { //these functions are responsible for checking position of ball on window
	return this->circle.getPosition().x - circle.getRadius();
}

float Ball::right() {
	return this->circle.getPosition().x + circle.getRadius();
}

float Ball::up() {
	return this->circle.getPosition().y - circle.getRadius();
}

float Ball::down() {
	return this->circle.getPosition().y + circle.getRadius();
}

void Ball::moveDown(){
	this->velocity.y = ballVelocity;
}
void Ball::moveUp() {
	this->velocity.y = -ballVelocity;
}
void Ball::moveRight() {
	this->velocity.x = -ballVelocity;
}
void Ball::moveLeft() {
	this->velocity.x = -ballVelocity;
}

Vector2f Ball::getPosition() {

	return circle.getPosition();

}
Ball::~Ball()
{
}
