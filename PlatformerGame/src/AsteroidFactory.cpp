#include <AsteroidFactory.hpp>
#include <cstdlib>

std::vector<std::unique_ptr<Asteroid>> AsteroidFactory::createAsteroids(int count, float windowWidth, float windowHeight)
{
	std::vector<std::unique_ptr<Asteroid>> asteroids;
	for (int i = 0; i < count; i++)
	{
		float x = static_cast<float>(rand() % static_cast<int>(windowWidth));
		float y = static_cast<float>(rand() % static_cast<int>(windowHeight));

		float size = 20.f + (rand() % 20);
		asteroids.push_back(std::make_unique<Asteroid>(x, y, size));
	}

	return asteroids;
}
