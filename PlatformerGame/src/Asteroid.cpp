#include <Asteroid.hpp>
#include <cstdlib>	// For rand()

Asteroid::Asteroid(float x, float y, float size)
{
	shape.setRadius(size);
	shape.setFillColor(sf::Color::Blue);
	shape.setOrigin(size, size);
	shape.setPosition(x, y);
	velocity.x = (rand() % 200 - 100) * 1.f;	// Random -100 to 100
	velocity.y = (rand() % 200 - 100) * 1.f;
}

void Asteroid::update(float deltaTime)
{
	shape.move(velocity * deltaTime);
}

void Asteroid::render(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::FloatRect Asteroid::getBounds() const
{
	return shape.getGlobalBounds();
}


