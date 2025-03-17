#ifndef SCORE_DISPLAY_HPP
#define SCORE_DISPLAY_HPP

#include "ScoreObserver.hpp"
#include <SFML/Graphics.hpp>

class ScoreDisplay : public ScoreObserver {
public:
	ScoreDisplay();
	void render(sf::RenderWindow& window);
	void onScoreChanged(int newScore) override;

private:
	sf::Font font;
	sf::Text text;
};
#endif // !SCORE_DISPLAY_HPP
