#include "map.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

Map::Map(textureManager& texManager)
    : texManager(texManager) // initialize the reference here
{
    std::random_device rd;
    rng.seed(rd());
}

std::vector<std::string> Map::loadSection(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open map section: " + path);
    }

    std::vector<std::string> section;
    std::string line;
    while (std::getline(file, line)) {
        // remove possible carriage return for Windows formatted files
        if (!line.empty() && line.back() == '\r') line.pop_back();
        section.push_back(line);
    }

    if (section.empty()) {
        throw std::runtime_error("Map section is empty: " + path);
    }

    return section;
}

void Map::loadAllSections() {
    // Add as many section files as you have
    sections.clear();
    sections.push_back(loadSection("assets/maps/section1.txt"));
    sections.push_back(loadSection("assets/maps/section2.txt"));
    //sections.push_back(loadSection("assets/maps/section_3.txt"));
    //sections.push_back(loadSection("assets/maps/section_4.txt"));

    // sanity: ensure all sections have the same height (rows)
    std::size_t height = sections.front().size();
    for (const auto& s : sections) {
        if (s.size() != height) {
            std::cerr << "Warning: not all sections share the same row count.\n";
            break;
        }
    }
}

void Map::appendSection(const std::vector<std::string>& section) {
    if (combinedMap.empty()) {
        combinedMap = section;
        return;
    }

    size_t currentH = combinedMap.size();
    size_t newH = section.size();
    size_t maxH = std::max(currentH, newH);
    combinedMap.resize(maxH, std::string()); // pad with empty strings

    for (size_t y = 0; y < maxH; ++y) {
        std::string& combinedRow = combinedMap[y];
        const std::string& sectionRow = (y < newH) ? section[y] : std::string(section[0].size(), '.');

        // pad combinedRow with dots if needed
        if (combinedRow.size() < sectionRow.size())
            combinedRow.resize(combinedRow.size(), '.');

        combinedRow += sectionRow; // now append safely
    }
}


void Map::randomizeNextSection() {
    if (sections.empty()) {
        throw std::runtime_error("No sections loaded to randomize.");
    }
    std::uniform_int_distribution<std::size_t> dist(0, sections.size() - 1);
    std::size_t idx = dist(rng);
    appendSection(sections[idx]);
}

void Map::generate() {
    combinedMap.clear();
    solidTiles.clear();

    for (int i = 0; i < 5; ++i)
        randomizeNextSection();

    const int tileSize = 32;

    for (size_t y = 0; y < combinedMap.size(); ++y) {
        for (size_t x = 0; x < combinedMap[y].size(); ++x) {
            if (combinedMap[y][x] == '#') {
                solidTiles.emplace_back(
                    texManager.grassTile, // texture
                    '#',                  // type
                    sf::Vector2f(static_cast<float>(x * tileSize),
                        static_cast<float>(y * tileSize)) // position
                );
            }
        }
    }
}




void Map::draw(sf::RenderWindow& window, const sf::Texture& groundTex, int tileSize) const {
    for (const auto& tile : solidTiles) {
        window.draw(tile.sprite);
    }
}
