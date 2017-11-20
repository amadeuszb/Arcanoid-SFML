#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include"Ball.h"
#include "Paddle.h"

class Game 
{
public:
	template <class T1, class T2> bool isIntersecting(T1&, T2&);
	bool collisionTest(Paddle&, Ball&);
	Game() = delete;
	Game(unsigned int, unsigned int);
	void PlayGame(); //this method starts game
	~Game();
private:
	sf::RenderWindow *window;
	unsigned int resolutionX, resolutionY;
	int rendering;
	sf::Event pressEvent; 
};

