#ifndef SCORE_MANAGER_HPP
#define SCORE_MANAGER_HPP

#include "ScoreObserver.hpp"
#include <vector>

class ScoreManager {
public:
	void addObserver(ScoreObserver* observer);
	void increaseScore(int points);
	int getScore() const;

private:
	int score = 0;
	std::vector<ScoreObserver*> observers;
	void notifyObservers();
};

#endif // !SCORE_MANAGER_HPP
