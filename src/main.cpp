#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TILE_WIDTH 128.0f
#define TILE_HEIGHT 48.0f

std::pair<float, float> toIsometric(float x, float y) {
    float isoX = (x - y) * (TILE_WIDTH / 2);
    float isoY = (x + y) * (TILE_HEIGHT / 2);
    return std::make_pair(isoX, isoY);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "game");
    sf::Texture texture;
    if (!texture.loadFromFile("assets/grass.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setScale(TILE_WIDTH / texture.getSize().x, TILE_HEIGHT / texture.getSize().y);
    sprite.setOrigin(TILE_WIDTH * 2, 0);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
	for (int y = 0; y <= 10; y++)
	{
		for (int x = 0; x <= 10; x++)
		{
			std::pair<float, float> isoPos = toIsometric(x, y);
			sprite.setPosition(isoPos.first + WINDOW_HEIGHT / 2, isoPos.second);
        		window.draw(sprite);
		}
	}
        window.display();
    }
    return EXIT_SUCCESS;
}

