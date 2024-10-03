#include "Game.hpp"

Game::Game() {
	_window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), TITLE);
	_window.setMouseCursorVisible(false);
	_offset = sf::Vector2f(0, 0);
	_mousePos = sf::Vector2f(sf::Mouse::getPosition(_window));
	_mouseIsoPos = carToIso(sf::Vector2f(_mousePos.x, _mousePos.y));

	auto grassTexture = new sf::Texture;
	if (!grassTexture->loadFromFile("assets/grass.png"))
		exit(EXIT_FAILURE);
	auto grass = new sf::Sprite(*grassTexture);
	grass->setScale(TILE_WIDTH / grassTexture->getSize().x, TILE_HEIGHT / grassTexture->getSize().y);
	grass->setOrigin(grassTexture->getSize().x / 2, 0);
	_sprites["grass"] = grass;

	auto cursorTexture = new sf::Texture;
	if (!cursorTexture->loadFromFile("assets/cursor.png"))
		exit(EXIT_FAILURE);
	auto cursor = new sf::Sprite(*cursorTexture);
	cursor->setTexture(*cursorTexture);
	cursor->setScale(10.0f / cursorTexture->getSize().x, 15.0f / cursorTexture->getSize().y);
	_sprites["cursor"] = cursor;

	auto font = new sf::Font;
	if (!font->loadFromFile("/usr/share/fonts/JetBrainsMonoNerdFont-Regular.ttf"))
		exit(EXIT_FAILURE);
	auto debug = new sf::Text;
	debug->setFont(*font);
	debug->setCharacterSize(12);
	debug->setPosition(10, 10);
	_texts["debug"] = debug;
}

sf::RenderWindow& Game::getWindow() {
	return _window;
}

void Game::setOffset(sf::Vector2f offset) {
	_offset = offset;
}

sf::Vector2f Game::getOffset() {
	return _offset;
}

void Game::addOffset(sf::Vector2f offset) {
	_offset += offset;
}

sf::Vector2f Game::getMousePos() {
	return _mousePos;
}

sf::Vector2f Game::getMouseIsoPos() {
	return _mouseIsoPos;
}

sf::Sprite* Game::getSprite(std::string name) {
	return _sprites[name];
}

sf::Text* Game::getText(std::string name) {
	return _texts[name];
}

void Game::update() {
	_mousePos = sf::Vector2f(sf::Mouse::getPosition(_window));
	_mouseIsoPos = carToIso(_mousePos - _offset);

	sf::Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
				case sf::Keyboard::Up:
					addOffset(sf::Vector2f(0, 10));
					break;
				case sf::Keyboard::Down:
					addOffset(sf::Vector2f(0, -10));
					break;
				case sf::Keyboard::Left:
					addOffset(sf::Vector2f(10, 0));
					break;
				case sf::Keyboard::Right:
					addOffset(sf::Vector2f(-10, 0));
					break;
				default:
					break;
			}

		}
	}
}