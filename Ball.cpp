#include "Ball.h"
Ball::Ball(float startX, float startY)
{
	ballShape.setPosition(startX,startY);
	ballShape.setRadius(ballRadius);
	ballShape.setFillColor(sf::Color::Cyan);
	ballShape.setOrigin(ballRadius, ballRadius);
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
	//return x()-ballShape.getRadius();
	return x() - ballShape.getPosition().x;
}

float Ball::right()
{
	//return x()+ ballShape.getRadius();
	return x() + ballShape.getPosition().x;

}

float Ball::up()
{
	//return y()-ballShape.getRadius();
	return y() - ballShape.getPosition().x;

}

float Ball::down()
{
	//return y()+ballShape.getRadius();
	return y() + ballShape.getPosition().x;

}

void Ball::draw(sf::RenderTarget& window)
{
	window.draw(ballShape);
}

/*lopta mora ostati unutar ekrana,dakle ako napusta ekran desno moramo staviti
horizontalni velocity na negativnu vrijednosta da ga vrati ulijevo i vice versa*/
void Ball::update()
{	
	ballShape.move(velocity);
	if (left() < 0) { velocity.x = ballVelocity; }
	
		
	
	else if (right() > windowWidth) { velocity.x = -ballVelocity; }
	
	
		
	if (up() < 0) { velocity.y = ballVelocity; }
	
		
	
	else if (down() > windowHeight) { velocity.y = -ballVelocity; }

	
	
}
