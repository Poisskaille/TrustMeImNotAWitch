#include "textureManager.h"
#include <stdexcept>

void textureManager::loadAll() {
    grassTile.loadFromFile("assets/tiles/grass.png");

    AnimationData idle, run, jump;

    // Example: all spritesheets are horizontal strips
    idle.texture.loadFromFile("assets/player/idle.png");
    idle.frameCount = 4;
    idle.frameSize = { 64, 64 };

    run.texture.loadFromFile("assets/player/run.png");
    run.frameCount = 6;
    run.frameSize = { 64, 64 };

    jump.texture.loadFromFile("assets/player/jump.png");
    jump.frameCount = 3;
    jump.frameSize = { 64, 64 };

    playerAnimations[playerAnimation::Idle] = idle;
    playerAnimations[playerAnimation::Run] = run;
    playerAnimations[playerAnimation::Jump] = jump;

    // Default animation
    //setplayerAnimation(playerAnimation::Idle);
}

void textureManager::setplayerAnimation(playerAnimation anim, sf::RectangleShape& player) {
    currentAnim = anim;

    auto& animData = playerAnimations[anim];
    animData.currentFrame = 0;
    animData.timer = 0.0f;

    player.setTexture(animData.texture);
    player.setTextureRect(sf::IntRect(0, 0, animData.frameSize.x, animData.frameSize.y));
}

void textureManager::update(float deltaTime) {
    auto& animData = playerAnimations[currentAnim];
    animData.timer += deltaTime;

    if (animData.timer >= animData.frameTime) {
        animData.timer -= animData.frameTime;
        animData.currentFrame = (animData.currentFrame + 1) % animData.frameCount;

        playerSprite.setTextureRect(sf::IntRect(
            animData.currentFrame * animData.frameSize.x,
            0,
            animData.frameSize.x,
            animData.frameSize.y
        ));
    }
}

const sf::Sprite& textureManager::getPlayerSprite() const {
    return playerSprite;
}
