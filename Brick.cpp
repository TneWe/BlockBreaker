#include "Brick.h"



Brick::Brick(float startX, float startY)
{
	bricky.setPosition(startX, startY);
	bricky.setFillColor(sf::Color::Green);
	bricky.setOutlineColor(sf::Color::Green);
	bricky.setSize(sf::Vector2f(brickWidth, brickHeight));
	destroy = false;
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(bricky);
}




sf::FloatRect Brick::getPosition()
{
	return bricky.getGlobalBounds();
}


