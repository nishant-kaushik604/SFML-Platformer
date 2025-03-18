#include "GameOverState.hpp"
#include "Game.hpp"

GameOverState::GameOverState(Game* game, int finalScore)
{
    this->game = game;
    if (!font.loadFromFile("assets/arial/arial.ttf")) {}
    text.setFont(font);
    text.setString("Game Over\nScore: " + std::to_string(finalScore) + "\nPress R to Restart");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(250.f, 250.f);
}

void GameOverState::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
        game->setState(GameState::Playing);
    }
}

void GameOverState::update(float deltaTime)
{
}

void GameOverState::render(sf::RenderWindow& window)
{
    window.draw(text);
}
