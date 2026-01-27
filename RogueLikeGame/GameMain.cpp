
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

	ResourceSystem::Instance()->LoadTextureMap("player_idle", "Resources/Textures/Idle.png", { 100, 64 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("level_walls", "Resources/Textures/Wall.png", { 16, 16 }, 48, false);
	ResourceSystem::Instance()->LoadTextureMap("cobald_idle", "Resources/Textures/idleCob.png", { 148, 96 }, 6, false);

	ResourceSystem::Instance()->LoadSound("GamePlaymusic", "Resources/Sounds/trapped.wav");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	MyEngine::Engine::Instance()->Run();

	return 0;
}