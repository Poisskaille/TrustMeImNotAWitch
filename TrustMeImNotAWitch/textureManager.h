#pragma once
#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <stdexcept>
#include <iostream>

enum class playerAnimation {
    Idle,
    Run,
    Jump,
    Fall,
    WallCling,
    Slide,
    Walk
};

enum class ForkAnim {
    Idle,
    DeathFront,
    DeathBack
};
enum class TorchAnim {
    Idle,
    DeathFront,
    DeathBack
};
enum class SignAnim {
    Idle,
    Readying,
    ReadyIdle,
    Reflect,
    DeathFront,
    DeathBack
};
enum class deathWallAnim {
    Idle,
};

enum class FireballAnim {
    Idle,
};

enum class EnemyType {
    Fork,
    Torch,
    Sign,
    DeathWall,
    Fireball
};

enum class animationType {
    Idle,
	DeathFront,
    DeathBack,
    Readying,
    ReadyIdle,
	Reflect
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
    std::unordered_map<ForkAnim, AnimationData> forkAnimations;
    std::unordered_map<TorchAnim, AnimationData> torchAnimations;
    std::unordered_map<SignAnim, AnimationData> signAnimations;
    std::unordered_map<deathWallAnim, AnimationData> wallAnimations;
    std::unordered_map<FireballAnim, AnimationData> fireBallAnimations;
    playerAnimation currentAnim = playerAnimation::Idle;

    std::vector<sf::Texture> textureList;

public:
    static textureManager* getInstance();
    sf::Texture grassTile;
    sf::Texture test;
    sf::Texture backgroundTexture;
    sf::Texture coins;
    void loadAll();
    void setplayerAnimation(playerAnimation anim, sf::Sprite& player);
    void updatePlayer(float deltaTime, sf::Sprite& player);
    sf::Texture& getEnemyTexture(EnemyType type, animationType animType);
    void setEnemyAnimation(EnemyType type, ForkAnim anim, sf::Sprite& enemy);
    void updateEnemy(EnemyType type, ForkAnim anim, float deltaTime, sf::Sprite& enemy);


};

extern textureManager* managerText;