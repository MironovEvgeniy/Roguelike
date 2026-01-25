#include "pch.h"
#include "Engine.h"
#include <iostream>

Engine::Engine() {}

void Engine::Initialize()
{
	std::cout << "Engine is initialized" << std::endl;
}

void Engine::Run()
{
	std::cout << "Engine is started" << std::endl;
}