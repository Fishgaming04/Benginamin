#include <SDL.h>
#include "InputManager.h"


dae::InputManager::InputManager()
{
	//ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	//ZeroMemory(&previousState, sizeof(XINPUT_STATE));
	for (unsigned int index{}; index < m_MaxControllers; ++index)
	{
		m_Controllers.push_back(new ControllerInput{ index });
	}
}

bool dae::InputManager::ProcessInput(float deltaTime)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
	}


	for (auto controller: m_Controllers)
	{
		controller->update();
		for (auto command : m_ControllerCommands)
		{
			if (command.first.first.first == controller->GetControllerIndex()) {

				if (command.first.second == buttonState::heldDown)
				{
					if (controller->IsPressed(command.first.first.second))
					{
						command.second->Execute(deltaTime);
					}
				}
				else if (command.first.second == buttonState::up)
				{
					if (controller->IsUpThisFrame(command.first.first.second))
					{
						command.second->Execute(deltaTime);
					}
				}
				else if (command.first.second == buttonState::down)
				{
					if (controller->IsDownThisFrame(command.first.first.second))
					{
						command.second->Execute(deltaTime);
					}
				}
			}
		}
	}

	//int m_controllerIndex{};
	//CopyMemory(&previousState, &currentState, sizeof(XINPUT_STATE));
	//ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	//XInputGetState(m_controllerIndex, &currentState);
	//auto buttonChanges = currentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
	//buttonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
	//buttonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);

		
	return true;
}

void dae::InputManager::AddCommand(const ControllerInput::controllerButtons button, const buttonState state, Command* command, const unsigned int controllerIndex)
{
	ControllerButton cButton = std::make_pair(controllerIndex, button);
	ControllerButtonState cButtonState = std::make_pair(cButton, state);
	m_ControllerCommands.insert(std::make_pair(cButtonState, command));
}

void dae::InputManager::RemoveCommand(const ControllerInput::controllerButtons button, const buttonState state, const unsigned int controllerIndex)
{
	ControllerButton cButton = std::make_pair(controllerIndex, button);
	ControllerButtonState cButtonState = std::make_pair(cButton, state);
	m_ControllerCommands.erase(cButtonState);
}

dae::InputManager::~InputManager()
{
	for (auto controller : m_Controllers)
	{
		delete controller;
		controller = nullptr;
	}
	m_Controllers.clear();
}





//
//
//bool dae::InputManager::IsDownThisFrame(unsigned int button) const
//{
//	return buttonsPressedThisFrame & button;
//}
//
//bool dae::InputManager::IsUpThisFrame(unsigned int button) const
//{
//	return buttonsReleasedThisFrame & button;
//}
//
//bool dae::InputManager::IsPressed(unsigned int button) const
//{
//	return currentState.Gamepad.wButtons & button;
//}
