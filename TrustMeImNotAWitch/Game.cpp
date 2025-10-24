#include "Game.h"
#include "Player.h"
#include "memory.h"
#include "map.h"

Game::Game()
	:window(sf::VideoMode({ 1920, 1080 }), "Trust Me, I'm Not A Witch!")
{
}
Game::~Game(){}


void Game::init(sf::RenderWindow& window, textureManager& texManager) {

    background.setTexture(&texManager.backgroundTexture);
	background.setSize(sf::Vector2f(1920.f, 1080.f));

}

void Game::run()
{
 
    textureManager texManager;
    Map map(texManager);
    texManager.loadAll();

    sf::Clock clock;
    map.loadAllSections();
    map.generate();
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

        window.clear();
        window.draw(background);
        map.draw(window, texManager.grassTile, 48);
		
        window.display();
    }
}
