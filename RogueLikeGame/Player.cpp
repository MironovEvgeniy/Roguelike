#include "Player.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>
#include <MovementComponent.h>


namespace XYZRoguelike
{

	Player::Player(const MyEngine::Vector2Df& position)
	{
		gameObject = MyEngine::GameWorld::Instance()->CreateGameObject("Player");
		auto transform = gameObject->GetComponent<MyEngine::TransformComponent>();
		transform->SetWorldPosition(position);

		auto renderer = gameObject->AddComponent<MyEngine::SpriteRendererComponent>();
		renderer->SetTexture(*MyEngine::ResourceSystem::Instance()->GetTextureMapElementShared("player_idle", 0));
		renderer->SetPixelSize(100, 100);

		auto camera = gameObject->AddComponent<MyEngine::CameraComponent>();
		camera->SetWindow(&MyEngine::RenderSystem::Instance()->GetMainWindow());
		camera->SetBaseResolution(1280, 720);

		auto input = gameObject->AddComponent<MyEngine::InputComponent>();

		auto movement = gameObject->AddComponent<MyEngine::MovementComponent>();
		movement->SetSpeed(400.f);

		auto rigidbody = gameObject->AddComponent<MyEngine::RigidbodyComponent>();
		rigidbody->SetKinematic(false);

		auto collider = gameObject->AddComponent<MyEngine::SpriteColliderComponent>();
		collider->SetPadding({ 50.f, 0.f });

	}




	MyEngine::GameObject* Player::GetGameObject()
	{
		return gameObject;
	}
}