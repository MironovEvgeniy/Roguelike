#include "pch.h"
#include "HealthComponent.h"
#include "GameObject.h"
#include "SpriteRendererComponent.h"
#include "GameWorld.h"
#include "SpriteColliderComponent.h"

namespace MyEngine
{
   HealthComponent::HealthComponent(GameObject* gameObject, float health, float armor)
      : Component(gameObject), maxHealth(health), currentHealth(health), armor(armor)
   {
   }

   void HealthComponent::TakeDamage(float damage)
   {
      damage -= armor;

      if (damage < 0)
      {
         damage = 0;
      }
      armor -= 1;

      if (armor < 0)
      {
         armor = 0;
         LOG_INFO("Armor was broken");
      }
      currentHealth -= damage;
      if (currentHealth < 0)
      {
         currentHealth = 0;
      }
      LOG_INFO("Hit:" + std::to_string(damage) + " damage,current health:" + std::to_string(currentHealth));
      hurtTimer = 0.40f;
      if (currentHealth <= 0)
      {
         isDead = true;
      }
   }
   void HealthComponent::Heal(float amount)
   {
      currentHealth += amount;
      if (currentHealth > maxHealth)
      {
         currentHealth = maxHealth;
      }
      LOG_INFO("Healed:" + std::to_string(amount) + "Health,current health:" + std::to_string(currentHealth));
   }

   void HealthComponent::AddArmor(float amount)
   {
      armor += amount;
      if (armor > maxArmor)
      {
         armor = maxArmor;
      }
      LOG_INFO("Picked up armor:" + std::to_string(amount) + ", current armor:" + std::to_string(armor));
   }

   void HealthComponent::Update(float deltaTime)
   {
      hurtTimer = std::max(0.f, hurtTimer - deltaTime);
   }
} 