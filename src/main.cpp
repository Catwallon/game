#include "Game.hpp"

int main()
{
	Game game;
	sf::Texture texture;
	auto& window = game.getWindow();
	if (!texture.loadFromFile("assets/grass.png"))
		return EXIT_FAILURE;
	sf::Font font;
	if (!font.loadFromFile("/usr/share/fonts/JetBrainsMonoNerdFont-Regular.ttf")) {
		return EXIT_FAILURE;
	}
    sf::Text debugText;
    debugText.setFont(font);
    debugText.setCharacterSize(12);
    debugText.setFillColor(sf::Color::White);
    debugText.setPosition(10, 10);
	sf::Sprite sprite(texture);
	sprite.setScale(TILE_WIDTH / texture.getSize().x, TILE_HEIGHT / texture.getSize().y);
	sprite.setOrigin(texture.getSize().x / 2, 0);
	sf::RectangleShape cursor(sf::Vector2f(5, 5));
	cursor.setOrigin(2.5f, 2.5f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Up:
						game.addOffset(sf::Vector2f(0, 10));
						break;
					case sf::Keyboard::Down:
						game.addOffset(sf::Vector2f(0, -10));
						break;
					case sf::Keyboard::Left:
						game.addOffset(sf::Vector2f(10, 0));
						break;
					case sf::Keyboard::Right:
						game.addOffset(sf::Vector2f(-10, 0));
						break;
					default:
						break;
				}

			}
		}
		game.update();
		window.clear();
		for (int y = 0; y <= 10; y++)
		{
			for (int x = 0; x <= 10; x++)
			{
				sprite.setPosition(carToIsoTile(sf::Vector2f(x, y)) + game.getOffset());
				window.draw(sprite);
			}
		}
		if (DEBUG) {
			debugText.setString(
				"mousePos= x:" + std::to_string(game.getMousePos().x) + " y:" + std::to_string(game.getMousePos().x)
				+ "\nmouseIsoPos= x:" + std::to_string(game.getMouseIsoPos().x) + " y:" + std::to_string(game.getMouseIsoPos().x)
			);
			window.draw(debugText);
		}
		cursor.setPosition(game.getMousePos());
		window.draw(cursor);
		window.display();
	}
	return EXIT_SUCCESS;
}
