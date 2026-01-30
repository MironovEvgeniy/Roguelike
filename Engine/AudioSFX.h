#pragma once
#include "GameObject.h"
#include "GameWorld.h"
#include "AudioComponent.h"
#include "ResourceSystem.h"
#include "DestroyStopAudio.h"
namespace MyEngine
{
   class AudioSFX
   {

   public:
      AudioSFX(const std::string& soundName);
   };
} 