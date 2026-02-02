#pragma once

#include <GameWorld.h>
#include <SpriteRendererComponent.h>
#include <ResourceSystem.h>
#include "GameObject.h"

namespace XYZRoguelike
{
class Floor
{
  public:
    Floor(const MyEngine::Vector2Df &position, int textureMapIndex);

    MyEngine::GameObject *getGameObject() const
    {
        return gameObject;
    }
  private:
    MyEngine::GameObject *gameObject;
};
} 