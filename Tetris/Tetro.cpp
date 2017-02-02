#include "stdafx.h"
#include "Tetro.h"


Tetro::Tetro()
{
	_width = 45;
	_height = 45;
	_pos = sf::Vector2f(250.0f, 0.0f);
}

void Tetro::createTet()
{
	// Create L tetro
	// Size is number of quads * 4
	tet.resize(4 * 4);
	tet.setPrimitiveType(sf::Quads);
	for (int i = 0; i < 4; i++)
	{
		// Gets pointer to current block 
		sf::Vertex *quad = &tet[i * 4];
		quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
		quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
		quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
		quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));

		// Last block is placed to right
		if (i == 3)
		{
			std::cout << "last\n";
			quad[0] = sf::Vector2f(_pos.x + _width, _pos.y + ((i - 1) * _height));
			quad[1] = sf::Vector2f(_pos.x + _width * 2, _pos.y + ((i - 1) * _height));
			quad[2] = sf::Vector2f(_pos.x + _width * 2, _pos.y + _height * (1 + (i - 1)));
			quad[3] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + (i - 1)));
		}
	}
}

void Tetro::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(tet, states);
}

void Tetro::update()
{

}
