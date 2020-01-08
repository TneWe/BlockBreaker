#pragma once
#include"SFML/Graphics.hpp"
#include"Player.h"
class Ball
{
private:
	sf::Vector2f velocity {--ballVelocity,--ballVelocity};

	sf::CircleShape ballShape;//loptica

	 int windowWidth = 1024;
	 int windowHeight = 768;
public:
	float ballVelocity = 1.f;//brzina
	float ballRadius = 10.f;//radijus
	Ball(float startX, float startY);//konstruktor inicijalizira loptu na ekran
	void draw(sf::RenderTarget& window);
	void update();
	float x();//funkcije za pozicioniranje
	float y();		//funkcije za pozicioniranje
	float left();	//funkcije za pozicioniranje 
	float right();	//funkcije za pozicioniranje
	float up();		//funkcije za pozicioniranje
	float down();	//funkcije za pozicioniranje
	sf::Vector2f getvelocity();
};

