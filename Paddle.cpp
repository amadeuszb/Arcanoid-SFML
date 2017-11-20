#include "Paddle.h"



Paddle::Paddle(float x, float y){

	rectangle.setPosition(x, y);
	rectangle.setSize({ this->width,this->height });
	rectangle.setOrigin(width / 2.f, height / 2.f);

	texturePaddle.loadFromFile("paletka.png");
	
	rectangle.setTexture(&texturePaddle);

}

void Paddle::draw(RenderTarget& target, RenderStates state) const {

	target.draw(this->rectangle, state);

}
void Paddle::changePosition() {

	this->rectangle.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0) {
		velocity.x = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800) { //i need to add varaiable for resolution or do this in main class
		velocity.x = paddleVelocity;
	}
	else {
		velocity.x = 0;
	}

}

float Paddle::left() {

	return this->rectangle.getPosition().x - rectangle.getSize().x / 2.f;
}

float Paddle::right() {

	return this->rectangle.getPosition().x + rectangle.getSize().x / 2.f;
}

float Paddle::up() {

	return this->rectangle.getPosition().y - rectangle.getSize().y / 2.f;
}

float Paddle::down() {

	return this->rectangle.getPosition().y + rectangle.getSize().y / 2.f;
}

Vector2f Paddle::getPosition() {

	return rectangle.getPosition();

}

Paddle::~Paddle(){

}
