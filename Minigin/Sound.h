#pragma once
#include <SDL_mixer.h>
#include <vector>


namespace dae{
	class Sound

	{
	public:
		Sound();
		virtual ~Sound() {}
		virtual void PlaySound(const int soundID) = 0;
		virtual void StopSound(const int soundID) = 0;
		virtual void StopAllSounds() = 0;
		virtual int LoadSound(const char* path) = 0;
	};

	class NullAudio : public Sound
	{
	public:
		virtual void PlaySound(const int) {}
		virtual void StopSound(const int) {}
		virtual void StopAllSounds(){}
		virtual int LoadSound(const char*) { return 0; };
	};



	class ConsoleAudio : public Sound
	{
	public:
		virtual void PlaySound(const int soundID) override;
		virtual void StopSound(const int soundID) override;
		virtual void StopAllSounds() override;
		virtual int LoadSound(const char* path) override;
	private:
		std::vector<Mix_Music*> m_pMusic;
		std::vector<Mix_Chunk*> m_pSound;
	};
}