#include "Game.h"

Game::Game()
	:window(sf::VideoMode({ 1920, 1080 }), "Trust Me, I'm Not A Witch!")
{
    sf::Image icon;
    icon.loadFromFile("../assets/UI/menu/nottaHat.png");
    window.setIcon(icon);
}
Game::~Game(){}

void Game::run()
{
    managerText->loadAll();
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();
    if (!menu->runMain(window))
        return;

    UIManagers().getInstance().clearMenu();

    managerGame->init();
    sf::Clock clock;

    //Threads
    std::thread tCollisions(&collisionsManager::checkCollisions, managerCollisions);

    while (window.isOpen())
    {
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

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
    managerScore->newScore();
}
