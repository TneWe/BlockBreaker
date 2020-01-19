#include "Ball.h"
Ball::Ball(float startX, float startY)
{
	ballShape.setPosition(startX, startY);
	ballShape.setRadius(ballRadius);
	ballShape.setFillColor(sf::Color::Cyan);
	ballShape.setOrigin(ballRadius, ballRadius);
	ballShape.setOutlineThickness(2);
	ballShape.setOutlineColor(sf::Color::Magenta);
	velocity.x = -ballVelocity;
	velocity.y = -ballVelocity;
}

float Ball::x()
{
	return ballShape.getPosition().x;
}

float Ball::y()
{
	return ballShape.getPosition().y;
}

float Ball::left()
{
	return x() - ballShape.getRadius();
}

float Ball::right()
{
	return x() + ballShape.getRadius();

}

float Ball::up()
{
	return y() - ballShape.getRadius();

}

float Ball::down()
{
	return y() + ballShape.getRadius();

}

sf::FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}




void Ball::draw(sf::RenderTarget& window)
{
	window.draw(ballShape);
}

/*lopta mora ostati unutar ekrana,dakle ako napusta ekran desno moramo staviti
horizontalni velocity na negativnu vrijednosta da ga vrati ulijevo i vice versa*/
void Ball::update()
{
	sf::Vector2f pos = ballShape.getPosition();
	pos += velocity;
	ballShape.setPosition(pos);
	if (left() <= 0 || right() >= windowWidth)
		velocity.x *= -1;
	if (up() <= 0 || down() >= windowHeight)
		velocity.y *= -1;
	
	

}