#pragma once
#include <SDL_mixer.h>
#include <vector>


namespace dae{
	class Sound

	{
	public:
		virtual ~Sound() {}

		virtual void PlaySoundEffect(const int soundID) = 0;
		virtual void StopSound(const int soundID) = 0;
		virtual void StopAllSounds() = 0;
		virtual int	 LoadSound(const char* path) = 0;
		virtual void PlayMusic(const char* path, const int loops) = 0;
	};

	class NullAudio : public Sound
	{
	public:
		virtual void PlaySoundEffect(const int) {}
		virtual void StopSound(const int) {}
		virtual void StopAllSounds(){}
		virtual int LoadSound(const char*) { return 0; };
		virtual void PlayMusic(const char*, const int) {};
	};



	class ConsoleAudio : public Sound
	{
	public:
		ConsoleAudio();
		virtual ~ConsoleAudio();

		//rule of 5
		ConsoleAudio(const ConsoleAudio& other) = delete;
		ConsoleAudio(ConsoleAudio&& other) = delete;
		ConsoleAudio& operator=(const ConsoleAudio& other) = delete;
		ConsoleAudio& operator=(ConsoleAudio&& other) = delete;

		virtual void PlaySoundEffect(const int soundID) override;
		virtual void StopSound(const int soundID) override;
		virtual void StopAllSounds() override;
		virtual int LoadSound(const char* path) override;
		virtual void PlayMusic(const char* path, const int loops = -1) override;
	private:
		std::vector<Mix_Chunk*> m_pSound;
	};
}