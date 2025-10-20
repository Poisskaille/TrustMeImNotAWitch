#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"

enum class playerAnimation {
	Idle,
	Run,
	Jump,
	Fall,
	WallCling,
	Slide
};

struct AnimationData {
	sf::Texture texture;
	int frameCount = 1;
	sf::Vector2i frameSize;
	int currentFrame = 0;
	float frameTime = 0.1f; // time per frame
	float timer = 0.0f;
};

class textureManager {
private:
	sf::Texture grassTile;

	std::unordered_map<playerAnimation, AnimationData> playerAnimations;
	playerAnimation currentAnim = playerAnimation::Idle;

public:
	void loadAll();
	void setplayerAnimation(playerAnimation anim, sf::RectangleShape& player);
	void update(float deltaTime, sf::RectangleShape& player);
};