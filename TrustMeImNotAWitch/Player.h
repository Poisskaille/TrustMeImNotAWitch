#pragma once
#include "SFML/Graphics.hpp"
#include "textureManager.h"

enum class State { GROUNDED, JUMPING };

class Player {
public:
    Player(const sf::Texture& texture, textureManager& texManager);
    ~Player();

    void Update(float dT);
    void Draw(sf::RenderWindow& window);
    void HandleInput();

private:
    sf::Sprite player;
    State playerState;
    float speed;
    float deltaTime;

    textureManager& texManager; // keep a reference if you’ll use animations later
};
