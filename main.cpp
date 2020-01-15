#include<iostream>
#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Ball.h"
#include<vector>
#include"Brick.h"
//#include"Game.h"
bool coll_paddle_ball(Ball& b, Player& p)
{
	if (b.right() >= p.left() ||b.left() >= p.right() || b.up() >= p.down() || b.down() >= p.up())
	{
		return true;
	}
	return false;
}
void koli(Ball&b,Player &p)
{
	if (coll_paddle_ball(b, p))
	{
		b.velocity.x *= 1;
		b.velocity.y *= 1;
	}
}

void fillvec(std::vector<Brick>& grid) {
	Brick b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			float y = i * (3 + b.height);
			float x = j * (3 + b.width);
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
	/*for (int i = 0; i < 10; i++)
	{
		for(int y=0;y<8;y++)
		{
			bricks.emplace_back((i + 1) * (60 + 3) + 22, (y + 2) * (20 + 3));
		}
	}*/
	
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