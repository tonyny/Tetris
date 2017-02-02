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

	// Game Objects
	Tetro tetro;
};

