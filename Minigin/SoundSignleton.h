#pragma once
#include "Sound.h"
#include "SoundLogger.h"
#include <memory>
namespace dae {

    class SoundSingleton
    {
    public:
        static void initialize() {
            service_ = &nullService_; }

        ~SoundSingleton() {
        }

        //rule of 5
        SoundSingleton(const SoundSingleton& other) = delete;
        SoundSingleton(SoundSingleton&& other) = delete;
        SoundSingleton& operator=(const SoundSingleton& other) = delete;
        SoundSingleton& operator=(SoundSingleton&& other) = delete;        


        static Sound& getAudio() { return *service_; }

<<<<<<< HEAD
        static void provide(std::unique_ptr<Sound> service);

        static void enableAudioLogging();

    private:
        static std::unique_ptr<Sound> service_;
=======
        static void provide(Sound* service)
        {
            if (service == nullptr) {
                // Revert to null service.
                service_ = &nullService_;
            }
            else {
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
>>>>>>> parent of 03d3b21 (memory leaks but works)
    };
}


