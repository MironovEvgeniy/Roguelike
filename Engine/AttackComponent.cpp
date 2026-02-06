#include "pch.h"
#include "AttackComponent.h"

namespace MyEngine
{
AttackComponent::AttackComponent(GameObject *gameObject, float attackPower) : Component(gameObject), attackPower(attackPower)

{
}

void AttackComponent::Update(float deltaTime)
{
}
void AttackComponent::Initialize(float newFramerate)
{
}
} // namespace MyEngine
