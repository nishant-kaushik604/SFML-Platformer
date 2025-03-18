#ifndef PLAYING_UI_HPP
#define PLAYING_UI_HPP

#include <SFML/Graphics.hpp>
#include "ScoreObserver.hpp"

class PlayingUI : public ScoreObserver {
public:
	PlayingUI();
	void setLives(int lives);
	void onScoreChanged(int newScore) override;
	void render(sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text livesText;
	sf::Text scoreText;
	void initUI();
	void setTextProperty(sf::Text& text, const sf::String& str, int size, const sf::Color color);
};
#endif // !GAME_UI_HPP
