#pragma once
class Tetro : public sf::Drawable
{
public:
	Tetro();
	void update();
	void createTet();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

	int _width;
	int _height;
	sf::Vector2f _pos;
	sf::VertexArray tet;
};

