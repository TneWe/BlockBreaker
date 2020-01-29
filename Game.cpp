#include "Game.h"




Game::Game():window(sf::VideoMode(windowWidth, windowHeight), "Dobro Dosli")
{
	Player player();
	Ball b();
	Brick brick(0,0);
}

void Game::run()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		procesEvent();
		update(deltaTime);
		draw();
	}
}

void Game::procesEvent()
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	createBall();
	createBrick();
	player.update();	
	std::for_each(balls.begin(), balls.end(), [&](Ball ball) {ball.update(); });

	for (auto i : balls)
	{
		sf::FloatRect ballbounds{ i.getPosition() };
		for (auto it : bricks)
		{

			if (collision(it.getPosition(), ballbounds))
			{
				i.brickCollisionVelocity();
				updateBrick();
			}
		}
		if (collision(player.getPosition(), ballbounds))
		{
			i.paddleCollisionVelocity();
		}
	}
}

void Game::draw()
{
	window.clear(sf::Color::Black);
	for (Brick& brick : bricks) {
		brick.draw(window);
	}	
	std::for_each(balls.begin(), balls.end(), [&](Ball ball) {ball.draw(window); });
	player.draw(window);

	window.display();
}

bool Game::collision(sf::FloatRect f, sf::FloatRect s)
{
	return f.intersects(s);
}

void Game::createBrick()
{
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 19; j++) {
			float y = i * (spacing + brickHeight);
			float x = j * (spacing + brickWidth);
			bricks.emplace_back(Brick(x, y));
		}
	}
}

void Game::updateBrick()
{

	bricks.erase(std::remove_if(begin(bricks), end(bricks), [](Brick& brick) {return brick.destroy == true; }), end(bricks));

}

void Game::createBall()
{
	for (int i = 0; i <= 3; i++)
		balls.emplace_back(Ball());
}

void Game::checklive()
{
	balls.erase(std::remove_if(balls.begin(), balls.end(),[&](Ball ball)

		{
			if (ball.down()>player.y()+player.down())
			{
				return true;
				lives--;
			}
			return false;

		}

	), balls.end());
}


