#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SFML/Graphics.hpp>

class Asteroid {
public:
	Asteroid(float x, float y, float size);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
	sf::FloatRect getBounds() const;

private:
	sf::CircleShape shape;
	sf::Vector2f velocity;
};

#endif // !ASTEROID_HPP
