#pragma once
class Sound

{
public:
	virtual ~Sound() {}
	virtual void playSound(int soundID) = 0;
	virtual void stopSound(int soundID) = 0;
	virtual void stopAllSounds() = 0;
};

class NullAudio : public Sound
{
public:
	virtual void playSound(int soundID) {}
	virtual void stopSound(int soundID) {}
	virtual void stopAllSounds()		{}
};



class ConsoleAudio : public Sound
{
public:
	virtual void playSound(int soundID)
	{
		// Play sound using console audio api...
	}

	virtual void stopSound(int soundID)
	{
		// Stop sound using console audio api...
	}

	virtual void stopAllSounds()
	{
		// Stop all sounds using console audio api...
	}
};