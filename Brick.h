#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
#include"GameObject.h"
class Brick
{
private:
	sf::RectangleShape bricky;

public:
	int score{ 0 };
	Brick()=default;
	Brick(float startX, float startY);
	virtual ~Brick()=default;
	void draw(sf::RenderWindow& window) ;
	bool destroy;
	sf::FloatRect getPosition();
};