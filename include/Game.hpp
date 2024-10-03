#pragma once

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#define TITLE "game"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TILE_WIDTH 128.0f
#define TILE_HEIGHT 64.0f

#define DEBUG 1

class Game {
	private:
		sf::RenderWindow _window;
		sf::Vector2f _offset;
		sf::Vector2f _mousePos;
		sf::Vector2f _mouseIsoPos;
	public:
		Game();
		sf::RenderWindow& getWindow();
		void setOffset(sf::Vector2f offset);
		void addOffset(sf::Vector2f offset);
		sf::Vector2f getOffset();
		sf::Vector2f getMousePos();
		sf::Vector2f getMouseIsoPos();
		void update();
};

// utils.cpp
sf::Vector2f carToIsoTile(sf::Vector2f v);
sf::Vector2f carToIso(sf::Vector2f v);
sf::Vector2f isoToCar(sf::Vector2f v);