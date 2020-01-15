#pragma once
#include"SFML/Graphics.hpp"
#include<string>
#include<iostream>
#define TEX "\images\\"
class Player
{
	int windowWidth=1024;
	int windowHeight = 768;
	float mSpeed = 0.5f;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
public:
	Player(std::string texturePath,sf::Vector2f size);
	~Player();
	void draw(sf::RenderTarget& window);
	void update();
	//funkcije za pozicioniranje(graniènici)
	float x();
	float y();
	float left();	 
	float right();	
	float up();
	float down();

};

