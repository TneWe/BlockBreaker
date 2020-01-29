#include<iostream>
#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Ball.h"
#include<vector>
#include"Brick.h"
#define spacing 4
#include<algorithm>
#include"Game.h"


int main()
{
	Game app;
	app.run();
	/*sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Dobro Dosli");
	Ball ball;
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
		grid.erase(std::remove_if(begin(grid), end(grid), [](Brick& brick) {return brick.destroy == true; }), end(grid));
		for (Brick& brick : grid) {
			koli1(ball, brick);
		}
		palica.draw(window);
		ball.draw(window);
		for (Brick& brick : grid) {
			brick.draw(window);
		}
		koli(ball, palica);
		window.display();*/
	


	return 0;
}
