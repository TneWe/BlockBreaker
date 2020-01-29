#pragma once
#include"SFML/Graphics.hpp"
#include<string>
#include<iostream>
#define TEX "\images\\"
#include"GameObject.h"

class Player
{

	float mSpeed = 0.5f;
	sf::Texture playerTexture;
public:

	sf::Sprite playerSprite;
	Player();
	Player(std::string texturePath,sf::Vector2f size);
	~Player()=default;
	void draw(sf::RenderWindow& window) ;
	void update() ;
	//funkcije za pozicioniranje(graniènici)
	float x();
	float y();
	float left();	 
	float right();	
	float up();
	float down();
	sf::FloatRect getPosition();
	
};

