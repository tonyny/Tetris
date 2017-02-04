#pragma once
#include "Tetro.h"
class Game
{
public:
	Game();
	void run();

private:
	void draw();
	void update();

	int SCREEN_WIDTH = 700;
	int SCREEN_HEIGHT = 800;
	sf::RenderWindow window;
	sf::Time _dt;
	sf::Clock clock;

	// Game Objects
	Tetro tetro;

	//
	std::default_random_engine generator;
};

