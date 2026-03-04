#pragma once

#include <iostream>
#include <array>
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Music.h"
#include "Wall.h"
#include "Floor.h"
// #include "HealthPickup.h"
// #include "ArmorPickup.h"
#include "HealthBar.h"
#include "ArmorBar.h"
#include "AudioSFX.h"
#include "LevelExit.h"
#include "EnemySpawner.h"


using namespace MyEngine;

namespace XYZRoguelike
{
class DeveloperLevel : public Scene
{
  public:
    void Start() override;
    void Restart() override;
    void Stop() override;
    void AddWallTheBorder();
    void CreateExit();
    void GenerateMaze();

    void AddSpawner()
    {
        auto enemySpawner = std::make_shared<EnemySpawner>();
        enemySpawner->Spawn(this, player->GetGameObject(), 3);
    }
    /*oid AddEnemy()
    {
        auto enemy = std::make_shared<Enemy>(MyEngine::Vector2Df({350.f, 350.f}), player);
    }*/

    std::vector<std::unique_ptr<Wall>> walls;
    std::vector<std::unique_ptr<Floor>> floors;
    int width = 17;
    int height = 17;
  private:
    std::unique_ptr<LevelExit> levelExit = nullptr;
    std::unique_ptr<Player> player = nullptr;
    std::unique_ptr<Music> music = nullptr;
   
    float sizeBlock = 128.f;
    int x_Offset = 0;
    int y_Offset = 0;
    int numSpawners = 0;
    std::unique_ptr<HealthBar> healthBar;
    std::unique_ptr<ArmorBar> armorBar;
};
} 