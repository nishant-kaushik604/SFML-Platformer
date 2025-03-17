#include <Bullet.hpp>
#include <cmath>

Bullet::Bullet(float x, float y, float angle)
{
	shape.setSize(sf::Vector2f(2.f, 10.f));		// Thin Rectangle
	shape.setFillColor(sf::Color::Yellow);
	shape.setOrigin(1.f, 5.f);
	shape.setPosition(x, y);
	shape.setRotation(angle);
	float rad = angle * 3.14159f / 180.f;
	velocity.x = std::sin(rad) * speed;
	velocity.y = -1 * std::cos(rad) * speed;
}

void Bullet::update(float deltaTime)
{
	shape.move(velocity * deltaTime);
}

void Bullet::render(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::FloatRect Bullet::getBounds() const
{
	return shape.getGlobalBounds();
}

bool Bullet::isOffScreen(float windowWidth, float windowHeight) const
{
	sf::Vector2f pos = shape.getPosition();
	return pos.x < 0 || pos.x > windowWidth || pos.y < 0 || pos.y > windowHeight;
}


