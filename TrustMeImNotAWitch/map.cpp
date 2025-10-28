#include "map.h"

Map* Map::getInstance()
{
    if (instance == nullptr) { instance = new Map(); }
    return instance;
}

void Map::initMap()
{
    loadIndex = 0;
    currentEndX = 0;
    loadAllMap();
    for (int i = 0; i < 3; i++)
    {
        loadSection(i);
    }
}

void Map::loadAllMap()
{
    for(int i = 0; i < 10; i++)
    {
        std::string currentPath = "../assets/maps/map_" + std::to_string(i) + ".txt";
        std::fstream file(currentPath);

        char currentChar;
        std::vector<sf::RectangleShape> newMap;

        const float tileSize = 100.f;

        int x = 0;
        int y = 0;

        while (file.get(currentChar))
        {
            if (currentChar == '\n')
            {
                y++;
                x = 0;
                continue;
            }

            if (currentChar == '#')
            {
                sf::RectangleShape shape;
                shape.setSize({ tileSize, tileSize });
                shape.setPosition({ x * tileSize, y * tileSize });
                int x = (rand() % 3);
                switch(x)
                {
                case 0:
                    shape.setFillColor(sf::Color::Blue);
                    break;
                case 1:
                    shape.setFillColor(sf::Color::Red);
                    break;
                case 2:
                    shape.setFillColor(sf::Color::Green);
                    break;
                }
                newMap.push_back(shape);
            }

            x++;
        }

        loaded_map.push_back(std::make_shared<std::vector<sf::RectangleShape>>(newMap));
    }
}

void Map::loadSection(int index)
{
    current_map.push_back(std::make_shared<std::vector<sf::RectangleShape>>(placeTile(loaded_map[index])));
    loadIndex++;
}

std::vector<sf::RectangleShape> Map::placeTile(std::shared_ptr<std::vector<sf::RectangleShape>>& map)
{
    std::vector<sf::RectangleShape> newChunk;

    float offsetX = currentEndX;
    for (auto& tile : *map)
    {
        sf::RectangleShape newTile = tile;
        newTile.move({ offsetX, 0 });
        newChunk.push_back(newTile);
    }

    float maxX = 0;
    for (auto& tile : newChunk)
        maxX = std::max(maxX, tile.getPosition().x + tile.getSize().x);

    currentEndX = maxX;

    return newChunk;
}

void Map::unloadMap(sf::Vector2f playerPos)
{
    float lastTileX = current_map[0]->back().getPosition().x;
    if (lastTileX < playerPos.x - 300.f)
    {
        current_map.erase(current_map.begin());
        loadSection(0);
    }

    //current_map.erase(std::remove_if(current_map.begin(), current_map.end(), [&](const auto& section)
    //    {
    //       
    //    }
    //),
    //    current_map.end());
}

void Map::draw(sf::RenderWindow * window)         
{
    for (auto& chunk : current_map)
    {
        if (chunk) {
            for (auto& tile : *chunk)
            {
                if (&tile != nullptr)
                {
                    window->draw(tile);
                }
            }
        }
    }
}

bool Map::checkCollision(sf::FloatRect bounds)
{
    for (auto& chunk : current_map)
    {
            for (auto& tile : *chunk)
            {
                if (tile.getGlobalBounds().findIntersection(bounds))
                    return true;
            }
    }
    return false;
}

Map* Map::instance = nullptr;
Map* managerMap = Map::getInstance();