#include "Game.h"
#include "Player.h"
#include "memory.h"
#include "map.h"

Game::Game()
	:window(sf::VideoMode({ 1920, 1080 }), "Trust Me, I'm Not A Witch!")
{
}
Game::~Game(){}

void Game::run()
{
 
    textureManager texManager;
    
    texManager.loadAll();
    managerMap->init(texManager);

    sf::Clock clock;
    managerMap->loadAllSections();
    managerMap->generate();

    managerGame->init(texManager);

    //Threads
    std::thread tCollisions(&collisionsManager::checkCollisions, managerCollisions);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                managerCollisions->setGameRunning(false);
				tCollisions.join();
                managerEntity->~entityManager();
                window.close();
            }
        }
        managerGame->update(&window);
    }
}
