#include "PlayingState.hpp"
#include "Game.hpp"
#include "AsteroidFactory.hpp"

PlayingState::PlayingState(Game* gamePtr)
{
	this->game = gamePtr;
	asteroids = AsteroidFactory::createAsteroids(5, 800.f, 600.f);
	scoreManager.addObserver(&ui);
	ui.setLives(lives);
}

void PlayingState::handleInput(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	{
		game->setState(GameState::Landing);
	}
}

void PlayingState::update(float deltaTime)
{
	player.handleInput();
	player.update(deltaTime, 800, 600);
	for (auto& asteroid : asteroids)
	{
		asteroid->update(deltaTime);
	}

	spawnTimer += deltaTime;
	if (spawnTimer > spawnInterval)
	{
		asteroids.push_back(AsteroidFactory::createSingleAsteroid(800.f, 600.f));
		spawnTimer = 0.f;
	}

	// Collision: Player vs Asteroids
	sf::FloatRect playerBounds = player.getBounds();
	for (auto it = asteroids.begin(); it != asteroids.end();) {
		if (playerBounds.intersects((*it)->getBounds()))
		{
			lives--;
			ui.setLives(lives);
			resetPlayer();
			it = asteroids.erase(it);
			if (lives < 0) {
				game->setState(GameState::GameOver);
				return;
			}
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

void PlayingState::render(sf::RenderWindow& window)
{
	// Rendering will go here
	player.render(window);
	for (auto& asteroid : asteroids)
	{
		asteroid->render(window);
	}
	ui.render(window);
}

int PlayingState::getScore() const
{
	return scoreManager.getScore();
}

void PlayingState::resetPlayer()
{
	player = Player();
}


