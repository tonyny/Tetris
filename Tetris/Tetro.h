#pragma once
class Tetro : public sf::Drawable, public sf::Transformable
{
public:
	Tetro();
	enum Shape { I, J, L, O, S, T, Z };
	void update(sf::Time dt);
	void createTetro(Shape s);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void move(sf::Vector2f offset);
	void setPosition(Shape s, sf::Vector2f _pos = sf::Vector2f(300, 0));

	Shape _shape;
	int _width;
	int _height;
	bool _BOUNDLEFT;
	bool _BOUNDRIGHT;
	sf::VertexArray tet;
	sf::Vector2f _vel;
	float speed;
	int quads;
	bool movable;
	sf::Clock movementClock;
};

