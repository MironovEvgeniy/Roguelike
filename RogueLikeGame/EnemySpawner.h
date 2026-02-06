#pragma once

#include <vector>

namespace MyEngine
{
class GameObject;
}

namespace XYZRoguelike
{
class DeveloperLevel;

class EnemySpawner
{
  public:
    void Spawn(DeveloperLevel *level, MyEngine::GameObject *player, int enemyCount);

  private:
    int GetRandomFloorIndex(int max) const;
};
}