#include "Sound.h"
#include <iostream>
#include <SDL.h>

namespace dae {
	void ConsoleAudio::PlaySound(const int soundID)
	{
		if (soundID < m_pSound.size())
		{
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

	Sound::Sound()
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
}