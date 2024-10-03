#include "Game.hpp"

Game::Game() {
	_window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), TITLE);
	_window.setMouseCursorVisible(false);
	_offset = sf::Vector2f(0, 0);
	_mousePos = sf::Vector2f(sf::Mouse::getPosition(_window));
	_mouseIsoPos = carToIso(sf::Vector2f(_mousePos.x, _mousePos.y));
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

void Game::update() {
	_mousePos = sf::Vector2f(sf::Mouse::getPosition(_window));
	_mouseIsoPos = carToIso(_mousePos - _offset);
	
}