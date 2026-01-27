#pragma once

#include <iostream>
#include <array>
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Music.h"

#include "Wall.h"

using namespace MyEngine;

namespace XYZRoguelike
{
	class DeveloperLevel : public Scene
	{
	public:
		void Start() override;
		void Restart() override;
		void Stop() override;
	private:
		std::shared_ptr<Player> player;
		std::shared_ptr<Enemy> ai;
		std::unique_ptr<Music> music;

		std::vector<std::unique_ptr<Wall>> walls;
	};
}