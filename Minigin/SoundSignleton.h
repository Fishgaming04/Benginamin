#pragma once
#include "Sound.h"
#include "SoundLogger.h"


class Locator
{
public:
    static void initialize() { service_ = &nullService_; }

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
        Sound* service_ = new LoggedAudio(Locator::getAudio());

        // Swap it in.
        Locator::provide(service_);
    }

private:
    static Sound* service_;
    static NullAudio nullService_;
};


