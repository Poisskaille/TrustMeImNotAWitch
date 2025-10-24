#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "CameraUI.h"
#include "textureManager.h"
#include "map.h"

enum class State { GROUNDED, JUMPING, SLIDING, FALLING};

class Player : public Entity
{
public:
    Player(const sf::Texture& _texture, textureManager& _texManager);
	~Player() override {};
	void HandleInput();
	void Jump();
	void Slide();

	void Collision(const std::vector<Tile>& tile);


	//void Update(float dT) override;
private:
	playerAnimation currentAnimation = playerAnimation::Idle; // default

	int walkingSpeed = 100; //Permet d'ajuster la vitesse plus facilement
	int runningSpeed = 200;
	bool isWalking = false;
	float slideDuration = 2.0f; //en secondes
	float slideTimer = 0.0f;
	bool isSliding = false;

	sf::Sprite playerSprite;
    State playerState;
    float speed;
    float deltaTime;

	sf::Vector2f velocity;
	float jumpForce;
	float gravity;

	textureManager& texManager;	

	// A supprimer plus tard, juste pour test
	sf::RectangleShape ground;

	CameraUI cam;
	
};
