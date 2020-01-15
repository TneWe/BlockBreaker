#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
class Brick
{
private:
	sf::RectangleShape bricky;

public:
	const float height{ 20.f };
	const float	width{ 50.f };
	Brick();
	Brick(float startX, float startY);
	void draw(sf::RenderWindow& window);
	float x();
	float y();
	float left();
	float right();
	float up();
	float down();
	bool destroy;
};

