#pragma once
#include "Sound.h"
#include <iostream>
namespace dae {
    class LoggedAudio : public Sound
    {
    public:
        LoggedAudio(Sound* wrapped)
            : wrapped_(wrapped)
        {}

        ~LoggedAudio()
        {
			delete wrapped_;
            wrapped_ = nullptr;
		}

        virtual void PlaySoundEffect(const int soundID)
        {
            log("play sound");
            wrapped_->PlaySoundEffect(soundID);
        }

        virtual void StopSound(const int soundID)
        {
            log("stop sound");
            wrapped_->StopSound(soundID);
        }

        virtual void StopAllSounds()
        {
            log("stop all sounds");
            wrapped_->StopAllSounds();
        }

        virtual int LoadSound(const char* path) {
            log("load sound");
            wrapped_->LoadSound(path);
            return 0;
        }
        virtual void PlayMusic(const char* path, const int loops = -1) {
            log("play music");
            wrapped_->PlayMusic(path, loops);
        }
        virtual void SetVolume(int volume) {
        	log("set volume");
			wrapped_->SetVolume(volume);
        };
        virtual void SetMusicVolume(int volume) {
        	log("set music volume");
			wrapped_->SetMusicVolume(volume);
        };
        virtual void StopMusic() {
    			log("stop music");
                wrapped_->StopMusic();
        };
        virtual void PauseMusic() {
        	log("pause music");
            wrapped_->PauseMusic();
        };
        virtual void ResumeMusic() {
        	log("resume music");
			wrapped_->ResumeMusic();
        };
        virtual void PauseSound(int channel) {
        	log("pause sound");
            wrapped_->PauseSound(channel);
        };
        virtual void ResumeSound(int channel) {
        	log("resume sound");
			wrapped_->ResumeSound(channel);
        };
    private:
        void log(const char* message)
        {
            std::cout << "LoggedAudio: " << message << "\n";
        }

        Sound* wrapped_;
    };
}