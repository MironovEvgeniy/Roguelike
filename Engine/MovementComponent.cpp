#include "pch.h"
#include "MovementComponent.h"

MyEngine::MovementComponent::MovementComponent(GameObject *gameObject) : Component(gameObject)
{
    input = gameObject->GetComponent<InputComponent>();
    transform = gameObject->GetComponent<TransformComponent>();

    if (input == nullptr)
    {
        std::cout << "Need input component for movement" << std::endl;
        gameObject->RemoveComponent(this);
    }
}

void MyEngine::MovementComponent::Update(float deltaTime)
{
    float xAxis = input->GetHorizontalAxis();
    float yAxis = input->GetVerticalAxis();

    transform->MoveBy(speed * deltaTime * Vector2Df{xAxis, yAxis});

    acceleration = transform->GetWorldPosition() - previousPosition;
    previousPosition = transform->GetWorldPosition();
}

void MyEngine::MovementComponent::Render()
{
}

void MyEngine::MovementComponent::SetSpeed(float newSpeed)
{
    speed = newSpeed;
}

float MyEngine::MovementComponent::GetSpeed() const
{
    return speed;
}

float MyEngine::MovementComponent::GetAccelerationSquared() const
{
    return acceleration.x * acceleration.x + acceleration.y * acceleration.y;
}