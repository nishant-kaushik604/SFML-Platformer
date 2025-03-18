#include "LandingState.hpp"
#include "Game.hpp"

LandingState::LandingState(Game* gamePtr)
{
	this->game = gamePtr;
	if(!font.loadFromFile("assets/arial/arial.ttf")){}
	text.setFont(font);
	text.setString("Press Enter to Start");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(280.f, 280.f);
}

void LandingState::handleInput(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
	{
		game->setState(GameState::Playing);
	}
}

void LandingState::update(float deltaTime)
{
}

void LandingState::render(sf::RenderWindow& window)
{
	window.draw(text);
}
