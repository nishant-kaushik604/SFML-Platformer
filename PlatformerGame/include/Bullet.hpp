#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet {
public:
	Bullet(float x, float y, float angle);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
	sf::FloatRect getBounds() const;
	bool isOffScreen(float windowWidth, float windowHeight) const;

private:
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	float speed = 500.f;
};

#endif // !BULLET_HPP
