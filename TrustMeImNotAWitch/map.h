#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>
#include "textureManager.h"

struct Tile {
    sf::Sprite sprite;
    char type;

    Tile(const sf::Texture& tex, char t, sf::Vector2f pos)
        : sprite(tex), type(t) // directly initialize the sprite with the texture
    {
        sprite.setPosition(pos);
    }
};


class Map {
private:
    static Map* instance;

    Map();
    std::vector<std::vector<std::string>> sections;
    std::vector<std::string> combinedMap;
    std::vector<Tile> solidTiles; // persistent list of solid tiles

    std::mt19937 rng{ std::random_device{}() };
    void appendSection(const std::vector<std::string>& section);
    void randomizeNextSection();
    std::vector<std::string> loadSection(const std::string& path);

public:
    static Map* getInstance();
    void init();
    void loadAllSections();
    void generate();
    void draw(sf::RenderWindow& window, const sf::Texture& groundTex, int tileSize) const;

    // This will be used by Player for collisions
    const std::vector<Tile>& getSolidTiles() const { return solidTiles; }
};


extern Map* managerMap;