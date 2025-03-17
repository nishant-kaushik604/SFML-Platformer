#include "ScoreDisplay.hpp"

ScoreDisplay::ScoreDisplay()
{
	if (!font.loadFromFile("assets/arial/arial.ttf")) {
		// No fallback
	}

	text.setFont(font);
	text.setString("Score: 0");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(10.f, 10.f);
}

void ScoreDisplay::render(sf::RenderWindow& window)
{
	window.draw(text);
}

void ScoreDisplay::onScoreChanged(int newScore)
{
	text.setString("Score: " + std::to_string(newScore));
}
