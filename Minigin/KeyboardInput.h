#pragma once
#include <vector>
#include <SDL.h>

class KeyboardInput final
{
public:

	KeyboardInput();

	void update();

	bool IsDownThisFrame(Uint8  button) const;
	bool IsUpThisFrame(Uint8 button) const;
	bool IsPressed(Uint8 button) const;


	~KeyboardInput() {};
	KeyboardInput(const KeyboardInput& other) = delete;
	KeyboardInput(KeyboardInput&& other) = delete;
	KeyboardInput& operator=(const KeyboardInput& other) = delete;
	KeyboardInput& operator=(KeyboardInput&& other) = delete;
private:

	std::vector<Uint8> m_PreviousKeyboardInput;
	std::vector<Uint8> m_CurrentKeyboardInput;

};

