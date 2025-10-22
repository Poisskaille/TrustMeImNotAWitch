#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "textureManager.h"

enum class State { GROUNDED, JUMPING };

class Player {
public:
    textureManager& texManager;
    Player(const sf::Texture& texture, textureManager& texManager);
    ~Player();

	void Update(float dT);
	void Draw(sf::RenderWindow& window);
	void HandleInput();
	void Jump();

	void Collision();

private:
    sf::Sprite player;
    State playerState;
    float speed;
    float deltaTime;

    
};
