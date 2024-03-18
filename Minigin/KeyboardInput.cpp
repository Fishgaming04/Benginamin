#include "KeyboardInput.h"
#include <iostream>
#include <algorithm>

KeyboardInput::KeyboardInput()
	:m_PreviousKeyboardInput{}
	,m_CurrentKeyboardInput{}
{
}

void KeyboardInput::update()
{

	int size{};
	auto CurrentKeyboardState = SDL_GetKeyboardState(&size);

	m_CurrentKeyboardInput.assign(CurrentKeyboardState, CurrentKeyboardState + size);
	m_PreviousKeyboardInput = m_PreviousKeyboardInput;

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
