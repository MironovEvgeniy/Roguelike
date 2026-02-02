#include "GameStatePlaying.h"
#include "Application.h"
#include "Game.h"
#include "Text.h"
#include "randomizer.h"
#include <assert.h>
#include <sstream>

namespace RogueLikeGame
{
void GameStatePlayingData::Init()
{
    // Init game resources (terminate if error)
    assert(font.loadFromFile(SETTINGS.FONTS_PATH + "Roboto-Regular.ttf"));
    assert(gameOverSoundBuffer.loadFromFile(SETTINGS.SOUNDS_PATH + "Death.wav"));

    // Init background
    background.setSize(sf::Vector2f(SETTINGS.SCREEN_WIDTH, SETTINGS.SCREEN_HEIGHT));
    background.setPosition(0.f, 0.f);
    background.setFillColor(sf::Color(0, 0, 0));

    temporaryText.setFont(font);
    temporaryText.setCharacterSize(48);
    temporaryText.setFillColor(sf::Color::Yellow);
    temporaryText.setString("WORK IN PROGRESS");
    temporaryText.setOrigin(GetTextOrigin(temporaryText, {0.5f, 0.5f}));

    inputHintText.setFont(font);
    inputHintText.setCharacterSize(24);
    inputHintText.setFillColor(sf::Color::White);
    inputHintText.setString("Use arrow keys to move, ESC to pause");
    inputHintText.setOrigin(GetTextOrigin(inputHintText, {1.f, 0.f}));

    // Init sounds
    gameOverSound.setBuffer(gameOverSoundBuffer);
    bonusSound.setBuffer(bonusSoundBuffer);
}

void GameStatePlayingData::HandleWindowEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            Application::Instance().GetGame().PauseGame();
        }
    }
}

void GameStatePlayingData::Update(float timeDelta)
{
    static auto updateFunctor = [timeDelta](auto obj) { obj->Update(timeDelta); };

    std::for_each(bonuses.begin(), bonuses.end(), [timeDelta](auto &bonusPair) { bonusPair.second.Update(timeDelta); });
}

void GameStatePlayingData::Draw(sf::RenderWindow &window)
{
    // Draw background
    window.draw(background);

    static auto drawFunc = [&window](auto block) { block->Draw(window); };

    // Draw game objects
    temporaryText.setPosition(SETTINGS.SCREEN_WIDTH / 2.f, SETTINGS.SCREEN_HEIGHT / 2.f);
    window.draw(temporaryText);

    sf::Vector2f viewSize = window.getView().getSize();
    inputHintText.setPosition(viewSize.x - 10.f, 10.f);
    window.draw(inputHintText);
}

} // namespace RogueLikeGame
