#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <Bullet.hpp>

class Player {
public:
	Player();
	void update(float deltaTime, float windowWidth, float windowHeight);
	void render(sf::RenderWindow& window);
	void handleInput();
	sf::FloatRect getBounds() const;	// For collision
	const std::vector<std::unique_ptr<Bullet>>& getBullets() const;		// Access bullets

private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speed = 300.f;
	float rotationSpeed = 200.f;
	std::vector<std::unique_ptr<Bullet>> bullets;	// Store bullets
	float shootCooldown = 0.2f;
	float timeSinceLastShot = 0.f;
};

#endif // !PLAYER_HPP
