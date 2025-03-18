#ifndef LANDING_STATE_HPP
#define LANDING_STATE_HPP

#include "GameState.hpp"

class LandingState : public GameStateBase {
public:
	LandingState(Game* game);
	void handleInput(sf::Event& event) override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::Text text;
	sf::Font font;
};

#endif // !LANDING_STATE_HPP
