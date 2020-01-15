#include "Brick.h"

Brick::Brick(float startX, float startY)
{
	bricky.setPosition(startX, startY);
	bricky.setFillColor(sf::Color::White);
	bricky.setSize(sf::Vector2f(width, height));
	destroy == false;
}

void Brick::draw(sf::RenderWindow &window)
{
		window.draw(bricky);
}

float Brick::x()
{
	return bricky.getPosition().x;
}

float Brick::y()
{
	return	bricky.getPosition().y;
}

float Brick::left()
{
	return x()-3;
}

float Brick::right()
{
	return bricky.getPosition().x+ bricky.getSize().x +3;
}

float Brick::up()
{
	return y();
}

float Brick::down()
{
	return y()+ bricky.getSize().y;
}


