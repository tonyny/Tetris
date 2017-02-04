#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tetris", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
}

void Game::run()
{
	// Change parameters for different block
	tetro.createTetro(Tetro::T);
	// Gameplay Loop
	while (window.isOpen())
	{
		_dt = clock.restart();
		// Event Handling 
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			// debug
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				std::cout << "(" << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << ")\n";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				// testing

				std::uniform_int_distribution<int> dist(0, 6);
				int piece = dist(generator);
				tetro.createTetro(Tetro::Shape(piece));
			}
		}
		// Clear 
		window.clear(sf::Color::Black);
		// Draw
		draw();
		// Update
		update();
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
	tetro.update(_dt);
}