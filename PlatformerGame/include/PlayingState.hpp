#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include "GameState.hpp"
#include "Player.hpp"
#include "Asteroid.hpp"
#include "ScoreManager.hpp"
#include "ScoreDisplay.hpp"
#include <vector>

class PlayingState : public GameStateBase {
public:
	PlayingState(Game* game);
	void handleInput(sf::Event& event) override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;
    int getScore() const;

private:
    Player player;
    std::vector<std::unique_ptr<Asteroid>> asteroids;
    ScoreManager scoreManager;
    ScoreDisplay scoreDisplay;
    float spawnTimer = 0.f;
    float spawnInterval = 5.f;
};

#endif // !PLAYING_STATE_HPP
