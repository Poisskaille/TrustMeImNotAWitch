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

        // grab the animation data from textureManager
        const AnimationData& animData = managerText->getSignAnimationData(SignAnim::Readying);
        float animDuration = animData.frameTime * animData.frameCount;

        if (animTimer >= animDuration)
        {
            // switch automatically to ReadyIdle when done
            currentType = animationType::ReadyIdle;
            animTimer = 0.f;
        }
    }
}

void sign::animTypeSetter(animationType type)
{
    currentType = type;
    animTimer = 0.f;
}
