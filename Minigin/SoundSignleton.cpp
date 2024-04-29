#include "SoundSignleton.h"

namespace dae {
<<<<<<< HEAD
	std::unique_ptr<Sound> SoundSingleton::service_ = nullptr;

    Sound& SoundSingleton::getAudio()
    {
		if (service_ == nullptr)
        {
			service_ = std::make_unique<NullAudio>();
			return *service_;
		}
		return *service_;
    }

    void SoundSingleton::provide(std::unique_ptr<Sound>&& service)
    {
        if (service_ == nullptr) {
            // Revert to null service.
            service_ = std::make_unique<NullAudio>();
        }
        else {
            // Create a new LoggedAudio object that wraps the existing service_.
            service_ = std::make_unique<LoggedAudio>(std::move(service_));
        }
    }

    void SoundSingleton::enableAudioLogging()
    {
        // Create a new LoggedAudio object that wraps the existing service_.
        std::unique_ptr<Sound> service = std::make_unique<LoggedAudio>(*service_);
        // Swap it in.
        SoundSingleton::provide(std::move(service));
    }
}
=======
	Sound* SoundSingleton::service_{ new NullAudio };
	NullAudio SoundSingleton::nullService_{  };
}
>>>>>>> parent of 03d3b21 (memory leaks but works)
