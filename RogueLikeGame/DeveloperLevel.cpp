#include "DeveloperLevel.h"
#include "MazeGenerator.h"

using namespace MyEngine;

namespace XYZRoguelike
{
void DeveloperLevel::Start()
{
    if (player == nullptr)
    {
        player = std::make_unique<Player>(std::forward<MyEngine::Vector2Df>({(x_Offset + width) / 2 * sizeBlock, (y_Offset + height) / 2 * sizeBlock}));
    }

    healthBar = std::make_unique<HealthBar>(std::forward<MyEngine::Vector2Df>({width / 2 * 128.f, height / 2 * 128.f}));
    armorBar = std::make_unique<ArmorBar>(std::forward<MyEngine::Vector2Df>({width / 2 * 128.f, height / 2 * 128.f}));
    music = std::make_unique<Music>("GamePlaymusic");
}
void DeveloperLevel::Restart()
{
    Stop();
    Start();
}
void DeveloperLevel::Stop()
{
    if (levelExit != nullptr)
    {
        MyEngine::GameWorld::Instance()->DestroyGameObject(levelExit->GetGameObject());
    }
    if (player != nullptr)
    {
        MyEngine::GameWorld::Instance()->DestroyGameObject(player->GetGameObject());
        player.reset();
        //player->GetGameObject()->GetComponent<TransformComponent>()->SetWorldPosition({(x_Offset + width) / 2 * sizeBlock, (y_Offset + height) / 2 * sizeBlock});
    }
    for (auto it = walls.begin(); it != walls.end(); ++it)
    {
        MyEngine::GameWorld::Instance()->DestroyGameObject(it->get()->transform->GetGameObject());
    }
    walls.clear();
    for (auto it = floors.begin(); it != floors.end(); ++it)
    {
        MyEngine::GameWorld::Instance()->DestroyGameObject(it->get()->transform->GetGameObject());
    }
    floors.clear();

    while (true)
    {
        std::vector<MyEngine::GameObject *> aiEnemy = MyEngine::GameWorld::Instance()->GetGameObjectsByComponent<AIMovementComponent>();
        if (!aiEnemy.empty())
        {
            for (auto it = aiEnemy.begin(); it != aiEnemy.end(); ++it)
            {
                MyEngine::GameWorld::Instance()->DestroyGameObject(*it);
            }
            break;
        }
        else
        {
            break;
        }
    }
}
void DeveloperLevel::CreateExit()
{
    int side = std::rand() % 4;
    int exitX, exitY = 0;

    switch (side)
    {
    case 0:                                    // Top screen (y = 0)
        exitX = 1 + std::rand() % (width - 1); // not angel
        exitY = 0;
        break;
    case 1: // Right screen (x = width - 1)
        exitX = width;
        exitY = 1 + std::rand() % (height - 1);
        break;
    case 2: // Down screen (y = height - 1)
        exitX = 1 + std::rand() % (width - 1);
        exitY = height;
        break;
    case 3: // Left screen (x = 0)
        exitX = 0;
        exitY = 1 + std::rand() % (height - 1);
        break;
    }

    levelExit = std::make_unique<LevelExit>(MyEngine::Vector2Df{(exitX + 0.5f) * sizeBlock, (exitY + 0.5f) * sizeBlock});

    for (auto it = walls.begin(); it != walls.end(); ++it)
    {
        auto &wall = *it; // unique_ptr<Wall>
        if (wall.get()->transform->GetWorldPosition().x == (exitX + 0.5f) * sizeBlock &&
            wall.get()->transform->GetWorldPosition().y == (exitY + 0.5f) * sizeBlock)
        {
            MyEngine::GameWorld::Instance()->DestroyGameObject(wall.get()->transform->GetGameObject());
            it = walls.erase(it);
            break;
        }
    }
}

void DeveloperLevel::AddWallTheBorder()
{
    bool floorEmpty = floors.empty();
    for (int y = 0; y < height + 1; y++)
    {
        for (int x = 0; x < width + 1; x++)
        {
            // if not wall place
            if (x != 0 && x != width && y != 0 && y != height && floorEmpty)
            {
                floors.push_back(std::make_unique<Floor>(
                    std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                         std::forward<int>(0)));
            }

            // Left-bottom angle screen
            if (x == 0 && y == 0)
            {
                walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                       std::forward<int>(25)));
            }

            // Right-bottom angle screen
            if (x == width && y == 0)
            {
                walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                       std::forward<int>(27)));
            }

            // Left-top angle screen
            if (x == 0 && y == height)
            {
                walls.push_back(std::make_unique<Wall>(
                    std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                       std::forward<int>(1)));
            }

            // Right-top angle screen
            if (x == width && y == height)
            {
                walls.push_back(std::make_unique<Wall>(
                    std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                       std::forward<int>(3)));
            }

            // Left screen
            if (x == 0 && y != height && y != 0)
            {
                if (floorEmpty)
                {
                    floors.push_back(std::make_unique<Floor>(
                        std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                             std::forward<int>(18)));
                }
                walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                       std::forward<int>(12)));
            }

            // Right screen
            if (x == width && y != height && y != 0)
            {
                if (floorEmpty)
                {
                    floors.push_back(std::make_unique<Floor>(
                        std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                             std::forward<int>(19)));
                }
                walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                       std::forward<int>(12)));
            }

            // Bottom screen
            if (y == 0 && x != width && x != 0)
            {
                walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                       std::forward<int>(38)));
            }

            // Top screen
            if (y == height && x != width && x != 0)
            {
                walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({x_Offset + (x + 0.5f) * sizeBlock, y_Offset + (y + 0.5f) * sizeBlock}),
                                                       std::forward<int>(38)));
            }
        }
    }
}
void DeveloperLevel::GenerateMaze()
{
    int generatWidth = width - 1;
    int generatHeight = height - 1;
    int generatOffsetWidth = 1;
    int generatOffsetHeight = 1;
    MazeGenerator mazeGenerator(generatWidth, generatHeight, this, generatOffsetWidth, generatOffsetHeight);
    mazeGenerator.Generate();
}
} // namespace XYZRoguelike