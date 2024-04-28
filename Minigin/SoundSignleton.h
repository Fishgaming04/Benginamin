#pragma once
#include "Sound.h"
#include "SoundLogger.h"

namespace dae {

    class SoundSingleton
    {
    public:
        static void initialize() {
            nullService_ = NullAudio{};
            service_ = &nullService_; }

        static Sound& getAudio() { return *service_; }

        static void provide(Sound* service)
        {
            if (service == nullptr)
            {
                // Revert to null service.
                service_ = &nullService_;
            }
            else
            {
                service_ = service;
            }
        }

        void enableAudioLogging()
        {
            // Decorate the existing service.
            Sound* service = new LoggedAudio(SoundSingleton::getAudio());

            // Swap it in.
            SoundSingleton::provide(service);
        }

    private:
        static Sound* service_;
        static NullAudio nullService_;
    };
}


