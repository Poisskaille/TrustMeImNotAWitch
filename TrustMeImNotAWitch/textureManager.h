#pragma once
#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <stdexcept>

enum class playerAnimation {
    Idle,
    Run,
    Jump,
    Fall,
    WallCling,
    Slide,
    Walk
};

struct AnimationData {
    sf::Texture texture;
    int frameCount = 1;
    sf::Vector2i frameSize;
    int currentFrame = 0;
    float frameTime = 0.1f;
    float timer = 0.0f;
};

class textureManager {
private:
    static textureManager* instance;
    textureManager() {};

    std::unordered_map<playerAnimation, AnimationData> playerAnimations;
    playerAnimation currentAnim = playerAnimation::Idle;

public:
    static textureManager* getInstance();
    sf::Texture grassTile;
    sf::Texture test;
    sf::Texture backgroundTexture;
    void loadAll();
    void setplayerAnimation(playerAnimation anim, sf::Sprite& player);
    void update(float deltaTime, sf::Sprite& player);
};

extern textureManager* managerText;