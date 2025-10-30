#pragma once
#include <iostream>
#include "CameraUI.h"
#include "textureManager.h"
#include "map.h"
#include "Entity.h"
#include "entityManager.h"
#include "Score.h"

class entityManager;

enum class State { GROUNDED, JUMPING, SLIDING, FALLING };

class Player : public Entity
{
public:
	Player(const sf::Texture& _texture);
	~Player() {};

	void update(float dT) override;
	void Draw(sf::RenderWindow& window);
	void HandleInput();
	void Jump();
	void Slide();

	void Collision();
	void shoot();

	void addSpeed();



private:
	playerAnimation currentAnimation = playerAnimation::Idle; // default

	sf::Vector2f defaultColliderSize = { 48.f, 80.f };
	sf::Vector2f slideColliderSize = { 72, 48 };

	sf::Vector2f playerSlideScale = { 3.f, 2.5f };
	sf::Vector2f playerDefaultScale = { 3.f, 3.f };

	sf::Vector2f slideOffset = { 0.f, 34.f };

	float walkingSpeed = 100.f; //Permet d'ajuster la vitesse plus facilement
	int runningSpeed = 200;
	bool isWalking = false;
	float slideDuration = 0.5f; //en secondes
	float slideTimer = 0.0f;
	float slideCooldown = 0.5f;
	float slideRefresh = 0.5f;
	bool isSliding = false;
	float isAgainstWall = false;
	State playerState;
	float defaultSpeed = 200;
	float speed;
	float boostSpeed = 350;
	sf::Clock _updateClock;

	sf::Vector2f velocity;
	float jumpForce;
	float gravity;

	float deltaTime;
	float totalTime;
	float scoreTime;

	//textureManager& texManager;

	CameraUI cam;
};