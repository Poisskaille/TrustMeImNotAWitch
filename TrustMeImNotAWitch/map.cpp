#include "map.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

Map::Map() {
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
        // start from the new section
        combinedMap = section;
        return;
    }

    // If heights differ, pad the shorter one with '.' (air)
    std::size_t currentH = combinedMap.size();
    std::size_t newH = section.size();
    std::size_t maxH = std::max(currentH, newH);

    if (currentH < maxH) combinedMap.resize(maxH, std::string());
    // ensure each row has at least something (avoid undefined behaviour)
    for (auto& row : combinedMap) if (row.empty()) row = std::string();

    // pad section rows if needed while concatenating
    for (std::size_t y = 0; y < maxH; ++y) {
        std::string right = (y < newH) ? section[y] : std::string();
        // ensure the right part contains '.' where empty
        if (right.empty()) right = std::string(combinedMap[y].size() > 0 ? 0 : 0, '.');
        combinedMap[y] += right;
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

void Map::generate(std::size_t numberOfSections) {
    if (sections.empty()) {
        throw std::runtime_error("No sections loaded. Call loadAllSections() first.");
    }

    combinedMap.clear();
    for (std::size_t i = 0; i < numberOfSections; ++i) {
        randomizeNextSection();
    }
}

void Map::draw(sf::RenderWindow& window, const sf::Texture& groundTex, int tileSize) const {
    if (combinedMap.empty()) return;

    sf::Sprite tile(groundTex);

    for (std::size_t y = 0; y < combinedMap.size(); ++y) {
        for (std::size_t x = 0; x < combinedMap[y].size(); ++x) {
            char c = combinedMap[y][x];
            if (c == '#') {
                tile.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)));
                window.draw(tile);
            }
        }
    }
}
