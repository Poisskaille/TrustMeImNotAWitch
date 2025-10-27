#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>
#include "textureManager.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Map {
public:

	static Map* getInstance();

	void initMap();

	void loadAllMap();
	void loadSection(int index);
	std::vector<sf::RectangleShape> placeTile(std::vector<sf::RectangleShape>&);

	void unloadMap(sf::Vector2f playerPos);

	void draw(sf::RenderWindow* window);

	bool checkCollision(sf::FloatRect bounds);

private:

	std::vector<std::vector<sf::RectangleShape>> loaded_map;
	std::vector<std::vector<sf::RectangleShape>> current_map;

	static Map* instance;

	int loadIndex;
	float currentEndX;
};

extern Map* managerMap;