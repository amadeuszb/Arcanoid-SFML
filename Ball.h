#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Ball 
	:public Drawable
{
public:
	Ball() = delete;
	Ball(float, float);
	~Ball();
	void changePosition();
	virtual float left();
	virtual float right();
	virtual float up();
	virtual float down();
private:
	float x, y; //resolution of screen 
	Texture food; //texture of ball
	CircleShape circle;
	float radius;
	const float ballVelocity{ 3.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(RenderTarget& target, RenderStates state) const override;
};

