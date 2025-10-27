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


    textureManager texManager;
    Map::getInstance().initMap();
    texManager.loadAll();
    std::shared_ptr<Player> player = std::make_shared<Player>(texManager.test, texManager);
	init(window, texManager);
	
    Score score;
    score.highScore();
    sf::Clock clock;
    managerGame->init();

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

        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        score.addScore(10);
        window.clear();
        player->Draw(window);
        Map::getInstance().draw(window);
		
        window.display();
        managerGame->update(&window);
    }

    score.newScore();
}
