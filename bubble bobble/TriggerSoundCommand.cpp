#include "TriggerSoundCommand.h"
#include "SoundSignleton.h"

namespace dae {
	dae::TriggerSound::TriggerSound(int soundID)
		:Command()
		, m_SoundID{ soundID }
		, m_pSoundService{ SoundSingleton::getAudio() }
	{
	}

	void dae::TriggerSound::Execute(float)
	{
		m_pSoundService.PlaySoundEffect(m_SoundID);
	}
}
