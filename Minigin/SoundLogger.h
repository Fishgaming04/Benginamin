#pragma once
#include "Sound.h"

class LoggedAudio : public Sound
{
public:
    LoggedAudio(Sound& wrapped)
        : wrapped_(wrapped)
    {}

    virtual void playSound(int soundID)
    {
        log("play sound");
        wrapped_.playSound(soundID);
    }

    virtual void stopSound(int soundID)
    {
        log("stop sound");
        wrapped_.stopSound(soundID);
    }

    virtual void stopAllSounds()
    {
        log("stop all sounds");
        wrapped_.stopAllSounds();
    }

private:
    void log(const char* message)
    {
        // Code to log message...
    }

    Sound& wrapped_;
};