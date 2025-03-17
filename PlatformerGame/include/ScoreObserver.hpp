#ifndef SCORE_OBSERVER_HPP
#define SCORE_OBSERVER_HPP

class ScoreObserver {
public:
	virtual void onScoreChanged(int newScore) = 0;
	virtual ~ScoreObserver() = default;
};
#endif // !SCORE_OBSERVER_HPP
