#pragma once
#include<SFML\Graphics.hpp>
#include"Game.h"
using namespace std;
using namespace sf;


class Paddle 
	:public Drawable
	
{
public:
	void draw();
	Paddle(float, float);
	Paddle() = delete;
	~Paddle();
	void changePosition();
	float left();
	float right();
	float up();
	float down();
private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape rectangle;
	Texture texturePaddle;
	const float width{ 180.0f };
	const float height{ 30.0f };
	const float paddleVelocity{ 6.0f };
	Vector2f velocity{ paddleVelocity, 0 };

};