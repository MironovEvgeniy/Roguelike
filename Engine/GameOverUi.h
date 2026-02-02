#pragma once
#include "SFML/Graphics.hpp"
#include "GameWorld.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "HealthComponent.h"

namespace MyEngine
{

class GameOverUi
{
  public:
    float timeSinceGameOver = 0.f;
    sf::Text gameOverText;
    sf::Font font;
    HealthComponent *targetStats = nullptr;
    TransformComponent *targetTransform = nullptr;
};
void InitUI(GameOverUi &ui);
void AttachTextToPlayer(GameOverUi &ui, GameObject *player);
void UpdateUI(GameOverUi &ui, float timeDelta);
void DrawUI(GameOverUi &ui, sf::RenderWindow &window);

} // namespace MyEngine