#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

Game::Game(unsigned int x = 800, unsigned int y = 600){
	this->resolutionX = x;
	this->resolutionY = y;
	this->window = new RenderWindow(VideoMode(this->resolutionX, this->resolutionY), "Arcanoid Amadeusz");
	window->setFramerateLimit(60);
	//this->ball = new Ball((float)(resolutionX / 2), (float)(resolutionY / 2));
}

void Game::PlayGame(){
	
	Ball ball((float)(resolutionX / 2), (float)(resolutionY / 2));
	Paddle paddle(400, 550);
	while (pressEvent.type != Event::Closed) {
		
		window->clear(Color::White);
		ball.changePosition();
		paddle.changePosition();
		window->draw(paddle);
		window->draw(ball);
		window->display();
		window->pollEvent(this->pressEvent);
		paddle.changePosition();
		
	}
}

Game::~Game(){
	delete window;
	//delete ball;
}
