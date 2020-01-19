#include<iostream>
#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Ball.h"
#include<vector>
#include"Brick.h"
#define spacing 4
#include<algorithm>
//#include"Game.h"

bool coll_paddle_ball(Ball& b, Player& p)
{
	if (b.getPosition().intersects(p.getPosition()))
	{
		return true;
	}
	return false;
}
void koli(Ball&b,Player &p)
{
	if (coll_paddle_ball(b, p))
	{
		b.velocity.y *= -1;
	}
}
bool coll_ball_brick(Ball& b, Brick br)
{
	if(b.getPosition().intersects(br.getPosition()))
	{
		return true;
	}
	return false;
}
void koli1(Ball& b, Brick& br)
{
	if (coll_ball_brick(b, br))
	{
		b.velocity.x *= -1;
		b.velocity.y *= -1;
		br.destroy = true;
	}
}  
void fillvec(std::vector<Brick>& grid) {
	Brick b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 19; j++) {
			float y = i * (spacing + b.height);
			float x = j * (spacing + b.width);
			grid.emplace_back(Brick(x, y));
		}
	}
}
int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Dobro Dosli");
	Ball ball{ 612,384 };
	Player palica("palica.png", sf::Vector2f(16.f, 16.f));
	//Game game;
	int score = 0;
	int lives = 3;
	
	
	std::vector<Brick> grid;
	fillvec(grid);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
			window.clear(sf::Color::Black);
			ball.update();
			palica.update();
			grid.erase(std::remove_if(begin(grid), end(grid), [](Brick& brick) {return brick.destroy == true; }),end(grid));
			for (Brick& brick : grid) {
				koli1(ball, brick);}
			palica.draw(window);
			ball.draw(window);
			for (Brick& brick : grid) {
				brick.draw(window);
			}
			koli(ball, palica);
			window.display();
	}

		return 0;
}