#include "Game.hpp"
#include "LandingState.hpp"
#include "PlayingState.hpp"
#include "GameOverState.hpp"

Game::Game()
{
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "Asteriods");
	window->setFramerateLimit(60);
	currentState = std::make_unique<LandingState>(this);
}

void Game::run() {
	sf::Clock clock;
	while (window->isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::setState(GameState newState)
{
	if (newState == GameState::Landing)
	{
		currentState = std::make_unique<LandingState>(this);
	}
	else if (newState == GameState::Playing) {
		currentState = std::make_unique<PlayingState>(this);
		finalScore = 0;
	}
	else if (newState == GameState::GameOver) {
		finalScore = dynamic_cast<PlayingState*>(currentState.get())->getScore();
		currentState = std::make_unique<GameOverState>(this, finalScore);
	}
}

void Game::processEvents() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
		currentState->handleInput(event);
	}
}

void Game::update(float deltaTime) {
	currentState->update(deltaTime);
}

void Game::render() {
	window->clear(sf::Color::Black);
	currentState->render(*window);
	window->display();
}
