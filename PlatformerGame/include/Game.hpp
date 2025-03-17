#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include <Player.hpp>
#include <Asteroid.hpp>
#include <AsteroidFactory.hpp>
#include "ScoreManager.hpp"
#include "ScoreDisplay.hpp"
#include <vector>

class Game {
public:
	Game();
	void run();

private:
	std::unique_ptr<sf::RenderWindow> window;
	Player player;
	std::vector<std::unique_ptr<Asteroid>> asteroids;
	ScoreManager scoreManager;
	ScoreDisplay scoreDisplay;
	void processEvents();
	void update(float deltaTime);
	void render();
};

#endif // !GAME_HPP
