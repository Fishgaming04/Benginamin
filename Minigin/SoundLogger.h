#pragma once
#include "Sound.h"
namespace dae {
    class LoggedAudio : public Sound
    {
    public:
        LoggedAudio(Sound& wrapped)
            : wrapped_(wrapped)
        {}

        virtual void PlaySound(const int soundID)
        {
            log("play sound");
            wrapped_.PlaySound(soundID);
        }

        virtual void StopSound(const int soundID)
        {
            log("stop sound");
            wrapped_.StopSound(soundID);
        }

        virtual void StopAllSounds()
        {
            log("stop all sounds");
            wrapped_.StopAllSounds();
        }

        virtual int LoadSound(const char* path) {
            log("load sound");
            wrapped_.LoadSound(path);
            return 0;
        }

    private:
        void log(const char* message)
        {
            message;
        }

        Sound& wrapped_;
    };
}