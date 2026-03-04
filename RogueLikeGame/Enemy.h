#pragma once

#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "AIMovementComponent.h"
#include "GameObject.h"

namespace XYZRoguelike
{
class Enemy
{
  public:
    Enemy(const MyEngine::Vector2Df &position, MyEngine::GameObject *target);
    MyEngine::GameObject *GetGameObject()
    {
        return gameObject;
    }

  private:
    MyEngine::GameObject *gameObject;
};
} // namespace XYZRoguelike