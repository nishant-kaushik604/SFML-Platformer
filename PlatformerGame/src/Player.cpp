#include "Player.hpp"
#include <iostream>

Player::Player() {
	if (!texture.loadFromFile("assets/ship.png")) {
		// Fallback if asset missing
		texture.create(50, 50);
		sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
		sprite.setColor(sf::Color::White);
	}
	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);		// Center of sprite
	sprite.setPosition(400.f, 300.f);	// Screen center
}

//Player::Player() {
//	sprite.setSize(sf::Vector2f(50.f, 50.f));
//	sprite.setFillColor(sf::Color::White);
//	sprite.setOrigin(25.f, 25.f);
//	sprite.setPosition(400.f, 300.f);
//}
void Player::update(float deltaTime, float windowWidth, float windowHeight)
{
	timeSinceLastShot += deltaTime;

	for (auto it = bullets.begin(); it != bullets.end();)
	{
		(*it)->update(deltaTime);
		if ((*it)->isOffScreen(windowWidth, windowHeight)) {
			it = bullets.erase(it);		// Remove off screen bullets
		}
		else
		{
			++it;
		}
	}

	// Clamp position to screen bounds
	sf::Vector2f pos = sprite.getPosition();
	float halfWidth = texture.getSize().x / 2.f;
	float halfHeight = texture.getSize().y / 2.f;
	pos.x = std::max(halfWidth, std::min(windowWidth - halfWidth, pos.x));
	pos.y = std::max(halfHeight, std::min(windowHeight - halfHeight, pos.y));
	sprite.setPosition(pos);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(sprite);
	for (const auto& bullet : bullets) {
		bullet->render(window);
	}
}

void Player::handleInput()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sprite.rotate(-rotationSpeed * 0.016f); // Approx deltaTime for 60 FPS
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sprite.rotate(rotationSpeed * 0.016f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		float angle = sprite.getRotation() * 3.14159f / 180.f;
		sprite.move(std::sin(angle) * speed * 0.016f, -1 * std::cos(angle) * speed * 0.016f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeSinceLastShot >= shootCooldown)
	{
		bullets.push_back(std::make_unique<Bullet>(sprite.getPosition().x, sprite.getPosition().y, sprite.getRotation()));
		timeSinceLastShot = 0.f;
	}
}

sf::FloatRect Player::getBounds() const
{
	return sprite.getGlobalBounds();
}

const std::vector<std::unique_ptr<Bullet>>& Player::getBullets() const
{
	return bullets;
}



