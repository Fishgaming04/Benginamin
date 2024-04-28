#include "Sound.h"
#include "Sound.h"
#include <iostream>
#include <SDL.h>

namespace dae {

	ConsoleAudio::ConsoleAudio()
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

	ConsoleAudio::~ConsoleAudio(){

		for (auto& pSound : m_pSound)
		{
			Mix_FreeChunk(pSound);
			delete pSound;
			pSound = nullptr;
		}
		Mix_Quit();
		SDL_Quit();
	}

	void ConsoleAudio::PlaySoundEffect(const int soundID)
	{
		if (soundID < m_pSound.size())
		{
			Mix_Volume(-1, 128); 
			if (!Mix_PlayChannel(-1, m_pSound[soundID], 0))
			{
				std::cout << "SoundID: " << soundID << " failed to play\n";
			}
		}
		else
		{
			std::cout << "SoundID out of range\n";
		}
	}

	void ConsoleAudio::StopSound(const int soundID)
	{
		soundID;
	}

	void ConsoleAudio::StopAllSounds()
	{
	}


	int ConsoleAudio::LoadSound(const char* path)
	{
		if (path == nullptr)
		{
			std::cout << "Path is null\n";
			return 0;
		}
		else
		{
			m_pSound.push_back(Mix_LoadWAV(path));
			return static_cast<int>(m_pSound.size() - 1);
		}
	}

	void ConsoleAudio::PlayMusic(const char* path, const int loops)
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

}