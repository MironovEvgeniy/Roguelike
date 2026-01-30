#include "ArmorBar.h"
namespace XYZRoguelike
{
   ArmorBar::ArmorBar(const MyEngine::Vector2Df& position)
   {
      gameObject = MyEngine::GameWorld::Instance()->CreateGameObject("Armor_bar");
      auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();
      transform->SetWorldPosition(position);

      auto renderer = gameObject->AddComponent<MyEngine::SpriteRendererComponent>();
      renderer->SetTexture(*MyEngine::ResourceSystem::Instance()->GetTextureMapElementShared("armor_bar", 0));
      renderer->SetPixelSize(100, 100);

      if (auto* player = MyEngine::GameWorld::Instance()->FindObjectByName("Player"))
      {
         auto* playerT = player->GetComponent<MyEngine::TransformComponent>();
         playerArmor = player->GetComponent<MyEngine::HealthComponent>();
         transform->SetParent(playerT);
         transform->SetLocalPosition({ -610.f, 175.f });
      }
      auto change = gameObject->AddComponent<MyEngine::HUDComponent>();
      change->Initialize();
      change->SetTargetStats(playerArmor);
   }

}