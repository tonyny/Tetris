#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tetris", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
}

void Game::run()
{
	tetro.createTet(Tetro::J);
	// Gameplay Loop
	while (window.isOpen())
	{
		// Event Handling
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			// debug
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				std::cout << "(" << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << ")\n";
		}
		// Clear 
		window.clear(sf::Color::Black);
		// Draw
		draw();
		// Update

		// Display
		window.display();
	}
}

void Game::draw()
{
	window.draw(tetro);
}

void Game::update()
{

}

