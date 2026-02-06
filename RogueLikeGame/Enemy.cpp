#include "Enemy.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>
#include <SpriteDirectionComponent.h>
#include <AIMovementComponent.h>
#include <AIAnimationComponent.h>
#include <AttackComponent.h>

namespace XYZRoguelike
{
Enemy::Enemy(const MyEngine::Vector2Df &position, MyEngine::GameObject *target)
{
    gameObject = MyEngine::GameWorld::Instance()->CreateGameObject("Enemy");
    auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();
    transform->SetWorldPosition(position);

    auto renderer = gameObject->AddComponent<MyEngine::SpriteRendererComponent>();
    renderer->SetTexture(*MyEngine::ResourceSystem::Instance()->GetTextureMapElementShared("enemy_idle", 0));
    renderer->SetPixelSize(100, 120);

    auto movement = gameObject->AddComponent<MyEngine::AIMovementComponent>();
    movement->SetSpeed(100.f);
    movement->SetTarget(target);
    auto rigidbody = gameObject->AddComponent<MyEngine::RigidbodyComponent>();
    rigidbody->SetKinematic(false);
    auto healthComponent = gameObject->AddComponent<MyEngine::HealthComponent>(10.f, 0.f);
    auto AIAnimation = gameObject->AddComponent<MyEngine::AIAnimationComponent>();
    AIAnimation->Initialize(6.f, 5.f);
    auto collider = gameObject->AddComponent<MyEngine::SpriteColliderComponent>();
    collider->SetPadding({50.f, 0.f});

    auto attack = gameObject->AddComponent<MyEngine::AttackComponent>(10.f);
}

} // namespace XYZRoguelike