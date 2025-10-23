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
    std::shared_ptr<Player> player = std::make_shared<Player>(texManager.test, texManager);
	init(window, texManager);
	

    sf::Clock clock;
    map.loadAllSections();
    map.generate();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        window.setFramerateLimit(60);
        window.clear();
        player->Update(deltaTime, map.getSolidTiles());
        window.draw(background);
        player->Draw(window);
        map.draw(window, texManager.grassTile, 48);
		
        window.display();
    }
}
