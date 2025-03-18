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

	// wrap around screen
	sf::Vector2f pos = shape.getPosition();
	float radius = shape.getRadius();
	if (pos.x < -radius) pos.x = 800.f + radius;
	if (pos.x > 800.f + radius) pos.x = -radius;
	if (pos.y < -radius) pos.y = 600.f + radius;
	if (pos.y > 600.f + radius) pos.y = -radius;
	shape.setPosition(pos);
}

void Asteroid::render(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::FloatRect Asteroid::getBounds() const
{
	return shape.getGlobalBounds();
}


