#include "Game.hpp"

int main() {
	Game game;
	auto& window = game.getWindow();

	while (window.isOpen()) {
		game.update();
		window.clear();
		for (int y = 0; y <= 10; y++) {
			for (int x = 0; x <= 10; x++) {
				game.getSprite("grass")->setPosition(carToIsoTile(sf::Vector2f(x, y)) + game.getOffset());
				window.draw(*game.getSprite("grass"));
			}
		}
		game.getSprite("knight")->setPosition(isoToCar(sf::Vector2f(175, 175)) + game.getOffset());
		window.draw(*game.getSprite("knight"));
		if (DEBUG) {
			game.getText("debug")->setString(
				"mousePos= x:" + floatToString(game.getMousePos().x, 0) + " y:" + floatToString(game.getMousePos().x, 0)
				+ "\nmouseIsoPos= x:" + floatToString(game.getMouseIsoPos().x, 0) + " y:" + floatToString(game.getMouseIsoPos().x, 0)
			);
			window.draw(*game.getText("debug"));
		}
		game.getSprite("cursor")->setPosition(game.getMousePos());
		window.draw(*game.getSprite("cursor"));
		window.display();
	}
	return EXIT_SUCCESS;
}
