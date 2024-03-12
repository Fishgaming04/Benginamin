#pragma once
#include "Singleton.h"
#include <Xinput.h>
#include <Windows.h>
namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		bool IsDownThisFrame(unsigned int button) const;
		bool IsUpThisFrame(unsigned int button) const;
		bool IsPressed(unsigned int button) const;
	private:
	XINPUT_STATE previousState;
	XINPUT_STATE currentState;
	unsigned int buttonsPressedThisFrame;
	unsigned int buttonsReleasedThisFrame;
	};

}
