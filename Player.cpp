#include "Player.h"


Player::Player(std::string texturePath, sf::Vector2f size)
{
	playerTexture.loadFromFile(TEX "palica.png");
	if(!playerTexture.loadFromFile(TEX "palica.png"))
	{
		std::cout << "Error - No picture";
	}
	playerSprite.setTexture(playerTexture);
	

}

Player::~Player()
{
	
}

void Player::draw(sf::RenderTarget& window)
{
	window.draw(playerSprite);
}

float Player::x()
{
	return playerSprite.getPosition().x;
}

float Player::y()
{
	return playerSprite.getPosition().y;
}

float Player::left()
{
	return x()-playerSprite.getPosition().y;
}






float Player::right()
{
	
	
		return x() + playerSprite.getPosition().x;
	
}

void Player::update(/*sf::Sprite& playerTexture*/)
{
	
	/*if (left() < 0)
	{
		velocity.x = mSpeed;
	}
	else if (right() > windowWidth)
	{
		velocity.x = -mSpeed;
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		playerSprite.move(-mSpeed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		playerSprite.move(mSpeed, 0.0f);
	}

}
