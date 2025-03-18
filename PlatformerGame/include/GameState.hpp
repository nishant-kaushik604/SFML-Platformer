#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Game;			// Forward Declaration

class GameStateBase {
public:
	virtual ~GameStateBase() = default;
	virtual void handleInput(sf::Event& event) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

protected:
	Game* game;
};
#endif // !GAME_STATE_HPP
