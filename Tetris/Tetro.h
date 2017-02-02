#pragma once
class Tetro : public sf::Drawable
{
public:
	Tetro();
	enum Shape { I, J, L, O, S, T, Z };
	void update();
	void createTet(Shape s);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

	int _width;
	int _height;
	sf::Vector2f _pos;
	sf::VertexArray tet;
	int quads;
};

