#pragma once

#include <GameObject.h>
#include <SpriteRendererComponent.h>
#include <SpriteColliderComponent.h>
namespace XYZRoguelike
{
class LevelExit
{
  public:
    LevelExit(const MyEngine::Vector2Df position);
    void Transition(MyEngine::Collision collision);
    MyEngine::GameObject *GetGameObject();
    void SetIsDoorClosed(bool isClosed);

  private:
    MyEngine::GameObject *gameObject;
    bool isDoorClosed = false;
};
} // namespace XYZRoguelike