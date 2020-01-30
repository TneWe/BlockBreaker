#include "Game.h"




Game::Game():window(sf::VideoMode(windowWidth, windowHeight), "Dobro Dosli")
{
	
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen())
	{
		procesEvent();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > (sf::seconds(1.f / 60.f)))
		{
			timeSinceLastUpdate -= (sf::seconds(1.f / 60.f));
			procesEvent();
			update(sf::seconds(1.f / 60.f));
		draw(window);
		}	
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

	window.clear(sf::Color::Black);

	//createBall();
	createBrick();
	player.update();	
	//std::for_each(balls.begin(), balls.end(), [&](Ball ball) {ball.update(); });
	ball.update();
	if (collision(ball.getPosition(), player.getPosition()))
	{
		ball.paddleCollisionVelocity();
	}
	for (auto it : bricks)
	{
		if (collision(ball.getPosition(), it.getPosition()))
		{
			updateBrick();
			ball.brickCollisionVelocity();
		}

	}

		/*sf::FloatRect ballbounds{ i.getPosition() };
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
		}*/
	
}

void Game::draw(sf::RenderWindow &window)
{
	window.clear(sf::Color::Black);
	for (Brick& brick : bricks) {
		brick.draw(window);
	}	
	//std::for_each(balls.begin(), balls.end(), [&](Ball ball) {ball.draw(window); });
	player.draw(window);
	ball.draw(window);
	window.display();
}

bool Game::collision(sf::FloatRect f, sf::FloatRect s)
{
	if (f.intersects(s))
	{
		return true;
	}
	return false;
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



/*void Game::checklive()
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
}*/


