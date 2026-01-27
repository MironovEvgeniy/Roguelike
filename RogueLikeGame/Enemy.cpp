#include "Enemy.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>
//#include <SpriteDirectionComponent.h>
#include <AIMovementComponent.h>


namespace XYZRoguelike
{
   Enemy::Enemy(const MyEngine::Vector2Df& position, MyEngine::GameObject* target)
   {
      gameObject = MyEngine::GameWorld::Instance()->CreateGameObject("Enemy");
      auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();
      transform->SetWorldPosition(position);

      auto renderer = gameObject->AddComponent<MyEngine::SpriteRendererComponent>();
      renderer->SetTexture(*MyEngine::ResourceSystem::Instance()->GetTextureMapElementShared("cobald_idle", 0));
      renderer->SetPixelSize(100, 120);

      auto movement = gameObject->AddComponent<MyEngine::AIMovementComponent>();
      movement->SetSpeed(100.f);
      movement->SetTarget(target);
      auto rigidbody = gameObject->AddComponent<MyEngine::RigidbodyComponent>();
      rigidbody->SetKinematic(false);
      auto collider = gameObject->AddComponent<MyEngine::SpriteColliderComponent>();
      collider->SetPadding({ 50.f, 0.f });
   }

}