#include "pch.h"
#include "DestroyStopAudio.h"
namespace MyEngine
{
	DestroyStopAudio::DestroyStopAudio(GameObject* gameObject) : Component(gameObject)
	{

	}
	void DestroyStopAudio::Update(float deltaTime)
	{
		auto a = GetGameObject()->GetComponent<MyEngine::AudioComponent>();
		if (a && !a->IsPlaying())
		{
			MyEngine::GameWorld::Instance()->DestroyGameObject(GetGameObject());
		}

	}
	void DestroyStopAudio::Render()
	{
	}
}