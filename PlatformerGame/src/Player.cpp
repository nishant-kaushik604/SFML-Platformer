#include "Player.hpp"
#include <iostream>

//Player::Player() {
//	if (!texture.loadFromFile("assets/ship.png")) {
//		std::cout << "Texture failed to load, using fallback\n"; // Debug output
//		// Fallback if asset missing
//		sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
//		sprite.setColor(sf::Color::White);
//	}
//	else {
//		sprite.setTexture(texture);
//	}
//
//	sprite.setOrigin(25.f, 25.f);		// Center of sprite
//	sprite.setPosition(400.f, 300.f);	// Screen center
//}

Player::Player() {
	sprite.setTextureRect(sf::IntRect(0, 0, 50, 50)); // 50x50 square
	sprite.setColor(sf::Color::Red); // Red for visibility
	sprite.setOrigin(25.f, 25.f);
	sprite.setPosition(400.f, 300.f);
}

void Player::update(float deltaTime)
{
	// Movement logic will use deltaTime
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sprite.rotate(-rotationSpeed * 0.016f); // Approx deltaTime for 60 FPS
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sprite.rotate(rotationSpeed * 0.016f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		float angle = sprite.getRotation() * 3.14159f / 180.f;
		sprite.move(std::cos(angle) * speed * 0.016f, std::sin(angle) * speed * 0.016f);
	}
}



