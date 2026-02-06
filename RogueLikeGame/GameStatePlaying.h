#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "GameStateData.h"
#include "Bonus.h"

#include <unordered_map>

namespace RogueLikeGame
{
class Game;

enum class BonusType
{
    BiggerPlatform,
    SlowBall,

    Count
};

class GameStatePlayingData : public GameStateData
{
  public:
    void Init() override;
    void HandleWindowEvent(const sf::Event &event) override;
    void Update(float timeDelta) override;
    void Draw(sf::RenderWindow &window) override;

  private:
    // Resources
    sf::Texture appleTexture;
    sf::Texture rockTexture;
    sf::Font font;
    sf::SoundBuffer eatAppleSoundBuffer;
    sf::SoundBuffer gameOverSoundBuffer;
    sf::SoundBuffer bonusSoundBuffer;

    // Game data

    // UI data
    sf::Text temporaryText;
    sf::Text inputHintText;
    sf::RectangleShape background;

    // Sounds
    sf::Sound gameOverSound;
    sf::Sound bonusSound;

    // Bonus
    std::map<BonusType, Bonus> bonuses;
};
} // namespace RogueLikeGame
