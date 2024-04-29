#pragma once
#include "Sound.h"
namespace dae {
    class LoggedAudio : public Sound
    {
    public:
<<<<<<< HEAD
<<<<<<< HEAD
        LoggedAudio(std::unique_ptr<Sound> wrapped)
            : wrapped_(std::move(wrapped))
        {}


=======
=======
>>>>>>> parent of 03d3b21 (memory leaks but works)
        LoggedAudio(Sound& wrapped)
            : wrapped_(wrapped)
        {}

<<<<<<< HEAD
>>>>>>> parent of 03d3b21 (memory leaks but works)
=======
>>>>>>> parent of 03d3b21 (memory leaks but works)
        virtual void PlaySoundEffect(const int soundID)
        {
            log("play sound");
            wrapped_.PlaySoundEffect(soundID);
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
        virtual void PlayMusic(const char* path, const int loops = -1) {
            log("play music");
            wrapped_.PlayMusic(path, loops);
        }

    private:
        void log(const char* message)
        {
            message;
        }

<<<<<<< HEAD
<<<<<<< HEAD
        std::unique_ptr<Sound> wrapped_;
=======
        Sound& wrapped_;
>>>>>>> parent of 03d3b21 (memory leaks but works)
=======
        Sound& wrapped_;
>>>>>>> parent of 03d3b21 (memory leaks but works)
    };
}