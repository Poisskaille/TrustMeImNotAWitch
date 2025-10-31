#include "sign.h"
#include "textureManager.h"

sign::sign(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size)
    : Ennemy('B', _texture, _pos, _size)
{
    sprite.setScale({ 3.f, 3.f });
    currentType = animationType::Idle;
}

void sign::update(float dT)
{
    // update animation normally
    managerText->updateEnemy(EnemyType::Sign, currentType, dT, sprite);

    // track animation time if we’re in a special state
    if (currentType == animationType::Readying)
    {
        animTimer += dT;
        const AnimationData* animData = &managerText->getSignAnimationData(currentType);
        float animDuration = animData->frameTime * animData->frameCount;

        if (animTimer >= animDuration)
        {
            currentType = animationType::ReadyIdle;  // auto-switch when done
            animTimer = 0.f;
        }
    }
    else if (currentType == animationType::Reflect)
    {
        animTimer += dT;
        const AnimationData* animData = &managerText->getSignAnimationData(currentType);
        float animDuration = animData->frameTime * animData->frameCount;

        if (animTimer >= animDuration)
        {
            animTypeSetter(animationType::Idle);  // Use setter to reset everything
        }
    }
}


void sign::animTypeSetter(animationType anim) {
    currentType = anim;  // Make sure currentType is updated!
    animTimer = 0.f;     // Reset the timer used in sign::update

    auto& animData = textureManager::getInstance()->getSignAnimationData(anim);
    animData.currentFrame = 0;
    animData.timer = 0.f;

    sprite.setTexture(animData.texture);
    sprite.setTextureRect(sf::IntRect(
        { 0, 0 },
        { animData.frameSize.x, animData.frameSize.y }
    ));
}


animationType sign::animTypeGetter() {
    return currentType;
}
