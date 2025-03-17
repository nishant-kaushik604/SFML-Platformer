#include "Game.hpp"

Game::Game()
{
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "Asteriods");
	window->setFramerateLimit(60);
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

void Game::processEvents() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

void Game::update(float deltaTime) {
	player.handleInput();
	player.update(deltaTime);
}

void Game::render() {
	window->clear(sf::Color::Black);

	// Rendering will go here
	player.render(*window);

	window->display();
}
