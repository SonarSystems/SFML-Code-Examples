#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	sf::Texture texture;

	if (!texture.loadFromFile("Red.png"))
	{
		// handle error
	}

	sf::Texture texture2;

	if (!texture2.loadFromFile("Yellow.png"))
	{
		// handle error
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sprite.getPosition().x + 300, sprite.getPosition().y + 300);


	sf::Sprite sprite2;
	sprite2.setTexture(texture2);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite2.setPosition(sprite2.getPosition().x - 0.1, sprite2.getPosition().y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite2.setPosition(sprite2.getPosition().x + 0.1, sprite2.getPosition().y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sprite2.setPosition(sprite2.getPosition().x, sprite2.getPosition().y - 0.1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sprite2.setPosition(sprite2.getPosition().x, sprite2.getPosition().y + 0.1);
		}

		sf::FloatRect shape1 = sprite.getGlobalBounds();
		sf::FloatRect shape2 = sprite2.getGlobalBounds();

		if (sprite.getPosition().x < sprite2.getPosition().x + shape2.width &&
			sprite.getPosition().x + shape1.width > sprite2.getPosition().x &&
			sprite.getPosition().y < sprite2.getPosition().y + shape2.height &&
			shape1.height + sprite.getPosition().y > sprite2.getPosition().y)
		{
			std::cout << "Collision Detected" << std::endl;
		}
		else
		{
			std::cout << "No Collision Detected" << std::endl;
		}

		window.clear();

		window.draw(sprite);

		window.draw(sprite2);

		window.display();
	}
}