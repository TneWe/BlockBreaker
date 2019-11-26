#include<iostream>
#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Ball.h"
#include"Player.h"
int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;
	// Make a window that is 1024 by 768 pixels
	// And has the title "Pong"
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");

	int score = 0;
	int lives = 3;

	// create a bat
	Player bat(windowWidth / 2, windowHeight - 20);

	// create a ball
	Ball ball(windowWidth / 2, 1);
	return 0;


}