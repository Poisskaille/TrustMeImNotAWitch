#include "textureManager.h"


textureManager* textureManager::getInstance()
{
    if (instance == nullptr) { instance = new textureManager(); }
    return instance;
}
 
void textureManager::loadAll() {

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../assets/background.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/background.png");
    }
    textureList.insert({ "background",backgroundTexture });

    sf::Texture grassTile;
    if (!grassTile.loadFromFile("../assets/tiles/ground.png")) {
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    }
    textureList.insert({ "grass",grassTile });

    sf::Texture coins;
    if (!coins.loadFromFile("../assets/coin.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "coin",coins });

    sf::Texture playButton;
        if(!playButton.loadFromFile("../assets/UI/menu/playButton.png"))
            throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "normalPlay",playButton });


    sf::Texture playButtonHover;
    if(!playButtonHover.loadFromFile("../assets/UI/menu/playButtonHover.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "hoverPlay",playButtonHover });

    sf::Texture exitButton;
    if(!exitButton.loadFromFile("../assets/UI/menu/exitButton.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "normalExit",exitButton });

    sf::Texture exitButtonHover;
    if(!exitButtonHover.loadFromFile("../assets/UI/menu/exitButtonHover.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "hoverExit",exitButtonHover });

    sf::Texture nottaHat;
    if(!nottaHat.loadFromFile("../assets/UI/menu/nottaHat.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "nottaHat",nottaHat });

    sf::Texture menu;
    if (!menu.loadFromFile("../assets/UI/MainMenu.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "menu",menu });

    sf::Texture wof;
    if (!wof.loadFromFile("../assets/wallofflesh.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "walldeath",wof });

    sf::Texture fireball;
    if(!fireball.loadFromFile("../assets/fireball1.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "fireball",fireball });

    sf::Texture barricade;
    if(!barricade.loadFromFile("../assets/tiles/obstacles/barricade.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "barricade",barricade });

    sf::Texture dirt;
    if (!dirt.loadFromFile("../assets/tiles/dirt.png"))
        throw std::runtime_error("Failed to load texture: ../assets/tiles/ground.png");
    textureList.insert({ "dirt",dirt });

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
    forkIdle.frameTime = 0.10f;

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
    signReflect.frameTime = 0.08f;


    signAnimations[SignAnim::Idle] = signIdle;
    signAnimations[SignAnim::DeathFront] = signDeathFront;
    signAnimations[SignAnim::DeathBack] = signDeathBack;
    signAnimations[SignAnim::Readying] = signReadying;
    signAnimations[SignAnim::ReadyIdle] = signReadyIdle;
    signAnimations[SignAnim::Reflect] = signReflect;
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
        break;
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
        break;
    case EnemyType::DeathWall:
		if (animType == animationType::Idle)
        return wallAnimations[deathWallAnim::Idle].texture;
        break;
    default:
        throw std::runtime_error("Unknown EnemyType in getEnemyTexture()");
        break;
    }
}

void textureManager::updateEnemy(EnemyType type, animationType animType, float deltaTime, sf::Sprite& enemy)
{
    AnimationData* animData = nullptr;

    switch (type) {
    case EnemyType::Fork:
        switch (animType) {
        case animationType::Idle:
            animData = &forkAnimations[ForkAnim::Idle];
            break;
        case animationType::DeathBack:
            animData = &forkAnimations[ForkAnim::DeathBack];
            break;
        case animationType::DeathFront:
            animData = &forkAnimations[ForkAnim::DeathFront];
            break;
        default:
            throw std::runtime_error("Ennemy fork doesn't have such animType");
            break;
        }
        break;
    case EnemyType::Torch:
        switch (animType) {
        case animationType::Idle:
            animData = &torchAnimations[TorchAnim::Idle];
            break;
        case animationType::DeathBack:
            animData = &torchAnimations[TorchAnim::DeathBack];
            break;
        case animationType::DeathFront:
            animData = &torchAnimations[TorchAnim::DeathFront];
            break;
        default:
            throw std::runtime_error("Ennemy Torch doesn't have such animType");
        }
        break;
    case EnemyType::Sign:
        switch (animType) {
        case animationType::Idle:
            animData = &signAnimations[SignAnim::Idle];
            break;
        case animationType::DeathBack:
            animData = &signAnimations[SignAnim::DeathBack];
            break;
        case animationType::DeathFront:
            animData = &signAnimations[SignAnim::DeathFront];
            break;
        case animationType::Readying:
            animData = &signAnimations[SignAnim::Readying];
            break;
        case animationType::ReadyIdle:
            animData = &signAnimations[SignAnim::ReadyIdle];
            break;
        case animationType::Reflect:
            animData = &signAnimations[SignAnim::Reflect];
            break;
        default:
            throw std::runtime_error("Ennemy Sign doesn't have such animType");
        }
        break;
    case EnemyType::Fireball:
        switch (animType) {
        case animationType::Idle:
            animData = &fireBallAnimations[FireballAnim::Idle];
            break;
        default:
            throw std::runtime_error("Fireball doesn't have such animType");
        }
        break;
    case EnemyType::DeathWall:
        switch (animType) {
        case animationType::Idle:
            animData = & wallAnimations[deathWallAnim::Idle];
            break;
        default:
            throw std::runtime_error("Ennemy WOF doesn't have such animType");
        }
        break;
    default:
        break;
    }


    
    animData->timer += deltaTime;

    if (animData->timer >= animData->frameTime)
    {
        animData->timer -= animData->frameTime;
        animData->currentFrame = (animData->currentFrame + 1) % animData->frameCount;

        enemy.setTextureRect(sf::IntRect(
            { animData->currentFrame * animData->frameSize.x, 0 },
            { animData->frameSize.x, animData->frameSize.y }
        ));
    }
}




sf::Texture& textureManager::getTexture(const std::string& key)
{
    auto texture = textureList.find(key);
    if (texture == textureList.end())
        std::cout << "Impossible de trouver la texture";
    return texture->second;
}

AnimationData& textureManager::getSignAnimationData(animationType anim) {
    switch (anim) {
    case animationType::Idle:
        return signAnimations.at(SignAnim::Idle);
        break;
    case animationType::DeathBack:
        return signAnimations.at(SignAnim::DeathBack);
        break;
    case animationType::DeathFront:
        return signAnimations.at(SignAnim::DeathFront);
        break;
    case animationType::Readying:
        return signAnimations.at(SignAnim::Readying);
        break;
    case animationType::ReadyIdle:
        return signAnimations.at(SignAnim::ReadyIdle);
        break;
    case animationType::Reflect:
        return signAnimations.at(SignAnim::Reflect);
        break;
    default:
        throw std::runtime_error("Invalid animationType in getSignAnimationData");
    }
    
}

textureManager* textureManager::instance = nullptr;
textureManager* managerText = textureManager::getInstance();