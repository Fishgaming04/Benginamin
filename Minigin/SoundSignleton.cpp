#include "SoundSignleton.h"

namespace dae {
	Sound* SoundSingleton::service_{ new NullAudio };
}
