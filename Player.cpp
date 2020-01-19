#include "Player.h"


Player::Player(std::string texturePath, sf::Vector2f size)
{
	playerTexture.loadFromFile(TEX "palica.png");
	if(!playerTexture.loadFromFile(TEX "palica.png"))
	{
		std::cout << "Error - No picture";
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(sf::Vector2f(300,650));
	playerSprite.setScale(sf::Vector2f(0.4, 0.25));
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
	return x();// -playerSprite.getGlobalBounds().width;
}


float Player::right()
{
	
	return x() + playerSprite.getGlobalBounds().width;
}

float Player::up()
{
	return y();// -playerSprite.getGlobalBounds().height;
}

float Player::down()
{
	return y()+playerSprite.getGlobalBounds().height;

}

sf::FloatRect Player::getPosition()
{
	return playerSprite.getGlobalBounds();
}






void Player::update()
{
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		playerSprite.move(-mSpeed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		playerSprite.move(mSpeed, 0.0f);
	}

	if(playerSprite.getPosition().x<0)//ogranièenje palice lijevo
	{
		playerSprite.setPosition(0, playerSprite.getPosition().y);
	}
	if (playerSprite.getPosition().x + playerSprite.getGlobalBounds().width> windowWidth)//ogranièenje palice desno
	{
		playerSprite.setPosition(windowWidth-playerSprite.getGlobalBounds().width, playerSprite.getPosition().y);
	}


}
