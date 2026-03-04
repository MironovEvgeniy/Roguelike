#include "pch.h"
#include "LevelManager.h"
#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
namespace XYZRoguelike
{

LevelManager *LevelManager::Instance()
{
    static LevelManager levels;
    return &levels;
}

void XYZRoguelike::LevelManager::LoadRandomLevels()
{
    ++currentLevel;
    if (level == nullptr)
    {
        level = std::make_unique<DeveloperLevel>();
    }
    level->Stop();
    level->AddWallTheBorder();
    level->GenerateMaze();
    level->CreateExit();
    level->Start();
    std::srand(std::time(nullptr));
    
    level->AddSpawner();
    
}

} // namespace XYZRoguelike