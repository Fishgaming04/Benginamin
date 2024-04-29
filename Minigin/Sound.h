#pragma once
#include <SDL_mixer.h>
#include <vector>
#include <thread>

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
		virtual void SetVolume(int volume) = 0;
		virtual void SetMusicVolume(int volume) = 0;
		virtual void StopMusic() = 0;
		virtual void PauseMusic() = 0;
		virtual void ResumeMusic() = 0;
		virtual void PauseSound(int channel) = 0;
		virtual void ResumeSound(int channel) = 0;
	};

	class NullAudio : public Sound
	{
	public:
		virtual void PlaySoundEffect(const int) {}
		virtual void StopSound(const int) {}
		virtual void StopAllSounds(){}
		virtual int LoadSound(const char*) { return 0; };
		virtual void PlayMusic(const char*, const int) {};
		virtual void SetVolume(int ) {};
		virtual void SetMusicVolume(int ) {};
		virtual void StopMusic() {};
		virtual void PauseMusic() {};
		virtual void ResumeMusic() {};
		virtual void PauseSound(int ) {};
		virtual void ResumeSound(int ) {};
	};


	class SoundSystem final: public Sound
	{
	private:
		class SoundSystemImpl;
		SoundSystemImpl* m_pImpl;
		std::jthread m_thread;
	
	public:
		SoundSystem();
		virtual ~SoundSystem();

		//rule of 5
		SoundSystem(const SoundSystem& other) = delete;
		SoundSystem(SoundSystem&& other) = delete;
		SoundSystem& operator=(const SoundSystem& other) = delete;
		SoundSystem& operator=(SoundSystem&& other) = delete;

		virtual void PlaySoundEffect(const int soundID) override;
		virtual void StopSound(const int soundID) override;
		virtual void StopAllSounds() override;
		virtual int  LoadSound(const char* path) override;
		virtual void PlayMusic(const char* path, const int loops = -1) override;
		virtual void SetVolume(int volume) override;
		virtual void SetMusicVolume(int volume) override;
		virtual void StopMusic() override;
		virtual void PauseMusic() override;
		virtual void ResumeMusic() override;
		virtual void PauseSound(int channel) override;
		virtual void ResumeSound(int channel) override;
	};
}