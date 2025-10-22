#pragma once
#include "CameraUI.h"
#include "textureManager.h"

enum class PlayerState { GROUNDED, JUMPING };

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
    PlayerState playerState;
    float speed;
    float deltaTime;

	sf::RectangleShape playerCollider;

	sf::Vector2f velocity;
	float jumpForce;
	float gravity;

	textureManager& texManager;

	// A supprimer plus tard, juste pour test
	sf::RectangleShape ground;

	CameraUI cam;
	
};
