#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "textureManager.h"
#include "map.h"

enum class State { GROUNDED, JUMPING, SLIDING};

class Player {
public:
    Player(const sf::Texture& texture, textureManager& texManager);
    ~Player();

	void Update(float dT, const std::vector<Tile>& tile);
	void Draw(sf::RenderWindow& window);
	void HandleInput();
	void Jump();

	void Collision(const std::vector<Tile>& tile);

private:
	playerAnimation currentAnimation = playerAnimation::Idle; // default

	int walkingSpeed = 100; //Permet d'ajuster la vitesse plus facilement
	int runningSpeed = 200;
	bool isWalking = false;

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
