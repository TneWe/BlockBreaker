#pragma once
#include"SFML/Graphics.hpp"
class Ball
{
private:
	sf::Vector2f velocity {-ballVelocity,ballVelocity};

	sf::CircleShape ballShape;//lopta

	float ballVelocity = 1.f;//brzina
	float ballRadius = 10.f;//radijus
	 int windowWidth = 1024;
	 int windowHeight = 768;
	float x();//funkcije za pozicioniranje
	float y();		//funkcije za pozicioniranje
	float left();	//funkcije za pozicioniranje 
	float right();	//funkcije za pozicioniranje
	float up();		//funkcije za pozicioniranje
	float down();	//funkcije za pozicioniranje
public:
	Ball(float startX, float startY);//konstruktor inicijalizira loptu na ekran
	void draw(sf::RenderTarget& window);
	

	void update();
};

