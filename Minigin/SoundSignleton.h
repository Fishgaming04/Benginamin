#pragma once
#include "Sound.h"
#include "SoundLogger.h"

namespace dae {

    class SoundSingleton
    {
    public:
        static void initialize() {
            service_ = &nullService_; }

        ~SoundSingleton() {
			delete service_; 
        }

        //rule of 5
        SoundSingleton(const SoundSingleton& other) = delete;
        SoundSingleton(SoundSingleton&& other) = delete;
        SoundSingleton& operator=(const SoundSingleton& other) = delete;
        SoundSingleton& operator=(SoundSingleton&& other) = delete;        


        static Sound& getAudio() { return *service_; }

<<<<<<< HEAD
<<<<<<< HEAD
        static void provide(std::unique_ptr<Sound> service);
=======
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
>>>>>>> parent of 2c02a82 (testing smartpointers)

        static void enableAudioLogging()
        {
            // Decorate the existing service.
            Sound* service = new LoggedAudio(service_);

            // Swap it in.
            SoundSingleton::provide(service);
        }

    private:
<<<<<<< HEAD
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
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 03d3b21 (memory leaks but works)
=======
>>>>>>> parent of 03d3b21 (memory leaks but works)
=======
>>>>>>> parent of 03d3b21 (memory leaks but works)
=======
        static Sound* service_;
>>>>>>> parent of 2c02a82 (testing smartpointers)
    };
}


