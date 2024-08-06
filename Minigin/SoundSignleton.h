#pragma once
#include "Sound.h"
#include "SoundLogger.h"
#include <memory>
namespace dae {

    class SoundSingleton
    {
    public:
        static Sound& getAudio();
        static void provide(std::unique_ptr<Sound>&& service);
        static void enableAudioLogging();

    private:
        static std::unique_ptr<Sound> service_;
    };
}


