#pragma once
#include "Component.h"
#include "HealthComponent.h"
#include "GameObject.h"

namespace MyEngine
{
class AttackComponent : public Component
{
  public:
    void Initialize(float newFramerate);

    AttackComponent(GameObject *gameObject, float attackPower);

    float GetAttackPower() const
    {
        return attackPower;
    }
    void SetAttackPower(float newAttackPower)
    {
        attackPower = newAttackPower;
    }
    void Update(float deltaTime) override;
    void Render() override
    {
    }
    void Attack(GameObject *target)
    {
        if (!target)
        {
            return;
        }
        auto targetHealthComponent = target->GetComponent<HealthComponent>();
        if (targetHealthComponent)
        {
            float damage = attackPower;
            targetHealthComponent->TakeDamage(damage);
        }
    }

  private:
    float attackPower = 0.f;
};
} // namespace MyEngine