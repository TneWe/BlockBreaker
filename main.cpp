#include<iostream>
#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Ball.h"
#include<vector>
//#include"Game.h"


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
			
			//game.collision(ball, palica);
			

			window.display();
	}

		return 0;
}