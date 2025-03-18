#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameState.hpp"

enum class GameState {
	Landing,
	Playing,
	GameOver
};


class Game {
public:
	Game();
	void run();
	void setState(GameState newState);

private:
	std::unique_ptr<sf::RenderWindow> window;
	std::unique_ptr<GameStateBase> currentState;
	int finalScore = 0;

	void processEvents();
	void update(float deltaTime);
	void render();
};

#endif // !GAME_HPP
