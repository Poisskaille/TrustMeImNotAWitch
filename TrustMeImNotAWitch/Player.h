#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "textureManager.h"

enum class State { GROUNDED, JUMPING };

class Player : public Entity
{
public:
    Player(const sf::Texture& texture, textureManager& texManager, sf::Vector2f& _pos, sf::Vector2f& _size);
    ~Player();
	void HandleInput();
	void Jump();

	void Update(float dT) override;

	void Collision(Entity& other);

private:
    State playerState;
    float speed;
    float deltaTime;

	sf::Vector2f velocity;
	float jumpForce;
	float gravity;

	textureManager& texManager;	
};
