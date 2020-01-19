#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
class Brick
{
private:
	sf::RectangleShape bricky;

public:
	 float height{ 20.f };
	 float	width{ 50.f };
	Brick()=default;
	Brick(float startX, float startY);
	void draw(sf::RenderWindow& window);
	float x();
	float y();
	float left();
	float right();
	float up();
	float down();
	bool destroy;
	sf::FloatRect getPosition();
};