#pragma once
#include "GameObject.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "ResourceSystem.h"
#include "HealthComponent.h"
#include "HUDComponent.h"

namespace XYZRoguelike
{
class ArmorBar
{
  public:
    ArmorBar(const MyEngine::Vector2Df &position);

  private:
    MyEngine::GameObject *gameObject;
    MyEngine::HealthComponent *playerArmor;
};

} // namespace XYZRoguelike