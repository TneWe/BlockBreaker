#include<iostream>
#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Ball.h"
int main()
{
	 int windowWidth = 1024;
	 int windowHeight = 768;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Dobro Dosli");
	Ball ball{ 600,350 };
	Player palica ("palica.png",sf::Vector2f(16.f,16.f));
	int score = 0;
	int lives = 3;
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if(event.type==sf::Event::Closed)
			{
				window.close();
			}
		}
	}
	ball.update();
	palica.update ();
	ball.draw(window);
	palica.draw(window);
	
	return 0;


}