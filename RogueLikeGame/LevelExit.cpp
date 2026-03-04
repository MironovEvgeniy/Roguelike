
#include "GameSettings.h"

#include "LevelExit.h"
#include "LevelManager.h"
#include <GameWorld.h>
#include <SpriteColliderComponent.h>
#include <RigidbodyComponent.h>
#include <ResourceSystem.h>

namespace XYZRoguelike
{
LevelExit::LevelExit(const MyEngine::Vector2Df position)
{
    gameObject = MyEngine::GameWorld::Instance()->CreateGameObject("Exit");
    auto body = gameObject->AddComponent<MyEngine::RigidbodyComponent>();
    body->SetKinematic(true);
    auto renderer = gameObject->AddComponent<MyEngine::SpriteRendererComponent>();
    renderer->SetTexture(*MyEngine::ResourceSystem::Instance()->GetTextureShared("ball"));
    renderer->SetPixelSize(128, 128);
    auto collider = gameObject->AddComponent<MyEngine::SpriteColliderComponent>();
    auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();
    transform->SetWorldPosition(position);
    collider->SubscribeCollision(std::bind(&LevelExit::Transition, this, std::placeholders::_1));
}

void LevelExit::Transition(MyEngine::Collision collision)
{
    auto player = collision.first->GetGameObject();
    if (player)
    {
        isDoorClosed = false;
    }

    // XYZEngine::GameWorld::Instance()->DestroyGameObject(this->gameObject);
    if (!isDoorClosed)
    {
        LevelManager::Instance()->LoadRandomLevels();
    }
    //}
}
MyEngine::GameObject *LevelExit::GetGameObject()
{
    return gameObject;
}

void LevelExit::SetIsDoorClosed(bool isClosed)
{
    isDoorClosed = isClosed;
}

} // namespace XYZRoguelike