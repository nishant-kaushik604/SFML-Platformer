#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <Player.hpp>

class Game {
public:
	Game();
	void run();

private:
	std::unique_ptr<sf::RenderWindow> window;
	Player player;
	sf::RectangleShape testShape; // Add this
	void processEvents();
	void update(float deltaTime);
	void render();
};

#endif // !GAME_HPP
