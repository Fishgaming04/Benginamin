#include "SoundSignleton.h"

namespace dae {
    std::unique_ptr<Sound> SoundSingleton::service_ = nullptr;

    Sound& SoundSingleton::getAudio()
    {
        if (service_ == nullptr)
        {
            service_ = std::make_unique<NullAudio>();
        }
        return *service_.get();
    }

    void SoundSingleton::provide(std::unique_ptr<Sound>&& service)
    {
        if (service == nullptr) {
            // Revert to null service.
            service_ = std::make_unique<NullAudio>();
        }
        else {
            // Create a new LoggedAudio object that wraps the existing service_.
            service_ = std::move(service);
        }
    }

    void SoundSingleton::enableAudioLogging()
    {
        // Create a new LoggedAudio object that wraps the existing service_.
        std::unique_ptr<Sound> service = std::make_unique<LoggedAudio>(std::move(service_));
        // Swap it in.
        SoundSingleton::provide(std::move(service));
    }
}
