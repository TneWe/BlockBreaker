#pragma once
#include"SFML/Graphics.hpp"
#include<string>
#include"Brick.h"
#include"Ball.h"
#include"Player.h"
#include<vector>
class Game
{
public:
	Game();
	~Game()=default;
	void run();
	void procesEvent();
	void update(sf::Time deltaTime);
	void draw();
	bool collision(sf::FloatRect f,sf::FloatRect s);
	void createBrick();
	void updateBrick();
	void createBall();
	void checklive();
private:
	sf::RenderWindow window;
	int lives{ 3 };
	sf::Text livetext;
	Player player;
	std::vector<Ball> balls;
	std::vector<Brick> bricks;

};


