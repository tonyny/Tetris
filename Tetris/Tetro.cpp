#include "stdafx.h"
#include "Tetro.h"


Tetro::Tetro()
{
	// Initialise values
	_width = 50;
	_height = 50;
	_BOUNDLEFT = 50;
	_BOUNDRIGHT = 600;
	_vel = sf::Vector2f(0, 0);
	speed = 50;
	movementClock.restart();
	_BOUNDLEFT = false;
	_BOUNDRIGHT = false;
	movable = true;
	textureSize = sf::Vector2f(96, 96);

	// Load tileset
	if (texture.loadFromFile("tileSet.png"))
		std::cout << "tileset loaded successfully\n";
}

void Tetro::setPosition(Shape block, sf::Vector2f _pos)
{
	_shape = block;
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

			quad[0].texCoords = sf::Vector2f(textureSize.x * 0, 0);
			quad[1].texCoords = sf::Vector2f(textureSize.x * 1, 0);
			quad[2].texCoords = sf::Vector2f(textureSize.x * 1, textureSize.y);
			quad[3].texCoords = sf::Vector2f(0, textureSize.y);
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

			quad[0].texCoords = sf::Vector2f(textureSize.x * 1, 0);
			quad[1].texCoords = sf::Vector2f(textureSize.x * 2, 0);
			quad[2].texCoords = sf::Vector2f(textureSize.x * 2, textureSize.y);
			quad[3].texCoords = sf::Vector2f(textureSize.x * 1, textureSize.y);
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

			quad[0].texCoords = sf::Vector2f(textureSize.x * 2, 0);
			quad[1].texCoords = sf::Vector2f(textureSize.x * 3, 0);
			quad[2].texCoords = sf::Vector2f(textureSize.x * 3, textureSize.y);
			quad[3].texCoords = sf::Vector2f(textureSize.x * 2, textureSize.y);
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

			quad[0].texCoords = sf::Vector2f(textureSize.x * 3, 0);
			quad[1].texCoords = sf::Vector2f(textureSize.x * 4, 0);
			quad[2].texCoords = sf::Vector2f(textureSize.x * 4, textureSize.y);
			quad[3].texCoords = sf::Vector2f(textureSize.x * 3, textureSize.y);
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
				quad[0] = sf::Vector2f(_pos.x + _width, _pos.y + ((i - 2) * _height));
				quad[1] = sf::Vector2f(_pos.x + _width * 2, _pos.y + ((i - 2) * _height));
				quad[2] = sf::Vector2f(_pos.x + _width * 2, _pos.y + _height * (1 + (i - 2)));
				quad[3] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + (i - 2)));
			}

			quad[0].texCoords = sf::Vector2f(textureSize.x * 4, 0);
			quad[1].texCoords = sf::Vector2f(textureSize.x * 5, 0);
			quad[2].texCoords = sf::Vector2f(textureSize.x * 5, textureSize.y);
			quad[3].texCoords = sf::Vector2f(textureSize.x * 4, textureSize.y);
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

			quad[0].texCoords = sf::Vector2f(textureSize.x * 5, 0);
			quad[1].texCoords = sf::Vector2f(textureSize.x * 6, 0);
			quad[2].texCoords = sf::Vector2f(textureSize.x * 6, textureSize.y);
			quad[3].texCoords = sf::Vector2f(textureSize.x * 5, textureSize.y);
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
				quad[0] = sf::Vector2f(_pos.x, _pos.y + (i * _height));
				quad[1] = sf::Vector2f(_pos.x + _width, _pos.y + (i * _height));
				quad[2] = sf::Vector2f(_pos.x + _width, _pos.y + _height * (1 + i));
				quad[3] = sf::Vector2f(_pos.x, _pos.y + _height * (1 + i));

			}
			// Last two blocks is placed to left
			if (i > 1)
			{
				quad[0] = sf::Vector2f(_pos.x - _width, _pos.y + ((i - 1) * _height));
				quad[1] = sf::Vector2f(_pos.x, _pos.y + ((i - 1) * _height));
				quad[2] = sf::Vector2f(_pos.x, _pos.y + _height * i);
				quad[3] = sf::Vector2f(_pos.x - _width, _pos.y + _height * i);
			}

			quad[0].texCoords = sf::Vector2f(textureSize.x * 6, 0);
			quad[1].texCoords = sf::Vector2f(textureSize.x * 7, 0);
			quad[2].texCoords = sf::Vector2f(textureSize.x * 7, textureSize.y);
			quad[3].texCoords = sf::Vector2f(textureSize.x * 6, textureSize.y);
		}
	}
}

void Tetro::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &texture;
	target.draw(tet, states);
}

void Tetro::update(sf::Time dt)
{
	// Movement
	_vel = sf::Vector2f(0, 0);
	sf::Event e;
	if (movementClock.getElapsedTime().asSeconds() > 0.1f)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			_vel.y = -speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (tet.getBounds().left <= 50)
			{
				movable = false;
				_BOUNDLEFT = true;
			}
			if (_BOUNDRIGHT)
			{
				_BOUNDRIGHT = false;
				movable = true;
			}
			_vel.x = -speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			_vel.y = speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (tet.getBounds().left + tet.getBounds().width >= 650)
			{
				movable = false;
				_BOUNDRIGHT = true;
			}
			if (_BOUNDLEFT)
			{
				_BOUNDLEFT = false;
				movable = true;
			}
			_vel.x = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			std::cout << "POS: (" << tet[0].position.x << "," << tet[0].position.y << ")\n";

		// Can only move if within boundary -> determine by boolean movable
		if (movable)
			move(_vel);
		movementClock.restart();
	}
}

void Tetro::move(sf::Vector2f offset)
{
	// Move every vertex
	for (int i = 0; i < tet.getVertexCount(); i++)
	{
		tet[i].position = tet[i].position + offset;
	}
}

void Tetro::createTetro(Shape s)
{
	setPosition(s);
}