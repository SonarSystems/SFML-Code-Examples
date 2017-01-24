#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	window.setFramerateLimit(60);
	//window.setVerticalSyncEnabled(true);

	sf::Clock clock;

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

		sf::Time time = clock.getElapsedTime();
		std::cout << 1.0f / time.asSeconds() << std::endl;

		clock.restart().asSeconds();

		window.clear();

		window.display();
	}
}