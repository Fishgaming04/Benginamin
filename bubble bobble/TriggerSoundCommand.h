#pragma once
#include "GameObject.h"
#include "Command.h"
#include "Sound.h"
#include <string>

namespace dae {
	class TriggerSound final : public Command
	{
	public:

		TriggerSound(int soundID);

		virtual void Execute(float);

		virtual ~TriggerSound() {};
		TriggerSound(const TriggerSound& other) = delete;
		TriggerSound(TriggerSound&& other) = delete;
		TriggerSound& operator=(const TriggerSound& other) = delete;
		TriggerSound& operator=(TriggerSound&& other) = delete;

	private:
		int m_SoundID;
		Sound& m_pSoundService;
	};
}