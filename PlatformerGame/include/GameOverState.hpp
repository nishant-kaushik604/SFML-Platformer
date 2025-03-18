#ifndef GAME_OVER_STATE_HPP
#define GAME_OVER_STATE_HPP

#include "GameState.hpp"
#include "ScoreManager.hpp"

class GameOverState : public GameStateBase {
public:
    GameOverState(Game* game, int finalScore);
    void handleInput(sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Text text;
    sf::Font font;
};
#endif // !GAME_OVER_STATE_HPP
