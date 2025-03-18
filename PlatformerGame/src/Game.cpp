#include "Game.hpp"

Game::Game()
{
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "Asteriods");
	window->setFramerateLimit(60);
	asteroids = AsteroidFactory::createAsteroids(5, 800.f, 600.f);
	scoreManager.addObserver(&scoreDisplay);
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
	player.update(deltaTime, 800, 600);

	for (auto& asteroid : asteroids)
	{
		asteroid->update(deltaTime);
	}

	// Collision: Player vs Asteroids
	sf::FloatRect playerBounds = player.getBounds();
	for (auto it = asteroids.begin(); it != asteroids.end();) {
		if (playerBounds.intersects((*it)->getBounds()))
		{
			window->close();
			break;
		}
		else
		{
			++it;
		}
	}

	// Collision: Bullets vs Asteroids
	const auto& bullets = player.getBullets();
	for (auto bulletIt = bullets.begin(); bulletIt != bullets.end(); ++bulletIt) {
		for (auto asteroidIt = asteroids.begin(); asteroidIt != asteroids.end();) {
			if ((*bulletIt)->getBounds().intersects((*asteroidIt)->getBounds()))
			{
				asteroidIt = asteroids.erase(asteroidIt);
				scoreManager.increaseScore(10);
			}
			else
			{
				++asteroidIt;
			}
		}
	}
}

void Game::render() {
	window->clear(sf::Color::Black);

	// Rendering will go here
	player.render(*window);
	for (auto& asteroid : asteroids)
	{
		asteroid->render(*window);
	}
	scoreDisplay.render(*window);

	window->display();
}
