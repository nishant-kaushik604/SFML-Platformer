#include "ScoreManager.hpp"

void ScoreManager::addObserver(ScoreObserver* observer)
{
	observers.push_back(observer);
}

void ScoreManager::increaseScore(int points)
{
	score + points;
	notifyObservers();
}

int ScoreManager::getScore() const
{
	return score;
}

void ScoreManager::notifyObservers()
{
	for (auto* observer : observers) {
		observer->onScoreChanged(score);
	}
}
