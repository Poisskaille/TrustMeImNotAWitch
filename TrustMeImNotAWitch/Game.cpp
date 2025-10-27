#include "Game.h"
#include "Player.h"
#include "memory.h"
#include "map.h"
#include "Menu.h"

Game::Game()
	:window(sf::VideoMode({ 1920, 1080 }), "Trust Me, I'm Not A Witch!")
{
}
Game::~Game(){}

void Game::run()
{
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();
    if (!menu->runMain(window))
        return;

    managerText->loadAll();
    managerGame->init();
	
    Score score;
    score.highScore();
    sf::Clock clock;

    //Threads
    std::thread tCollisions(&collisionsManager::checkCollisions, managerCollisions);
    //managerEntity->createPlayer(managerText->test);

    while (window.isOpen())
    {
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        score.addScore(10);
        managerGame->update(&window);

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                managerCollisions->setGameRunning(false);
				tCollisions.join();
                window.close();
            }
        }
    }

    managerEntity->~entityManager();
    score.newScore();
}
