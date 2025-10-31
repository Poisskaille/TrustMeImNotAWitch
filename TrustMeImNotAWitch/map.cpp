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
            switch (currentChar)
            {
            case '\n':
                y++;
                x = 0;
                break;
            case '#':
            {
                sf::RectangleShape shape;
                shape.setSize({ tileSize, tileSize });
                shape.setPosition({ x * tileSize, y * tileSize });
                int randC = (rand() % 3);
                shape.setTexture(&managerText->getTexture("grass"));
                newMap.push_back(shape);
                break;
            }
            default:
                break;
            }
            x++;
        }

        loaded_map.push_back(std::make_shared<std::vector<sf::RectangleShape>>(newMap));
    }
}

void Map::loadEntity(int index)
{
    std::string currentPath = "../assets/maps/map_" + std::to_string(index) + ".txt";

    std::fstream file(currentPath);
    char currentChar;

    const float tileSize = 100.f;

    int x = 0;
    int y = 0;

    while (file.get(currentChar))
    {
        switch (currentChar)
        {
        case '\n':
            y++;
            x = 0;
            break;
        case 'F':
            managerEntity->createEnnemies(currentChar, managerText->getEnemyTexture(EnemyType::Fork,animationType::Idle), { x * tileSize + offsetX, y * tileSize }, { 0, 0});
            break;
        case 'T':
            managerEntity->createEnnemies(currentChar, managerText->getEnemyTexture(EnemyType::Torch, animationType::Idle), { x * tileSize + offsetX, y * tileSize }, { 0, 0 });
            break;
        case 'O':
            managerEntity->createEnnemies(currentChar, managerText->getTexture("barricade"), {x * tileSize + offsetX, y * tileSize}, {1, 1});
            break;
        case 'B':
            managerEntity->createEnnemies(currentChar, managerText->getEnemyTexture(EnemyType::Sign, animationType::Idle), { x * tileSize + offsetX, y * tileSize }, { 0, 0 });
            break;
        case 'G':
            managerEntity->createPowerUp(PowerType::GOLD, managerText->getTexture("coin"), {x * tileSize + offsetX, y * tileSize}, {1 , 1});
            break;
        case 'M':
            managerEntity->createPowerUp(PowerType::SCORE_BOOST, managerText->getTexture("coin"), {x * tileSize + offsetX, y * tileSize}, {tileSize, tileSize});
            break;
        default:
            break;
        }
        x++;
    }

}

void Map::loadSection(int index)
{
    loadIndex++;
    current_map.push_back(std::make_shared<std::vector<sf::RectangleShape>>(placeTile(loaded_map[index])));
    loadEntity(index);
    lastChunk = index;
}

std::vector<sf::RectangleShape> Map::placeTile(std::shared_ptr<std::vector<sf::RectangleShape>>& map)
{
    std::vector<sf::RectangleShape> newChunk;

    offsetX = currentEndX;
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
        nextChunk();
    }
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

void Map::nextChunk()
{
    int possibility[5];
    int size = 5;

    switch(lastChunk)
    {
    case 0:
        possibility[0] = 1;
        size = 1;
        break;
    case 1: // 2 4 5 6 7
        possibility[0] = 2;
        possibility[1] = 4;
        possibility[2] = 5;
        possibility[3] = 6;
        possibility[4] = 7;
        break;
    case 2: // 1 3 4 5 7
        possibility[0] = 1;
        possibility[1] = 3;
        possibility[2] = 4;
        possibility[3] = 5;
        possibility[4] = 7;
        break;
    case 3: // 4 7
        possibility[0] = 4;
        possibility[1] = 7;
        size = 2;
        break;
    case 4: // 1 2 6
        possibility[0] = 1;
        possibility[1] = 2;
        possibility[2] = 6;
        size = 2;
        break;
    case 5: // 1 2 4 7
        possibility[0] = 1;
        possibility[1] = 2;
        possibility[2] = 4;
        possibility[3] = 7;
        size = 4;
        break;
    case 6:  // 1 2 4 5 7
        possibility[0] = 1;
        possibility[1] = 2;
        possibility[2] = 4;
        possibility[3] = 5;
        possibility[4] = 7;
        break;
    case 7: // 8
        possibility[0] = 8;
        size = 1;
        break;
    case 8: // 9
        possibility[0] = 9;
        size = 1;
        break;
    case 9: // 1 2
        possibility[0] = 1;
        possibility[1] = 2;
        size = 2;
        break;
    }
    int random = (rand() % size);
    loadSection(possibility[random]);
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

sf::RectangleShape Map::getCollidingTile(sf::FloatRect bounds) {
    for (auto& chunk : current_map)
    {
        for (auto& tile : *chunk)
        {
            if (tile.getGlobalBounds().findIntersection(bounds))
                return tile;
        }
    }
}

Map* Map::instance = nullptr;
Map* managerMap = Map::getInstance();