#include <SDL.h>
#include "InputManager.h"




bool dae::InputManager::ProcessInput(float deltaTime)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
	}

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

	m_Keyboard.update();
	for (auto& command : m_KeyboardCommands)
	{
		if (command.first.second == buttonState::heldDown)
		{
			if (m_Keyboard.IsPressed(static_cast<Uint8>(command.first.first)))
			{
				command.second->Execute(deltaTime);
			}
		}
		else if (command.first.second == buttonState::up)
		{
			if (m_Keyboard.IsUpThisFrame(static_cast<Uint8>(command.first.first)))
			{
				command.second->Execute(deltaTime);
			}
		}
		else if (command.first.second == buttonState::down)
		{
			if (m_Keyboard.IsDownThisFrame(static_cast<Uint8>(command.first.first)))
			{
				command.second->Execute(deltaTime);
			}
		}
	}


	return true;
}

void dae::InputManager::AddCommand(const ControllerInput::controllerButtons button, const buttonState state, std::unique_ptr<Command> command, const unsigned int controllerIndex)
{
	ControllerButton cButton = std::make_pair(controllerIndex, button);
	ControllerButtonState cButtonState = std::make_pair(cButton, state);
	m_ControllerCommands.insert(std::make_pair(cButtonState, std::move(command)));
}

void dae::InputManager::AddCommand(const SDL_Scancode key, const buttonState state, std::unique_ptr<Command> command)
{
	KeyboardKeyState keyState = std::make_pair(key, state);
	m_KeyboardCommands.insert(std::make_pair(keyState, std::move(command)));
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

unsigned int dae::InputManager::AddController()
{
	if (m_Controllers.size() >= m_MaxControllers)
	{
		m_Controllers.push_back(std::make_unique<ControllerInput>( static_cast<unsigned int>(m_Controllers.size()-1)));
		return static_cast<unsigned int>(m_Controllers.size() - 2);
	}
	return 100;
}



