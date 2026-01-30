#include "HealthBar.h"
#include "GameWorld.h"
#include "Player.h"
#include "HUDComponent.h"

namespace XYZRoguelike
{
   HealthBar::HealthBar(const MyEngine::Vector2Df& position)
   {
      gameObject = MyEngine::GameWorld::Instance()->CreateGameObject("Health_bar");
      auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();
      transform->SetWorldPosition(position);

      auto renderer = gameObject->AddComponent<MyEngine::SpriteRendererComponent>();
      renderer->SetTexture(*MyEngine::ResourceSystem::Instance()->GetTextureMapElementShared("health_bar", 0));
      renderer->SetPixelSize(250, 200);
      if (auto* player = MyEngine::GameWorld::Instance()->FindObjectByName("Player"))
      {
         auto* playerT = player->GetComponent<MyEngine::TransformComponent>();
         playerHP = player->GetComponent<MyEngine::HealthComponent>();
         transform->SetParent(playerT);
         transform->SetLocalPosition({ -525.f, 295.f });

      }

      auto change = gameObject->AddComponent<MyEngine::HUDComponent>();
      change->Initialize();
      change->SetTargetStats(playerHP);
   }

}