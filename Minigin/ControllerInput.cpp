#include "ControllerInput.h"

namespace dae {




	ControllerInput::ControllerInput(unsigned int controllerIndex)
		: previousState{}
		, currentState{}
		, buttonsPressedThisFrame{}
		, buttonsReleasedThisFrame{}
		, m_ControllerIndex{ controllerIndex }
	{
		ZeroMemory(&previousState, sizeof(XINPUT_STATE));
		ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	}

	void ControllerInput::update()
	{
		CopyMemory(&previousState, &currentState, sizeof(XINPUT_STATE));
		ZeroMemory(&currentState, sizeof(XINPUT_STATE));
		XInputGetState(m_ControllerIndex, &currentState);
		auto buttonChanges = currentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
		buttonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
		buttonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);

	}

	bool ControllerInput::IsDownThisFrame(controllerButtons button) const
	{
		return buttonsPressedThisFrame & static_cast<unsigned int>(button);
	}

	bool ControllerInput::IsUpThisFrame(controllerButtons button) const
	{
		return buttonsReleasedThisFrame & static_cast<unsigned int>(button);
	}

	bool ControllerInput::IsPressed(controllerButtons button) const
	{
		return currentState.Gamepad.wButtons & static_cast<unsigned int>(button);
	}

	ControllerInput::~ControllerInput()
	{
	}

}