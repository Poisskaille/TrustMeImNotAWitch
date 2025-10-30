#include "textureManager.h"


textureManager* textureManager::getInstance()
{
    if (instance == nullptr) { instance = new textureManager(); }
    return instance;
}
 
void textureManager::loadAll() {
    if (!test.loadFromFile("../assets/test.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/test.png");
    }
    if (!backgroundTexture.loadFromFile("../assets/background.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/background.png");
    }
    if (!grassTile.loadFromFile("../assets/tiles/ground.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    }

    if (!coins.loadFromFile("../assets/coin.png"));
    std::cout << "CACA" << '\n';

    AnimationData idle, run, jump, walk, fall, slide;
	AnimationData fireBallIdle ,forkIdle, torchIdle, signIdle, signReadying, signReadyIdle, signReflect, deathWallIdle;
	AnimationData forkDeathFront, forkDeathBack, torchDeathFront, torchDeathBack, signDeathFront, signDeathBack;

    // Example: all spritesheets are horizontal strips
    if (!idle.texture.loadFromFile("../assets/character/notta_Idle.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/notta_Idle.png");
    }
    idle.frameCount = 8;
    idle.frameSize = { 32, 32 };

    if (!run.texture.loadFromFile("../assets/character/notta_Run.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/notta_Run.png");
    }
    run.frameCount = 18;
    run.frameSize = { 32, 32 };
    run.frameTime = 0.1f;

    if (!walk.texture.loadFromFile("../assets/character/notta_Walk.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/notta_Walk.png");
    }
    walk.frameCount = 6;
    walk.frameSize = { 32, 32 };
	walk.frameTime = 0.15f; //Ajuste la vitesse de l'animation de marche

    if (!jump.texture.loadFromFile("../assets/character/notta_Jump.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/notta_Jump.png");
    }
    jump.frameCount = 8;
    jump.frameSize = { 32, 32 };
    jump.frameTime = 0.10f;

    if (!fall.texture.loadFromFile("../assets/character/notta_Fall.png")) {
        throw std::runtime_error("Failed to load texture : ../assets/character/notta_Fall.png");
    }
    fall.frameCount = 2;
    fall.frameSize = { 32,32 };
    fall.frameTime = 0.20f;

    if (!slide.texture.loadFromFile("../assets/character/notta_Slide.png")) {
        throw std::runtime_error("Failed to load texture : ../assets/character/notta_Slide.png");
    }
    slide.frameCount = 4;
    slide.frameSize = { 32,32 };
    slide.frameTime = 0.10f;


    playerAnimations[playerAnimation::Idle] = idle;
    playerAnimations[playerAnimation::Run] = run;
    playerAnimations[playerAnimation::Jump] = jump;
	playerAnimations[playerAnimation::Walk] = walk;
    playerAnimations[playerAnimation::Fall] = fall;
    playerAnimations[playerAnimation::Slide] = slide;

    
    if (!forkIdle.texture.loadFromFile("../assets/character/enemies/fork/fork_Idle.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/fork/fork_Idle.png");
    }
    forkIdle.frameCount = 2;
    forkIdle.frameSize = { 32, 32 };

    if (!forkDeathBack.texture.loadFromFile("../assets/character/enemies/fork/forkDeathBackHit.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/fork/forkDeathBackHit.png");
    }
    forkDeathBack.frameCount = 4;
    forkDeathBack.frameSize = { 32, 32 };

    if (!forkDeathFront.texture.loadFromFile("../assets/character/enemies/fork/forkDeathFrontHit.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/fork/forkDeathFrontHit.png");
    }
    forkDeathFront.frameCount = 4;
    forkDeathFront.frameSize = { 32, 32 };


	forkAnimations[ForkAnim::Idle] = forkIdle;
    forkAnimations[ForkAnim::DeathFront] = forkDeathFront;
    forkAnimations[ForkAnim::DeathBack] = forkDeathBack;

    if (!torchIdle.texture.loadFromFile("../assets/character/enemies/fire/fire.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/fire/fire.png");
    }
    torchIdle.frameCount = 2;
    torchIdle.frameSize = { 32, 32 };

    if (!torchDeathBack.texture.loadFromFile("../assets/character/enemies/fire/fireDeathBackhit.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/fire/fireDeathBackhit.png");
    }
    torchDeathBack.frameCount = 4;
    torchDeathBack.frameSize = { 32, 32 };

    if (!torchDeathFront.texture.loadFromFile("../assets/character/enemies/fire/fireDeathFronthit.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/fire/fireDeathFronthit.png");
    }
    torchDeathFront.frameCount = 4;
    torchDeathFront.frameSize = { 32, 32 };

    if (!fireBallIdle.texture.loadFromFile("../assets/character/enemies/fire/fire_projectile.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/fire/fire_projectile.png");
    }
    fireBallIdle.frameCount = 2;
    fireBallIdle.frameSize = { 16, 16 };


    torchAnimations[TorchAnim::Idle] = torchIdle;
    torchAnimations[TorchAnim::DeathFront] = torchDeathFront;
    torchAnimations[TorchAnim::DeathBack] = torchDeathBack;
    fireBallAnimations[FireballAnim::Idle] = fireBallIdle;

    if (!signIdle.texture.loadFromFile("../assets/character/enemies/sign/sign_Idle.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/sign/sign_Idle.png");
    }
    signIdle.frameCount = 2;
    signIdle.frameSize = { 32, 32 };

    if (!signDeathBack.texture.loadFromFile("../assets/character/enemies/sign/signDeathBackhit.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/sign/signDeathBackhit.png");
    }
    signDeathBack.frameCount = 4;
    signDeathBack.frameSize = { 32, 32 };

    if (!signDeathFront.texture.loadFromFile("../assets/character/enemies/sign/signDeathFronthit.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/sign/signDeathFronthit.png");
    }
    signDeathFront.frameCount = 4;
    signDeathFront.frameSize = { 32, 32 };

    if (!signReadying.texture.loadFromFile("../assets/character/enemies/sign/sign_Ready.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/sign/sign_Ready.png");
    }
    signReadying.frameCount = 4;
    signReadying.frameSize = { 32, 32 };

    if (!signReadyIdle.texture.loadFromFile("../assets/character/enemies/sign/sign_ReadyIdle.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/sign/sign_ReadyIdle.png");
    }
    signReadyIdle.frameCount = 2;
    signReadyIdle.frameSize = { 32, 32 };

    if (!signReflect.texture.loadFromFile("../assets/character/enemies/sign/sign_Reflect.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/character/enemies/sign/sign_Reflect.png");
    }
    signReflect.frameCount = 8;
    signReflect.frameSize = { 32, 32 };


    torchAnimations[TorchAnim::Idle] = torchIdle;
    torchAnimations[TorchAnim::DeathFront] = torchDeathFront;
    torchAnimations[TorchAnim::DeathBack] = torchDeathBack;
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

void textureManager::updatePlayer(float deltaTime, sf::Sprite& player) { 
    auto& animData = playerAnimations[currentAnim]; animData.timer += deltaTime;
    if (animData.timer >= animData.frameTime) {
        animData.timer -= animData.frameTime;
        animData.currentFrame = (animData.currentFrame + 1) % animData.frameCount;

        player.setTextureRect(sf::IntRect(
            { animData.currentFrame * animData.frameSize.x, 0 },
            { animData.frameSize.x, animData.frameSize.y }
        ));


    }
}

sf::Texture& textureManager::getEnemyTexture(EnemyType type, animationType animType)
{
    switch (type)
    {
    case EnemyType::Fork:
		if (animType == animationType::Idle)
            return forkAnimations[ForkAnim::Idle].texture;
		else if (animType == animationType::DeathFront)
			return forkAnimations[ForkAnim::DeathFront].texture;
		else if (animType == animationType::DeathBack)
            return forkAnimations[ForkAnim::DeathBack].texture;
		break;
    case EnemyType::Torch:
		if (animType == animationType::Idle)
            return torchAnimations[TorchAnim::Idle].texture;
        else if (animType == animationType::DeathFront)
            return torchAnimations[TorchAnim::DeathFront].texture;
        else if (animType == animationType::DeathBack)
			return torchAnimations[TorchAnim::DeathBack].texture;
    case EnemyType::Sign:
        if (animType == animationType::Idle)
            return signAnimations[SignAnim::Idle].texture;
        else if (animType == animationType::DeathFront)
            return signAnimations[SignAnim::DeathFront].texture;
        else if (animType == animationType::DeathBack)
            return signAnimations[SignAnim::DeathBack].texture;
        else if (animType == animationType::Readying)
            return signAnimations[SignAnim::Readying].texture;
        else if (animType == animationType::ReadyIdle)
            return signAnimations[SignAnim::ReadyIdle].texture;
        else if (animType == animationType::Reflect)
			return signAnimations[SignAnim::Reflect].texture;
    case EnemyType::DeathWall:
		if (animType == animationType::Idle)
        return wallAnimations[deathWallAnim::Idle].texture;
    default:
        throw std::runtime_error("Unknown EnemyType in getEnemyTexture()");
    }
}

//void textureManager::setEnemyAnimation(EnemyType type, ForkAnim anim, sf::Sprite& enemy)
//{
//    auto& animData = forkAnimations[anim];
//    animData.currentFrame = 0;
//    animData.timer = 0.0f;
//
//    enemy.setTexture(animData.texture);
//    enemy.setTextureRect(sf::IntRect(
//        { animData.currentFrame * animData.frameSize.x, 0 },
//        { animData.frameSize.x, animData.frameSize.y }
//    ));
//}

void textureManager::updateEnemy(EnemyType type, ForkAnim anim, float deltaTime, sf::Sprite& enemy)
{
    auto& animData = forkAnimations[anim];
    animData.timer += deltaTime;

    if (animData.timer >= animData.frameTime)
    {
        animData.timer -= animData.frameTime;
        animData.currentFrame = (animData.currentFrame + 1) % animData.frameCount;

        enemy.setTextureRect(sf::IntRect(
            { animData.currentFrame * animData.frameSize.x, 0 },
            { animData.frameSize.x, animData.frameSize.y }
        ));
    }
}




textureManager* textureManager::instance = nullptr;
textureManager* managerText = textureManager::getInstance();