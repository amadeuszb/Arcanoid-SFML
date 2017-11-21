#pragma once
#include<SFML\Graphics.hpp>
#include"Object.h"

using namespace std;
using namespace sf;

class Block
	:public Drawable
{
public:
	Block() = delete;
	Block(float x, float y,float width, float height);
	~Block() = default;

	bool isDestroyed();
	void destroy();
	void changePosition();
	Vector2f getPosition();
	Vector2f getSize();
	void update();
	float left();
	float right();
	float up();
	float down();
private:
	void draw(RenderTarget& target, RenderStates state) const override;
	float w, h;
	RectangleShape rectangle;
	bool destroyed{ false };
};

