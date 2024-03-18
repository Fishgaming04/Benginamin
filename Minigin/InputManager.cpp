#include <SDL.h>
#include "InputManager.h"


dae::InputManager::InputManager()
	: m_KeyboardPtr{ new KeyboardInput() }
{
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

	m_KeyboardPtr->update();

	for (auto& controller: m_Controllers)
	{
		controller->update();
		for (auto& command : m_ControllerCommands)
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

	m_KeyboardPtr->update();
	for (auto& command : m_KeyboardCommands)
	{
		if (command.first.second == buttonState::heldDown)
		{
			if (m_KeyboardPtr->IsPressed(static_cast<Uint8>(command.first.first)))
			{
				command.second->Execute(deltaTime);
			}
		}
		else if (command.first.second == buttonState::up)
		{
			if (m_KeyboardPtr->IsUpThisFrame(static_cast<Uint8>(command.first.first)))
			{
				command.second->Execute(deltaTime);
			}
		}
		else if (command.first.second == buttonState::down)
		{
			if (m_KeyboardPtr->IsDownThisFrame(static_cast<Uint8>(command.first.first)))
			{
				command.second->Execute(deltaTime);
			}
		}
	}


	return true;
}

void dae::InputManager::AddCommand(const ControllerInput::controllerButtons button, const buttonState state, Command* command, const unsigned int controllerIndex)
{
	ControllerButton cButton = std::make_pair(controllerIndex, button);
	ControllerButtonState cButtonState = std::make_pair(cButton, state);
	m_ControllerCommands.insert(std::make_pair(cButtonState, command));
}

void dae::InputManager::AddCommand(const SDL_Scancode key, const buttonState state, Command* command)
{
	KeyboardKeyState keyState = std::make_pair(key, state);
	m_KeyboardCommands.insert(std::make_pair(keyState, command));
}

void dae::InputManager::RemoveCommand(const ControllerInput::controllerButtons button, const buttonState state, const unsigned int controllerIndex)
{
	ControllerButton cButton = std::make_pair(controllerIndex, button);
	ControllerButtonState cButtonState = std::make_pair(cButton, state);
	m_ControllerCommands.erase(cButtonState);
}

void dae::InputManager::RemoveCommand(const SDL_Scancode key, const buttonState state)
{
	KeyboardKeyState keyState = std::make_pair(key, state);
	m_KeyboardCommands.erase(keyState);
}

dae::InputManager::~InputManager()
{
	delete m_KeyboardPtr;
	m_KeyboardPtr = nullptr;

	for (auto controller : m_Controllers)
	{
		delete controller;
		controller = nullptr;
	}
	m_Controllers.clear();
}


