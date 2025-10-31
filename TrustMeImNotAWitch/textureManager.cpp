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

    AnimationData idle, run, jump, walk, fall, slide;

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

sf::Texture& textureManager::getTexture(const std::string& key)
{
    auto texture = textureList.find(key);
    if (texture == textureList.end())
        std::cout << "Impossible de trouver la texture";
    return texture->second;
}

textureManager* textureManager::instance = nullptr;
textureManager* managerText = textureManager::getInstance();