#pragma once
#include "Sound.h"
#include "SoundLogger.h"

namespace dae {

    class SoundSingleton
    {
    public:
        static void initialize() {
            }

        ~SoundSingleton() {
			delete service_; 
        }

        //rule of 5
        SoundSingleton(const SoundSingleton& other) = delete;
        SoundSingleton(SoundSingleton&& other) = delete;
        SoundSingleton& operator=(const SoundSingleton& other) = delete;
        SoundSingleton& operator=(SoundSingleton&& other) = delete;        


        static Sound& getAudio() { return *service_; }

        static void provide(Sound* service)
        {
            if (service == nullptr) {
                // Revert to null service.
                delete service_;
                service_ = new NullAudio{};
            }
            else if (static_cast<LoggedAudio*>(service) != nullptr) {
				// Already decorated.
                service_ = service;
			}
            else {
                delete service_;
                service_ = service;
            }
        }

        static void enableAudioLogging()
        {
            // Decorate the existing service.
            Sound* service = new LoggedAudio(service_);

            // Swap it in.
            SoundSingleton::provide(service);
        }

    private:
        static Sound* service_;
    };
}


