#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <random>


class Map {
private:
    std::vector<std::vector<std::string>> sections; // all loaded map chunks
    std::vector<std::string> combinedMap;            // final map after assembling
    std::mt19937 rng;

    std::vector<std::string> loadSection(const std::string& path);
    void randomizeNextSection();
    void appendSection(const std::vector<std::string>& section);

public:
    Map();
    void loadAllSections();
    void generate(std::size_t numberOfSections);
    void draw(sf::RenderWindow& window, const sf::Texture& groundTex, int tileSize) const;
};
