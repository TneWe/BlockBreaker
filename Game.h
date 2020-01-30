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
	void draw(sf::RenderWindow &window);
	bool collision(sf::FloatRect f,sf::FloatRect s);
	void createBrick();
	void updateBrick();
	
private:
	sf::RenderWindow window;
	int lives{ 3 };
	sf::Font font;
	sf::Text livetext;
	Player player;
	Ball ball;
	std::vector<Brick> bricks;
	sf::Clock clock;
};


