#include "SoundSignleton.h"

namespace dae {
	Sound* SoundSingleton::service_{ new NullAudio };
	NullAudio SoundSingleton::nullService_{  };
}
