#pragma once
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

private:

	State playerState;
	sf::RectangleShape playerShape;
	float speed;
	float deltaTime;
	
};

