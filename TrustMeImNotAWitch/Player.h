#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

enum class State{GROUNDED, JUMPING};

class Player
{
public:

	Player();
	~Player();

	void Update(float dT);
	void Draw(sf::RenderWindow& window);
	void HandleInput();
	void Jump();

	void Collision();

private:

	State playerState;
	sf::RectangleShape playerShape;

	sf::Vector2f velocity;
	float speed;
	float deltaTime;
	float jumpForce;
	float gravity;

	// A supprimer plus tard, juste pour test
	sf::RectangleShape ground;
	
};

