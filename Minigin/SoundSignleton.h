#pragma once
#include "Sound.h"
#include "SoundLogger.h"
#include <memory>
namespace dae {

    class SoundSingleton
    {
    public:
        static void initialize() {
        }

        ~SoundSingleton() {
        }

        //rule of 5
        SoundSingleton(const SoundSingleton& other) = delete;
        SoundSingleton(SoundSingleton&& other) = delete;
        SoundSingleton& operator=(const SoundSingleton& other) = delete;
        SoundSingleton& operator=(SoundSingleton&& other) = delete;        


        static Sound& getAudio();

        static void provide(std::unique_ptr<Sound> service);

        static void enableAudioLogging();

    private:
        static std::unique_ptr<Sound> service_;
      
    };
}


