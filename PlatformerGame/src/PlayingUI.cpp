#include "PlayingUI.hpp"
#include <iostream>

PlayingUI::PlayingUI()
{
	initUI();
}

void PlayingUI::setLives(int lives)
{
	livesText.setString("Lives: " + std::to_string(lives));
}

void PlayingUI::onScoreChanged(int newScore)
{
	scoreText.setString("Score: " + std::to_string(newScore));
}

void PlayingUI::render(sf::RenderWindow& window)
{
	window.draw(livesText);
	window.draw(scoreText);
}

void PlayingUI::initUI()
{
	if (!font.loadFromFile("assets/arial/arial.ttf")){
		// No Fallback
		std::cout << "PlayingUI: font not found";
	}

	setTextProperty(livesText, "Lives: 3", 24, sf::Color::White);
	livesText.setPosition(10.f, 40.f);

	setTextProperty(scoreText, "Score: 0", 24, sf::Color::White);
	scoreText.setPosition(10.f, 10.f);
}

void PlayingUI::setTextProperty(sf::Text& text,const sf::String& str, int size, const sf::Color color)
{
	text.setFont(font);
	livesText.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
}


