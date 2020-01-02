#pragma once
#include"SFML/Graphics.hpp"
#include<string>
#include<iostream>
//#define windowWidth 1024
//#define windowHeight 768
#define TEX "externals\SFML\lib\images\\"
class Player
{
	int windowWidth=1024;
	int windowHeight = 768;
	float mSpeed = 0.3f;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	//funkcije za pozicioniranje(graniènici)
	float x();
	float y();
	float left();	 
	float right();	
public:
	Player(std::string texturePath,sf::Vector2f size);
	~Player();
	void draw(sf::RenderTarget& window);
	void update(/*sf::Sprite &playerTexture*/);

};

