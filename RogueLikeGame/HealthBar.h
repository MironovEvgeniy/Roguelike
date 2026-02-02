#pragma once
#include "GameObject.h"
#include "GameWorld.h"
#include "RenderSystem.h"
#include "SpriteRendererComponent.h"
#include "Vector.h"
#include "ResourceSystem.h"
#include "HealthComponent.h"

namespace XYZRoguelike

{
class HealthBar
{
  public:
    HealthBar(const MyEngine::Vector2Df &position);

  private:
    MyEngine::GameObject *gameObject;
    MyEngine::HealthComponent *playerHP;
};

} // namespace XYZRoguelike