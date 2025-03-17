#ifndef ASTEROID_FACTORY_HPP
#define ASTEROID_FACTORY_HPP

#include "Asteroid.hpp"
#include <vector>
#include <memory>

class AsteroidFactory {
public:
	static std::vector<std::unique_ptr<Asteroid>> createAsteroids(int count, float windowWidth, float windowHeight);
};

#endif // !ASTEROID_FACTORY_HPP
