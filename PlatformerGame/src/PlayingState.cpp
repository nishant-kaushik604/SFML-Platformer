#include "PlayingState.hpp"
#include "Game.hpp"
#include "AsteroidFactory.hpp"

PlayingState::PlayingState(Game* gamePtr)
{
	this->game = gamePtr;
	asteroids = AsteroidFactory::createAsteroids(5, 800.f, 600.f);
	scoreManager.addObserver(&scoreDisplay);
}

void PlayingState::handleInput(sf::Event& event)
{
	
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
			game->setState(GameState::GameOver);
			return;
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
	scoreDisplay.render(window);
}

int PlayingState::getScore() const
{
	return scoreManager.getScore();
}


