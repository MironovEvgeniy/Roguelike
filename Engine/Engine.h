#pragma once
#define NOMINMAX
#include "EngineAPI.h"
#include "SFML/Graphics.hpp"

namespace XYZEngine
{
	class ENGINE_API Engine
	{
	public:
		Engine(const Engine& app) = delete;
		Engine& operator= (const Engine&) = delete;

		static Engine* Instance();

		void Run();

	private:
		Engine();
		~Engine() = default;

	private:
		sf::RenderWindow window;
	};
}