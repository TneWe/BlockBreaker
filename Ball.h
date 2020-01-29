#pragma once
#include"SFML/Graphics.hpp"
#include"Player.h"
#include"GameObject.h"
class Ball
{
private:

	sf::CircleShape ballShape;//loptica
	float startX{ windowWidth / 2.f };
	float startY{ windowHeight / 2.f };
public:
	sf::Vector2f velocity;
	float ballVelocity = 0.5f;//brzina
	/*const*/ float ballRadius = 10.f;//radijus
	Ball();//konstruktor inicijalizira loptu na ekran
	void draw(sf::RenderWindow& window) ;
	void update() ;
	float x();//funkcije za pozicioniranje
	float y();		//funkcije za pozicioniranje
	float left();	//funkcije za pozicioniranje 
	float right();	//funkcije za pozicioniranje
	float up();		//funkcije za pozicioniranje
	float down();	//funkcije za pozicioniranje
	sf::FloatRect getPosition();
	sf::CircleShape getShape();
	void paddleCollisionVelocity();
	void brickCollisionVelocity();
};