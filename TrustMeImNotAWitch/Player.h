#pragma once
#include <iostream>
#include "CameraUI.h"
#include "textureManager.h"
#include "map.h"
#include "Entity.h"
#include "entityManager.h"

class entityManager;

enum class State { GROUNDED, JUMPING, SLIDING, FALLING};

class Player : public Entity
{
public:
	Player(const sf::Texture& _texture);
	~Player() {};

	void update() override;
	void Draw(sf::RenderWindow& window);
	void HandleInput();
	void Jump();
	void Slide();

	void Collision();
	void shoot();


private:
	playerAnimation currentAnimation = playerAnimation::Idle; // default

	float walkingSpeed = 100.f; //Permet d'ajuster la vitesse plus facilement
	int runningSpeed = 200;
	bool isWalking = false;
	float slideDuration = 0.5f; //en secondes
	float slideTimer = 0.0f;
	float slideCooldown = 1.0f;
	float slideRefresh = 1.0f;
	bool isSliding = false;
	sf::Time deltaTime;
	State playerState;
	float defaultSpeed = 200;
	float speed;
	float boostSpeed = 250;
	sf::Clock _updateClock;

	sf::Vector2f velocity;
	float jumpForce;
	float gravity;

	//textureManager& texManager;

	CameraUI cam;

};