#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "textureManager.h"

enum class State { GROUNDED, JUMPING };

class Player : public Entity
{
public:
    Player(const sf::Texture& _texture, textureManager& _texManager);
    ~Player();
	void HandleInput();
	void Jump();

	//void Update(float dT) override;

private:
    State playerState;
    float speed;
    float deltaTime;

	sf::Vector2f velocity;
	float jumpForce;
	float gravity;

	textureManager& texManager;	
};
