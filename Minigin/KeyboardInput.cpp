#include "KeyboardInput.h"
#include <iostream>
#include <algorithm>

KeyboardInput::KeyboardInput()
	:m_PreviousKeyboardInput(SDL_NUM_SCANCODES)
	,m_CurrentKeyboardInput(SDL_NUM_SCANCODES)
{
}

void KeyboardInput::update()
{

	int size{};
	auto CurrentKeyboardState = SDL_GetKeyboardState(&size);

	m_PreviousKeyboardInput = m_CurrentKeyboardInput;
	m_CurrentKeyboardInput.assign(CurrentKeyboardState, CurrentKeyboardState + size);

}

bool KeyboardInput::IsDownThisFrame(Uint8 button) const
{
	return m_CurrentKeyboardInput[button] && !m_PreviousKeyboardInput[button];
}

bool KeyboardInput::IsUpThisFrame(Uint8 button) const
{
	return !m_CurrentKeyboardInput[button] && m_PreviousKeyboardInput[button];
}

bool KeyboardInput::IsPressed(Uint8 button) const
{
	return m_CurrentKeyboardInput[button];
}
