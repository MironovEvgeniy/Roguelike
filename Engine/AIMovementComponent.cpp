#include "pch.h"
#include "AIMovementComponent.h"

namespace MyEngine
{
   AIMovementComponent::AIMovementComponent(GameObject* gameObject) : Component(gameObject)
   {
      transform = gameObject->GetComponent<TransformComponent>();
      spriteRenderer = gameObject->GetComponent<SpriteRendererComponent>();
   }

   void AIMovementComponent::Update(float deltaTime)
   {
      if (transform == nullptr || targetTransform == nullptr) return;

      Vector2Df currentPos = transform->GetWorldPosition();
      Vector2Df targetPos = targetTransform->GetWorldPosition();
      Vector2Df direction = targetPos - currentPos;

      float lenght = direction.GetLength();

      if (lenght > 0.001f)
      {
         Vector2Df normalized = Vector2Df(direction.x / lenght, direction.y / lenght);
         transform->MoveBy(normalized * speed * deltaTime);

         if (spriteRenderer)
         {
            spriteRenderer->FlipX(direction.x < 0);
         }
      }
   }

   void AIMovementComponent::Render()
   {
   }

   void AIMovementComponent::SetSpeed(float newSpeed)
   {

      speed = newSpeed;
   }

   void AIMovementComponent::SetTarget(GameObject* targetObject)
   {
      if (targetObject)
      {
         targetTransform = targetObject->GetComponent<TransformComponent>();
         if (targetTransform == nullptr)
         {
            std::cout << "There is no transform component in this target object." << std::endl;
         }
      }
   }
}