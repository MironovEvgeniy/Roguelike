#pragma once

#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "GameObject.h"
#include "Vector.h"

namespace XYZRoguelike
{
class Player
{
  public:
    Player(const MyEngine::Vector2Df &position);
    MyEngine::GameObject* GetGameObject()
    {
        return gameObject;
    }

  private:
    MyEngine::GameObject *gameObject;
};
} // namespace XYZRoguelike