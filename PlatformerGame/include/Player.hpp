#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
	Player();
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
	void handleInput();

private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speed = 300.f;
	float rotationSpeed = 200.f;
};

#endif // !PLAYER_HPP
