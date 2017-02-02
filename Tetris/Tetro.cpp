#include "stdafx.h"
#include "Tetro.h"


Tetro::Tetro()
{
	_width = 45;
	_height = 45;
	_pos = sf::Vector2f(250.0f, 0.0f);
}

void Tetro::createTet(Shape block)
{
	if (block == L)
	{
		// Create L tetro
		quads = 4;
		tet.resize(quads * 4);
		tet.setPrimitiveType(sf::Quads);
		for (int i = 0; i < quads; i++)
		{
			// Gets pointer to current block 
			sf::Vertex *quad = &tet[i * 4];
			quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
			quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
			quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
			quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));

			// Last block is placed to right
			if (i == quads - 1)
			{
				quad[0] = sf::Vector2f(_pos.x + _width, _pos.y + ((i - 1) * _height));
				quad[1] = sf::Vector2f(_pos.x + _width * 2, _pos.y + ((i - 1) * _height));
				quad[2] = sf::Vector2f(_pos.x + _width * 2, _pos.y + _height * i);
				quad[3] = sf::Vector2f(_pos.x + _width, _pos.y + _height * i);
			}
		}
	}
	else if (block == I)
	{
		// Create I tetro
		quads = 4;
		tet.resize(quads * 4);
		tet.setPrimitiveType(sf::Quads);
		for (int i = 0; i < quads; i++)
		{
			// Gets pointer to current block 
			sf::Vertex *quad = &tet[i * 4];
			quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
			quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
			quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
			quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));
		}
	}
	else if (block == J)
	{
		// Create J tetro
		quads = 4;
		tet.resize(quads * 4);
		tet.setPrimitiveType(sf::Quads);
		for (int i = 0; i < quads; i++)
		{
			// Gets pointer to current block 
			sf::Vertex *quad = &tet[i * 4];
			quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
			quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
			quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
			quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));

			// Last block is placed to left
			if (i == quads - 1)
			{
				quad[0] = sf::Vector2f(_pos.x - _width, _pos.y + ((i - 1) * _height));
				quad[1] = sf::Vector2f(_pos.x, _pos.y + ((i - 1) * _height));
				quad[2] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + (i - 1)));
				quad[3] = sf::Vector2f(_pos.x - _width, _pos.y + _height * (1 + (i - 1)));
			}
		}
	}
	else if (block == S)
	{
		// Create S tetro
		quads = 4;
		tet.resize(quads * 4);
		tet.setPrimitiveType(sf::Quads);
		for (int i = 0; i < quads; i++)
		{
			// Gets pointer to current block 
			sf::Vertex *quad = &tet[i * 4];
			quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
			quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
			quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
			quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));

			// Last block is placed to right
			if (i > 1)
			{
				quad[0] = sf::Vector2f(_pos.x + _width, _pos.y + ((i - 1) * _height));
				quad[1] = sf::Vector2f(_pos.x + _width * 2, _pos.y + ((i - 1) * _height));
				quad[2] = sf::Vector2f(_pos.x + _width * 2, _pos.y + _height * i);
				quad[3] = sf::Vector2f(_pos.x + _width, _pos.y + _height * i);
			}
		}
	}
	else if (block == O)
	{
		// Create O tetro
		quads = 4;
		tet.resize(quads * 4);
		tet.setPrimitiveType(sf::Quads);
		for (int i = 0; i < quads; i++)
		{
			// Gets pointer to current block 
			sf::Vertex *quad = &tet[i * 4];
			quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
			quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
			quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
			quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));

			// Last block is placed to right
			if (i > 1)
			{
				std::cout << "f\n";
				quad[0] = sf::Vector2f(_pos.x + _width, _pos.y + ((i - 2) * _height));
				quad[1] = sf::Vector2f(_pos.x + _width * 2, _pos.y + ((i - 2) * _height));
				quad[2] = sf::Vector2f(_pos.x + _width * 2, _pos.y + _height * (1 + (i - 2)));
				quad[3] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + (i - 2)));
			}
		}
	}
	else if (block == T)
	{
		// Create T tetro
		quads = 4;
		tet.resize(quads * 4);
		tet.setPrimitiveType(sf::Quads);
		for (int i = 0; i < quads; i++)
		{
			// Gets pointer to current block 
			sf::Vertex *quad = &tet[i * 4];
			quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
			quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
			quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
			quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));

			// Last block is placed to right
			if (i == quads - 1)
			{
				quad[0] = sf::Vector2f(_pos.x + _width, _pos.y + ((i - 2) * _height));
				quad[1] = sf::Vector2f(_pos.x + _width * 2, _pos.y + ((i - 2) * _height));
				quad[2] = sf::Vector2f(_pos.x + _width * 2, _pos.y + _height * (i - 1));
				quad[3] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (i - 1));
			}
		}
	}
	else if (block == Z)
	{
		// Create Z tetro
		quads = 4;
		tet.resize(quads * 4);
		tet.setPrimitiveType(sf::Quads);
		for (int i = 0; i < quads; i++)
		{
			sf::Vertex *quad = &tet[i * 4];
			// Gets pointer to current block 
			if (i <= 1)
			{
				std::cout << "1\n";
				quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
				quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
				quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
				quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));

			}
			// Last two blocks is placed to left
			if (i > 1)
			{
				std::cout << "2\n";
				quad[0] = sf::Vector2f(_pos.x - _width, _pos.y + ((i - 1) * _height));
				quad[1] = sf::Vector2f(_pos.x, _pos.y + ((i - 1) * _height));
				quad[2] = sf::Vector2f(_pos.x, _pos.y + _height * i);
				quad[3] = sf::Vector2f(_pos.x - _width, _pos.y + _height * i);
			}
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
