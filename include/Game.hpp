#pragma once

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>

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
		std::map<std::string, sf::Sprite*> _sprites;
		std::map<std::string, sf::Text*> _texts;
	public:
		Game();
		sf::RenderWindow& getWindow();
		void setOffset(sf::Vector2f offset);
		void addOffset(sf::Vector2f offset);
		sf::Vector2f getOffset();
		sf::Vector2f getMousePos();
		sf::Vector2f getMouseIsoPos();
		sf::Sprite* getSprite(std::string name);
		sf::Text* getText(std::string name);
		void update();
};

// utils.cpp
sf::Vector2f carToIsoTile(sf::Vector2f v);
sf::Vector2f carToIso(sf::Vector2f v);
sf::Vector2f isoToCar(sf::Vector2f v);
std::string floatToString(float value, int precision);