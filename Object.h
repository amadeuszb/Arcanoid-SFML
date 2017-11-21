#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Object
{
public:
	Object();
	Object(unsigned int, unsigned int);
	~Object();
	void changePosition();
	float left(); //to get position of object
	float right();
	float up();
	float down();
	Vector2f getPosition();

protected:
	Shape *shapeType;
	Texture textureOfObject;
	unsigned int resolutionX, resolutionY;
	float sizeOfObjectX;
	float sizeOfObjectY;
	float x, y; //resolution of screen 
	void draw(RenderTarget& target, RenderStates state);
};

