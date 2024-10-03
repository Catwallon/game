#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TILE_WIDTH 128.0f
#define TILE_HEIGHT 64.0f

sf::Vector2f carToIsoTile(sf::Vector2f v)
{
	return sf::Vector2f((v.x - v.y) * (TILE_WIDTH / 2), (v.x + v.y) * (TILE_HEIGHT / 2));
}


sf::Vector2f carToIso(sf::Vector2f v)
{
	return sf::Vector2f((v.x + 2.0f * v.y) / 4.0f, (2.0f * v.y - v.x) / 4.0f);
}

sf::Vector2f isoToCar(sf::Vector2f v)
{
	return sf::Vector2f(2.0f * v.x - 2.0f * v.y, v.x + v.y);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "game");
	window.setMouseCursorVisible(false);
	int offset_x = 0;
	int offset_y = 0;
	sf::Texture texture;
	if (!texture.loadFromFile("assets/grass.png"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	sprite.setScale(TILE_WIDTH / texture.getSize().x, TILE_HEIGHT / texture.getSize().y);
	sprite.setOrigin(texture.getSize().x / 2, 0);
	sf::RectangleShape rectangle(sf::Vector2f(5, 5));
	rectangle.setOrigin(2.5f, 2.5f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					offset_y += 10;
				if (event.key.code == sf::Keyboard::Down)
					offset_y -= 10;
				if (event.key.code == sf::Keyboard::Left)
					offset_x += 10;
				if (event.key.code == sf::Keyboard::Right)
					offset_x -= 10;
			}
		}
		auto mousePos = sf::Mouse::getPosition(window);
		auto mouseIsoPos = carToIso(sf::Vector2f(mousePos.x - offset_x, mousePos.y - offset_y));
		std::cout << "mousePos = " << mousePos.x - offset_x << ", " << mousePos.y - offset_y << std::endl;
		std::cout << "mouseIsoPos = " << mouseIsoPos.x << ", " << mouseIsoPos.y << std::endl;
		window.clear();
		for (int y = 0; y <= 10; y++)
		{
			for (int x = 0; x <= 10; x++)
			{
				auto isoPos = carToIsoTile(sf::Vector2f(x, y));
				sprite.setPosition(isoPos.x + offset_x, isoPos.y + offset_y);
				window.draw(sprite);
			}
		}
		rectangle.setPosition(mousePos.x, mousePos.y);
		window.draw(rectangle);
		window.display();
	}
	return EXIT_SUCCESS;
}
