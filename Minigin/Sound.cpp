#include "Sound.h"
#include <iostream>
#include <SDL.h>

namespace dae {

	class SoundSystem::SoundSystemImpl
	{
	public:
		SoundSystemImpl();
		~SoundSystemImpl();

		virtual void PlaySoundEffect(const int soundID);
		virtual void StopSound(const int soundID);
		virtual void StopAllSounds();
		virtual void LoadSound(const char* path, int& soundID);
		virtual void PlayMusic(const char* path, const int loops = -1);
		virtual void SetVolume(int volume) { Mix_Volume(-1, volume); }
		virtual void SetMusicVolume(int volume) { Mix_VolumeMusic(volume); }
		virtual void StopMusic() { Mix_HaltMusic(); }
		virtual void PauseMusic() { Mix_PauseMusic(); }
		virtual void ResumeMusic() { Mix_ResumeMusic(); }
		virtual void PauseSound(int channel) { Mix_Pause(channel); }
		virtual void ResumeSound(int channel) { Mix_Resume(channel); }

	private:
		std::vector<Mix_Chunk*> m_pSound;
	};


	SoundSystem::SoundSystemImpl::SoundSystemImpl()
	{
		if (SDL_Init(SDL_INIT_AUDIO) == -1) {
			std::cout << "SDL_Init: " << SDL_GetError() << "\n";
			exit(1);
		}

		if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3) {
			std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << "\n";
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << "\n";
		}

	}

	SoundSystem::SoundSystemImpl::~SoundSystemImpl() {

		for (auto& pSound : m_pSound)
		{
			Mix_FreeChunk(pSound);
			delete pSound;
			pSound = nullptr;
		}
		Mix_Quit();
	}

	void SoundSystem::SoundSystemImpl::PlaySoundEffect(const int soundID)
	{
		if (soundID < static_cast<int>(m_pSound.size()))
		{
			Mix_Volume(-1, 128);
			if (Mix_PlayChannel(-1, m_pSound[soundID], 0) == -1)
			{
				std::cout << "SoundID: " << soundID << " failed to play\n";
			}
		}
		else
		{
			std::cout << "SoundID out of range\n";
		}
	}

	void SoundSystem::SoundSystemImpl::StopSound(const int soundID)
	{
		Mix_HaltChannel(soundID);
	}

	void SoundSystem::SoundSystemImpl::StopAllSounds()
	{
		StopSound(-1);
	}


	void SoundSystem::SoundSystemImpl::LoadSound(const char* path, int& soundID)
	{
		if (path == nullptr)
		{
			std::cout << "Path is null\n";
			return;
		}
		else
		{
			m_pSound.push_back(Mix_LoadWAV(path));
			soundID = static_cast<int>(m_pSound.size() - 1);
			if (m_pSound.back() == nullptr)
			{
				std::cout << "Failed to load sound: " << path << " SDL_mixer Error: " << Mix_GetError() << "\n";
			}
			return;
		}
	}

	void SoundSystem::SoundSystemImpl::PlayMusic(const char* path, const int loops)
	{
		if (path == nullptr)
		{
			std::cout << "Path is null\n";
		}
		else
		{
			Mix_Music* music = Mix_LoadMUS(path);
			if (music == nullptr)
			{
				std::cout << "Failed to load music: " << path << " SDL_mixer Error: " << Mix_GetError() << "\n";
			}
			else
			{
				Mix_PlayMusic(music, loops);
			}
		}
	}





	SoundSystem::SoundSystem()
		: m_pImpl{ new SoundSystemImpl() }
	{
	}

	SoundSystem::~SoundSystem()
	{
		delete m_pImpl;
		m_pImpl = nullptr;
	}

	void SoundSystem::PlaySoundEffect(const int soundID)
	{
		m_thread = std::jthread{ &SoundSystemImpl::PlaySoundEffect , m_pImpl, soundID };
	}

	void SoundSystem::StopSound(const int soundID)
	{
		m_thread = std::jthread{ &SoundSystemImpl::StopSound , m_pImpl, soundID };
	}

	void SoundSystem::StopAllSounds()
	{
		m_thread = std::jthread{ &SoundSystemImpl::StopAllSounds , m_pImpl };
	}

	int SoundSystem::LoadSound(const char* path)
	{
		int soundID;
		m_thread = std::jthread{ &SoundSystemImpl::LoadSound, m_pImpl , path, std::ref(soundID) };
		return soundID;
	}

	void SoundSystem::PlayMusic(const char* path, const int loops)
	{
		m_thread = std::jthread{ &SoundSystemImpl::PlayMusic, m_pImpl, path, loops };
	}

	void SoundSystem::SetVolume(int volume)
	{
		m_thread = std::jthread{ &SoundSystemImpl::SetVolume, m_pImpl, volume };
	}

	void SoundSystem::SetMusicVolume(int volume)
	{
		m_thread = std::jthread{ &SoundSystemImpl::SetMusicVolume, m_pImpl, volume };
	}

	void SoundSystem::StopMusic()
	{
		m_thread = std::jthread{ &SoundSystemImpl::StopMusic, m_pImpl };
	}

	void SoundSystem::PauseMusic()
	{
		m_thread = std::jthread{ &SoundSystemImpl::PauseMusic, m_pImpl };
	}

	void SoundSystem::ResumeMusic()
	{

		m_thread = std::jthread{ &SoundSystemImpl::ResumeMusic , m_pImpl };
	}

	void SoundSystem::PauseSound(int channel)
	{
		m_thread = std::jthread{ &SoundSystemImpl::PauseSound , m_pImpl , channel };
	}

	void SoundSystem::ResumeSound(int channel)
	{
		m_thread = std::jthread{ &SoundSystemImpl::ResumeSound , m_pImpl , channel };
	}

}