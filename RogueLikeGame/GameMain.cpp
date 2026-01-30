
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "DeveloperLevel.h"
#include "Matrix2D.h"

using namespace XYZRoguelike;

int main()
{
	MyEngine::RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "XYZRoguelike"));

   ResourceSystem::Instance()->LoadTextureMap("player_attack", "Resources/Textures/Attack.png", { 100, 64 }, 9, false);
   ResourceSystem::Instance()->LoadTextureMap("player_hurt", "Resources/Textures/Hurt.png", { 100, 64 }, 4, false);
   ResourceSystem::Instance()->LoadTextureMap("player_walking", "Resources/Textures/Walking.png", { 100, 64 }, 7, false);
   ResourceSystem::Instance()->LoadTextureMap("player_idle", "Resources/Textures/Idle.png", { 100, 64 }, 4, false);
   ResourceSystem::Instance()->LoadTextureMap("player_dying", "Resources/Textures/Dying.png", { 100, 64 }, 6, false);
   ResourceSystem::Instance()->LoadTextureMap("level_walls", "Resources/Textures/Wall.png", { 16, 16 }, 48, false);
   ResourceSystem::Instance()->LoadTextureMap("enemy_idle", "Resources/Textures/idleEnemy.png", { 148, 96 }, 6, false);
   ResourceSystem::Instance()->LoadTextureMap("enemy_walking", "Resources/Textures/RUN.png", { 148, 96 }, 8, false);
   ResourceSystem::Instance()->LoadTextureMap("enemy_attacking", "Resources/Textures/Attack1.png", { 158, 96 }, 5, false);
   ResourceSystem::Instance()->LoadTextureMap("health_item", "Resources/Textures/Spritesheet.png", { 50, 114 }, 10, false);
   ResourceSystem::Instance()->LoadTextureMap("armor_item", "Resources/Textures/armor.png", { 32, 32 }, 1, false);
   ResourceSystem::Instance()->LoadTextureMap("health_bar", "Resources/Textures/HealthBar.png", { 700, 200 }, 10, false);
   ResourceSystem::Instance()->LoadTextureMap("armor_bar", "Resources/Textures/armorBar.png", { 32, 32 }, 1, false);

   ResourceSystem::Instance()->LoadSound("GamePlaymusic", "Resources/Sounds/trapped.wav");
   ResourceSystem::Instance()->LoadSound("PlayerHurt", "Resources/Sounds/playerHurt.wav");
   ResourceSystem::Instance()->LoadSound("EnemyDeath", "Resources/Sounds/Enemy_death.wav");
   ResourceSystem::Instance()->LoadSound("PlayerAttack", "Resources/Sounds/player_attack.wav");
   ResourceSystem::Instance()->LoadSound("ArmorPick", "Resources/Sounds/armor.wav");
   ResourceSystem::Instance()->LoadSound("HealthPick", "Resources/Sounds/AS.wav");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	MyEngine::Engine::Instance()->Run();

	return 0;
}