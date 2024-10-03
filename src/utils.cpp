#include "Game.hpp"

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

std::string floatToString(float value, int precision) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << value;
	return oss.str();
	}