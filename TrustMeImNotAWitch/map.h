#pragma once
#include "Outils.h"

class Map {
public:

	static Map* getInstance();

	void initMap();

	void loadAllMap();
	void loadSection(int index);
	std::vector<sf::RectangleShape> placeTile(std::shared_ptr<std::vector<sf::RectangleShape>>& map);

	void unloadMap(sf::Vector2f playerPos);

	void draw(sf::RenderWindow* window);

	bool checkCollision(sf::FloatRect bounds);

private:

	std::vector<std::shared_ptr<std::vector<sf::RectangleShape>>> loaded_map;
	std::vector<std::shared_ptr<std::vector<sf::RectangleShape>>> current_map;

	static Map* instance;

	int loadIndex;
	float currentEndX;
};

extern Map* managerMap;