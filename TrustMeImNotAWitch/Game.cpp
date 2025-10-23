#include "Game.h"


Game::Game()
	:window(sf::VideoMode({ 1920, 1080 }), "Trust Me, I'm Not A Witch!")
{
}
Game::~Game(){}

void Game::run()
{
    textureManager texManager;
    texManager.loadAll();

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
                window.close();
            }
        }
        managerGame->update(&window);
    }
}
