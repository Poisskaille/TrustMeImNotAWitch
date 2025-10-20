#include "Game.h"

Game::Game()
	:window(sf::VideoMode({ 1920, 1080 }), "Trust me im not a Witch")
{
}
Game::~Game(){}

void Game::run()
{
    Player player;

    sf::Clock clock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        window.clear();
        player.Update(deltaTime);
        player.Draw(window);
        window.display();
    }
}
