#include "EnemySpawner.h"
#include "DeveloperLevel.h"
#include "Enemy.h"

#include <cstdlib>

namespace XYZRoguelike
{
void EnemySpawner::Spawn(DeveloperLevel *level, MyEngine::GameObject *player, int enemyCount)
{
    if (level->floors.empty())
        return;

    for (int i = 0; i < enemyCount; ++i)
    {
        int index = GetRandomFloorIndex((int)level->floors.size());
        const auto &floor = level->floors[index];

        MyEngine::Vector2Df spawnPos = floor->getGameObject()->GetComponent<MyEngine::TransformComponent>()->GetWorldPosition();

        std::make_unique<Enemy>(spawnPos, player);
    }
}

int EnemySpawner::GetRandomFloorIndex(int max) const
{
    return std::rand() % max;
}
}