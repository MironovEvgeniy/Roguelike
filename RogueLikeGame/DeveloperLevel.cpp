#include "DeveloperLevel.h"
#include "Wall.h"

using namespace MyEngine;

namespace XYZRoguelike
{
	void DeveloperLevel::Start()
	{
		int width = 10;
		int height = 10;

		for (int y = 0; y < height + 1; y++)
		{
			for (int x = 0; x < width + 1; x++)
			{
				//if left-bottom corner
				if (x == 0 && y == 0)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({ x * 128.f, y * 128.f }), std::forward<int>(25)));
				}

				//if right-bottom corner
				if (x == width && y == 0)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({ x * 128.f, y * 128.f }), std::forward<int>(27)));
				}

				//if left-top corner
				if (x == 0 && y == height)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({ x * 128.f, y * 128.f }), std::forward<int>(1)));
				}

				//if right-top corner
				if (x == width && y == height)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({ x * 128.f, y * 128.f }), std::forward<int>(3)));
				}

				//if bottom (not corner)
				if (y == 0 && x != width && x != 0)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({ x * 128.f, y * 128.f }), std::forward<int>(38)));
				}

				//if top (not corner)
				if (y == height && x != width && x != 0)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<MyEngine::Vector2Df>({ x * 128.f, y * 128.f }), std::forward<int>(38)));
				}
			}
		}

		player = std::make_unique<Player>(std::forward<MyEngine::Vector2Df>({ width / 2 * 128.f, height / 2 * 128.f }));
		ai = std::make_unique<Enemy>(std::forward<MyEngine::Vector2Df>({ 4 / 2 * 128.f, height / 2 * 128.f }), player->GetGameObject());
		music = std::make_unique<Music>("GamePlaymusic");
	}
	void DeveloperLevel::Restart()
	{
		Stop();
		Start();
	}
	void DeveloperLevel::Stop()
	{
		GameWorld::Instance()->Clear();
	}
}