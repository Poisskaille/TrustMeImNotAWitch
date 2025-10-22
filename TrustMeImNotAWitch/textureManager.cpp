#include "textureManager.h"
#include <stdexcept>

void textureManager::loadAll() {
    if (!test.loadFromFile("assets/test.png")) {
        throw std::runtime_error("Failed to load texture: assets/test.png");
    }
    if (!backgroundTexture.loadFromFile("assets/background.png")) {
        throw std::runtime_error("Failed to load texture: assets/background.png");
    }
    if (!grassTile.loadFromFile("assets/tiles/ground.png")) {
        throw std::runtime_error("Failed to load texture: assets/tiles/ground.png");
    }


    AnimationData idle, run, jump;

    // Example: all spritesheets are horizontal strips
    if (!idle.texture.loadFromFile("assets/character/notta_Idle.png")) {
        throw std::runtime_error("Failed to load texture: assets/character/notta_Idle.png");
    }
    idle.frameCount = 8;
    idle.frameSize = { 32, 32 };

    // Uncomment and handle other animations similarly if neede  d
    /*
    if (!run.texture.loadFromFile("assets/player/run.png")) {
        throw std::runtime_error("Failed to load texture: assets/player/run.png");
    }
    run.frameCount = 6;
    run.frameSize = { 64, 64 };

    if (!jump.texture.loadFromFile("assets/player/jump.png")) {
        throw std::runtime_error("Failed to load texture: assets/player/jump.png");
    }
    jump.frameCount = 3;
    jump.frameSize = { 64, 64 };

    playerAnimations[playerAnimation::Idle] = idle;
    playerAnimations[playerAnimation::Run] = run;
    playerAnimations[playerAnimation::Jump] = jump;

    // Default animation
    setplayerAnimation(playerAnimation::Idle);
    */
}

void textureManager::setplayerAnimation(playerAnimation anim, sf::Sprite& player) {
    currentAnim = anim;

    auto& animData = playerAnimations[anim];
    animData.currentFrame = 0;
    animData.timer = 0.0f;

    player.setTexture(animData.texture);
    player.setTextureRect(sf::IntRect(
        { animData.currentFrame * animData.frameSize.x, 0 },
        { animData.frameSize.x, animData.frameSize.y }
    ));


}

void textureManager::update(float deltaTime, sf::Sprite& player) {
    auto& animData = playerAnimations[currentAnim];
    animData.timer += deltaTime;

    if (animData.timer >= animData.frameTime) {
        animData.timer -= animData.frameTime;
        animData.currentFrame = (animData.currentFrame + 1) % animData.frameCount;

        player.setTextureRect(sf::IntRect(
            { animData.currentFrame * animData.frameSize.x, 0 },
            { animData.frameSize.x, animData.frameSize.y }
        ));


    }
}
