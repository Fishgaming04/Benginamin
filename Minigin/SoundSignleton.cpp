#include "SoundSignleton.h"

namespace dae {
	std::unique_ptr<Sound> SoundSingleton::service_ = nullptr;

    Sound& SoundSingleton::getAudio()
    {
		if (service_ == nullptr)
        {
			service_ = std::make_unique<NullAudio>(NullAudio{});
			return *service_;
		}
		return *service_;
    }

    void SoundSingleton::provide(std::unique_ptr<Sound>&& service)
    {
        if (service == nullptr) {
            // Revert to null service.
            service_ = std::make_unique<NullAudio>(NullAudio{});
        }
        else {
            service_ = std::move(service);
        }
    }

    void SoundSingleton::enableAudioLogging()
    {
        std::unique_ptr<Sound> service = std::make_unique<Sound>(LoggedAudio(std::move(service_)));

        // Swap it in.
        SoundSingleton::provide(std::move(service));
    }
}