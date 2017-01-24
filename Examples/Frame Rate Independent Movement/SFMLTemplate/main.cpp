#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	sf::Texture texture;

	if (!texture.loadFromFile("Crash.png"))
	{
		// handle error
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	//window.setFramerateLimit(45);

	sf::Clock _clock;

	float newTime, frameTime, interpolation;

	float currentTime = _clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	const float dt = 1.0f / 5;

	while (window.isOpen())
	{
		sf::Event event;

		newTime = _clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		
		sprite.setPosition(sprite.getPosition().x + (0.1 * interpolation), sprite.getPosition().y);


		window.clear();

		window.draw(sprite);

		window.display();
	}
}