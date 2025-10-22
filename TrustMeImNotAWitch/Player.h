#pragma once
#include <iostream>
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
	void Jump();

	void Collision();

private:
	sf::Sprite playerSprite;
    State playerState;
    float speed;
    float deltaTime;

	sf::RectangleShape playerCollider;

	sf::Vector2f velocity;
	float jumpForce;
	float gravity;

	textureManager& texManager;

	// A supprimer plus tard, juste pour test
	sf::RectangleShape ground;
	
};
