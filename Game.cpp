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
	vector<Block> blocks;
	for (unsigned int i = 0; i < blocksY; i++){ //this loop locates blocks on the gamefield
		for (unsigned int j = 0; j < blocksX; j++) {
			blocks.emplace_back((j + 1) * (blockWidth), (i + 2) * (blockHeight), blockWidth, blockHeight);
		}
	}
	while (pressEvent.type != Event::Closed) {
		
		window->clear(Color::White);
		ball.changePosition();
		paddle.changePosition();
		collisionTest(paddle, ball);
		for(auto& block : blocks) collisionTest(block, ball);
		window->draw(paddle);
		window->draw(ball);
		for (auto& block : blocks) //lecimy po wszystkich blokach z kontenera
		{
			window->draw(block);
		}
		window->display();
		window->pollEvent(this->pressEvent);
		paddle.changePosition();
		
	}
}

template <class T1, class T2> bool Game::isIntersecting(T1& a, T2& b) {

	return a.right() >= b.left() && a.left() <= b.right() && a.down() >= b.up() && a.up() <= b.down();

}

bool Game::collisionTest(Paddle& paddle, Ball& ball) {
	if (!isIntersecting(paddle, ball)) return false;
	else {
		ball.moveUp();
	}
	/*if (ball.getPosition().x < paddle.getPosition.x) ball.moveLeft();
	else ball.moveRight();
	*/
}
bool Game::collisionTest(Block& paddle, Ball& ball) {
	if (!isIntersecting(paddle, ball)) return false;
	else {
		ball.moveUp();
		paddle.destroy();
	}
}

Game::~Game(){
	delete window;
	//delete ball;
}
